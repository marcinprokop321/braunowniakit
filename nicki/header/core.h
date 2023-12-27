#pragma once
#include "utility.h"
#include<iostream>
#include"global_includes.h"
#include "nick.h"
#include "image.h"
#include "security.h"

void log(const char* data);
int setup();
int run(int mode);
int command(std::string *string);
template<typename T,int t>
struct vec3
{
	T x;
	T y;
	T z;
};
#define TWITCH_FORMAT vec<int,3>{30,15,500};
void braunExit(int i, std::vector<std::string> args);
