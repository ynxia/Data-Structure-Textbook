//区别队空还是队满的情况，有三种情况

//(1)牺牲一个队列元素空间
#define maxSize 100
typedef int QElemType;
typedef struct{
	QElemType elem[maxSize]; //循环队列的存储空间
	int front, rear; //循环队列的队头、队尾指针
}CircQueue;

//队空条件：
Q.front == Q.rear
//队满条件：
(Q.rear + 1) % maxSize == Q.front

//增设记录实际队列元素个数的数据成员size(or length)来区分队空与队满的条件
#define maxSize 100
typedef int QElemType;
typedef struct
{
	QElemType elem[maxSize];
	int front, size; //队列的队头指针和元素个数
}CircQueue;

//队空条件：
Q.size == 0
//队满条件：
Q.size == maxSize

//(3)增设一个标志域tag，来区分队空与队满的条件
#define mazSize 100
typedef int QElemType;
typedef struct
{
	QElemType elem[maxSize];
	int front, rear, tag;
}CircQueue;

//队空条件：
Q.front == Q.rear && Q.tag == 0
//队尾条件：
Q.front == Q.rear && Q.tag == 1

//队列的链式存储结构
typedef int QElemType;
typedef struct node
{
	QElemType data;
	struct node *link;
}LinkNode;
typedef struct 
{
	LinkNode *front, *rear;
}LinkQueue;

//3.2.10 设以数组Q.elem[maxSize]存放循环队列的元素，同时以Q.rear和Q.length分别指示循环队列中的队尾位置和队列中所含元素的个数
//给出该循环队列的队空条件和队满条件，并写出相应的插入(enQueue)和删除(deQueue)元素操作
//循环队列的结构定义
#define maxSize 100
typedef int QElemType;
typedef struct
{
	QElemType elem[maxSize]; //用数组表示队列
	int rear, length;
}CircQueue;


//该队列的插入函数
int enQueue(CircQueue& Q, QElemType x)
{
	if(Q.length == maxSize)
	{
		return 0;
	}
	Q.rear = (Q.rear+1) % maxSize; //队尾指针进1
	Q.elem[Q.rear] = x; //进队列
	Q.length++;
	return 1;
};

//该队列的删除函数
int deQueue(CircQueue& Q, QElemType& x) //因为同时要将退出元素的值返回
{
	if(Q.length == 0)
	{
		return 0;
	}
	Q.length--;
	x = elem[(Q.rear - Q.length + 1 + maxSize) % maxSize]; //返回原队头元素的值
	return 1;
};

//3.2.11 设以数组Q.elem[maxSize]存放循环队列的元素，同时设置一个标志Q.tag，
//以Q.tag = 0和Q.tag = 1来区别在队头指针(front)和队尾指针(rear)相等时队列的状态是满还是空。
//试编写本结构相应的插入算法和删除算法
#define maxSize 100
typedef int QElemType;
typedef struct
{
	QElemType elem[maxSize];
	int front, rear;
	int tag;
}CircQueue;
int enQueue(CircQueue& Q, QElemType x)
{
	if(Q.front == Q.rear && Q.tag == 1) //判断队列是否已满，满则出错
	{
		return 0;
	}
	Q.rear = (Q.rear + 1) % maxSize; //队尾进一
	Q.elem[Q.rear] = x;
	Q.tag = 1; //标志改为1，表示队列不空
	return 1;
};
int deQueue(CircQueue& Q, QElemType& x)
{
	if(Q.front == Q.rear && Q.tag == 0)
	{
		return 0;
	}
	Q.front = (Q.front + 1) % maxSize;
	Q.tag = 0;
	x = Q.elem[Q.front];
	return 1;
};

//3.2.12 循环队列采用一维数组作为它的存储比啊噢是，往往很难确定到底数组需要设置多少元素才够用
//因此可以改写队列的插入和删除算法，自动根据需要调整队列的存储数组大小
//(1)改写队列的插入(进队)函数，当队列满并需要插入新元素时将数组空间扩大一倍，使新元素得以插入
//(2)改写队列的删除(出队)函数，当队列元素少于数组空间的1/4时将数组空间自动缩减一半

//(1)
int enQueue(CircQueue& Q, QElemType x)
{
	if((Q.rear - Q.front + maxSize) % Q.maxSize == Q.maxSize) //队列已满
	{
		int newSize = 2 * Q.maxSize;
		QElemType *newArray = new ElemType[newSize];
		if(newArray == NULL)
		{
			cerr << "存储分配失败" << endl;
			return 0;
		}
		int newRear = Q.front, newFront = Q.front; //向数组传递数据
		while(Q.rear != Q.front)
		{
			newArray[newRear] = Q.elem[Q.front];
			Q.front = (Q.front + 1) % maxSize;
			newRear = (newRear + 1) % newSize;
		}
		delete []Q.elem;
		Q.elem = newArray;
		Q.rear = newRear;
		Q.front = newFront;
		Q.maxSize = newSize;
	}
	Q.elem[Q.rear] = x;
	Q.rear = (Q.rear + 1) % Q.maxSize;
	return 1;
};

//(2)
int deQueue(CircQueue& Q, QElemType& x)
{
	if((Q.rear - Q.front + Q.maxSize) % Q.maxSize <= Q.maxSize / 4)
	{
		int newSize = Q.maxSize / 2;
		QElemType *newArray = new QElemType[newSize];
		if(newArray == NULL)
		{
			cerr << "存储分配失败" << endl;
			return 0;
		}
		int newRear = Q.front, newFront = Q.front; //传值
		while(Q.rear != Q.front)
		{
			newArray[newRear] = Q.elem[Q.front];
			Q.front = (Q.front + 1) % maxSize;
			newRear = (newRear + 1) % newSize;
		}
		delete []Q.elem;
		Q.elem = newArray;
		Q.rear = newRear;
		Q.front = newFront;
		Q.maxSize = newSize;
	}
	if(Q.rear == Q.front)
	{
		return 0;
	}
	x = Q.elem[Q.rear];
	Q.front = (Q.front + 1) % Q.maxSize;
	return 1;
};

//3.2.13 若使用单循环链表来表示队列，rear是链表中的一个指针(视为队尾指针)。试基于该结构给出插入和删除算法
//并给出rear为何值时队列为空

//结构定义
typedef struct
{
	CircNode *rear;
}CircLinkQueue;
//(1)
int enQueue(CircLinkQueue& Q, QElemType x)
{
	CircNode *s = new CircNode;
	if(s == NULL)
	{
		cerr << "存储分配失败" << endl;
		return 0;
	}
	s -> data = x;
	s -> link = Q.rear -> link;
	Q.rear -> link = s;
	Q.rear = Q.rear -> link;
	return 1;
};
//(2)
int deQueue(CircLinkQueue& Q, QElemType& x)
{
	if(Q.rear == NULL)
	{
		cerr << "队列空，不能删除" <<endl;
		return 0;
	}
	CircNode *p = Q.rear -> link;
	if(Q.rear == p)
	{
		Q.rear = NULL;
	}
	else
	{
		Q.rear -> link = p -> link;
	}
	x = p -> data;
	delete p;
	return 1;
};
