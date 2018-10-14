// 循环链表的类定义
template<class T>
struct CircLinkNode{
	T data;
	CircLinkNode<T>* link;
	CircLinkNode(CircLinkNode<T>* next = NULL):link(next){}
	CircLinkNode(T d, CircLinkNode<T>* next = NULL):data(d), link(next){}
};

template<class T>
class CircList:public LinearList<T>{
public:
	CircList(const T& x);
	CircList(CircList<T>& L);
	~CircList();
	int Length() const;
	bool IsEmpty()
	{
		return first -> link == first ? true:false;
	}
	CircLinkNode<T>* getHead() const;
	void setHead(CircLinkNode<T>* p);
	CircLinkNode<T> *Search(T x);
	CircLinkNode<T> *Locate(int i);
	T *getData(int i, T& x);
	void setData(int i, T& x);
	bool Insert(int i, T& x);
	bool Remove(int i, T& x);
private:
	CircLinkNode<T> *first, *last; //头指针，尾指针
};

//使用循环链表求解Josephus的算法
#include<iostream>
#include"CircList.h"
template<class T>
void Josephus(CircList<T>& Js, int n, int m)
{
	//n作为人的总数，m作为报数值
	CircLinkNode<T>* p = Js.Locate(1);
	CircLinkNode<T>* pre = NULL;
	int i, j;
	for(int i = 0; i < n - 1; i++) //执行n-1次
	{
		for(j = 1; j < m; j++) //数m-1个人
		{
			pre = p;
			p = p -> link;
		}
		cout << "出列的人是" << p -> data << endl;
		pre -> link = p -> link; //先保存p的下一个节点
		delete p; // 删除p
		p = pre -> link; //将p移到p的下一个节点上
	}
};

void main()
{
	CircList<int> clist;
	int i, n, m;
	cout << "输入游戏者人数和报数间隔：";
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		clist.Insert(i);
	}
	Josephus(clist, n, m);
};
