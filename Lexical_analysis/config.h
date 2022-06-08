#pragma once
#include<string>
#include<fstream>
using namespace std;




enum Terminal
{
	IDENTIFIER,//��ʶ��
	CONST, //����
	//���涼�Ǳ�����
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
	//�������
	ADD,//+
	MINUS,//-
	MULTY,//��
	DEVIDE,//��
	LT,//С��
	COLON,//�ֺ�
	COMMA,//����
	ASSIGN,//��ֵ
	ARRAYTOP,//�����Ͻ�
	ENDOFFILE,  //EOF
	
	LEFTPAREN,//������
	RIGHTPAREN,//������
	LEFTMIDPAREN,//��������
	RIGHTMIDPAREN,  //��������
	ERROR,  //����
	NONE,	
	EQUAL, //�Ⱥ�

	TYPE,
	RECORD,
	RETURN,
	DOT
};

enum NonTerminal
{
	Program, ProgramHead, ProgramName, DeclarePart,
	TypeDecpart, TypeDec, TypeDecList, TypeDecMore,
	TypeId, TypeDef, BaseType, StructureType,
	ArrayType, Low, Top, RecType,
	FieldDecList, FieldDecMore, IdList, IdMore,
	VarDecpart, VarDec, VarDecList, VarDecMore,
	VarIdList, VarIdMore, ProcDecpart, ProcDec,
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
}; // ���ռ���

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
	string name;
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
void printToken(Token* token);
