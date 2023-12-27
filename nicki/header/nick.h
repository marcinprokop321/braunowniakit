#pragma once
#include"global_includes.h"



void losujNick(void);
int loadFromFile(std::vector<std::string> *zapis,const char*path);
void parsNick(int i, std::vector<std::string> args);
void clearNick(std::vector<std::string>* zapis);
void loadDefault(void);
void pokazNicki(int i);
void domyslne(void);