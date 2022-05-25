#pragma once
#include<string>
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
	ADD,
	MINUS,
	MULTY,
	DEVIDE,
	LT,
	ENDOFFILE,  //EOF
	LEFTPAREN,
	RIGHTPAREN,
	LEFTMIDPAREN,
	RIGHTMIDPAREN,
	ERROR,
	NONE,
	EQUAL
};

enum
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
	DONE
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
