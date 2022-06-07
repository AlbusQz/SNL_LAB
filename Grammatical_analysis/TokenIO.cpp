#pragma once
#define  _CRT_SECURE_NO_WARNINGS

#include "..\Lexical_analysis\config.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Syntax_tree.h"

Identifier identifier_list[500];
Const const_list[500];
void printTokenToFile(Token* head, string path) {
	fstream file;
	file.open(path);
	if (!file.is_open())
	{
		printf("connot open %s\n", path.c_str());
		return;
	}
	char line[100] = "";
	while (head != NULL)
	{
		switch (head->type)
		{
		case IDENTIFIER:
			sprintf(line, "%d %d %d %s\n",
				head->line, head->type, head->index, identifier_list[head->index].text.c_str());
			break;
		case CONST:
			if (const_list[head->index].isnum)
			{
				sprintf(line, "%d %d %d %d %d\n",
					head->line, head->type, head->index, const_list[head->index].isnum, const_list[head->index].num);
			}
			else
			{
				sprintf(line, "%d %d %d %d %s\n",
					head->line, head->type, head->index, const_list[head->index].isnum, const_list[head->index].text.c_str());
			}
			break;
		default:
			sprintf(line, "%d %d\n",
				head->line, head->type);
			break;
		}
		file.write(line, strlen(line));

		head = head->next;

	}

	file.close();
}
Token* readTokenFromFile(string path)
{
	int temp = 0;
	fstream file;
	file.open(path);
	if (!file.is_open())
	{
		printf("connot open %s", path.c_str());
		return NULL;
	}
	char line[100] = "";
	Token* head = new Token();
	Token* curr =head;
	int isnum = 0;
	while (!file.eof())
	{
		curr->next = new Token();
		curr = curr->next;
		file.getline(line, 100);

		char text[100] = "";
		sscanf(line, "%d %d",
			&curr->line, &curr->type);
		switch (curr->type)
		{
			case IDENTIFIER:
				sscanf(line, "%d %d %d %s",
					&curr->line, &curr->type, &curr->index, text);
				identifier_list[curr->index].text = text;
				break;
			case CONST:
				sscanf(line, "%d %d %d %d %s",
					&curr->line, &curr->type, &curr->index,&isnum, text);
				if (isnum)
				{
					const_list[curr->index].isnum = true;
					const_list[curr->index].num = atoi(text);
				}
				else
				{
					const_list[curr->index].isnum = false;
					identifier_list[curr->index].text = text;
				}
				break;
			default:
				break;
		}
	}
	curr->next = NULL;
	file.close();
	return head;
}
