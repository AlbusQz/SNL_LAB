#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<cstdlib>
#include<cstring>
#include"Syntax_tree.h"
#include<stack>
#include "..\Lexical_analysis\config.h"



STree* rootTree;
stack<StackNode> AStack;
//LL1·ÖÎö±í
int LL1Table[104][104];

using namespace std;

void CreateLL1Table()
{
	memset(LL1Table, 0, sizeof(LL1Table));
	LL1Table[Program][PROGRAM] = 1;

	LL1Table[ProgramHead][PROGRAM] = 2;

	LL1Table[ProgramName][IDENTIFIER] = 3;

	LL1Table[DeclarePart][TYPE] = 4;
	LL1Table[DeclarePart][VAR] = 4;
	LL1Table[DeclarePart][PROCEDURE] = 4;
	LL1Table[DeclarePart][BEGIN] = 4;

	LL1Table[TypeDec][VAR] = 5;
	LL1Table[TypeDec][PROCEDURE] = 5;
	LL1Table[TypeDec][BEGIN] = 5;

	LL1Table[TypeDec][TYPE] = 6;

	LL1Table[TypeDeclaration][TYPE] = 7;

	LL1Table[TypeDecList][IDENTIFIER] = 8;

	LL1Table[TypeDecMore][VAR] = 9;
	LL1Table[TypeDecMore][PROCEDURE] = 9;
	LL1Table[TypeDecMore][BEGIN] = 9;


	LL1Table[TypeDecMore][IDENTIFIER] = 10;

	LL1Table[TypeId][IDENTIFIER] = 11;

	LL1Table[TypeName][INTEGER] = 12;
	LL1Table[TypeName][CHAR] = 12;

	LL1Table[TypeName][ARRAY] = 13;
	LL1Table[TypeName][RECORD] = 13;

	LL1Table[TypeName][IDENTIFIER] = 14;

	LL1Table[BaseType][INTEGER] = 15;

	LL1Table[BaseType][CHAR] = 16;

	LL1Table[StructureType][ARRAY] = 17;

	LL1Table[StructureType][RECORD] = 18;

	LL1Table[ArrayType][ARRAY] = 19;

	LL1Table[Low][INTC] = 20;

	LL1Table[Top][INTC] = 21;

	LL1Table[RecType][RECORD] = 22;

	LL1Table[FieldDecList][INTEGER] = 23;
	LL1Table[FieldDecList][CHAR] = 23;

	LL1Table[FieldDecList][ARRAY] = 24;

	LL1Table[FieldDecMore][END] = 25;

	LL1Table[FieldDecMore][INTEGER] = 26;
	LL1Table[FieldDecMore][CHAR] = 26;
	LL1Table[FieldDecMore][ARRAY] = 26;

	LL1Table[IdList][IDENTIFIER] = 27;

	LL1Table[IdMore][COLON] = 28;

	LL1Table[IdMore][COMMA] = 29;

	LL1Table[VarDec][PROCEDURE] = 30;
	LL1Table[VarDec][BEGIN] = 30;

	LL1Table[VarDec][VAR] = 31;

	LL1Table[VarDeclaration][VAR] = 32;

	LL1Table[VarDecList][INTEGER] = 33;
	LL1Table[VarDecList][CHAR] = 33;
	LL1Table[VarDecList][ARRAY] = 33;
	LL1Table[VarDecList][RECORD] = 33;
	LL1Table[VarDecList][IDENTIFIER] = 33;

	LL1Table[VarDecMore][PROCEDURE] = 34;
	LL1Table[VarDecMore][BEGIN] = 34;


	LL1Table[VarDecMore][INTEGER] = 35;
	LL1Table[VarDecMore][CHAR] = 35;
	LL1Table[VarDecMore][ARRAY] = 35;
	LL1Table[VarDecMore][RECORD] = 35;
	LL1Table[VarDecMore][IDENTIFIER] = 35;

	LL1Table[VarIdList][IDENTIFIER] = 36;

	LL1Table[VarIdMore][COLON] = 37;

	LL1Table[VarIdMore][COMMA] = 38;

	LL1Table[ProcDec][BEGIN] = 39;

	LL1Table[ProcDec][PROCEDURE] = 40;

	LL1Table[ProcDeclaration][PROCEDURE] = 41;

	LL1Table[ProcDecMore][BEGIN] = 42;

	LL1Table[ProcDecMore][PROCEDURE] = 43;

	LL1Table[ProcName][IDENTIFIER] = 44;

	LL1Table[ParamList][RIGHTPAREN] = 45;

	LL1Table[ParamList][INTEGER] = 46;
	LL1Table[ParamList][CHAR] = 46;
	LL1Table[ParamList][ARRAY] = 46;
	LL1Table[ParamList][RECORD] = 46;
	LL1Table[ParamList][IDENTIFIER] = 46;
	LL1Table[ParamList][VAR] = 46;

	LL1Table[ParamDecList][INTEGER] = 47;
	LL1Table[ParamDecList][CHAR] = 47;
	LL1Table[ParamDecList][ARRAY] = 47;
	LL1Table[ParamDecList][RECORD] = 47;
	LL1Table[ParamDecList][IDENTIFIER] = 47;
	LL1Table[ParamDecList][VAR] = 47;

	LL1Table[ParamMore][LEFTPAREN] = 48;

	LL1Table[ParamMore][COLON] = 49;

	LL1Table[Param][INTEGER] = 50;
	LL1Table[Param][CHAR] = 50;
	LL1Table[Param][ARRAY] = 50;
	LL1Table[Param][RECORD] = 50;
	LL1Table[Param][IDENTIFIER] = 50;

	LL1Table[Param][VAR] = 51;

	LL1Table[FormList][IDENTIFIER] = 52;

	LL1Table[FidMore][COLON] = 53;
	LL1Table[FidMore][RIGHTMIDPAREN] = 53;
	LL1Table[FidMore][RIGHTMIDPAREN] = 53;

	LL1Table[FidMore][COMMA] = 54;

	LL1Table[ProcDecPart][TYPE] = 55;
	LL1Table[ProcDecPart][VAR] = 55;
	LL1Table[ProcDecPart][PROCEDURE] = 55;
	LL1Table[ProcDecPart][BEGIN] = 55;

	LL1Table[ProcBody][BEGIN] = 56;

	LL1Table[ProgramBody][BEGIN] = 57;

	LL1Table[StmList][IDENTIFIER] = 58;
	LL1Table[StmList][IF] = 58;
	LL1Table[StmList][WHILE] = 58;
	LL1Table[StmList][RETURN] = 58;
	LL1Table[StmList][READ] = 58;
	LL1Table[StmList][WRITE] = 58;

	LL1Table[StmMore][END] = 59;
	LL1Table[StmMore][ENDWH] = 59;
	LL1Table[StmMore][ELSE] = 59;
	LL1Table[StmMore][FI] = 59;

	LL1Table[StmMore][COLON] = 60;

	LL1Table[Stm][IF] = 61;

	LL1Table[Stm][WHILE] = 62;

	LL1Table[Stm][READ] = 63;

	LL1Table[Stm][WRITE] = 64;

	LL1Table[Stm][RETURN] = 65;

	LL1Table[Stm][IDENTIFIER] = 66;

	LL1Table[AssCall][ASSIGN] = 67;

	LL1Table[AssCall][LEFTPAREN] = 68;

	LL1Table[AssignmentRest][ASSIGN] = 69;
	LL1Table[AssignmentRest][LEFTMIDPAREN] = 69;
	LL1Table[AssignmentRest][DOT] = 69;

	LL1Table[ConditionalStm][IF] = 70;


	LL1Table[LoopStm][WHILE] = 71;

	LL1Table[InputStm][READ] = 72;

	LL1Table[InVar][IDENTIFIER] = 73;

	LL1Table[OutputStm][WRITE] = 74;

	LL1Table[ReturnStm][RETURN] = 75;

	LL1Table[CallStmRest][LEFTPAREN] = 76;

	LL1Table[ActParamList][RIGHTPAREN] = 77;

	LL1Table[ActParamList][IDENTIFIER] = 78;
	LL1Table[ActParamList][INTC] = 78;
	LL1Table[ActParamList][LEFTPAREN] = 78;

	LL1Table[ActParamMore][RIGHTPAREN] = 79;

	LL1Table[ActParamMore][COMMA] = 80;

	LL1Table[RelExp][LEFTPAREN] = 81;
	LL1Table[RelExp][INTC] = 81;
	LL1Table[RelExp][IDENTIFIER] = 81;

	LL1Table[OtherRelE][LT] = 82;
	LL1Table[OtherRelE][EQUAL] = 82;

	LL1Table[Exp][LEFTPAREN] = 83;
	LL1Table[Exp][INTC] = 83;
	LL1Table[Exp][IDENTIFIER] = 83;

	LL1Table[OtherTerm][LT] = 84;
	LL1Table[OtherTerm][EQUAL] = 84;
	LL1Table[OtherTerm][THEN] = 84;
	LL1Table[OtherTerm][DO] = 84;
	LL1Table[OtherTerm][RIGHTPAREN] = 84;
	LL1Table[OtherTerm][END] = 84;
	LL1Table[OtherTerm][COLON] = 84;
	LL1Table[OtherTerm][COMMA] = 84;
	LL1Table[OtherTerm][ENDWH] = 84;
	LL1Table[OtherTerm][ELSE] = 84;
	LL1Table[OtherTerm][FI] = 84;
	LL1Table[OtherTerm][RIGHTMIDPAREN] = 84;


	LL1Table[OtherTerm][ADD] = 85;
	LL1Table[OtherTerm][MINUS] = 85;

	LL1Table[Term][LEFTPAREN] = 86;
	LL1Table[Term][INTC] = 86;
	LL1Table[Term][IDENTIFIER] = 86;

	LL1Table[OtherFactor][ADD] = 87;
	LL1Table[OtherFactor][MINUS] = 87;
	LL1Table[OtherFactor][LT] = 87;
	LL1Table[OtherFactor][EQUAL] = 87;
	LL1Table[OtherFactor][THEN] = 87;
	LL1Table[OtherFactor][ELSE] = 87;
	LL1Table[OtherFactor][FI] = 87;
	LL1Table[OtherFactor][DO] = 87;
	LL1Table[OtherFactor][ENDWH] = 87;
	LL1Table[OtherFactor][RIGHTPAREN] = 87;
	LL1Table[OtherFactor][END] = 87;
	LL1Table[OtherFactor][COLON] = 87;
	LL1Table[OtherFactor][COMMA] = 87;
	LL1Table[OtherFactor][RIGHTMIDPAREN] = 87;

	LL1Table[OtherFactor][MULTY] = 88;
	LL1Table[OtherFactor][DEVIDE] = 88;

	LL1Table[Factor][LEFTPAREN] = 89;

	LL1Table[Factor][INTC] = 90;

	LL1Table[Factor][IDENTIFIER] = 91;

	LL1Table[Variable][IDENTIFIER] = 92;

	LL1Table[VariMore][ASSIGN] = 93;
	LL1Table[VariMore][MULTY] = 93;
	LL1Table[VariMore][DEVIDE] = 93;
	LL1Table[VariMore][ADD] = 93;
	LL1Table[VariMore][MINUS] = 93;
	LL1Table[VariMore][LT] = 93;
	LL1Table[VariMore][EQUAL] = 93;
	LL1Table[VariMore][THEN] = 93;
	LL1Table[VariMore][ELSE] = 93;
	LL1Table[VariMore][FI] = 93;
	LL1Table[VariMore][DO] = 93;
	LL1Table[VariMore][ENDWH] = 93;
	LL1Table[VariMore][RIGHTPAREN] = 93;
	LL1Table[VariMore][END] = 93;
	LL1Table[VariMore][COLON] = 93;
	LL1Table[VariMore][COMMA] = 93;
	LL1Table[VariMore][RIGHTMIDPAREN] = 93;

	LL1Table[VariMore][LEFTMIDPAREN] = 94;

	LL1Table[VariMore][DOT] = 95;

	LL1Table[FieldVar][IDENTIFIER] = 96;

	LL1Table[FieldVarMore][ASSIGN] = 97;
	LL1Table[FieldVarMore][MULTY] = 97;
	LL1Table[FieldVarMore][DEVIDE] = 97;
	LL1Table[FieldVarMore][ADD] = 97;
	LL1Table[FieldVarMore][MINUS] = 97;
	LL1Table[FieldVarMore][LT] = 97;
	LL1Table[FieldVarMore][EQUAL] = 97;
	LL1Table[FieldVarMore][THEN] = 97;
	LL1Table[FieldVarMore][ELSE] = 97;
	LL1Table[FieldVarMore][FI] = 97;
	LL1Table[FieldVarMore][DO] = 97;
	LL1Table[FieldVarMore][ENDWH] = 97;
	LL1Table[FieldVarMore][RIGHTPAREN] = 97;
	LL1Table[FieldVarMore][END] = 97;
	LL1Table[FieldVarMore][COLON] = 97;
	LL1Table[FieldVarMore][COMMA] = 97;

	LL1Table[FieldVarMore][LEFTMIDPAREN] = 98;

	LL1Table[CmpOp][LT] = 99;

	LL1Table[CmpOp][EQUAL] = 100;

	LL1Table[AddOp][ADD] = 101;

	LL1Table[AddOp][MINUS] = 102;

	LL1Table[MultOp][MULTY] = 103;

	LL1Table[MultOp][DEVIDE] = 104;

}

