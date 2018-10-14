// 单链表的类定义
// (1)复合类
class List; //List的前置声明

class LinkNode{
friend class List;
private:
	int data;
	LinkNode* link;
};

class List{
public:
	//链表的公共操作
private:
	LinkNode* first;
};

// (2)嵌套类
class List{
public:
	//链表操作
private:
	class LinkNode{
	public:
		int data;
		LinkNode* link;
	};
	LinkNode* first;
};

// (3)基类和派生类
class LinkNode{
protected:
	int data;
	LinkNode* link;
};

class List:public class LinkNode{
private:
	LinkNode* first;
public:
	//链表操作
};

// (4)用struct定义LinkNode类
struct LinkNode{
	int data;
	LinkNode* link;
};

class List{
private:
	LinkNode* first;
public:
	//链表操作
};

//没有头节点的单链表的插入和删除

//单链表的插入算法
bool List::Insert(int i, int& x)
{
	//将新元素x插入到第i个节点之后。i从一开始，i=0表示插入到第一个节点之前
	if(first == NULL || i == 0)
	{
		LinkNode* newNode = new LinkNode(x);
		if(newNode == NULL)
		{
			cerr  << "存储分配错误" << endl;
			exit(1);
		}
		newNode -> link = first;
		first = newNode;
	}
	else
	{
		LinkNode* current = first;
		//循链找到第i个结点，循环结束即找到第i个结点
		for(k = 1; k < i; k++) 
		{
			if(current == NULL)
			{
				break;
			}
			else
			{
				current = current -> link;
			}
		}
		if(current == NULL)
		{
			cerr << "无效的插入位置" << endl;
			return false;
		}
		else
		{
			LinkNode* newNode = new LinkNode(x);
			if(newNode == NULL)
			{
				cerr << "存储分配错误" << endl;
				exit(1);
			}
			newNode -> link = current -> link;
			current -> link = newNode;
		}
	}
	return true;
};

// 单链表的删除算法
bool List::Remove(int i, int& x)
{
	//将链表中第i个元素删去，i从1开始、
	if(i <= 1)
	{
		del = first; //删去首节点
		first = first -> link;
	}
	else
	{
		current = first;
		// 找到第i个结点
		for(int k = 0; k < i; k++)
		{
			if(current == NULL)
			{
				break;
			}
			else
			{
				current = current -> link;
			}
		}
		if(current == NULL)
		{
			cerr << "无效的删除位置" << endl;
			exit(1);
		}
		del = current -> link;
		current -> link = del -> link;
	}
	//取出被删除结点的值
	x = del -> data;
	delete del;
	return true;
}

// 带附加头结点的单链表的插入算法
newNode -> link = current -> link;
current -> link = newNode;
// 带附加头结点的单链表的删除算法
del = current -> link;
current -> link = del -> link;
delete del;

//带附加头结点的单链表的类定义
template<class T>
struct LinkNode{
	T data;
	LinkNode<T>* link;
	LinkNode(LinkNode<T>* ptr = NULL) //仅初始化指针成员的构造函数
	{
		link = ptr;
	}
	LinkNode(const T& item, LinkNode<T>* ptr = NULL)
	{
		data = item;
		link = ptr;
	}
};

template<class T>
class List:public LinearList<T>
{
public:
	List()
	{
		first = new LinkNode<T>;
	}
	List(const T& x)
	{
		first = new LinkNode<T>(x);
	}
	List(List<T>& L);
	~List()
	{
		makeEmpty();
	}
	void makeEmpty();
	int Length() const;
	LinkNode<T> *getHead() const //返回附加头结点地址
	{
		return first;
	}
	LinkNode<T> *Search(T x);
	LinkNode<T> *Locate(int i);
	bool getData(int i, T& x) const;
	void setData(int i, T& x);
	bool Insert(int i, T& x);
	bool Remove(int i, T& x);
	bool IsEmpty() const
	{
		return first -> link == NULL ? true:false;
	}
	bool IsFull() const
	{
		return false;
	}
	void Sort();
	void input();
	void output();
	List<T>& operator=(List<T>& L);
protected:
	LinkNode<T> *first;
};

//复制构造函数
template<class T>
List<T>&::List(List<T>& L)
{
	T value;
	LinkNode<T>* sourceptr = L.getHead(); //源链表的头结点
	LinkNode<T>* targetptr = new LinkNode<T>; //目标链表的头结点
	while(sourceptr -> link != NULL) 下一个节点非空时
	{
		value = sourceptr -> link -> data; //记录数据
		targetptr -> link = new LinkNode<T>(value); //目标链表添加一个带有value值的新节点
		targetptr = targetptr -> link;
		sourceptr = sourceptr -> link;
	}
	targetptr -> link = NULL; //给目标链表的尾节点增加NULL
};

// 将链表置为空表
template<class T>
void List<T>::makeEmpty()
{
	LinkNode* q;
	while(first -> link != NULL)
	{
		q = first -> link;
		first -> link = q -> link;
		delete q;
	}
};

