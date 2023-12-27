#include"core.h"
#define STB_IMAGE_IMPLEMENTATION  
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image/stb_image.h>
#include <stb_image/stb_image_write.h>
std::string commands[10];
 void (*comFuncs[10])(int i, std::vector<std::string> args);

void log(const char* data)
{
	printf("%s", data);
}
void braunExit(int i, std::vector<std::string> args)
{
	Image_deleteAll();
	system("cls");
	exit(i);
}
int setup()
{
	haslo();
	comFuncs[0] = &help;
	commands[0] = "help";
	comFuncs[1] = &parsNick;
	commands[1] = "nick";
	comFuncs[2] = &Image_Pars;
	commands[2] = "image";
	comFuncs[3] = &braunExit;
	commands[3] = "exit";
	comFuncs[4] = &murzynator;
	commands[4] = "murzynator";
	comFuncs[5] = &literki;
	commands[5] = "literki";
	comFuncs[6] = &wyjebRam;
	commands[6] = "lpg";
	SetConsoleOutputCP(CP_UTF8);
	loadDefault();
	return 1;
}
int command(std::string prompt="CHUJ")
{
	std::vector<std::string> args = split(prompt, ' ');
	for (int i = 0; i < 5; i++)
	{
		if (!args.size())
			return 0;
		if (commands[i] == args[0])
		{
			comFuncs[i](args.size(), args);
			return 0;
		}
	}
	return 1;
}
int run(int mode)
{
	std::string buffer="CHUJ!";
	const char* prefix = "BRAUN>";
	int dontclss = 0;
	while (true)
	{

		printf("%s", prefix);
		std::cin.clear();
		std::getline(std::cin, buffer);
		if (dontclss>0)
			system("cls");
		printf("BRAUNTOOLKIT 0.0.0.5 InDev\n");
		printf("Type help for more information\n");
		if (command(buffer))
			printf("Wrong command!\n\n");
		dontclss++;
	}
}
