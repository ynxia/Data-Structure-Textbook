//基于单链表的三种运算

//单链表的定位运算
LinkNode* Locate(LinkNode* L, int k)
{
	//找到则返回该节点的指针
	LinkNode* p;
	int i;
	i = 1;
	p = L -> link; //p表示首节点
	while(p != NULL && i < k)
	{
		p = p -> link;
		i++;
	}
	if(p != NULL && i != k)
	{
		return p;
	}
	return NULL;
};

//单链表的插入运算
int Insert(LinkNode* L, int k, int elem)
{
	LinkNode *p, *q;
	if(k == 1) //用p记录目标节点的前一个元素
	{
		p = L;
	}
	else
	{
		p = Locate(L, k-1);
	}
	if(p == NULL)
	{
		return 0;
	}
	q = new LinkNode;
	if(q == NULL) //robust
	{
		cerr << "存储分配错误" << endl;
		return 0;
	}
	q -> data = elem;
	q -> link = p -> link;
	p -> link = q;
	return 1;
};

//单链表的删除算法
int Remove(LinkNode* L, int k)
{
	LinkNode *p, *q;
	if(k == 1)
	{
		p = L;
	}
	else
	{
		p = Locate(L, k-1);
	}
	q = p -> link;
	p -> link = q -> link;
	delete p;
	return 1;
};

//2.3.14 在带头结点的单链表中寻找第i个结点并返回相应指针
LinkNode* Locate(LinkList& L, int i)
{
	if(i < 0)
	{
		cerr << "寻找位置错误" << endl;
		return 0;
	}
	LinkNode* p = L;
	int k = 0;
	while(p != NULL && k < i)
	{
		p = p -> link;
		k++;
	}
	return p;
};

//2.3.15 在带头结点的单链表中确定值最大的节点，并返回相应指针
LinkNode* Max(LinkList& L)
{
	if(L -> link == NULL)
	{
		cerr << "该表是空表" << endl;
		return NULL;
	}
	LinkNode* pmax = L -> link; //pmax表示单链表的首节点
	LinkNode* p = L -> link -> link; //p表示单链表的第二个节点
	while(p != NULL)
	{
		if(p -> data > pmax -> data)
		{
			pmax = p;
		}
		p = p -> link;
	}
	return pmax;
};

//2.3.16 统计带头结点的单链表中具有给定值x的所有元素数
int Count(LinkList& L, DataType x)
{
	int n = 0;
	LinkNode* p = L -> link;
	while(p != NULL)
	{
		if(p -> data == x)
		{
			count++;
		}
		p = p -> link;
	}
	return count;
};

//2.3.17 根据一个一位数组A[n]建立一个带头结点的单链表，使单链表中各元素的次序与A[n]中各元素的次序相同，要求时间复杂度为O(n)
void CreateList(LinkList& L, DataType A[], int n)
{
	LinkNode* rear; //建立单链表头结点
	L = rear = new LinkNode;
	for(int i = 0; i < n; i++)
	{
		rear -> link = new LinkNode;
		rear = rear -> link;
		rear -> data = A[i];
	}
	rear -> link = NULL;
};

//2.3.18 在 非递减有序 的带头结点的单链表中删除值相同的多余节点
void Tidyup(LinkList& L)
{
	LinkNode* p = L -> link; //p指向单链表首节点
	LinkNode* del;
	while(p != NULL && p -> link != NULL)
	{
		if(p -> data == p -> link -> data)
		{
			del = p -> link;
			p -> link = del -> link;
			delete del;
		}
		else
		{
			p = p -> link;
		}
	}
};

//2.3.19 已知L为不带头节点的单链表的表头指针，链表存储整型数据，写出下列运算的递归算法
//(1)求链表中的最大整数
//(2)求链表的结点个数
//(3)求链表中所有元素的平均值

//(1)
int Max(LinkNode *L)
{
	//该单链表不带附加的头节点
	if(L -> link == NULL)
	{
		return L -> data;
	}
	int temp = Max(L -> link); //递归运算
	if(L -> data > temp)
	{
		return L -> data;
	}
	else
	{
		return temp;
	}
};