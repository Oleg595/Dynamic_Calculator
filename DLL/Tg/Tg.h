#pragma once

#ifdef TG_EXPORTS
#define TG_API __declspec(dllexport)
#else
#define TG_API __declspec(dllimport)
#endif
#include<iostream>
using namespace std;

extern "C" TG_API double Tg(double num);
