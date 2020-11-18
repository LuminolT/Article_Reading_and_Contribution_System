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
	~List();		//����
	void ClearList();										// �����������
	bool ListEmpty();										// �ж������Ƿ�Ϊ��
	bool ListInsertHead(Node* pNode);						// ͷ������һ���ڵ�
	bool ListInsertTail(Node* pNode);						// β������һ���ڵ�
	bool ListInsert(int i, Node* pNode);					// ������λ�ò���ڵ�
	bool ListDelete(int i, Node* pNode);					// ������λ��ɾ�����
	bool ListGetElem(int i, Node* pNode);					// ���ҵ�i��Ԫ��
	int  LocateElem(Node* pNode);							// ���ҽ���λ��
	bool PrevElem(Node* pCurrentNode, Node* pPreNode);		// ��ָ���ǰ��ָ��
	bool NextElem(Node* pCurrentNode, Node* pNextNode);		// ��ָ��ĺ��ָ��
	void ListTraverse();									// ����ı���
	void ListSaveData(char* file);							// ���������ݱ��浽�ļ���
	int TraverseforElem(Node* pNode);						// Ѱ�ҷ��������Ľڵ�����
	void ListTraverseSearch(Node*);
};