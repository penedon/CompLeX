// Egrammar Lexer

#include "stdafx.h"
#include "EGrammar.h"
#include <string>

char yytext[YYTEXT_MAX];	// Global token text buffer

static int yytextpos = 0;

ifstream fin;				// lex input file stream

bool yylexopen(const char filename[])
{
	fin.open(filename, ios_base::in );
	return  fin.is_open();
}

void yytextclear()
{
	yytextpos = 0;
	yytext[yytextpos] = 0;
}

void yytextappend(int c)
{
	if(yytextpos >= YYTEXT_MAX-1)
		return;		// ignore char
	yytext[yytextpos++] = (char)c;
	yytext[yytextpos] = 0;			// null sentinel at end
}

int yylex()
{
	int c;
	string s;
	

	while(1)
	{
		yytextclear();

		// Skip whitespace
		while( (c = fin.get()) == ' ' || c == '\t' );
	    
		//if(c == EOF || c == '\n')	return EOFSY;		// Use \n as EOF sentinel
		if (c == EOF ) return EOFSY;
		if (c == ';' || c == '\n') return EOLNSY;
	
		if (c == ':') {
			yytextappend(c);
			c = fin.get();
			
			if (c == '=') {
				yytextappend(c);
				return ASSIGNOP;
			}
		}
	
		
		if ((c  >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) { //Only finds words
			while (c != ' ') {
				if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
					yytextappend(c);
					c = fin.get();


					if (strcmp(yytext, "if") == 0)return IFSY;
					if (strcmp(yytext, "while") == 0)return WHILESY;
					if (strcmp(yytext, "write") == 0)return WRITESY; //Write Function
					if (strcmp(yytext, "read") == 0)return READSY;	//Read Function
				}
				else break;
				
				

			}
			fin.unget();
			
		 return ID;
			
		}

		 
		
	
		
		
		yytextappend(c);
		if(c == '(')	return LPAREN;
		if(c == ')')	return RPAREN;
		if(c == '{')	return LBRCKT;
		if(c == '}')	return RBRCKT;
		if(c == '+')	return ADDOP;
		if(c == '-')	return SUBOP;
		if(c == '%')	return MODOP;
		if(c == '*')	return MULOP;
		if (c == '/') {
			c = fin.get();
			if (c == '*') {
				yytextclear();
				while (1) {
					
					c = fin.get();
					if (c == '*') {
						c = fin.get();
						if (c=='/') return RCOMM;
						fin.unget();
					}

				}
			}
			fin.unget();
			return DIVOP;
		}
		//if (c == '>') return GRTOP;
		if (c == '>') {
			c = fin.get();
			if (c == '=') {
				yytextappend(c);
				return GRTEOP;
			}
			fin.unget();
			return GRTOP;
		}
		if (c == '<') {
			c = fin.get();
			if (c == '=') {
				yytextappend(c);
				return LWREOP;
			}
			fin.unget();
			return LWROP;
		}
		if (c == '=') { // May cause bug (example-> 2 ==@ 2)
			yytextappend(c);
			c = fin.get();
			if (c == '=') {
				yytextappend(c);
				return EQLOP;
			}
			
		}
		else if (c == '!') {
				yytextappend(c);
				c = fin.get();
				if (c == '=') {
					yytextappend(c);
					return NEQLOP;
				}
		}
	




		
		
		if(c >= '0' && c <= '9')			// integer numeric constant?
		{
			int dot = 0;
			while (((c = fin.get()) >= '0' && c <= '9') || c == '.') {
				if (c == '.') {
					if (dot == 0) {
						yytextappend(c); 
						dot++;
					}
				}
				else yytextappend(c);
				
				
			}
				

			fin.unget();		// do not consume char following token
			return NUMCONST;
		}

		
	

		
		// Unidentified input character -- ignore it or report an error
		return c;
	}
	
	// Should never get here
	return EOFSY;
}
