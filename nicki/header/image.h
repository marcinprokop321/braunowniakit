#pragma once
#include "global_includes.h"


#include <stb_image/stb_image.h>
#include <stb_image/stb_image_write.h>
struct image
{
	int sizex;
	int sizey;
	unsigned char* data;
	int channels;
	char isCompressed;
	int compressedSize;
	const char* name;
};
struct compactPixels
{
	int ammount;
	char pixel[4];
};
bool Image_loadFile(const char* path, struct image* img);
void Image_reChannel(struct image* img, int channels);
void Image_Compress(struct image* img, unsigned char precision);
void Image_deCompress(struct image* img);
void Image_Pars(int i, std::vector<std::string> args);
bool Image_Save(struct image* img, const char* path, const char* name);
void Image_delete(struct image* img);
bool Image_toAscii(struct image* img, int sizex, int sizey,int level);
void Image_deleteAll(void);