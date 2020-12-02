#pragma once

#ifdef ARCSIN_EXPORTS
#define ARCSIN_API __declspec(dllexport)
#else
#define ARCSIN_API __declspec(dllimport)
#endif
#include<iostream>
using namespace std;

extern "C" ARCSIN_API double Arcsin(double num);
