#pragma once

#ifdef ARCCOS_EXPORTS
#define ARCCOS_API __declspec(dllexport)
#else
#define ARCCOS_API __declspec(dllimport)
#endif
#include<iostream>
using namespace std;

extern "C" ARCCOS_API double Arccos(double num);
