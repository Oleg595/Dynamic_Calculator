#pragma once

#ifdef COS_EXPORTS
#define COS_API __declspec(dllexport)
#else
#define COS_API __declspec(dllimport)
#endif
#include<iostream>
using namespace std;

extern "C" COS_API double Cos(double num);
