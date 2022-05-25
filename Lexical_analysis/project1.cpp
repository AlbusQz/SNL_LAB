#include<iostream>
#include<vector>
using namespace std;

int main()
{
	enum state { s0, s1, s2, s3, s4, s5 };
	enum letter{ temp1='a',temp2='z' };
	enum digit {temp3='0',temp4='9' };
	enum outkind
	{
		id,
		num,
		error
	};
	char ch;
	outkind outkind1;
	state state1;
	state1 = s0;
	vector<char> Letter;
	int k = 0;
	for (int i = 0; i < 5; i++)
	{
		char temp5;
		cin >> temp5;
		Letter.push_back(temp5);
	}
	ch = Letter[0];
	while(1)
	{
		if(state1==s0)
		{
			
			if (ch >= 'a' && ch <= 'z')
			{
				
				state1 = s1;
			}
			else if (ch >= '0' && ch <= '9')
			{
				
				state1 = s3;	
			}
			else
			{
				
				state1 = s5;
			}
		}
		else if(state1==s1)
		{
			
			while (ch >= temp1 && ch <= temp2)
			{
				if (k < Letter.size()-1)
				{
					k++;
					ch = Letter[k];
				}
				else
				{
					break;
				}
			}
			state1 = s2;
		}
		else if(state1==s2)
		{
		
			outkind1 = id;
			break;
		}
		else if(state1==s3)
		{
			
			while (ch >= temp3 && ch <= temp4)
			{
				if (k < Letter.size() - 1)
				{
					k++;
					ch = Letter[k];
				}
				else
				{
				 	break;
				}
			}
			state1 = s4;
		}
		else if(state1==s4)
		{
			
			outkind1 = num;
			break;
		}
		else 
		{
			
			outkind1 = error;
			break;
		}
	}
	if (outkind1 == id)
	{
		cout << "id" <<endl;
	}
	else if (outkind1 == num)
	{
		cout << "num" << endl;
	}
	else if(outkind1 == error)
	{
		cout << "error" << endl;
	}
	return 0;
}