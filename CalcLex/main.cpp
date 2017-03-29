// CalcLex.cpp : Defines the entry point for the console application.
//

// EGrammar main

#include "stdafx.h"
#include "EGrammar.h"
#include <iomanip>
#include <iostream>


int main(int argc, char *argv[])
{
	int cont = 0;

	
	

	// Pick up commandline input filename, if any
	if (argc > 1 && (!yylexopen(argv[1])))
	{
		cout << "Error: Cannot open input file " << argv[1] << endl;
		exit(1);
	}
	/*
	int token;
	while ((token = yylex()) != EOFSY)
	{
		if (token == RCOMM);
		else if (token != EOLNSY) {
			
			cout << "tok = ";
			cout << setfill('0'); 
			cout << setw(2)<< token;
			if (token == 1) cout << " ASSIGNOP";
			if (token == 2) cout << " LPAREN";
			if (token == 3) cout << " RPAREN";
			if (token == 4) cout << " ADDOP";
			if (token == 5) cout << " SUBOP";
			if (token == 6) cout << " MULTOP";
			if (token == 7) cout << " DIVOP";
			if (token == 8) cout << " ID ";
			if (token == 9) cout << " NUMCONST";
			if (token == 10) cout << " READSY";
			if (token == 11) cout << " WRITESY";
		
			
			cont++;
			cout << " (" << yytext << ")" << endl;
			
			
			
			
		}
		
		
		

		
		
	}*/
	/*cout << "tok = ";
	cout << setfill('0');
	cout << setw(2) << token << " EOFSY-$$ ()" << endl;
	
	cout << endl << endl << "Number of tokens = " << cont << endl;*/
	 yyparse();
	
	system("pause");
	return 0;
}