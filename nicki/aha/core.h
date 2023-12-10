#pragma once
#include "utility.h"
#include<iostream>
#include"global_includes.h"
#include "nick.h"

void log(const char* data);
int setup();
int run(int mode);
int command(const char* prompt);
