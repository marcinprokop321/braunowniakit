#include"core.h"
std::string commands[10];
 void (*comFuncs[10])(int i);

void log(const char* data)
{
	printf("%s", data);
}
int setup()
{
	comFuncs[0] = &help;
	commands[0] = "help";
	comFuncs[1] = &losujNick;
	commands[1] = "nick";

	printf("BRAUNTOOLKIT 0.0.0.1 InDev\n");
	printf("Type help for more information\n");
	return 1;
}
int command(std::string prompt="CHUJ")
{
	for (int i = 0; i < 10; i++)
	{
		if (commands[i] == prompt)
		{
			comFuncs[i](0);
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
		buffer = "NIEURUCHOMISZNIC";
		std::getline(std::cin, buffer);
		//system("cls");

		if (command(buffer))
			printf("Wrong command!\n\n");

	}
}
