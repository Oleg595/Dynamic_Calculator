#pragma once

#ifdef EXP_EXPORTS
#define EXP_API __declspec(dllexport)
#else
#define EXP_API __declspec(dllimport)
#endif
#include<iostream>
using namespace std;

extern "C" EXP_API double Exp(double num);
