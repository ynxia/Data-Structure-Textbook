//用C++类描述队列的抽象数据类型
const int maxSize = 50;
enum bool{false, true};
template<typename T>
class Queue{
public:
	Queue(){};
	~Queue(){};
	virtual void EnQueue(const T& x) = 0; //新元素x进队列
	virtual bool DeQueue(T& x) = 0; //队头元素出队列
	virtual bool getFront(T& x) = 0; //读取队头元素的值
	virtual bool IsEmpty() const = 0;
	virtual bool IsFull() const = 0;
	virtual int getSize() const = 0; //求队列元素个数
};

//循环队列
//队头指针进1
front = (front + 1) % maxSize;
//队尾指针进1
rear = (rear + 1) % maxSize;

//循环队列的类定义
#include<assert>
#include<iostream>
#include"Queue.h"
template<typename T>
class SeqQueue:public Queue<T>
{
public:
	SeqQueue(int sz = 10);
	~SeqQueue()
	{
		delete []elements;
	}
	bool EnQueue(const T& x);
	bool DeQueue(T& x);
	bool getFront(T& x);
	void makeEmpty()
	{
		front = rear = 0;
	}
	bool IsEmpty() const
	{
		return (front == rear) ? true : false;
	}
	bool IsFull() const
	{
		return ((rear+1) % maxSize == front) ? true : false;
	}
	int getSize() const
	{
		//求队列元素个数
		return (rear - front + maxSize) % maxSize;
	}
	friend ostream& operator<<(ostream& os, SeqQueue<T>& Q);
protected:
	int rear, front; //队尾与队头指针
	T* elements; //存放队列元素的数组
	int maxSize; //最大可容纳元素个数
};

template<typename T>
SeqQueue<T>::SeqQueue(int sz):front(0), rear(0), maxSize(sz)
{
	//建立一个最大具有maxSize个元素的空队列
	elements = new T[maxSize];
	assert(elements != NULL); //断言：动态存储分配成功与否
};

template<typename T>
bool SeqQueue<T>::EnQueue(const T& x)
{
	//若队列不满，则将元素x插入到该队列的队尾，否则出错处理
	if(IsFull() == true)
	{
		retur false;
	}
	elements[rear] = x; //按照队尾指针指示位置插入
	rear = (rear + 1) % maxSize; //队尾指针加一
	return true;
};

template<typename T>
bool SeqQueue<T>::DeQueue(T& x)
{
	//若队列不为空则函数退掉一个队头元素并返回true，否则返回false
	if(IsEmpty() == true)
	{
		return false;
	}
	x = elements[front];
	front = (front + 1) % maxSize; //退掉第一个元素
	return true;
}

template<typename T>
bool SeqQueue<T>::getFront(T& x) const
{
	//若队列不为空则函数返回该队列队头元素的值
	if(IsEmpty() == true)
	{
		return false;
	}
	x = elements[front];
	return true;
};

template<typename T>
ostream& operator<<(ostream& os, SeqQueue<T>& Q)
{
	//输出栈中元素的重载操作
	os << "front=" << Q.front << ", raer=" << Q.rear << endl;
	for(int i = front; i != rear; i = (i + 1) % maxSize)
	{
		os << i << ":" << Q.elements[i] << endl;
	}
	return os;
};

//链式队列的类定义及其成员函数的实现
#include<iostream>
#include"LinkedList.h"
#include"Queue.h"
template<typename T>
class LinkedQueue:public Queue<T>
{
public:
	LinkedQueue():raer(NULL), front(NULL){} //构造函数，建立空队列
	~LinkedQueue()
	{
		makeEmpty();
	}
	bool EnQueue(const T& x); //将x插入队列中
	bool DeQueue(T& x);
	bool getFront(T& x) const;
	void makeEmpty();
	bool IsEmpty() const
	{
		return (front == NULL) ? true : false;
	}
	int getSize() const;
	friend ostream& operator<<(operator& os, LinkedQueue<T>& Q);
protected:
	LinkNode<T> *rear, *front;
};

template<typename T>
void LinkedQueue<T>::makeEmpty()
{
	//逐个删除结点
	LinkNode<T> *p;
	while(front != NULL)
	{
		p = front;
		front = front -> link;
		delete p;
	}
};

template<typename T>
bool LinkedQueue<T>::EnQueue(const T& x)
{
	//将新元素x插入到队列的队尾（链式队列的队尾）
	if(front == NULL)
	{
		//是空链表则创建链表，创建完之后再一次检查NULL表示检查存储空间分配是否正确
		front = rear = new LinkNode<T>(x);
		if(front == NULL)
		{
			return false;
		}
	}
	else
	{
		rear -> link = new LinkNode<T>(x); //尾部追加结点
		if(rear -> link == NULL)
		{
			return false;
		}
		rear = rear -> link;
	}
	return true;
};

template<typename T>
bool LinkedQueue<T>::DeQueue(T& x)
{
	//DeQueue表示delete
	if(IsEmpty() == true)
	{
		return false;
	}
	LinkNode<T> *p = front;
	x = font -> link;
	front = front -> link;
	delete p;
	return true;
};

template<typename T>
bool LinkedQueue<T>::getFront(T& x) const
{
	if(IsEmpty() == true)
	{
		return false;
	}
	x = front -> data;
	return true;
};

template<typename T>
int LinkedQueue<T>::getSize() const
{
	LinkNode<T> *p = front;
	int k = 0;
	while(p != NULL)
	{
		p = p -> link;
		k++;
	}
	return k;
};

template<typename T>
ostream& operator<<(ostream& os, LinkedQueue<T>& Q)
{
	os << "队列中的元素个数有" << Q.getSize() << endl;
	LinkNode<T> *p = Q.front;
	nt i = 0;
	while(p != NULL)
	{
		os << ++i << ":" <<p -> data << endl;
		p = p -> link;
	}
	return os;
};

//一般情况下，逐行处理数据的情况都少不了使用队列作为辅助工具
#include<stdio>
#include<iostream>
#include"queue.h"
void YANGVI(int n) //n表示行数
{
	Queue q(n + 1);
	int i = 1, j, s = k = 0, t, u;
	//先放入两个初始元素1
	q.EnQueue(i);
	q.EnQueue(i);
	for(i = 1; i <= n; i++)
	{
		cout << endl;
		q.EnQueue(k);
		for(j = 1; j <= i + 2; j++) //处理第i行的i + 2个系数
		{
			q.DeQueue(t);
			u = s + t;
			q.EnQueue(u);
			s = t;
			if(j != i + 2)
			{
				cout << s << '';
			}
		}
	}
};