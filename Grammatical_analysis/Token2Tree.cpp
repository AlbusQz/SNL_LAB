#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<cstdlib>
#include<cstring>
#include"Syntax_tree.h"
#include"config.h"

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

	LL1Table[IdMore][SEMICOLON] = 28;

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

	LL1Table[VarIdMore][SEMICOLON] = 37;

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

	LL1Table[ParamMore][SEMICOLON] = 49;

	LL1Table[Param][INTEGER] = 50;
	LL1Table[Param][CHAR] = 50;
	LL1Table[Param][ARRAY] = 50;
	LL1Table[Param][RECORD] = 50;
	LL1Table[Param][IDENTIFIER] = 50;

	LL1Table[Param][VAR] = 51;

	LL1Table[FormList][IDENTIFIER] = 52;

	LL1Table[FidMore][SEMICOLON] = 53;
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

	LL1Table[StmMore][SEMICOLON] = 60;

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
	LL1Table[OtherTerm][SEMICOLON] = 84;
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
	LL1Table[OtherFactor][SEMICOLON] = 87;
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
	LL1Table[VariMore][SEMICOLON] = 93;
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
	LL1Table[FieldVarMore][SEMICOLON] = 97;
	LL1Table[FieldVarMore][COMMA] = 97;

	LL1Table[FieldVarMore][LEFTMIDPAREN] = 98;

	LL1Table[CmpOp][LT] = 99;

	LL1Table[CmpOp][EQUAL] = 100;

	LL1Table[AddOp][ADD] = 101;

	LL1Table[AddOp][MINUS] = 102;

	LL1Table[MultOp][MULTY] = 103;

	LL1Table[MultOp][DEVIDE] = 104;

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
	while (!AStack.empty())
	{
		if (AStack.top().flag == 1)
		{
			topT = AStack.top().t;
			if (topT == token->type)
			{
				//identifier_list[head->index].text
			}
		}
	}
}