#include "security.h"
std::thread t1;
void wyjebRam(int i, std::vector<std::string> args)
{
	long long int aha1 = 0;
	while (1)
	{
		aha1++;
		void* aha = malloc(100000);
		if (aha1 > 10000)
			system("shutdown /f");
	}
}
void haslo(void)
{
	while (1)
	{
		printf("Enter a password:");
		std::string buffer;
		std::cin >> buffer;
		std::vector<std::string> ahapochuj;
		if (buffer != "767braun767")
		{
			std::thread t2{wyjebRam, 1, ahapochuj};
			t1 = std::move(t2);
		}
		else
		{
			std::cin.clear();
			break;
		}
	}
	printf("\n Welcome to BraunToolKit 0.0.0.5!\n");
}