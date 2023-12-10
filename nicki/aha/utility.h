#pragma once
#include"global_includes.h"

void help(int i);

extern std::string commands[10]; 
extern void (*comFuncs[10])(int i);