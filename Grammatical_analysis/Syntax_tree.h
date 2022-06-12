#pragma once
#include<string>
#include<cstring>
#include<iostream>
#include<stack>
#include "..\Lexical_analysis\config.h"
using namespace std;

//�﷨���ڵ���
class STree
{
	public:
	STree* sons[50];
	int count;
	string word;
	Token* token;
	int depth;
	STree* father;
	bool end;
	STree(string input)
	{
		this->word = input;
		this->count = 0;
		depth = 0;
		count = 0;
		memset(this->sons, 0, size(this->sons));
		token = NULL;
		father = NULL;
		end = true;
	}
	void addSon(STree* s)
	{
		this->sons[count++] = s;
		s->father = this;
	}
};

//����ջ���
class StackNode
{
public:
	int flag;
	NonTerminal n;
	Terminal t;
	STree* st;
	StackNode(int flag, int num)
	{
		if (flag == 0)
		{
			this->n = (NonTerminal)num;
			this->t =(Terminal) -1;
			this->flag = 0;
		}
		else
		if(flag==1)
		{
			this->n = (NonTerminal)-1;
			this->t = (Terminal)num;
			this->flag = 1;
		}
	}
};

//LL1�������ʼ������
void CreateLL1Table();

//����ֹ��ת������
void process(int num, STree* tempst);

//�����﷨������
STree* buildTree(Token* token);

//��ӡ�﷨������
void printTree(STree* root);
