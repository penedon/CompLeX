#include "EGrammar.h"
#include <iomanip>
#include <iostream>

void main(int argc, char *argv[])
{
	if (argc > 1 && (!yylexopen(argv[1])))
	{
		cout << "Error: Cannot open input file " << argv[1] << endl;
		exit(1);
	}
	/*
	int token;
	while ((token = yylex()) != EOFSY)
	{

			cout << "tok = ";
			cout << setfill('0');
			cout << setw(2) << token;
			if (token == 2) cout << " ASSIGNOP";
			if (token == 3) cout << " LPAREN";
			if (token == 4) cout << " RPAREN";
			if (token == 5) cout << " ADDOP";
			if (token == 6) cout << " SUBOP";
			if (token == 7) cout << " MULTOP";
			if (token == 8) cout << " DIVOP";
			if (token == 9) cout << " ID ";
			if (token == 10) cout << " NUMCONST";
			if (token == 11) cout << " READSY";
			if (token == 12) cout << " WRITESY";
			if (token == 13) cout << " LCOMM";
			if (token == 14) cout << " RCOMM";
			if (token == 15) cout << " MODOP";
			if (token == 16) cout << " GRTOP";
			if (token == 17) cout << " LWROP";
			if (token == 18) cout << " GRTEOP";
			if (token == 19) cout << " LWREOP";
			if (token == 20) cout << " EQLOP";
			if (token == 21) cout << " NEQLOP";
			if (token == 22) cout << " IFSY";
			if (token == 23) cout << " WHILESY";
			if (token == 24) cout << " LBRCKT";
			if (token == 25) cout << " RBRCKT";
			if (token == 26) cout << " ANDOP";
			if (token == 27) cout << " OROP";
			if (token == 28) cout << " NOTOP";
			if (token == 29) cout << " INTTP";
			if (token == 30) cout << " DOUBLETP";
			if (token == 31) cout << " CHARTP";


			cout << " (" << yytext << ")" << endl;




		



	}*/

	yyparse();
	system("pause");
	/*for (int i = 0; i < 10; i++) {
		cout << yytext[i] << "\n";

	}*/
}