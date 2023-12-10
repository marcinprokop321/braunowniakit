#include "image.h"
std::vector<image> images;
std::string image_commands[7] = { "compress","load","list","toAscii","write","delete","deleteAll"};
bool Image_loadFile(const char* path, struct image* img)
{
	img->data = stbi_load(path, &img->sizex, &img->sizey, &img->channels, 0);
	if (!img->data)
		return 0;
	img->isCompressed = 0;
	img->name = path;
	return 1;
}
void Image_reChannel(struct image* img, int channels)
{
	const int temp = img->sizex * img->sizey * img->channels;
	unsigned char* data;
	data = (unsigned char*)malloc(temp * sizeof(char));
	int originalIterator = 0;
	int newIterator = 0;
	for (int x = 0; x < img->sizex; x++)
	{
		for (int y = 0; y < img->sizey; y++)
		{
			for (int c = 0; c < channels; c++)
			{
				if ((c + 1) > img->channels)
					data[newIterator + c] = 0;
				else
					data[newIterator + c] = img->data[originalIterator + c];
			}
			originalIterator += img->channels;
			newIterator += channels;
		}
	}
	free(img->data);
	img->data = data;
	img->channels = channels;
}
void Image_Compress(struct image* img, unsigned char precision)
{
	const int temp = img->sizex * img->sizey * img->channels;
	int iterator = 0;
	unsigned char* data;
	data = (unsigned char*)malloc(temp * 1.5 * sizeof(char));
	int dataiterator = 0;
	unsigned char previousPixel[4] = { 0,0,0,0 };
	int stack = 1;
	for (int x = 0; x < img->sizex; x++)
	{
		for (int y = 0; y < img->sizey; y++)
		{
			char isSimilar = 1;
			for (int c = 0; c < img->channels; c++)
				if ((img->data[iterator + c] - (img->data[iterator + c] % precision)) != previousPixel[c])
					isSimilar = 0;
			if (isSimilar && stack < 256)
				stack++;
			else
			{
				data[dataiterator] = stack;
				for (int c = 0; c < img->channels; c++)
					data[dataiterator + 1 + c] = previousPixel[c];
				dataiterator += (img->channels + 1);
				stack = 1;
			}
			for (int c = 0; c < img->channels; c++)
				previousPixel[c] = img->data[iterator + c] - (img->data[iterator + c] % precision);
			iterator += img->channels;
		}
	}
	free(img->data);
	img->data = data;
	img->isCompressed = 1;
	img->compressedSize = dataiterator;
}
bool Image_Save(image* img, const char* path,const char* name)
{
	if (!stbi_write_png(std::string(path+std::string(name)).c_str(), img->sizex, img->sizey, img->channels, img->data, img->sizex * img->channels))
		return 0;
	else
		return 1;
}
void Image_delete(image* img)
{
	stbi_image_free(img->data);
}
void Image_deCompress(struct image* img)
{
	const int temp = img->sizex * img->sizey * img->channels;
	unsigned char* data1;
	data1 = (unsigned char*)malloc(temp * sizeof(char));
	int iterator = 0;
	int iterator2 = -img->channels;
	for (int i = 0; i < img->compressedSize; i += (img->channels + 1))
	{
		for (int j = 0; j < img->data[i]; j++)
		{
			for (int c = 0; c < img->channels; c++)
			{
				data1[iterator2++] = img->data[c + 1 + iterator];
			}
		}
		iterator += (img->channels + 1);
	}
	img->isCompressed = 0;
	free(img->data);
	img->data = data1;
}
bool Image_toAscii(struct image* img, int sizex, int sizey,int level)
{
	if (img == nullptr)
	{
		printf("WRONG INDEX!\n");
		return 0;
	}
	std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> conv1;
	unsigned char aha2[8] = { 1,2,4,64,8,16,32,128 };
	int scalex = ((img->sizex / sizex)/2.0);
	int scaley = ((img->sizey / sizey)/4.0);
	long long int iterator = 0;
	std::string buffer = "";
	for(int y = 0; y < sizey; y++)
	{
		for(int x = 0; x < sizex; x++)
		{
			uint32_t chartoPrint = 10240;
			for (int i = 0; i < 8; i++)
			{
				int pixelSum = 0;
				for(int xi =0;xi<scalex; xi++)
				{
					for (int yi = 0; yi < scaley; yi++)
					{
						iterator =(((((((y * 4) + (i% 4))) * scaley) + yi) * img->sizex) + (((((x * 2) + (i / 4)) * scalex) + xi))) * img->channels;
						for(int j = 0; j < 3; j++)
							pixelSum += img->data[iterator+j];
					}
				}
				pixelSum /= (scalex * scaley*3);
				if (pixelSum <= level)
					chartoPrint += aha2[i];
			}
			if (chartoPrint == 10240)
				chartoPrint += 4;
			buffer+= conv1.to_bytes(chartoPrint);
		}
		buffer += "\n";
	}
	std::cout << buffer;
	return 1;
}
void Image_deleteAll(void)
{
	for (int i = 0; i < images.size(); i++)
	{
		Image_delete(&images[i]);
	}
}
void Image_Pars(int i, std::vector<std::string> args)
{
	if (args.size() == 1)
	{
		printf("IMAGE>\n      compress (index)(level of compression)\n      load (path)\n      list/*no arguments*/\n      toAscii (index)(sizeX)(sizeY)(colorLevel)\n      write (index)(path)(name)\n      delete (index)\n      deleteAll /*no arguments*/\n\n");
		return;
	}
	int commandId = -1;
	for (int i = 0; i < 6; i++)
	{
		if (args[1] == image_commands[i])
			commandId = i;
	}
	if (commandId == -1)
	{
		printf("WRONG ARGUMENTS\n");
		return;
	}
	int compLevel = -1;
	int imageId = 0;
	int scaley = 0;
	int scalex = 0;
	int level = 0;
	switch (commandId)
	{
	case 0:
		if (args.size() < 4)
		{
			printf("WRONG ARGUMENTS\n");
			return;
		}
		imageId += atoi(args[2].c_str());
		if (imageId == 0)
		{
			printf("WRONG ARGUMENTS\n");
			return;
		}
		compLevel = -1;
		compLevel += atoi(args[3].c_str());
		if (compLevel == -1)
		{
			printf("WRONG ARGUMENTS\n");
			return;
		}
		compLevel++;
		Image_Compress(&images[imageId-1], compLevel);
		Image_deCompress(&images[imageId-1]);
		break;
	case 1:
		if (args.size() < 3)
		{
			printf("WRONG ARGUMENTS\n");
			return;
		}
		image img;
		if (!Image_loadFile(args[2].c_str(), &img))
		{
			printf("LOAD ERROR\n");
			free(img.data);
			return;
		}
		else
			images.push_back(img);
		break;
	case 2:
		for (int i = 0; i < images.size(); i++)
		{
			printf("%d", i+1);
			printf(". ");
			printf("%s", images[i].name);
			printf("\n");
		}
		printf("\n");
		break;
	case 3:
		if (args.size() < 6)
		{
			printf("WRONG ARGUMENTS\n");
			return;
		}
		imageId += atoi(args[2].c_str());
		if (imageId == 0)
		{
			printf("WRONG ARGUMENTS\n");
			return;
		}
		scalex = atoi(args[3].c_str());
		if (scalex == 0)
		{
			printf("WRONG ARGUMENTS\n");
			return;
		}
		scaley = atoi(args[4].c_str());
		if (scaley == 0)
		{
			printf("WRONG ARGUMENTS\n");
			return;
		}
		level = atoi(args[5].c_str());
		if (level == 0)
		{
			printf("WRONG ARGUMENTS\n");
			return;
		}
		Image_toAscii(&images[imageId - 1], scalex, scaley, level);
		break;
	case 4:
		if (args.size() < 5)
		{
			printf("WRONG ARGUMENTS\n");
			return;
		}
		imageId += atoi(args[2].c_str());
		if (imageId == 0)
		{
			printf("WRONG ARGUMENTS\n");
			return;
		}
		if (!Image_Save(&images[imageId - 1], args[3].c_str(), args[4].c_str()))
			printf("WRITE ERROR\n");
		break;
	case 5:
		if (args.size() < 3)
		{
			printf("WRONG ARGUMENTS\n");
			return;
		}
		imageId += atoi(args[2].c_str());
		if (imageId == 0)
		{
			printf("WRONG ARGUMENTS\n");
			return;
		}
		Image_delete(&images[imageId - 1]);
		break;
	case 6:
		Image_deleteAll();
		break;
	default:
		printf("WRONG ARGUMENTS\n");
		break;
	}
}
