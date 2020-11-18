#include <iostream>
#include <sstream>
#include "List.h"
using namespace std;

enum frame {MainWindow, ReadersWindow, AuthorsWindow, AdminsWindow, ReviseSlect, AuthorsRead};

void showFrame(frame);				//框架页面
void addArticle(List* pList);		//增加文章
void printTable(int, List*);		//打印文章
void searchArticle(int, List*);		//文章查询
void deleteArticle(List* pList);	//文章删除
void reviseArticle(List* pList);	//文章修改
void verifyArticle(List* pList);	//文章审核
void ReadFile(List* pList);			//读入数据
void SaveFile(List* pList);			//存入数据

int main() {
	List list;
	ReadFile(&list);
	int auth;	//1.reader 2.author 3.admin
	int select, se;
	string pw;	//Admin password: Default 123456

	while (true) {
		mainwindow:
		showFrame(MainWindow);
		cin >> auth;
		system("cls");
		switch (auth) {
		case 1:		//读者入口
			readerwindow:
			system("cls");
			showFrame(ReadersWindow);
			cin >> select;
			system("cls");
			switch (select) {
			case 1:
				printTable(auth, &list);
				getchar();
				break;
			case 2:
				searchArticle(auth, &list);
				getchar();
				break;
			case 0:
				goto mainwindow;
			default:
				cout << "输入错误！" << endl;
				goto readerwindow;
			}
			goto readerwindow;
			break;
		case 2:		//作者入口
			authorwindow:
			showFrame(AuthorsWindow);
			cin >> select;
			system("cls");
			switch (select) {
			case 1:
				authorread:
				showFrame(AuthorsRead);
				cin >> se;
				system("cls");
				switch (se) {
				case 1:
					printTable(auth, &list);
					getchar();
					break;
				case 2:
					searchArticle(auth, &list);
					getchar();
					break;
				case 0:
					goto authorwindow;
				default:
					cout << "输入错误！" << endl;
					goto authorread;
				}
			case 0:
				goto mainwindow;
			default:
				cout << "输入错误！" << endl;
				goto authorwindow;
			}
			goto authorwindow;
			break;
		case 3:		//管理员入口
			cout << "请输入管理员密码（123456）：";
			while (cin >> pw) {
				if (pw == "exit")
					break;
				if (pw == "123456") {
					cout << "密码正确！按回车进入管理员页面";
					getchar();
					adminwindow:
					system("cls");
					showFrame(AdminsWindow);
					//管理员主体代码
					cin >> select;
					system("cls");
					switch (select) {
					case 1:
						verifyArticle(&list);
						getchar();
						break;
					case 2:
						deleteArticle(&list);
						getchar();
						break;
					case 3:
						SaveFile(&list);
						getchar();
						break;
					case 0:
						goto mainwindow;
					default:
						cout << "输入错误！" << endl;
						goto adminwindow;
					}
					goto adminwindow;
				}
				else
					cout << "密码错误！请重新输入密码或输入exit返回主菜单";
			}
			break;
		case 0:
			return 0;
		case '*':
			cout << "提示：" << endl;
			cout << "输入数字选择身份" << endl;
			cout << "读者身份可阅读或查询已审核文章" << endl;
			cout << "作者身份增加投稿、更新文章功能" << endl;
			cout << "管理员身份增加修改投稿状态功能" << endl;
		}
	}
	return 0;
}

