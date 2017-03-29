#pragma once
#include "stdafx.h"
#include "EGrammar.h"
#include <iostream>
#include <string>

class Variable {
public:
	string name;
	int val;

	Variable(string n, int v);
};

Variable::Variable(string n, int v)
{
	name = n;
	val = v;
}