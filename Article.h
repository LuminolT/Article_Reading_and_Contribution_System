#pragma once
#include<string>
#include<ostream>
#include <iostream>
#include <iomanip>
using namespace std;

class Article{
	friend ostream& operator << (ostream& out, Article& person);      // ������������
public:
	string number;
	string author;
	string name;
	string tag;
	string content;
	int status;	//��˵�status //1 ͨ�� -1 ��ͨ�� 0 δ���

	Article& operator = (Article& person);                            // ��ֵ���������
	bool operator == (Article& person);                               // �ж�������������
	void printfTable();
};