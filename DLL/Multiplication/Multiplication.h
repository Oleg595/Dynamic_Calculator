#pragma once

#ifdef MULTIPLICATION_EXPORTS
#define MULTIPLICATION_API __declspec(dllexport)
#else
#define MULTIPLICATION_API __declspec(dllimport)
#endif
#include<iostream>
using namespace std;

extern "C" MULTIPLICATION_API double Mul(double num1, double num2);
