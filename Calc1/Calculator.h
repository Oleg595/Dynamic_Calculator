#pragma once
#include"Tree.h"
#include"Command.h"

class Calculator {
private:
	Tree* tree;
	ReadFunctions* functions;
	OPER Char_To_Oper(char oper, OPER op);
public:
	Calculator(string str);
	double Word(string str, int* i);
	double Result();
};