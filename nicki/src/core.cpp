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
	exit(i);
}
int setup()
{
	comFuncs[0] = &help;
	commands[0] = "help";
	comFuncs[1] = &losujNick;
	commands[1] = "nick";
	comFuncs[2] = &Image_Pars;
	commands[2] = "image";
	comFuncs[3] = &braunExit;
	commands[3] = "exit";
	comFuncs[4] = &murzynator;
	commands[4] = "murzynator";

	printf("BRAUNTOOLKIT 0.0.0.2 InDev\n");
	printf("Type help for more information\n");
	SetConsoleOutputCP(CP_UTF8);
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
	std::string buffer;
	const char* prefix = "BRAUN>";
	while (true)
	{

		printf("%s", prefix);
		buffer = "NICNIEWPISZESZ";
		std::getline(std::cin, buffer);
		system("cls");
		printf("BRAUNTOOLKIT 0.0.0.2 InDev\n");
		printf("Type help for more information\n");
		if (command(buffer))
			printf("Wrong command!\n\n");
	}
}
