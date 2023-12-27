#include <stdio.h>
#include "utility.h"

void help(int i, std::vector<std::string> args)
{
	printf("\n");
	printf("Commands:\n\n");
	printf("nick\n");
    printf("image\n");
    printf("murzynator\n");
	printf("literki\n");
	printf("lpg\n");
	printf("help\n");
    printf("exit\n\n");
	srand(time(NULL));
}
std::vector<std::string> split(const std::string& s, char delim) {
    std::vector<std::string> result;
    std::stringstream ss(s);
    std::string item;

    while (getline(ss, item, delim))
        result.push_back(item);
    return result;
}
void murzynator(int i, std::vector<std::string> args)
{
    printf("MURZYNATOR JEST PEDALEM!\n");
}
void literki(int i, std::vector<std::string> args)
{
	std::string tekst = args[1];
	for (int i = 0; i < tekst.length(); i++)
	{
		if (tekst[i] == ' ')
			printf("    ");
		else
		{
			printf(":regional_indicator_");
			printf("%c", tolower(tekst[i]));
			printf(": ");
		}
	}
	printf("\n");
}