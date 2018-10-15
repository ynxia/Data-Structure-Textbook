//单循环链表的结构定义
typedef int DataType;
typedef struct node
{
	DataType data;
	struct node *link;
}CircNode, *CircList;

//双向链表的结构定义
typedef int DataType;
typedef struct node
{
	DataType data;
	struct node *rlink;
	struct node *llink;
}DblNode, *DblList;

//2.4.10 设有一个不带头结点、没有表头指针、只有表尾指针的单循环链表L，
//设计一个算法实现以下操作的时间复杂度为O(1)
//(1)在表尾结点后面插入新元素
//(2)删除首元结点（应在表尾结点后面）

//(1)
#include<iostream>
#include<stdlib>
#include"CirLink.h"
void InsertLink(CircNode* &rear, DataType x)
{
	CircNode *s = new CircNode;
	//robust
	if(s == NULL)
	{
		cerr << "存储分配错误" << endl;
		exit(1);
	}
	s -> data = x;
	s -> link = rear -> link;
	rear -> link = s;
	rear = s; //即rear = rear -> link;
};

//(2)
#include"CirLink.h"
int RemoveLink(CircNode* rear, DataType& x)
{
	if(raer == NULL)
	{
		return 0;
	}
	CircNode *s = rear -> link;
	rear -> link = s -> link;
	x = s -> data;
	delete s;
	return 1;
};

//2.4.11 设计一个算法，将一个带头结点的单循环链表中所有结点的链接方向逆转
//分析：该题是2.3.22的循环链表版
void ReverseLink(CircNode* L)
{
	CircNode *p, *q;
	//L形成新的循环链表，因此尾节点要指向自己
	p = L -> link; //p定位在循环链表的首元结点
	L -> link = L; //把链表的头结点的链接指针指向自己
	while(p != L)
	{
		q = p -> link; //保存p的下一个结点
		//将p链入新链表头结点后
		p -> link = L -> link;
		L -> link = p;
		p = q; //将p移到下一个结点
	}
}

//2.4.12 设有一个带头结点的非空双向循环链表L，指针p指向链表中第一个元素值为
//x的结点，设计一个算法，从链表中删除*p结点
int Remove(DblList L, DataType x)
{
	DblNode *p = L -> link;
	while(p != L && p -> data != x)
	{
		p = p -> link;
	}
	if(p == L)
	{
		return 0;
	}
	p -> llink -> rlink = p -> rlink;
	p -> rlink -> llink = p -> llink;
	delete p;
	return 1;
}

//2.4.13 设计一个算法，逆转带头结点的双向循环链表中所有结点的链接方向
void Reverse(DblList L)
{
	DblNode *p = L, *q;
	do{
		q = p -> rlink;
		//交换p两个链接指针所存的结点地址
		p -> rlink = p -> llink;
		p -> llink = q;
		
		p = q; //将p移到下一个结点
	}while(p != L);
};


