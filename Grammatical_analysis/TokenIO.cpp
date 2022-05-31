#pragma once
#define  _CRT_SECURE_NO_WARNINGS

#include "..\Lexical_analysis\config.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Syntax_tree.h"

Identifier identifier_list[500];
void printTokenToFile(Token* head, string path) {
	fstream file;
	file.open(path);
	char line[100] = "";
	while (head != NULL)
	{
		if (head->index != -1)
		{
			sprintf(line, "%d %d %d %s\n",
				head->line, head->type, head->index, identifier_list[head->index].text.c_str());
		}
		else
		{
			sprintf(line, "%d %d %d\n",
				head->line, head->type, head->index);
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
	Token* curr = new Token();
	head->next = curr;
	while (!file.eof())
	{
		file.getline(line, 100);

		char text[100] = "";
		sscanf(line, "%d %d %d",
			&curr->line, &curr->type, & curr->index);
		if (curr->index != -1)
		{
			//sscanf(line, "%d %d %d %s",
				//&curr->line, &curr->type, &curr->index, text);
			sscanf(line, "%s",
				text);
			identifier_list[curr->index].text = text;
		}

		curr->next = new Token();
		temp++;
		curr = curr->next;
	}
	file.close();
	cout << temp;
	return head;
}
