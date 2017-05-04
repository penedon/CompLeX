# CompLeX
CompLex is a language designed from **C++** as a final project of **CCO007** at **[UNIFEI](https://www.unifei.edu.br/)**. It has the basic features of a programming language. 

This project have some Visual Studio files in order to debug and fix. Final version will not present those files and will have support for **Linux**, **MacOS** and **Windows**.

In the next versions it will be simpler to build and to code. Also, more optimization will come.

## How to Use

##### Build Compiler:

    git clone
    cd /CompLeX/CompLex
    g++ complex main.cpp 

Now, write some code in a new document and save it as **[nameyouwant].complex**

##### To compile your code:
    ./complex [name of file].complex

## Current Version: 0.3.0

>Added:
>  - Increment support
>  - Syntax error catchers
>  - Math error catchers
>  - Semantic error catchers
>  - Error handling function
>
>Fixes:
>  - division by 0 does not interrupt the compiler anymore
>  - Variable needs a type to be declared
>  - READ can change a value from previously declared var
>  - WHILE can increment it's own condition variable
>  - Removed some IF bugs

## Features

1. Data types
	* Integer (**INT**)
	* Double Precision (**DOUBLE**)
	* Character (**CHAR**)
2. Commands
	* Attributtion (**:=**)
	* I/O (**READ** and **WRITE**)
	* Conditional (**IF**)
	* Repetition (**WHILE**)
3. Relational Operators
	* Greater than or equal to (**>=**)
	* Less  than or equal to (**<=**)
	* Greater than (**>**)
	* Less than (**<**)
	* Equal to (**==**)
	* Not Equal to (**!=**)
4. Logic Operators
	* AND (**&&**)
	* OR (**||**)
	* NOT (**!**)
5. Arithmetic Operators
	* Addition (**+**)
	* Subtraction (**−**)
	* Multiplication (**∗**)
	* Division (**/**)
	* Modulo (**%**)
6. Special Symbols
	* Number precision (**.**)
	* Parenthesis (**( )**) 
	* Brackets (**{ }**)
7. Comment Support
	* Comment Symbols (**/*  */**)

## License
MIT