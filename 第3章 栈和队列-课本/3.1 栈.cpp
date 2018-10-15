//栈的类定义
const int maxSize = 50;
enum bool{false, true};
template<typename T>
class Stack{
public:
	Stack(){};
	virtual void Push(const T& x) = 0;
	virtual bool Pop(T& x) = 0;
	virtual bool getTop(T& x) const = 0;
	virtual bool IsEmpty() const = 0;
	virtual bool IsFull() const = 0;
	virtual int getSize() const = 0;
};

//顺序栈的类定义
#include<assert>
#include<iostream>
#include"stack.h"
const int stackIncreament = 20; //栈溢出时扩展空间的增量
template<typename T>
class SeqStack:public Stack<T>{
public:
	SeqStack(int sz = 50); //建立一个空栈
	~SeqStack()
	{
		delete []elements;
	}
	void Push(const T& x);
	//如果IsFull()，则溢出处理；否则把x插入到栈的栈顶
	bool Pop(T& x);
	//如果IsEmpty(),则返回false，否则返回true，并通过引用参数x得到栈顶元素的值
	bool getTop(T& x);
	bool IsEmpty() const
	{
		//如果栈中元素等于maxSize，返回true，否则返回false
		return (top == - 1) ? true : false;
	}
	bool IsFull() const
	{
		return (top == maxSize - 1) ? true : false;
	}
	int getSize() const //top总0开始计算
	{
		return top + 1;
	}
	void MakeEmpty()
	{
		top = -1;
	}
	friend ostream& operator<<(ostream& os, SeqStack<T>& s);
private:
	T *elements; //存放栈中元素的栈数组
	int top; //栈顶指针
	int maxSize; //栈最大可容纳元素个数
	void overflowProcess(); //栈的溢出处理
};

//顺序栈的构造函数
template<typename T>
SeqStack<T>::SeqStack(int sz):top(-1), maxSize(sz)
{
	//创建一个最大尺寸为sz的空栈，若分配不成功则错误处理
	elements = new T[maxSize];
	assert(elements != NULL); //断言：动态存储分配成功与否
};

//私有函数：扩充栈的存储空间
template<typename T>
void SeqStack<T>::overflowProcess()
{
	T *newArray = new T[maxSize + stackIncreament];
	if(newArray == NULL)
	{
		cerr << "存储分配失败" << endl;
		exit(1); //int时：return 0; void时：exit(1);
	}
	for(int i = 0; i <= top; i++)
	{
		newArray[i] = elements[i];
	}
	maxSize = maxSize + stackIncreament;
	delete []elements; //先删再建
	elements = newArray;
};

template<typename T>
void SeqStack<T>::Push(const T& x)
{
	//公共函数：若栈不满，则将元素x插入到该栈的栈顶，否则溢出处理
	if(IsFull() == true)
	{
		overflowProcess(); //栈满则溢出处理
	}
	elements[++top] = x; //栈顶指针先加一，再进栈
};

template<typename T>
bool SeqStack<T>::Pop(T& x)
{
	//公共函数，若栈不空则函数返回该栈的栈顶元素的值，然后栈顶指针退1
	if(IsEmpty() == true)
	{
		return false;
	}
	x = elements[top--];
	return true;
};

template<typename T>
bool SeqStack<T>::getTop(T& x)
{
	//公共函数，若栈不空则函数返回该栈栈顶元素的地址
	if(IsEmpty() == true)
	{
		return false;
	}
	x = elements[top]; //返回栈顶元素的值
	return true;
};

template<typename T>
ostraem& operator<<(ostream& os, SeqStack<T>& s)
{
	//输出栈中元素的重载操作
	os << "top = " << s.top << endl; //输出栈顶位置
	for(int i = 0; i <= s.top; i++)
	{
		os << i << ":" << s.elements[i] << endl;
	}
	return os;
};

//链式栈的类定义
#include<iostream>
#include<LinkedList.h>
#include"stack.h"
template<typename T>
class LinkedStack:public Stack<T>
{
public:
	LinkedStack():top(NULL){}   //构造函数，置空栈
	~LinkedStack()
	{
		makeEmpty();
	}
	void Push(const T& x); //进栈
	bool Pop(T& x); //退栈
	bool getTop(T& x) const; //读取栈顶元素
	bool IsEmpty() const
	{
		return (top == NULL) ? true : false;
	}
	int getSize() const;
	void makeEmpty();
	friend ostream& operator<<(ostream& os, SeqStack<T>& s);
	//输出栈中元素的重载操作
private:
	LinkNode<T> *top; //栈顶指针，即链表头指针
};

template<typename T>
LinkedStack<T>::makeEmpty()
{
	LinkNode<T> *p;
	while(top != NULL)
	{
		p = top;
		top = top -> link;
		delete p;
	}
};

//