void addNode(int flag, int num, string name,STree*father)
{
	StackNode* newnode = new StackNode(flag, num);
	newnode->st = new STree(name);
	father->addSon(newnode->st);
	AStack.push(*newnode);
}

void process(int num,STree *tempst)
{
	if (num == 1)
	{
		int count = 4;
		addNode(1, DOT, "DOT",tempst);
		addNode(0, ProgramBody, "ProgramBody", tempst);
		addNode(0, DeclarePart, "DeclarePart", tempst);
		addNode(0, ProgramHead, "ProgramHead", tempst);
	}
	else if (num == 2)
	{
		int count = 2;
		addNode(0, ProgramName, "ProgramName", tempst);
		addNode(1, PROGRAM, "PROGRAM", tempst);
	}
	else if (num == 3)
	{
		int count = 1;
		//		addNode(1, COLON, "COLON", tempst);
		addNode(1, IDENTIFIER, "IDENTIFIER", tempst);
	}
	else if (num == 4)
	{
		int count = 3;
		addNode(0, ProcDec, "ProcDec", tempst);
		addNode(0, VarDec, "VarDec", tempst);
		addNode(0, TypeDec, "TypeDec", tempst);
	}
	else if (num == 5)
	{
		;
	}
	else if (num == 6)
	{
		int count = 1;
		addNode(0, TypeDeclaration, "TypeDeclaration", tempst);
	}
	else if (num == 7)
	{
		int count = 2;
		addNode(0, TypeDecList, "TypeDecList", tempst);
		addNode(1, TYPE, "TYPE", tempst);
	}
	else if (num == 8)
	{
		int count = 5;
		addNode(0, TypeDecMore, "TypeDecMore", tempst);
		addNode(1, COLON, "COLON", tempst);
		addNode(0, TypeName, "TypeName", tempst);
		addNode(1, EQUAL, "EQUAL", tempst);
		addNode(0, TypeId, "TypeID", tempst);
	}
	else if (num == 9)
	{
		;
	}
	else if (num == 10)
	{
		int count = 1;
		addNode(0, TypeDecList, "TypeDecList", tempst);
	}
	else if (num == 11)
	{
		int count = 1;
		addNode(1, IDENTIFIER, "IDENTIFIER", tempst);
	}
	else if (num == 12)
	{
		int count = 1;
		addNode(0, BaseType, "BaseType", tempst);
	}
	else if (num == 13)
	{
		int count = 1;
		addNode(0, StructureType, "StructureType", tempst);
	}
	else if (num == 14)
	{
		int count = 1;
		addNode(1, IDENTIFIER, "IDENTIFIER", tempst);
	}
	else if (num == 15)
	{
		int count = 1;
		addNode(1, INTEGER, "INTEGER", tempst);
	}
	else if (num == 16)
	{
		int count = 1;
		addNode(1, CHAR, "CHAR1", tempst);
	}
	else if (num == 17)
	{
		int count = 1;
		addNode(0, ArrayType, "ArrayType", tempst);
	}
	else if (num == 18)
	{
		int count = 1;
		addNode(0, RecType, "RecType", tempst);
	}
	else if (num == 19)
	{
		int count = 8;
		addNode(0, BaseType, "BaseType", tempst);
		addNode(1, OF, "OF", tempst);
		addNode(1, RIGHTMIDPAREN, "RIGHTMIDPAREN", tempst);
		addNode(0, Top, "Top", tempst);
		//addNode(1, UNDERANGE, "UNDERANGE", tempst);
		addNode(0, Low, "Low", tempst);
		addNode(1, LEFTMIDPAREN, "LEFTMIDPAREN", tempst);
		addNode(1, ARRAY, "ARRAY", tempst);
	}
	else if (num == 20)
	{
		int count = 1;
		addNode(1, INTC, "INTC", tempst);
	}
	else if (num == 21)
	{
		int count = 1;
		addNode(1, INTC, "INTC", tempst);
	}
	else if (num == 22)
	{
		int count = 3;
		addNode(1, END, "END", tempst);
		addNode(0, FieldDecList, "FieldDecList", tempst);
		addNode(1, RECORD, "RECORD", tempst);
	}
	else if (num == 23)
	{
		int count = 4;
		addNode(0, FieldDecMore, "FieldDecMore", tempst);
		addNode(1, COLON, "COLON", tempst);
		addNode(0, IdList, "IDList", tempst);
		addNode(0, BaseType, "BaseType", tempst);
	}
	else if (num == 24)
	{
		int count = 4;
		addNode(0, FieldDecMore, "FieldDecMore", tempst);
		addNode(1, COLON, "COLON", tempst);
		addNode(0, IdList, "IDList", tempst);
		addNode(0, ArrayType, "ArrayType", tempst);
	}
	else if (num == 25)
	{
		;
	}
	else if (num == 26)
	{
		int count = 1;
		addNode(0, FieldDecList, "FieldDecList", tempst);
	}
	else if (num == 27)
	{
		int count = 2;
		addNode(0, IdMore, "IDMore", tempst);
		addNode(1, IDENTIFIER, "IDENTIFIER", tempst);
	}
	else if (num == 28)
	{
		;
	}
	else if (num == 29)
	{
		int count = 2;
		addNode(0, IdList, "IDList", tempst);
		addNode(1, COMMA, "COMMA", tempst);
	}
	else if (num == 30)
	{
		;
	}
	else if (num == 31)
	{
		int count = 1;
		addNode(0, VarDeclaration, "VarDeclaration", tempst);
	}
	else if (num == 32)
	{
		int count = 2;
		addNode(0, VarDecList, "VarDecList", tempst);
		addNode(1, VAR, "VAR", tempst);
	}
	else if (num == 33)
	{
		int count = 4;
		addNode(0, VarDecMore, "VarDecMore", tempst);
		addNode(1, COLON, "COLON", tempst);
		addNode(0, VarIdList, "VarIDList", tempst);
		addNode(0, TypeName, "TypeName", tempst);
	}
	else if (num == 34)
	{
		;
	}
	else if (num == 35)
	{
		int count = 1;
		addNode(0, VarDecList, "VarDecList", tempst);
	}
	else if (num == 36)
	{
		int count = 2;
		addNode(0, VarIdMore, "VarIDMore", tempst);
		addNode(1, IDENTIFIER, "IDENTIFIER", tempst);
	}
	else if (num == 37)
	{
		;
	}
	else if (num == 38)
	{
		int count = 2;
		addNode(0, VarIdList, "VarIDList", tempst);
		addNode(1, COMMA, "COMMA", tempst);
	}
	else if (num == 39)
	{
		;
	}
	else if (num == 40)
	{
		int count = 1;
		addNode(0, ProcDeclaration, "ProcDeclaration", tempst);
	}
	else if (num == 41)
	{
		int count = 9;
		addNode(0, ProcDecMore, "ProcDecMore", tempst);
		addNode(0, ProcBody, "ProcBody", tempst);
		addNode(0, ProcDecPart, "ProcDecPart", tempst);
		addNode(1, COLON, "COLON", tempst);
		addNode(1, RIGHTPAREN, "RIGHTPAREN", tempst);
		addNode(0, ParamList, "ParamList", tempst);
		addNode(1, LEFTPAREN, "LEFTPAREN", tempst);
		addNode(0, ProcName, "ProcName", tempst);
		addNode(1, PROCEDURE, "PROCEDURE", tempst);
	}
	else if (num == 42)
	{
		;
	}
	else if (num == 43)
	{
		int count = 1;
		addNode(0, ProcDeclaration, "ProcDeclaration", tempst);
	}
	else if (num == 44)
	{
		int count = 1;
		addNode(1, IDENTIFIER, "IDENTIFIER", tempst);
	}
	else if (num == 45)
	{
		;
	}
	else if (num == 46)
	{
		int count = 1;
		addNode(0, ParamDecList, "ParamDecList", tempst);
	}
	else if (num == 47)
	{
		int count = 2;
		addNode(0, ParamMore, "ParamMore", tempst);
		addNode(0, Param, "Param", tempst);
	}
	else if (num == 48)
	{
		;
	}
	else if (num == 49)
	{
		int count = 2;
		addNode(0, ParamDecList, "ParamDecList", tempst);
		addNode(1, COLON, "COLON", tempst);
	}
	else if (num == 50)
	{
		int count = 2;
		addNode(0, FormList, "FormList", tempst);
		addNode(0, TypeName, "TypeName", tempst);
	}
	else if (num == 51)
	{
		int count = 3;
		addNode(0, FormList, "FormList", tempst);
		addNode(0, TypeName, "TypeName", tempst);
		addNode(1, VAR, "VAR", tempst);
	}
	else if (num == 52)
	{
		int count = 2;
		addNode(0, FidMore, "FidMore", tempst);
		addNode(1, IDENTIFIER, "IDENTIFIER", tempst);
	}
	else if (num == 53)
	{
		;
	}
	else if (num == 54)
	{
		int count = 2;
		addNode(0, FormList, "FormList", tempst);
		addNode(1, COMMA, "COMMA", tempst);
	}
	else if (num == 55)
	{
		int count = 1;
		addNode(0, DeclarePart, "DeclarePart", tempst);
	}
	else if (num == 56)
	{
		int count = 1;
		addNode(0, ProgramBody, "ProgramBody", tempst);
	}
	else if (num == 57)
	{
		int count = 3;
		addNode(1, END, "END", tempst);
		addNode(0, StmList, "StmList", tempst);
		addNode(1, BEGIN, "BEGIN", tempst);
	}
	else if (num == 58)
	{
		int count = 2;
		addNode(0, StmMore, "StmMore", tempst);
		addNode(0, Stm, "Stm", tempst);
	}
	else if (num == 59)
	{
		;
	}
	else if (num == 60)
	{
		int count = 2;
		addNode(0, StmList, "StmList", tempst);
		addNode(1, COLON, "COLON", tempst);
	}
	else if (num == 61)
	{
		int count = 1;
		addNode(0, ConditionalStm, "ConditionalStm", tempst);
	}
	else if (num == 62)
	{
		int count = 1;
		addNode(0, LoopStm, "LoopStm", tempst);
	}
	else if (num == 63)
	{
		int count = 1;
		addNode(0, InputStm, "InputStm", tempst);
	}
	else if (num == 64)
	{
		int count = 1;
		addNode(0, OutputStm, "OutputStm", tempst);
	}
	else if (num == 65)
	{
		int count = 1;
		addNode(0, ReturnStm, "ReturnStm", tempst);
	}
	else if (num == 66)
	{
		int count = 2;
		addNode(0, AssCall, "AssCall", tempst);
		addNode(1, IDENTIFIER, "IDENTIFIER", tempst);
	}
	else if (num == 67)
	{
		int count = 1;
		addNode(0, AssignmentRest, "AssignmentRest", tempst);
	}
	else if (num == 68)
	{
		int count = 1;
		addNode(0, CallStmRest, "CallStmRest", tempst);
	}
	else if (num == 69)
	{
		int count = 3;
		addNode(0, Exp, "Exp", tempst);
		addNode(1, ASSIGN, "ASSIGN", tempst);
		addNode(0, VariMore, "VariMore", tempst);
	}
	else if (num == 70)
	{
		int count = 7;
		addNode(1, FI, "FI", tempst);
		addNode(0, StmList, "StmList", tempst);
		addNode(1, ELSE, "ELSE", tempst);
		addNode(0, StmList, "StmList", tempst);
		addNode(1, THEN, "THEN", tempst);
		addNode(0, RelExp, "RelExp", tempst);
		addNode(1, IF, "IF", tempst);
	}
	else if (num == 71)
	{
		int count = 5;
		//addNode(1, COLON, "COLON", tempst);
		addNode(1, ENDWH, "ENDWH", tempst);
		addNode(0, StmList, "StmList", tempst);
		addNode(1, DO, "DO", tempst);
		addNode(0, RelExp, "RelExp", tempst);
		addNode(1, WHILE, "WHILE", tempst);
	}
	else if (num == 72)
	{
		int count = 4;
		addNode(1, RIGHTPAREN, "RIGHTPAREN", tempst);
		addNode(0, InVar, "InVar", tempst);
		addNode(1, LEFTPAREN, "LEFTPAREN", tempst);
		addNode(1, READ, "READ", tempst);
	}
	else if (num == 73)
	{
		int count = 1;
		addNode(1, IDENTIFIER, "IDENTIFIER", tempst);
	}
	else if (num == 74)
	{
		int count = 4;
		addNode(1, RIGHTPAREN, "RIGHTPAREN", tempst);
		addNode(0, Exp, "Exp", tempst);
		addNode(1, LEFTPAREN, "LEFTPAREN", tempst);
		addNode(1, WRITE, "WRITE", tempst);
	}
	else if (num == 75)
	{
		int count = 1;
		addNode(1, RETURN, "RETURN", tempst);
	}
	else if (num == 76)
	{
		int count = 3;
		addNode(1, RIGHTPAREN, "RIGHTPAREN", tempst);
		addNode(0, ActParamList, "ActParamList", tempst);
		addNode(1, LEFTPAREN, "LEFTPAREN", tempst);
	}
	else if (num == 77)
	{
		;
	}
	else if (num == 78)
	{
		int count = 2;
		addNode(0, ActParamMore, "ActParamMore", tempst);
		addNode(0, Exp, "Exp", tempst);
	}
	else if (num == 79)
	{
		;
	}
	else if (num == 80)
	{
		int count = 2;
		addNode(0, ActParamList, "ActParamList", tempst);
		addNode(1, COMMA, "COMMA", tempst);
	}
	else if (num == 81)
	{
		int count = 2;
		addNode(0, OtherRelE, "OtherRelE", tempst);
		addNode(0, Exp, "Exp", tempst);
	}
	else if (num == 82)
	{
		int count = 2;
		addNode(0, Exp, "Exp", tempst);
		addNode(0, CmpOp, "CmpOp", tempst);
	}
	else if (num == 83)
	{
		int count = 2;
		addNode(0, OtherTerm, "OtherTerm", tempst);
		addNode(0, Term, "Term", tempst);
	}
	else if (num == 84)
	{
		;
	}
	else if (num == 85)
	{
		int count = 2;
		addNode(0, Exp, "Exp", tempst);
		addNode(0, AddOp, "AddOp", tempst);
	}
	else if (num == 86)
	{
		int count = 2;
		addNode(0, OtherFactor, "OtherFactor", tempst);
		addNode(0, Factor, "Factor", tempst);
	}
	else if (num == 87)
	{
		;
	}
	else if (num == 88)
	{
		int count = 2;
		addNode(0, Term, "Term", tempst);
		addNode(0, MultOp, "MultOp", tempst);
	}
	else if (num == 89)
	{
		int count = 3;
		addNode(1, RIGHTPAREN, "RIGHTPAREN", tempst);
		addNode(0, Exp, "Exp", tempst);
		addNode(1, LEFTPAREN, "LEFTPAREN", tempst);
	}
	else if (num == 90)
	{
		int count = 1;
		addNode(1, INTC, "INTC", tempst);
	}
	else if (num == 91)
	{
		int count = 1;
		addNode(0, Variable, "Variable", tempst);
	}
	else if (num == 92)
	{
		int count = 2;
		addNode(0, VariMore, "VariMore", tempst);
		addNode(1, IDENTIFIER, "IDENTIFIER", tempst);
	}
	else if (num == 93)
	{
		;
	}
	else if (num == 94)
	{
		int count = 3;
		addNode(1, RIGHTMIDPAREN, "RIGHTMIDPAREN", tempst);
		addNode(0, Exp, "Exp", tempst);
		addNode(1, LEFTMIDPAREN, "LEFTMIDPAREN", tempst);
	}
	else if (num == 95)
	{
		int count = 2;
		addNode(0, FieldVar, "FieldVar", tempst);
		addNode(1, DOT, "DOT", tempst);
	}
	else if (num == 96)
	{
		int count = 2;
		addNode(0, FieldVarMore, "FieldVarMore", tempst);
		addNode(1, IDENTIFIER, "IDENTIFIER", tempst);
	}
	else if (num == 97)
	{
		;
	}
	else if (num == 98)
	{
		int count = 3;
		addNode(1, RIGHTMIDPAREN, "RIGHTMIDPAREN", tempst);
		addNode(0, Exp, "Exp", tempst);
		addNode(1, LEFTMIDPAREN, "LEFTMIDPAREN", tempst);
	}
	else if (num == 99)
	{
		int count = 1;
		addNode(1, LT, "LT", tempst);
	}
	else if (num == 100)
	{
		int count = 1;
		addNode(1, EQUAL, "EQUAL", tempst);
	}
	else if (num == 101)
	{
		int count = 1;
		addNode(1, ADD, "ADD", tempst);
	}
	else if (num == 102)
	{
		int count = 1;
		addNode(1, MINUS, "MINUS", tempst);
	}
	else if (num == 103)
	{
		int count = 1;
		addNode(1, MULTY, "MULTY", tempst);
	}
	else if (num == 104)
	{
		int count = 1;
		addNode(1, DEVIDE, "DIVIDE", tempst);
	}
}



