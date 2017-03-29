// Egrammar Recursive Descent Parser
#include "stdafx.h"
#include "EGrammar.h"
// EGrammar CFG rules
// EGrammar -> E $$
// E -> T Ttail
// Ttail -> + T Ttail
// Ttail -> <epsilon>
// T -> F Ftail
// Ftail -> * F Ftail
// Ftail -> <epsilon>
// F -> ( E )
// F -> numconst
// NonTerminal prototypes
void EGrammar();
void E();
void Ttail();
void T();
void Ftail();
void F();
// Current lexical token
int tok;
void match(int expectedTok)
{
	if (tok == expectedTok)
	{
		if (tok != EOFSY)
			tok = yylex();
	}
	else
	{
		cout << "Token " << expectedTok
			<< " expected, but instead encountered "
			<< yytext << endl;
	}
}

void EGrammar()
{
	stackinit(); // Initialize the execution environment
	E();
	match(EOFSY);
	int val = pop();
	cout << "EGrammar E = " << val << endl;
}
void E()
{
	T();
	Ttail();
}
void Ttail()
{
	if (tok == ADDOP) {
		match(ADDOP);
		T();
		cout << "ADDOP" << endl; // output postfix
		int v2 = pop(); // do the computation
		int v1 = pop();
		push(v1 + v2);
		Ttail();
		return;
	}
}
void T()
{
	F();
	Ftail();
}
void Ftail()
{
	if (tok == MULOP) {
		match(MULOP);
		F();
		cout << "MULOP" << endl; // output postfix
		int v2 = pop(); // do the computation
		int v1 = pop();
		push(v1 * v2);
		Ftail();
		return;
	}
}
void F()
{
	if (tok == LPAREN)
	{
		match(LPAREN);
		E();
		match(RPAREN);
		return;
	}
	else
		if (tok == NUMCONST)
		{
			int val = atoi(yytext); // convert value for this token
			match(NUMCONST);
			cout << val << endl; // output postfix
			push(val); // do the computation
			return;
		}
	cout << "Token ( or numconst expected" << endl;
}
int yyparse()
{
	tok = yylex(); // get initial token
	EGrammar();
	return 0;
}