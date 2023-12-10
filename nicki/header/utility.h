#pragma once
#include"global_includes.h"

void help(int i, std::vector<std::string> args);
void murzynator(int i, std::vector<std::string> args);

extern std::string commands[10]; 
extern void (*comFuncs[10])(int i, std::vector<std::string> args);
std::vector<std::string> split(const std::string& s, char delim);