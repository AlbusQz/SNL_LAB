#include<string>
#include<cstring>
#include<iostream>
#include<stack>
#include"config.h"
using namespace std;

//�﷨���ڵ���
class STree
{
	public:
	STree* sons[50];
	int count;
	string word;
	Token* token;
	STree(string input)
	{
		this->word = input;
		this->count = 0;
		memset(this->sons, 0, size(this->sons));
		token = NULL;
	}
	void addSon(STree* s)
	{
		this->sons[count++] = s;
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

STree* rootTree = NULL;
stack<StackNode> AStack;
