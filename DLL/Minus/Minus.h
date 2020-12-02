#pragma once

#ifdef MINUS_EXPORTS
#define MINUS_API __declspec(dllexport)
#else
#define MINUS_API __declspec(dllimport)
#endif
#include<iostream>
using namespace std;

extern "C" MINUS_API double Min(double num1, double num2);