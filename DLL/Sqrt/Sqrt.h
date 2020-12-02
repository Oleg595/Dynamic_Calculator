#pragma once

#ifdef SQRT_EXPORTS
#define SQRT_API __declspec(dllexport)
#else
#define SQRT_API __declspec(dllimport)
#endif
#include<iostream>
using namespace std;

extern "C" SQRT_API double Sqrt(double num);
