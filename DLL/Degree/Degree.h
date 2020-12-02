#pragma once

#ifdef DEGREE_EXPORTS
#define DEGREE_API __declspec(dllexport)
#else
#define DEGREE_API __declspec(dllimport)
#endif
#include<iostream>
using namespace std;

extern "C" DEGREE_API double Deg(double num1, double num2);