void showFrame(frame f) {
	switch (f) {
	case MainWindow:
		cout << "    ▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅"								<< endl;
		cout << "   ▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅ "								<< endl;
		cout << " ▅▅▅▅▅                                              ▅▅▅▅▅  "		<< endl;
		cout << " ▅▅▅▅              文章阅读与投稿系统                  ▅▅▅▅  "			<< endl;
		cout << " ▅▅▅                                                      ▅▅▅  "	<< endl;
		cout << " ▅▅                  Press = 1  读者                         ▅▅  "	<< endl;
		cout << " ▅▅                  Press = 2  作者                         ▅▅  "	<< endl;
		cout << " ▅▅                  Press = 3  管理员                       ▅▅  "	<< endl;
		cout << " ▅▅▅                Press = 0  退出系统                   ▅▅▅  "		<< endl;
		cout << " ▅▅▅▅              Press = *  帮助                     ▅▅▅▅  "		<< endl;
		cout << " ▅▅▅▅▅                                              ▅▅▅▅▅  "		<< endl;
		cout << "   ▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅ "								<< endl;
		cout << "    ▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅"						<< endl << endl;
		break;
	case ReadersWindow:
		cout << "    ▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅" << endl;
		cout << "   ▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅ " << endl;
		cout << " ▅▅▅▅▅                                              ▅▅▅▅▅  " << endl;
		cout << " ▅▅▅▅              请选择文章的查询方式                ▅▅▅▅  " << endl;
		cout << " ▅▅▅                                                      ▅▅▅  " << endl;
		cout << " ▅▅                  Press = 1  作者姓名                     ▅▅  " << endl;
		cout << " ▅▅                  Press = 2  文章编号和文章标题           ▅▅  " << endl;
		cout << " ▅▅                  Press = 0  返回                         ▅▅  " << endl;
		cout << " ▅▅▅                                                      ▅▅▅  " << endl;
		cout << " ▅▅▅▅                                                  ▅▅▅▅  " << endl;
		cout << " ▅▅▅▅▅                                              ▅▅▅▅▅  " << endl;
		cout << "   ▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅ " << endl;
		cout << "    ▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅" << endl << endl;
		break;
	case AuthorsWindow:
		cout << "    ▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅" << endl;
		cout << "   ▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅ " << endl;
		cout << " ▅▅▅▅▅                                              ▅▅▅▅▅  " << endl;
		cout << " ▅▅▅▅                  作者身份功能                    ▅▅▅▅  " << endl;
		cout << " ▅▅▅                                                      ▅▅▅  " << endl;
		cout << " ▅▅                  Press = 1  阅读文章                     ▅▅  " << endl;
		cout << " ▅▅                  Press = 2  投稿文章                     ▅▅  " << endl;
		cout << " ▅▅                  Press = 3  修改文章                     ▅▅  " << endl;
		cout << " ▅▅▅                Press = 4  删除文章                   ▅▅▅  " << endl;
		cout << " ▅▅▅▅              Press = 0  返回                     ▅▅▅▅  " << endl;
		cout << " ▅▅▅▅▅                                              ▅▅▅▅▅  " << endl;
		cout << "   ▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅ " << endl;
		cout << "    ▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅" << endl << endl;
		break;
	case AdminsWindow:
		cout << "    ▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅" << endl;
		cout << "   ▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅ " << endl;
		cout << " ▅▅▅▅▅                                              ▅▅▅▅▅  " << endl;
		cout << " ▅▅▅▅                  管理员身份功能                  ▅▅▅▅  " << endl;
		cout << " ▅▅▅                                                      ▅▅▅  " << endl;
		cout << " ▅▅                  Press = 1  审核文章                     ▅▅  " << endl;
		cout << " ▅▅                  Press = 2  删除文章                     ▅▅  " << endl;
		cout << " ▅▅                  Press = 3  保存信息                     ▅▅  " << endl;
		cout << " ▅▅▅                Press = 0  返回                       ▅▅▅  " << endl;
		cout << " ▅▅▅▅                                                  ▅▅▅▅  " << endl;
		cout << " ▅▅▅▅▅                                              ▅▅▅▅▅  " << endl;
		cout << "   ▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅ " << endl;
		cout << "    ▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅" << endl << endl;
		break;
	case AuthorsRead:
		cout << "    ▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅" << endl;
		cout << "   ▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅ " << endl;
		cout << " ▅▅▅▅▅                                              ▅▅▅▅▅  " << endl;
		cout << " ▅▅▅▅              请选择文章的查询方式                ▅▅▅▅  " << endl;
		cout << " ▅▅▅                                                      ▅▅▅  " << endl;
		cout << " ▅▅                  Press = 1  全部输出                     ▅▅  " << endl;
		cout << " ▅▅                  Press = 2  文章编号和文章标题           ▅▅  " << endl;
		cout << " ▅▅                  Press = 0  返回                         ▅▅  " << endl;
		cout << " ▅▅▅                                                      ▅▅▅  " << endl;
		cout << " ▅▅▅▅                                                  ▅▅▅▅  " << endl;
		cout << " ▅▅▅▅▅                                              ▅▅▅▅▅  " << endl;
		cout << "   ▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅ " << endl;
		cout << "    ▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅▅" << endl << endl;
		break;
	default:
		cout << "输入错误！";
	}
}

