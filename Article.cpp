#include "Article.h"



ostream& operator<<(ostream& out, Article& article){
	out << "���±�ţ�";
	out << article.number << endl;
	out << "�������ߣ�";
	out << article.author << endl;
	out << "���±�ǩ��";
	out << article.tag << endl;
	out << "�������ݣ�" << endl;
	out << article.content << endl;
	return out;
}

//��ֵ���������
Article& Article::operator=(Article& article){
	this->number = article.number;
	this->author = article.author;
	this->tag = article.tag;
	this->content = article.content;
	return *this;
}

//��ϵ��������أ����ڲ��ҹ��ܵ�ʵ�֣���Ż�������ͬ��
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
	cout << (this->status == 1) ? "��ͨ��":((this->status == -1) ? "δͨ��" : "δ���");
}