#include"Tree.h"

Number::Number(double num) {
	number = num;
	this->left = NULL;
	this->right = NULL;
}

double Number::value() {
	return number;
}

OPER Number::Oper() {
	return NO;
}

Operation::Operation(OPER op, Element* left, Element* right, map<FUNC, com> functions) {
	m = functions;
	operation = op;
	this->left = left;
	this->left->parent = this;
	this->right = right;
	this->right->parent = this;
}

double Operation::value() {
	Binary* s;
	switch (operation) {
	case PL:
		s = new Binary(m.find(PLUS)->second);
		break;
	case MINUS:
		s = new Binary(m.find(MIN)->second);
		break;
	case MULTIPLICATION:
		s = new Binary(m.find(MUL)->second);
		break;
	case DIVISION:
		s = new Binary(m.find(DIV)->second);
		break;
	case DEGREE:
		s = new Binary(m.find(DEG)->second);
		break;
	default:
		s = NULL;
	}
	if (s == NULL) {
		return 0;
	}
	return(s->Execute(left->value(), right->value()));
}

OPER Operation::Oper() {
	return operation;
}

Tree::Tree() {
	start = NULL;
}

void Tree::NewElem(Element* elem) {
	Element* cur = start;
	while ((cur != NULL) && ((cur->Oper() / 2) <= (elem->Oper() / 2))) {
		cur = cur->right;
	}
	if (cur == start) {
		Element* add = elem->left;
		elem->left = start;
		elem->parent = NULL;
		start = elem;
		return;
	}
	else {
		cur = cur->parent;
		Element* add = cur->right;
		cur->right->parent = elem;
		cur->right = elem;
		elem->left = add;
		elem->parent = cur;
		return;
	}
}

double Tree::result() {
	return start->value();
}