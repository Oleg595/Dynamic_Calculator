#pragma once

#ifdef PLUS_EXPORTS
#define PLUS_API __declspec(dllexport)
#else
#define PLUS_API __declspec(dllimport)
#endif
#include<iostream>
using namespace std;

extern "C" PLUS_API double Plus(double num1, double num2);