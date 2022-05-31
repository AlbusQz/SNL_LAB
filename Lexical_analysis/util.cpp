#include "config.h"
#include <iostream>
#include <fstream>
#include <string>

Token* token_head = new Token();
Token* token_tail = token_head;
Identifier identifier_list[500];
const char sourcepath[50] = "source.txt",tokenpath[50]="token_list.txt";
int id_list_tail = 0;
int main(void)
{
	int lineNum = 1;
	int index = 0;
	char ch=' ';
	fstream source;
	source.open(sourcepath);
	State state = START;
	string cur_word = "";
	while (!source.eof())
	{
		source.get(ch);
		if (ch == '\n')
			lineNum++;
		if (state == DONE)
		{
			cur_word = "";
			state = START;
		}
			
		switch (state)
		{
		case START:
			if (isLetter(ch))
			{
				state = INID;
				cur_word += ch;
			}
			if (isSpe(ch))
			{
				token_tail->next = new Token(lineNum, findNum(ch), -1);
				token_tail = token_tail->next;
				state = DONE;
			}
			break;
		case INID:
			if (isLetter(ch) || isDigit(ch))
			{
				cur_word += ch;
			}
			else
			{
				
				
				state = DONE;
				if (isReserved(cur_word))
				{
					token_tail->next = new Token(lineNum, findNum(cur_word), -1);
					token_tail = token_tail->next;
					
				}
				else
				{
					identifier_list[id_list_tail] = Identifier(id_list_tail, cur_word);
					id_list_tail++;
					token_tail->next = new Token(lineNum,IDENTIFIER,id_list_tail-1);
					token_tail = token_tail->next;
				}cur_word = "";
				if (isSpe(ch))
				{
					token_tail->next = new Token(lineNum, findNum(ch), -1);
					token_tail = token_tail->next;
				}
				
				
			}
			break;
		case STATEEND:
			break;
		case DONE:
			
			break;
		default:
			break;
		}
		
	}
	tokenPrint(token_head->next);


	return 0;
}