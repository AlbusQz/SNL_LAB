#include <iostream>
#include "config.h"
using namespace std;
//
extern Identifier identifier_list[500];

/**/string Termin[50] =
{
	"IDENTIFIER",//标识符
	"CONST", //常量
	//下面都是保留字
	"PROGRAM",
	"VAR",
	"INTEGER",
	"ARRAY",
	"OF",
	"CHAR",
	"PROCEDURE",
	"BEGIN",
	"WHILE",
	"DO",
	"IF",
	"THEN",
	"ELSE",
	"FI",
	"ENDWH",
	"END",
	"READ",
	"WRITE",
	//特殊符号
	"ADD",
	"MINUS",
	"MULTY",
	"DEVIDE",
	"LT",
	"ENDOFFILE",  //EOF
	"LEFTPAREN",
	"RIGHTPAREN",
	"LEFTMIDPAREN",
	"RIGHTMIDPAREN",
	"ERROR",
	"NONE",
	"EQUAL",
	//其他添加
	"TYPE",
	"RECORD",
	"INTC",
	"SEMICOLON",//分号
	"COMMA",//逗号
	"RETURN",
	"ASSIGN",//赋值符号
	"DOT",//点
};

bool isReserved(string s)
{
	if (s == "program")
		return true;
	if (s == "var")
		return true;
	if (s == "integer")
		return true;
	if (s == "array")
		return true;
	if (s == "of")
		return true;
	if (s == "procedure")
		return true;
	if (s == "begin")
		return true;
	if (s == "while")
		return true;
	if (s == "do")
		return true;
	if (s == "if")
		return true;
	if (s == "then")
		return true;
	if (s == "else")
		return true;
	if (s == "fi")
		return true;
	if (s == "endwh")
		return true;
	if (s == "end")
		return true;
	if (s == "read")
		return true;
	if (s == "write")
		return true;
	if (s == "type")
		return true;
	if (s == "record")
		return true;
	return false;

}

bool isLetter(char ch)
{
	if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
		return true;
	return false;
}

bool isDigit(char ch)
{
	if (ch >= '0' && ch <= '9')
		return true;
	return false;
}

Terminal findNum(string s)
{
	if (s == "program")
		return PROGRAM;
	if (s == "var")
		return VAR;
	if (s == "integer")
		return INTEGER;
	if (s == "array")
		return ARRAY;
	if (s == "of")
		return OF;
	if (s == "procedure")
		return PROCEDURE;
	if (s == "begin")
		return BEGIN;
	if (s == "while")
		return WHILE;
	if (s == "do")
		return DO;
	if (s == "if")
		return IF;
	if (s == "then")
		return THEN;
	if (s == "else")
		return ELSE;
	if (s == "fi")
		return FI;
	if (s == "endwh")
		return ENDWH;
	if (s == "end")
		return END;
	if (s == "read")
		return READ;
	if (s == "write")
		return WRITE;
	
	//
	if (s == "type")
		return TYPE;
	if (s == "record")
		return RECORD;

	return ERROR;
}

Terminal findNum(char ch)
{
	if (ch == '+')
		return ADD;
	if (ch == '-')
		return MINUS;
	if (ch == '*')
		return MULTY;
	if (ch == '/')
		return DEVIDE;
	if (ch == '<')
		return LT;
	if (ch == '(')
		return LEFTPAREN;
	if (ch == ')')
		return RIGHTPAREN;
	if (ch == '[')
		return LEFTMIDPAREN;
	if (ch == ']')
		return RIGHTMIDPAREN;
	if (ch == '=')
		return EQUAL;
	//曲政添加（有可能出错（很有可能））
	if (ch == ';')
		return SEMICOLON;
	if (ch == ',')
	{
		return COMMA;
	}
	if (ch == '.')
		return DOT;
}

void tokenPrint(Token* head)
{
	cout << "Token:" << endl;
	cout << "Line\t  " << "token\t\t" << "id" << endl;
	while (head != NULL)
	{
		if (head->index != -1)
		{
			cout<<head->line << '\t' << "< " << head->type <<" , " << head->index << " >"<< '\t'<<identifier_list[head->index].text<<"\t" <<Termin[head->type]<< endl;
		}
		else
		{
			cout << head->line << '\t' << "< " << head->type << " , " << '-' << " >" << "\t\t" << Termin[head->type] << endl;
		}
		head = head->next;
	}
	
}

bool isSpe(char ch)
{
	if (ch == '+')
		return true;
	if (ch == '-')
		return true;
	if (ch == '*')
		return true;
	if (ch == '/')
		return true;
	if (ch == '(')
		return true;
	if (ch == ')')
		return true;
	if (ch == ';')
		return true;
	if (ch == '[')
		return true;
	if (ch == ']')
		return true;
	if (ch == '=')
		return true;
	if (ch == '<')
		return true;
	if (ch == '.')
		return true;
	if (ch == ',')
		return true;
	return false;
}