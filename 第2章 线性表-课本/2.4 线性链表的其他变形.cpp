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

//双向链表

//带附加头结点的双向循环链表的类定义
template<class T>
struct DblNode{
	T data;
	DblNode<T> *lLink, *rLink;
	DblNode(DblNode<T> *left = NULL, DblNode<T> *right = NULL):data(value), lLink(left), rLink(right){} //构造函数
}；

template<class T>
class DblList:public LinearList<T>{
public:
	DblList(T uniqueVal); //建立附加头结点
	~DblList();
	int Length() const;
	bool IsEmpty()
	{
		return first -> rlink == first; //空的双向循环链表头结点指向自己则为空
	}
	DblNode<T> *getHead() const{ //获取头结点地址
		return first;
	}
	void setHead(DblNode<T> *ptr)
	{
		first = ptr;
	}
	DblNode<T> *Search(const T& x);
	DblNode<T> Locate(int i, int d); //在链表中定位序号为i的节点，其中d=0表示前驱方向，d!=0表示后继方向
	bool Insert(int i, const T& x, int d);
	bool Remove(int i, T& x, int d);
private:
	DblNode<T> *first;
};

template<class T>
DblList<T>::DblList(T uniqueVal){
	//构造函数，建立双向链表的附加头结点，它包含了一个用于某些特定情况的值
	first = new DblNode<T>(uniqueVal);
	if(first == NULL)
	{
		cerr << "存储分配错误" << endl;
		exit(1);
	}
	first -> lLink = first -> rLink = first; //双向链表头结点均指向自己
};

template<class T>
int DblList<T>::Length() const{
	//计算双向链表的长度
	DblNode<T> *current = first -> rLink;
	int count = 0;
	while(current != first)
	{
		current = current -> rLink;
		count++;
	}
	return count;
};

//双向链表的搜索、插入和删除算法

//搜索算法的实现，返回节点的地址
template<class T>
DblNode<T> *DblList<T>::Search(const T& x)
{
	DblNode<T>* current = first -> rLink;
	while(current != first && current -> data != x)
	{
		current = current -> rLink;
	}
	if(current != first)
	{
		return current;
	}
	else
	{
		return NULL;
	}
};

//定位运算的实现
template<class T>
DblNode<T>* DblList<T>::Locate(int i, int d){
	if(first -> rLink == first || i = 0)
	{
		return first;
	}
	DblNode<T>* current;
	if(d == 0)
	{
		current = first -> lLink;
	}
	else
	{
		current = first -> rLink;
	}
	for(j = 1; j < i; j++)
	{
		if(current == first) break; //链太短退出搜索
		else if(d == 0)
		{
			current = current -> lLink；
		}
		else{
			current = current => rLink;
		}
	}
	if(current != first)
	{
		return current;
	}
	else
	{
		return NULL;
	}
};

//插入算法的实现
template<class T>
bool DblList<T>::Insert(int i, const T& x, int d)
{
	//建立一个包含有值x的新节点，并将其按照d的方向插入到双向循环链表中
	DblNode<T>* current(i, d);
	if(current == NULL)  //i不合理，插入失败
	{
		return false;
	}
	DblNode *newNode = new DblNode<T>(x);
	if(newNode == NULL)
	{
		cerr << "存储分配错误" << endl;
		exit(1);
	}
	//d=0与d=1的情况分类讨论
	if(d == 0) // 前驱方向插入
	{
		//先向左
		newNode -> lLink = current -> lLink;
		current -> lLink = newNode;
		//再向右
		newNode -> lLink -> rLink = newNode;
		newNode -> rLink = current;
	}
	else
	{
		//先向右
		newNode -> rLink = current -> rLink;
		current -> rLink = newNode;
		//再向左
		newNode -> rLink -> lLink = newNode;
		newNode -> lLink = current;
	}
	return true;
};

//删除运算的实现
template<class T>
bool DblList<T>::Remove(int i, const T& x, int d)
{
	DblNode<T> *current = Locate(i, d);
	if(current == NULL)
	{
		cerr << "存储分配错误" << endl;
		exit(1);
	}
	//记得要保存数据
	current -> rLink -> lLink = current -> lLink;
	current -> lLink -> rLink = current -> rLink;
	x = current -> data;
	return true;
};