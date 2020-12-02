#pragma once

#ifdef INT_EXPORTS
#define INT_API __declspec(dllexport)
#else
#define INT_API __declspec(dllimport)
#endif
#include<iostream>
using namespace std;

extern "C" INT_API double Int(double num);

