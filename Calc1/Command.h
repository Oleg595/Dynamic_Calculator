#pragma once
#include<string>
#include<iostream>
#include<Windows.h>
#include<tchar.h>
#include<Map>
#include<algorithm>
#include<filesystem>
using namespace std;
namespace fs = filesystem;

typedef double (*com)(double num, ...);

enum FUNC{
	SIN = 0,
	COS,
	TG,
	CTG,
	ARCSIN,
	ARCCOS,
	ARCTG,
	ARCCTG,
	LOG,
	SQRT,
	EXP,
	INt,
	DIV,
	DEG,
	PLUS,
	MIN,
	MUL,
	END
};

class Command {
public:
	virtual double Execute(double num, ...) = 0;
protected:
	com command;
	Command(com func) : command(func) {};
};

class Single : public Command {
public:
	Single(com func) : Command(func) {}
	double Execute(double num, ...);
};

class Binary : public Command {
public:
	Binary(com func) : Command(func) {}
	double Execute(double num, ...);
};


class ReadFunctions {
private:
	map<FUNC, com> m;
	map<string, FUNC> search;
	string FUNC_To_string(FUNC func);
public:
	ReadFunctions(string str);
	com Function(FUNC func);
	map<FUNC, com> Map() { return m; };
	FUNC Search(string str);
};