void addArticle(List* pList){
	string s, temp;
	Node node;
	Article article;
	int i;
	cout << "请输入编号：";
	cin >> article.number;
	cout << "请输入文章名：";
	cin >> article.name;
	cout << "请输入文章作者：";
	cin >> article.author;
	cout << "请输入文章内容：";
	while (cin >> temp) {
		s += temp;
	}
	article.content = s;
	node.data = article;
	if (pList->ListInsertTail(&node))
		cout << "添加成功" << endl;
	else
		cout << "添加失败" << endl;
}

void printTable(int auth, List* pList) {
	Node node, ans;
	Article article;
	int i;
	cout << "请输入要查找的作者名:";
	cin >> article.author;
	node.data = article;
	i = pList->TraverseforElem(&node);
	if (i == 0)
		cout << "未找到此文章，或文章未通过审核，请再次确认您输入信息是否有误\n";
	else
		cout << "共找到" << i << "篇文章：\n";
	pList->ListTraverseSearch(&node);
}

void searchArticle(int auth, List* pList){
	Node node, ans;
	Article article;
	int i;
	cout << "请输入要查找文章编号和文章名:";
	cin >> article.name >> article.number;
	node.data = article;
	i = pList->LocateElem(&node);
	if (pList->ListGetElem(i, &ans))
		ans.printNode();
	else
		printf("未找到此文章，或文章未通过审核，请再次确认您输入信息是否有误\n");
}

void deleteArticle(List* pList){
	Node node;
	Article article;
	int i;
	cout << "请输入要删除的文章编号和文章名:";
	cin >> article.name >> article.number;
	node.data = article;
	i = pList->LocateElem(&node);
	if (pList->ListDelete(i, &node))
		cout << "删除文章" << article.number << ". " << article.name << "成功" << endl;
	else
		cout << "删除文章" << article.number << ". " << article.name << "失败" << endl;
}

void reviseArticle(List* pList) {
	Node node, ans;
	Article article;
	int i, select;
	string s, temp;
	cout << "请输入要修改的文章编号和文章名:";
	cin >> article.name >> article.number;
	node.data = article;
	i = pList->LocateElem(&node);
	if (pList->ListGetElem(i, &ans)) {
		ans.printNode();
		system("cls");
		showFrame(ReviseSlect);
		cin >> select;
		switch (select) {
		case 1:
			cin >> ans.data.number;
			break;
		case 2:
			cin >> ans.data.author;
			break;
		case 3:
			cin >> ans.data.tag;
			break;
		case 4:
			while (cin >> temp)
				s += temp;
			ans.data.content = s;
			break;
		default:
			cout << "输入错误！";
		}
	}
	else
		printf("未找到此文章，请再次确认您输入信息是否有误\n");
}

void verifyArticle(List* pList) {
	Node node, ans;
	Article article;
	int i, status;
	article.status = 0;
	node.data = article;
	i = pList->TraverseforElem(&node);
	if (i == 0)
		cout << "没有文章需要审核";
	else
		cout << "有" << i << "篇文章需要审核：";
	while (pList->TraverseforElem(&node) != 0) {
		i = pList->LocateElem(&node);
		pList->ListGetElem(i, &ans);
		cout << ans.data;
		cout << "审核结果（1表示通过，-1表示不通过）：";
		while (cin >> status) {
			if (status != 1 and status != -1)
				cout << "审核状态有误，请重新输入！";
			else
				break;
		}
		ans.data.status = status;
		pList->ListDelete(i, &node);
		pList->ListInsertTail(&ans);
	}
}

void ReadFile(List* pList){
	string s, temp;
	ifstream srcFile("article.txt", ios::in);
	Article article;
	Node node;
	while (srcFile >> article.number){
		srcFile >> article.author;
		srcFile >> article.tag;
		srcFile >> article.content;
		srcFile >> article.status;
		s.clear();
		temp.clear();
		node.data = article;
		pList->ListInsertTail(&node);
	}
	srcFile.close();
}

void SaveFile(List* pList){
	char file[30] = "article.txt";
	cout << file << endl;
	pList->ListSaveData(file);
}

