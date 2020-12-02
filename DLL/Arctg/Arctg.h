#pragma once

#ifdef ARCTG_EXPORTS
#define ARCTG_API __declspec(dllexport)
#else
#define ARCTG_API __declspec(dllimport)
#endif
#include<iostream>
using namespace std;

extern "C" ARCTG_API double Arctg(double num);
