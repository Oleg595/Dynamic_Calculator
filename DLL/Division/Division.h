#pragma once

#ifdef DIVISION_EXPORTS
#define DIVISION_API __declspec(dllexport)
#else
#define DIVISION_API __declspec(dllimport)
#endif
#include<iostream>
using namespace std;

extern "C" DIVISION_API double Div(double num1, double num2);