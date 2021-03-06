#ifndef _EGRAMMAR_H
#define _EGRAMMAR_H

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

enum EgrammarTokens {
	EOFSY = 0, EOLNSY, ASSIGNOP, LPAREN, RPAREN, ADDOP, SUBOP, MULOP, DIVOP, ID, NUMCONST, READSY, WRITESY, LCOMM, RCOMM,
	//======= Alpha Features ======//
	MODOP,
	GRTOP, LWROP, GRTEOP, LWREOP, EQLOP, NEQLOP, //16:21
	IFSY, WHILESY, //22,23
	LBRCKT, RBRCKT, //24,25
	ANDOP, OROP, NOTOP, //26:28
	INTTP, DOUBLETP, CHARTP, //29:31
	//======== Beta Features =======//
	INCOP, DECOP,
	RSTRING

};

#define YYTEXT_MAX 100
extern char yytext[YYTEXT_MAX];	// Global token text buffer

bool yylexopen(const char filename[]);
void yytextclear();
void yytextappend(int c);
int yylex();

int yyparse();

int lexpos();
void goToPos(int num);
void printTok(int token);

#endif
