// Grammatical_analysis.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include"Syntax_tree.h"
#include "..\Lexical_analysis\config.h"
int main()
{
    Token* head;
    string path = "D:\\t1.txt";
    head = readTokenFromFile(path);
    STree* root = buildTree(head->next);
    printTree(root);
}