STree* buildTree(Token *token)
{
	Token* next = token->next;
	Terminal topT;
	NonTerminal topN;
	CreateLL1Table();
	STree* root = rootTree;
	root = new STree("Program");
	StackNode *sn = new StackNode(0, Program);
	sn->st = root;
	AStack.push(*sn);
	int count = 0;
	while (!AStack.empty())
	{
		//cout << count++ << endl;
		//cout<<"SIZE:"AStack.
		cout << "FLAG:" << AStack.top().flag << "\tN:" << AStack.top().n << "\tT:" << AStack.top().t << endl;
		if (AStack.top().flag == 1)
		{
			STree* tempst = AStack.top().st;
			topT = AStack.top().t;
			if (topT == token->type)
			{
				cout << "YES" << endl;
				//tempst->word = identifier_list[token->index].text;
				token = token->next;
				AStack.pop();
			}
			else
			{
				cout << "T:" << topT<< endl;
				cout << "type:" << token->type << endl;
				cout << "Error in Line:" << token->line << "!" << endl;
				system("pause");
				//exit(0);
				//token = token->next;
			}
		}
		else
		{
			topN = AStack.top().n;
			//cout << "??" << topN << endl;
			//cout <<"!"<< token->type << endl;
			int temp = LL1Table[topN][token->type];
			cout << "TEMP:" << temp << endl;
			STree* tempst = AStack.top().st;
			AStack.pop();
			process(temp,tempst);
			//token = token->next;
			//cout << "hewe";
		}
		
	}
	if (token != NULL)
	{
		cout << "";
		system("pause");
	}
	return root;
}