#pragma once

#ifdef CTG_EXPORTS
#define CTG_API __declspec(dllexport)
#else
#define CTG_API __declspec(dllimport)
#endif
#include<iostream>
using namespace std;

extern "C" CTG_API double Ctg(double num);
