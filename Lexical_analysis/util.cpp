#include "config.h"
#include <iostream>
#include <fstream>
#include <string>

Token* token_head = new Token();
Token* token_tail = token_head;
extern Identifier identifier_list[500];
//const char sourcepath[50] = "source_code.txt",tokenpath[50]="./token_list.txt";
//Identifier identifier_list[500];
Const const_list[500];
const char sourcepath[50] = "source_code.txt",tokenpath[50]="token_list.txt";
int id_list_tail = 0;
int const_list_tail = 0;
int main(void)
{
	int lineNum = 1;
	int index = 0;
	char ch=' ';
	fstream source;
	source.open(sourcepath);
	bool reScan = false;
	State state = START;
	string cur_word = "";
	source.get(ch);
	while (!source.eof())
	{
		//source.get(ch);
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
			if (isDigit(ch))
			{
				state = INNUM;
				cur_word += ch;
			}
			if (ch=='.')
			{
				state = INPOI;
			}
			if (ch == ':')
			{
				state = INASIGN;
			}
			if (ch == '{')
			{
				state = INCOMM;
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
				reScan = true;
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
				}
				cur_word = "";
			}
			break;
		case STATEEND:
			break;
		case INCOMM:
			if (ch == '}')
			{
				state = DONE;
			}
			break;
		case INASIGN:
			if (ch == '=')
			{
				state = DONE;
				token_tail->next = new Token(lineNum, ASSIGN, -1);
				token_tail = token_tail->next;
			}
			else
			{
				//error
			}
			break;
		case INPOI:
			if (ch == '.')
			{
				state = DONE;
				token_tail->next = new Token(lineNum, ARRAYTOP,-1);
				token_tail = token_tail->next;
			}
			else
			{
				state = DONE;
				token_tail->next = new Token(lineNum, END, -1);
				token_tail = token_tail->next;
				reScan = true;
			}
			break;
		case DONE:

			break;
		case INNUM:
			if (isDigit(ch))
			{
				cur_word += ch;
			}
			else
			{
				state = DONE;
				reScan = true;
				const_list[const_list_tail] = Const(getValue(cur_word));
				const_list_tail++;
				token_tail->next = new Token(lineNum, CONST, const_list_tail - 1);
				token_tail = token_tail->next;
				cur_word = "";
			}
			break;
		default:
			break;
		}
		
		if (state == DONE)
		{
			cur_word = "";
			state = START;
		}
		if (reScan)
		{
			reScan = false;
		}
		else
		{
			if (ch == '\n')
				lineNum++;
			source.get(ch);
		}
			
	}
	tokenPrint(token_head->next);
	printTokenToFile(token_head->next, tokenpath);

	//Token* read = readTokenFromFile(tokenpath);
	//tokenPrint(read->next);

	return 0;
}