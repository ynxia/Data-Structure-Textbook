//用递归的方法搜索单链表最后一个结点的算法
LinkNode *FindRear(LinkNode *f)
{
	if(f == NULL)
	{
		return NULL;
	}
	else if(f -> link == NULL)
	{
		return f;
	}
	else
	{
		return FindRear(f -> link);
	}
};

//在以f为头指针的单链表中搜索其值等于给定值x的结点
void Search(LinkNode *f, T& x)
{
	if(f == NULL)
	{
		return;
	}
	else if(f -> data == x)
	{
		return f;
	}
	else
	{
		Search(f -> link, x);
	}
};

//求解n阶汉诺塔问题的算法
#include<iostream>
#include<string>
void Hanoi(int i, String A, String B, String C)
{
	if(n == 1)
	{
		cout << "Move top disk from peg" << A << "to peg" << C << endl;
	}
	else
	{
		Hanoi(n-1, A, C, B);
		cout << "Move top disk from peg" << A << "to peg" << C << endl;
		Hanoi(n-1, B, A, C);
	}
};
