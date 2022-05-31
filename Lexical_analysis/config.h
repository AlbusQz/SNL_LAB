#pragma once
#include<string>
#include<fstream>
using namespace std;




enum Terminal
{
	IDENTIFIER,//标识符
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
	ADD,//+
	MINUS,//-
	MULTY,//×
	DEVIDE,//÷
	LT,//小于
	COLON,//分号
	COMMA,//逗号
	ASSIGN,//赋值
	ARRAYTOP,//数组上界
	ENDOFFILE,  //EOF
<<<<<<< HEAD
	LEFTPAREN,
	RIGHTPAREN,
	LEFTMIDPAREN,
	RIGHTMIDPAREN,
	ERROR,
	NONE,
	EQUAL,
	//其他添加
	TYPE,
	RECORD,
	INTC,
	SEMICOLON,//分号
	COMMA,//逗号
	RETURN,
	ASSIGN,//赋值符号
	DOT,//点
=======
>>>>>>> 87fc15b30bd7c5f122ab946fcc54ecaf1b909f58
	
	LEFTPAREN,//左括号
	RIGHTPAREN,//右括号
	LEFTMIDPAREN,//左中括号
	RIGHTMIDPAREN,  //右中括号
	ERROR,  //错误
	NONE,	
	EQUAL //等号
};



enum NonTerminal
{
	Program, ProgramHead, ProgramName, DeclarePart,
	TypeDec, TypeDeclaration, TypeDecList, TypeDecMore,
	TypeId, TypeName, BaseType, StructureType,
	ArrayType, Low, Top, RecType,
	FieldDecList, FieldDecMore, IdList, IdMore,
	VarDec, VarDeclaration, VarDecList, VarDecMore,
	VarIdList, VarIdMore, ProcDec, ProcDeclaration,
	ProcDecMore, ProcName, ParamList, ParamDecList,
	ParamMore, Param, FormList, FidMore,
	ProcDecPart, ProcBody, ProgramBody, StmList,
	StmMore, Stm, AssCall, AssignmentRest,
	ConditionalStm, StmL, LoopStm, InputStm,
	InVar, OutputStm, ReturnStm, CallStmRest,
	ActParamList, ActParamMore, RelExp, OtherRelE,
	Exp, OtherTerm, Term, OtherFactor,
	Factor, Variable, VariMore, FieldVar,
	FieldVarMore, CmpOp, AddOp, MultOp
}; // 非终极符

class Word
{
public:
	string id;
	Terminal type;
};


enum State
{
	START,
	INID,
	STATEEND,
	DONE1,
	DONE,
	INNUM,
	INPOI,
	INASIGN,
	INCOMM
};

class Identifier
{
public:
	int index;
	string text;
	Identifier(int in,string cont)
	{
		index = in;
		text = cont;
	}
	Identifier(){}
};

class Const
{
public:
	bool isnum;
	int num;
	string text;
	Const(int nu)
	{
		num = nu;
		isnum = true;
	}
	Const(string tex)
	{
		text = tex;
		isnum = false;
	}
	Const()
	{

	}
};



class Token {
public:
	int line;
	Terminal type;
	int index; 
	Token* next;
	Token(int lin,Terminal typ,int in)
	{
		line = lin;
		type = typ;
		index = in;
		next = NULL;
	}

	Token()
	{
		
		next = NULL;
	}

};// token


char getNextChar();
char ungetNextChar();
bool isReserved(string s);
bool isLetter(char ch);
bool isDigit(char ch);
bool isSpe(char ch);
void tokenPrint(Token* head);

Terminal findNum(string word);
Terminal findNum(char ch);

void printTokenToFile(Token* head, string path);
Token* readTokenFromFile(string path);
int getValue(string s);
