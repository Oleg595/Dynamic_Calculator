#pragma once

#ifdef ARCCTG_EXPORTS
#define ARCCTG_API __declspec(dllexport)
#else
#define ARCCTG_API __declspec(dllimport)
#endif
#include<iostream>
using namespace std;

#define pi 3.1415926535

extern "C" ARCCTG_API double Arcctg(double num);
