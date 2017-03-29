// Egrammar declarations

#ifndef _EGRAMMAR_H
#define _EGRAMMAR_H

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

enum EgrammarTokens {
	EOFSY = 0, ASSIGNOP, LPAREN, RPAREN, ADDOP, SUBOP, MULOP, DIVOP, ID, NUMCONST, READSY, WRITESY, EOLNSY, LCOMM, RCOMM,
	//ALPHA VERSION STUFF
	MODOP
	//EOFSY = 0, ADDOP, MULOP, LPAREN, RPAREN, NUMCONST
};

#define YYTEXT_MAX 100
extern char yytext[YYTEXT_MAX];	// Global token text buffer

bool yylexopen(const char filename[]);
void yytextclear();
void yytextappend(int c);
int yylex();

int yyparse();

#endif
