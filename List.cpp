#include "List.h"
List::List(){
	m_pList = new Node;
	// m_pList->data = 0;
	m_pList->next = NULL;
	m_iLength = 0;
}

bool List::ListEmpty(){
	if (m_iLength == 0){
		return true;
	}
	else{
		return false;
	}
}

void List::ClearList(){
	Node* currentNode = m_pList->next; // 指向头指针后第一个元素
	while (currentNode != NULL){
		Node* temp = currentNode->next;
		delete currentNode;
		currentNode = temp;
	}
	m_pList->next = NULL;               // 头指针下一个为空

}

List::~List(){
	ClearList();
	delete m_pList;
	m_pList = NULL;
}

bool List::ListInsertHead(Node* pNode){
	Node* temp = m_pList->next;            // 头节点后第一个元素
	Node* newNode = new Node;              // 创建一个新的节点
	if (newNode == NULL)
		return false;
	newNode->data = pNode->data;
	m_pList->next = newNode;
	newNode->next = temp;
	m_iLength++;
	return true;
}

bool List::ListInsertTail(Node* pNode){
	Node* currentNode = m_pList;
	while (currentNode->next != NULL)
		currentNode = currentNode->next;   // 遍历到尾结点
	Node* newNode = new Node;
	if (newNode == NULL)
		return false;
	newNode->data = pNode->data;
	newNode->next = NULL;
	currentNode->next = newNode;
	m_iLength++;
	return true;
}

bool List::ListInsert(int i, Node* pNode){
	if (i<0 || i>m_iLength)
		return false;
	Node* currentNode = m_pList;
	for (int k = 0; k < i; k++){
		currentNode = currentNode->next;
	}
	Node* newNode = new Node;
	if (newNode == NULL)
		return false;
	newNode->data = pNode->data;
	newNode->next = currentNode->next;
	currentNode->next = newNode;
	m_iLength++;
	return true;
}

bool List::ListDelete(int i, Node* pNode){
	if (i < 0 || i >m_iLength)
		return false;
	Node* currentNode = m_pList;
	Node* currentNodeBefore = NULL;
	for (int k = 0; k <= i; k++){
		currentNodeBefore = currentNode;
		currentNode = currentNode->next;
	}
	currentNodeBefore->next = currentNode->next;
	pNode->data = currentNode->data;
	delete currentNode;
	currentNode = NULL;
	m_iLength--;
	return true;
}

bool List::ListGetElem(int i, Node* pNode){
	if (i < 0 || i >m_iLength)
		return false;
	Node* currentNode = m_pList;
	for (int k = 0; k <= i; k++){
		currentNode = currentNode->next;
	}
	pNode->data = currentNode->data;
	return true;
}

int List::LocateElem(Node* pNode){
	Node* currentNode = m_pList;
	int count = 0;
	while (currentNode->next != NULL){
		currentNode = currentNode->next;
		if (currentNode->data == pNode->data){
			return count;
		}
		count++;
	}
	return -1;
}

bool List::PrevElem(Node* pCurrentNode, Node* pPreNode){
	Node* currentNode = m_pList;
	Node* tempNode = NULL;
	while (currentNode->next != NULL){
		tempNode = currentNode;
		currentNode = currentNode->next;
		if (currentNode->data == pCurrentNode->data){
			if (tempNode == m_pList)
				return false;
			else{
				pPreNode->data = tempNode->data;
				return true;
			}

		}
	}
	return false;
}

bool List::NextElem(Node* pCurrentNode, Node* pNextNode){
	Node* currentNode = m_pList;
	while (currentNode->next != NULL){
		currentNode = currentNode->next;
		if (currentNode->data == pCurrentNode->data){
			if (currentNode->next == NULL){
				return false;
			}
			else{
				pNextNode->data = currentNode->next->data;
				return true;
			}

		}
	}
	return false;
}

void List::ListTraverse(){
	Node* currentNode = m_pList;
	while (currentNode->next != NULL){
		currentNode = currentNode->next;
		currentNode->printNode();
	}
}

int List::TraverseforElem(Node* pNode) {
	Node* currentNode = m_pList;
	int count = 0;
	int cnt = 0;
	while (currentNode->next != NULL) {
		currentNode = currentNode->next;
		if (currentNode->data == pNode->data) {
			cnt++;
		}
		count++;
	}
	return cnt;
}

void List::ListSaveData(char* file){
	ofstream destFile(file, ios::app);
	Node* currentNode = m_pList;
	while (currentNode->next != NULL){
		currentNode = currentNode->next;
		destFile << currentNode->data;
	}
	destFile.close();
}

void List::ListTraverseSearch(Node* pNode) {
	Node* currentNode = m_pList;
	while (currentNode->next != NULL) {
		if (currentNode->data == pNode->data) {
			currentNode->data.printfTable();
			cout << endl;
		}
		currentNode = currentNode->next;
		currentNode->printNode();
	}
}