#pragma once

#ifdef LN_EXPORTS
#define LN_API __declspec(dllexport)
#else
#define LN_API __declspec(dllimport)
#endif
#include<iostream>
using namespace std;

extern "C" LN_API double Ln(double num);
