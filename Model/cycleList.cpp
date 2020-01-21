#include <iostream>
#include <stdlib.h>
using namespace std;
 
//结点类
class Node {
public:
	int data;
	Node *pNext;
};
//单向循环链表类
class CircularLinkList {
public:
	CircularLinkList() {
		head = new Node;
		head->data = 0;
		head->pNext = head;
	}
	~CircularLinkList() {delete head;}
	void CreateLinkList(int n);				//创建单向循环链表
	void InsertNode(int position, int d);	//在指定位置插入结点
	void TraverseLinkList();				//遍历链表
	bool IsEmpty();							//判断链表是否为空
	int GetLength();						//得到链表的长度
	void DeleteNode(int position);			//删除指定位置结点
	void DeleteLinkList();					//删除链表
private:
	Node *head;
};
 
void CircularLinkList::CreateLinkList(int n) {
	if (n < 0) {
		cout << "输入结点个数错误！" << endl;
		exit(EXIT_FAILURE);
	}
	else {
		Node *pnew, *ptemp = head;
		int i = n;
		while (n-- > 0) {
			cout << "输入第" << i - n << "个结点值：";		
			pnew = new Node;
			cin >> pnew->data;
			pnew->pNext = head;
			ptemp->pNext = pnew;
			ptemp = pnew;	
		}	
	}
}
 
void CircularLinkList::InsertNode(int position, int d) {
	if (position < 0 || position > GetLength() + 1) {
		cout << "输入位置错误！" << endl;
		exit(EXIT_FAILURE);
	}
	else {
		Node *pnew, *ptemp = head;
		pnew = new Node;
		pnew->data = d;
		while (position-- > 1)
			ptemp = ptemp->pNext;
		pnew->pNext = ptemp->pNext;
		ptemp->pNext = pnew;
	}
}
 
void CircularLinkList::TraverseLinkList() {
	Node *ptemp = head->pNext;
	while (ptemp != head) {
		cout << ptemp->data << " ";
		ptemp = ptemp->pNext;
	}
	cout << endl;
}
 
bool CircularLinkList::IsEmpty() {
	if (head->pNext == head)
		return true;
	else
		return false;
}
 
int CircularLinkList::GetLength() {
	int n = 0;
	Node *ptemp = head->pNext;
	while (ptemp != head) {
		n++;
		ptemp = ptemp->pNext;
	}
	return n;
}
 
void CircularLinkList::DeleteNode(int position) {
	if (position < 0 || position > GetLength()) {
		cout << "输入位置错误！" << endl;
		exit(EXIT_FAILURE);
	}
	else {
		Node *ptemp = head, *pdelete;
 
		while (position-- > 1)
			ptemp = ptemp->pNext;
		pdelete = ptemp->pNext;
		ptemp->pNext = pdelete->pNext;
		delete pdelete;
		pdelete = NULL;
	}
}
 
void CircularLinkList::DeleteLinkList() {
	Node *pdelete = head->pNext, *ptemp;
	while (pdelete != head) {
		ptemp = pdelete->pNext;
		head->pNext = ptemp;
		delete pdelete;
		pdelete = ptemp;
	}
}
 
//测试函数
int main() {
 
	CircularLinkList cl;
	int position = 0, value = 0, n = 0;
	bool flag = false;
 
	cout << "请输入需要创建单向循环链表的结点个数：";
	cin >> n;
	cl.CreateLinkList(n);
 
	cout << "打印链表值如下：";
	cl.TraverseLinkList();
 
	cout << "请输入插入结点的位置和值：";
	cin >> position >> value;
	cl.InsertNode(position, value);
	
	cout << "打印链表值如下：";
	cl.TraverseLinkList();
 
	cout << "请输入要删除结点的位置：";
	cin >> position;
	cl.DeleteNode(position);
 
	cout << "打印链表值如下：";
	cl.TraverseLinkList();
 
	cl.DeleteLinkList();
	flag = cl.IsEmpty();
	if (flag)
		cout << "删除链表成功！" << endl;
	else
		cout << "删除链表失败！" << endl;
 
	return 0;
}
