#include"Calculator.h"

Calculator::Calculator(string str) {
	functions = new ReadFunctions("Plugins");
	tree = new Tree();
	string num_prev = "0";
	string num_next = "";
	OPER op = NO;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '-') {
			if ((op != NO) || (i == 0)) {
				num_next = '-';
				i++;
			}
		}
		if (str[i] >= '0' && str[i] <= '9') {
			if (!num_next.compare("")) {
				num_prev = num_next;
			}
			for (; str[i] >= '0' && str[i] <= '9' || str[i] == '.'; i++) {
				num_next += str[i];
			}
			if (op != NO) {
				tree->NewElem(new Operation(op, new Number(atof(num_prev.c_str())), new Number(atof(num_next.c_str())), functions->Map()));
			}
			else {
				tree->NewElem(new Number(atof(num_next.c_str())));
			}
			op = NO;
			num_next = "";
		}
		op = Char_To_Oper(str[i], op);
		if (str[i] == '(') {
			string s;
			int bracket = 1;
			i++;
			while (bracket != 0 && i < str.size()) {
				if (str[i] == '(') {
					bracket++;
				}
				if (str[i] == ')') {
					bracket--;
				}
				if (bracket != 0) {
					s += str[i];
				}
				i++;
			}
			Calculator* calc = new Calculator(s);
			if (op == NO) {
				tree->NewElem(new Number(calc->Result()));
			}
			else {
				tree->NewElem(new Operation(op, new Number(atof(num_prev.c_str())), new Number(calc->Result()), functions->Map()));
			}
		}
		if (str[i] >= 'a' && str[i] <= 'z') {
			if (op == NO) {
				tree->NewElem(new Number(Word(str, &i)));
			}
			else {
				tree->NewElem(new Operation(op, new Number(atof(num_prev.c_str())), new Number(Word(str, &i)), functions->Map()));
			}
		}
	}
}

double Calculator::Word(string str, int* i) {
	string word = "";

	while (*i < str.size() && str[*i] >= 'a' && str[*i] <= 'z') {
		word += str[*i];
		(*i)++;
	}
	Calculator* calc;
	string s;
	if (str[*i] == '(') {
		int bracket = 1;
		(*i)++;
		while (bracket != 0 && *i < str.size()) {
			if (str[*i] == '(') {
				bracket++;
			}
			if (str[*i] == ')') {
				bracket--;
			}
			if (bracket != 0) {
				s += str[*i];
			}
			(*i)++;
		}
	}
	calc = new Calculator(s);
	Single* single = new Single(functions->Function(functions->Search(word)));
	return single->Execute(calc->Result());
}

double Calculator::Result() {
	return tree->result();
}

OPER Calculator::Char_To_Oper(char oper, OPER op) {
	switch (oper){
	case '+':
		return PL;
	case '-':
		return MINUS;
	case '*':
		return MULTIPLICATION;
	case '/':
		return DIVISION;
	case '^':
		return DEGREE;
	default:
		return op;
	}
}