// 计算带附加头结点的单链表的长度
template<class T>
int List<T>::Length)() const
{
	LinkNode<T> *p = first -> link;
	int count = 0;
	while(p != NULL)
	{
		p = p -> link;
		count++;
	}
	return count;
};

//在表中搜索含数据x的节点，搜索成功时返回该节点地址，否则返回NULL
template<class T>
LinkNode<T>* List<T>::Search(T x)
{
	LinkNode<T>* current = first -> link;
	while(current != NULL)
	{
		if(current -> data == x)
		{
			break;
		}
		else
		{
			current = current -> link;
		}
	}
	return current;
};

//定位函数，返回表中第i个元素的地址
template<class T>
LinkNode<T>* List<T>::Locate(int i)
{
	if(i < 0)
	{
		return NULL;
	}
	LinkNode<T>* p = first;
	int k = 0;
	while(p != NULL && k < i) //循环后自然找到第i个节点
	{
		p = p -> link;
		k++;
	}
	return p;
};

//取出表中dii空格元素的值,保存在x中
template<class T>
bool List<T>::getData(int i, T& x) const
{
	//需要定位的算法首先确定是否在界内
	if(i < 0)
	{
		return NULL;
	}
	LinkNode<T>* current = Locate(i);
	if(current == NULL)
	{
		return false;
	}
	else
	{
		x = current -> data; //将数据记录在x中
		return true;
	}
};

//给链表第i个元素赋值
template<class T>
void List<T>::setData(int i, T& x)
{
	//定位先判断
	if(i < 0)
	{
		return false;
	}
	LinkNode<T>* current = Locate(i);
	if(current == NULL)
	{
		return false;
	}
	else
	{
		current -> data = x;
	}
};

//将新元素x插入到第i个节点之后。
template<class T>
bool List<T>::Insert(int i, T& x)
{
	LinkNode<T>* current = Locate(i);
	if(current == NULL)
	{
		return false;
	}
	LinkNode<T>* newNode = new LinkNode<T>(x);
	if(newNode == NULL)
	{
		cerr << "存储分配错误" << endl;
		exit(1);
	}
	newNode -> link = current -> link;
	current -> link = newNode;
	return true;
};

//将链表中的第i个元素删去，通过引用型参数x返回该元素的值
template<class T>
bool List<T>::Remove(int i, T& x)
{
	LinkNode<T>* current = Locate(i - 1);
	if(current == NULL ||current -> link == NULL)
	{
		return false;
	}
	LinkNode<T> *del = current -> link;
	current -> link = del -> link;
	x = del -> data;
	delete del;
	return true;
};

//单链表的输出函数：将单链表中所有数据按逻辑顺序输出到屏幕上
template<class T>
void List<T>::output()
{
	LinkNode<T>* current = first -> link;
	while(current != NULL)
	{
		cout << current -> data <<endl;
		current = current -> link;
	}
};

//重载函数：赋值操作，形如A=B，其中A是调用此操作的List对象，B是与参数表中的引用型参数L结合的实参
template<class T>
List<T>& List<T>::operator=(List<T>& L)
{
	T value;
	LinkNode<T>* sourceptr = L.getHead();
	LinkNode<T>* targetptr = first = new LinkNode<T>;
	while(sourceptr -> link != NULL)
	{
		value = sourceptr -> link -> data;
		targetptr -> link = new LinkNode<T>(value); //*
		sourceptr = sourceptr -> link;
		targetptr = targetptr -> link;
	}
	targetptr -> link = NULL;
	return *this;
};

//关于input()函数的两种实现
//前插法建立单链表
template<class T>
void List<T>::inputFront(T endTag)
{
	//endTag是约定的输入序列结束的标志，如果输入序列是正整数，endTag可以是0或者负数
	//如果输入序列是字符，endTag可以是字符集中不会出现的字符，如“\0”
	//前插法插入的节点永远是头结点之后的第一个位置
	//每次创建新节点都做一次存储分配是否正确的判断
	LinkNode<T>* newNode;
	T val;
	makeEmpty();
	cin >> val;
	while(val != endTag)
	{
		newNode = new LinkNode<T>(val);
		if(newNode == NULL)
		{
			cerr << "存储分配错误" << endl;
			exit(1);
		}
		newNode -> link = first -> link;
		first -> link = newNode; //插入到表前端
		cin >> val;
	}
};

//后插法建立单链表
template<class T>
void List<T>::inputRear(T endTag)
{
	LinkNode<T> *newNode, *last;
	T val;
	makeEmpty();
	cin >> val;
	last = first;
	while(val != endTag)
	{
		newNode = new LinkNode<T>(val);
		if(newNode == NULL)
		{
			cerr << "存储分配错误" << endl;
			exit(1);
		}
		last -> link = newNode;
		last = newNode;
		cin >> val;
	}
	last -> link = NULL;
};