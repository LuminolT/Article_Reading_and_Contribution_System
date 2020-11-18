#pragma once
#include<string>
#include<ostream>
#include <iostream>
#include <iomanip>
using namespace std;

class Article{
	friend ostream& operator << (ostream& out, Article& person);      // 输出运算符重载
public:
	string number;
	string author;
	string name;
	string tag;
	string content;
	int status;	//审核的status //1 通过 -1 不通过 0 未审核

	Article& operator = (Article& person);                            // 赋值运算符重载
	bool operator == (Article& person);                               // 判断相等运算符重载
	void printfTable();
};