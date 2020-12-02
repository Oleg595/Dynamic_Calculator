#pragma once

#ifdef SIN_EXPORTS
#define SIN_API __declspec(dllexport)
#else
#define SIN_API __declspec(dllimport)
#endif
#include<iostream>
using namespace std;

extern "C" SIN_API double Sin(double num);
