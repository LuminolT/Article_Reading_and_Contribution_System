#include "Article.h"



ostream& operator<<(ostream& out, Article& article){
	out << "文章编号：";
	out << article.number << endl;
	out << "文章作者：";
	out << article.author << endl;
	out << "文章标签：";
	out << article.tag << endl;
	out << "文章内容：" << endl;
	out << article.content << endl;
	return out;
}

//赋值运算符重载
Article& Article::operator=(Article& article){
	this->number = article.number;
	this->author = article.author;
	this->tag = article.tag;
	this->content = article.content;
	return *this;
}

//关系运算符重载，用于查找功能的实现（编号或名字相同）
bool Article::operator==(Article& article){
	if (this->author == article.author) {
		return true;
	}
	if (this->number == article.number){
		return true;
	}
	if (this->name == article.name){
		return true;
	}
	return false;
}

void Article::printfTable() {
	cout << setw(12) << this->number;
	cout << setw(6)	 <<	this->author;
	cout << setw(6)	 << this->tag;
	cout << (this->status == 1) ? "已通过":((this->status == -1) ? "未通过" : "未审核");
}