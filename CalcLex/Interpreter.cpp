#include "stdafx.h"
#include "EGrammar.h"
#include <iostream>
#include <vector>
#include "Interpreter.h"
#include "var.h"

int tok;
bool IDFLAG;


vector<Variable> vars;


void inparse(int num) 
{
	tok = num;
	if (IDFLAG == true) {
		readID();
	}
	else 
	{
		lookingforcommand();
	}
	
}




bool match(int expectedtoken) {
	if (tok == expectedtoken)
	{
		
		return true;
	}
	else
	{

		cout << "Token " << expectedtoken;
		cout << " expected, but instead ";
		cout << "encountered " << yytext ;
		return false;
	}

}

void lookingforcommand(){
	if (tok == READSY)
	{
		IDFLAG = true; //Program will look for an ID on next run of interpreter
	}
	if (tok == WRITESY)
	{

	}
}

void readID()
{
	if (match(ID))
	{
		int num;
		cout << "Enter value for " << yytext << ": ";
		cin >> num;
		Variable var(yytext, num);
		vars.push_back(var);

	}
}

