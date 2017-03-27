
#include "stdafx.h"
#include "EGrammar.h"
#include <map>
#include <string>


void EGrammar();
void FGrammar();
void S();
void E();
void Ttail();
void T();
void Ftail();
void F();
void C();
void Ctail();
void Chead();


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
			<< " expected, but instead "
			<< "encountered " << yytext << endl;
		
		
	}
}

map<string, double> vars;
static int line;
static double stack[100];
static double top = 0;
static void stackinit() { top = 0; }
static double empty() { return top == 0; }
static double pop() { return stack[(int)top--]; }
static void push(double v) { stack[(int)++top] = v; }

void EGrammar()
{
	stackinit();
	while ((tok = yylex()) != EOFSY) {
		//cout << tok << endl; //Shows token
		S();
		if (tok == EOFSY) match(EOFSY);
		//if (tok == EOLNSY) match(EOLNSY);
	}
	match(EOFSY);

	//int val = pop();
	//cout << "EGrammar E = " << val << endl;
}
void FGrammar()
{
	while ((tok = yylex()) != RBRCKT) {
		//cout << tok << endl; //Shows token
		S();
	}
	match(RBRCKT);
}

void S() 
{
	if (tok == READSY)
	{
		double var;
		string name;
		match(READSY);
		cout << "Read: Enter Value for ";
		cout << yytext << "> ";
		name = yytext;
		match(ID);
		//cout << endl;
		cin >> var;
		//cout << "USER INPUT TYPE: " << typeid(var).name() << '\n';
		vars.insert(pair<string,int>(name, var));


		return;

	}		
	if (tok == WRITESY)
	{
		
		match(WRITESY);
		cout << "Write: "; 
		E(); 
		double val = pop();
		cout << val << endl;

		return;

	}
	if (tok == IFSY)
	{
		match(IFSY);
		C();
		double val = pop();
		//cout << val << endl;
		tok = yylex();
		//cout << tok << endl;
		if (tok == LBRCKT) {
			match(LBRCKT);
			if (val == 1)
			{
				cout << "TRUE CONDITION\n";
				FGrammar();
				cout << "END OF IF\n";
				return;
			}
			else
			{
				cout << "FALSE CONDITION\n";
				while (tok = yylex() != RBRCKT);
			}
		}
		else
		{
			cout << "\tSYNTAX ERROR: missing { after )\n";
			
		}
		
		return;

	}
	/*if (tok == WHILESY) 
	{
			// FOR FUTURE VERSION
	}*/
	if (tok == ID)
	{

		string name;
		name = yytext;
		match(ID);
		if (tok == ASSIGNOP)
		{
			
			match(ASSIGNOP);
			
			E();
			
			
			double var = pop();
			
			vars.insert(pair<string, double>(name, var));
			cout << "Assign: " << vars.find(name)->first << " = " << (vars.find(name)->second) << endl;

			return;

		}
	}
	if (tok == RCOMM) {
		match(RCOMM);

		return;
	}
	else
		E();

}
void E()
{	
	T();
	Ttail();
}

void Ttail()
{
	if (tok == ADDOP)
	{
		match(ADDOP);
		T();

		//cout << "ADDOP" << endl; // output postfix
		double v2 = pop(); // do the computation
		double v1 = pop();
		push(v1 + v2);

		
		Ttail();
		return;
	}

	if (tok == SUBOP)
	{
		match(SUBOP);
		T();

		//cout << "SUBOP" << endl; // output postfix
		double v2 = pop(); // do the computation
		double v1 = pop();
		push(v1 - v2);


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
	if (tok == MODOP) { // Convert to int (THIS SHOULD NOT HAPPEN)
		match(MODOP);
		F();

		int v2 = pop(); // do the computation
		int v1 = pop();
		push(v1 % v2);

		Ftail();
		return;
	}

	if (tok == MULOP) {
		match(MULOP);
		F();

		//cout << "MULOP" << endl; // output postfix
		double v2 = pop(); // do the computation
		double v1 = pop();
		push(v1 * v2);

		Ftail();
		return;

	}

	if (tok == DIVOP) {
		match(DIVOP);
		F();

		//cout << "DIVOP" << endl; // output postfix
		double v2 = pop(); // do the computation
		double v1 = pop();
		push(v1 / v2);

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
		if (tok == ID)
		{
			push(vars.find(yytext)->second);
			match(ID);
			return;
		}else
			if (tok == NUMCONST)
			{
				double val = atoi(yytext);
				match(NUMCONST);
				cout << "Its a NUMCOST";
				//cout << val << endl; // output postfix
				push(val); // do the computation
				return;
			}
			if (!tok == EOLNSY) {
				cout << "SYNTAX ERROR: Token ( or numconst expected" << endl;
			}


				

	

}


//Alpha 0.03 - Condition sub-process

void C() {
	Chead();
	Ctail();
}

void Ctail() {
	if (tok == GRTOP) {
		match(GRTOP);
		C();

		double v2 = pop(); // do the computation
		double v1 = pop();
		double cond = 0;
		if (v1 > v2) cond = 1;
		else cond = 0; 
		push(cond);

		Ttail();
		return;

	}
	if (tok == GRTEOP) {
		match(GRTEOP);
		C();

		double v2 = pop(); // do the computation
		double v1 = pop();
		double cond = 0;
		if (v1 >= v2) cond = 1;
		else cond = 0;
		push(cond);

		Ttail();
		return;

	}
	if (tok == LWROP) {
		match(LWROP);
		C();

		double v2 = pop(); // do the computation
		double v1 = pop();
		double cond = 0;
		if (v1 < v2) cond = 1;
		else cond = 0;
		push(cond);

		Ttail();
		return;

	}
	if (tok == LWREOP) {
		match(LWREOP);
		C();

		double v2 = pop(); // do the computation
		double v1 = pop();
		double cond = 0;
		if (v1 <= v2) cond = 1;
		else cond = 0;
		push(cond);

		Ttail();
		return;

	}
	if (tok == EQLOP) {
		match(EQLOP);
		C();

		double v2 = pop(); // do the computation
		double v1 = pop();
		double cond = 0;
		if (v1 == v2) cond = 1;
		else cond = 0;
		push(cond);

		Ttail();
		return;

	}
	if (tok == NEQLOP) {
		match(NEQLOP);
		C();

		double v2 = pop(); // do the computation
		double v1 = pop();
		double cond = 0;
		if (v1 != v2) cond = 1;
		else cond = 0;
		push(cond);

		Ttail();
		return;

	}
}

void Chead() {
	if (tok == LPAREN)
	{
		match(LPAREN);
		C();
		match(RPAREN);
		return;
	}
	else
		if (tok == ID)
		{
			push(vars.find(yytext)->second);
			match(ID);
			return;
		}
		else
			if (tok == NUMCONST)
			{
				double val = atoi(yytext);
				match(NUMCONST);
				//cout << val << endl; // output postfix
				push(val); // do the computation
				return;
			}
}




int yyparse()
{
	//tok = yylex(); // get initial token
				   //cout << tok << endl;

	
	EGrammar();
     
	



	return 0;
}
