#pragma once
#include"Node.h"
#include<fstream>
using namespace std;
class List{
private:
	Node* m_pList;
	int m_iLength;

public:
	List();
	~List();		//析构
	void ClearList();										// 清空整个链表
	bool ListEmpty();										// 判断链表是否为空
	bool ListInsertHead(Node* pNode);						// 头部插入一个节点
	bool ListInsertTail(Node* pNode);						// 尾部插入一个节点
	bool ListInsert(int i, Node* pNode);					// 从任意位置插入节点
	bool ListDelete(int i, Node* pNode);					// 从任意位置删除结点
	bool ListGetElem(int i, Node* pNode);					// 查找第i个元素
	int  LocateElem(Node* pNode);							// 查找结点的位序
	bool PrevElem(Node* pCurrentNode, Node* pPreNode);		// 找指针的前驱指针
	bool NextElem(Node* pCurrentNode, Node* pNextNode);		// 找指针的后继指针
	void ListTraverse();									// 链表的遍历
	void ListSaveData(char* file);							// 将链表数据保存到文件中
	int TraverseforElem(Node* pNode);						// 寻找符合条件的节点数量
	void ListTraverseSearch(Node*);
};