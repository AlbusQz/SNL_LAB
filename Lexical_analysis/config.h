#pragma once
#include<string>
using namespace std;
//const char sourcepath[50], tokenpath[50];



enum Terminal
{
	ID,//标识符
	CONST, //常量
	//下面都是保留字
	PROGRAM,
	VAR,
	INTEGER,
	ARRAY,
	OF,
	CHAR,
	PROCEDURE,
	BEGIN,
	WHILE,
	DO,
	IF,
	THEN,
	ELSE,
	FI,
	ENDWH,
	END,
	READ,
	WRITE,
	//特殊符号
	ENDOFFILE,  //EOF
	LEFTPAREN,
	RIGHTPAREN,
	LEFTMIDPAREN,
	RIGHTMIDPAREN

};



class Word
{
public:
	string id;
	Terminal type;
};








class Token {
public:
	int line;
	Terminal type;
	int index = -1; 
};// token


char getNextChar();
char ungetNextChar();
bool isReserved(string s);
