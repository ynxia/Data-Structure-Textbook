//基于单链表的三种运算

//单链表的定位运算
LinkNode* Locate(LinkNode* L, int k)
{
	//找到则返回该结点的指针
	LinkNode* p;
	int i;
	i = 1;
	p = L -> link; //p表示首结点
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
	if(k == 1) //用p记录目标结点的前一个元素
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

//2.3.15 在带头结点的单链表中确定值最大的结点，并返回相应指针
LinkNode* Max(LinkList& L)
{
	if(L -> link == NULL)
	{
		cerr << "该表是空表" << endl;
		return NULL;
	}
	LinkNode* pmax = L -> link; //pmax表示单链表的首结点
	LinkNode* p = L -> link -> link; //p表示单链表的第二个结点
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

//2.3.18 在 非递减有序 的带头结点的单链表中删除值相同的多余结点
void Tidyup(LinkList& L)
{
	LinkNode* p = L -> link; //p指向单链表首结点
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

//2.3.19 已知L为不带头结点的单链表的表头指针，链表存储整型数据，写出下列运算的递归算法
//(1)求链表中的最大整数
//(2)求链表的结点个数
//(3)求链表中所有元素的平均值

//(1)
int Max(LinkNode *L)
{
	//该单链表不带附加的头结点
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

//(2)
int Num(LinkNode* L)
{
	if(L == NULL)
	{
		return 0;
	}
	return 1 + Num(L -> link);
};

//(3)
float Avg(LinkNode* L, int& n)
{
	if(L -> link == NULL)
	{
		n = 1;
		return (float)(L -> data);
	}
	else
	{
		float Sum = Avg(L -> link, n) * n;
		n++;
		return (L -> data + Sum) / n;
	}
};

//2.3.20 设ha和hb分别是两个带头结点的非递减有序单链表的表头指针，设计一个算法，
//将这两个有序链表合并成一个非递增有序单链表。
//要求结果链仍然使用原来两个链表的存储空间，不另外占用其他存储空间
void ReverseMerge(LinkList& ha, LinkList& hb)
{
	LinkNode *pa, *pb, *last, *q;
	pa = ha -> link;
	pb = hb -> link;
	ha -> link = NULL; //将ha作为结果链
	delete hb;
	while(pa != NULL pb != NULL)
	{
		if(pa -> data <= pb -> data)
		{
			q = pa;
			pa = pa -> link;
		}
		else
		{
			q = pb;
			pb = pb -> link;
		}
		q -> link = ha -> link;
		ha -> link = q;
	}
	if(pb != NULL)
	{
		pa = pb; //pb链更长的话用pa继续进行结点传递
	}
	while(pa != NULL)
	{
		q = pa;
		pa = pa -> link;
		q -> link = ha -> link;
		ha -> link = q;
	}
};

// 2.3.21 从左到右及从右到左遍历一个单链表是可能的，其方法是从左到右的遍历的过程中将链接方向逆转。
//(1)设计一个算法，从任意给定的位置(pr,p)开始，将指针p右移k个结点。如果p移出链表，则将p置为NULL，并让pr停留在链表最右边的结点上
//(2)设计一个算法，从任意给定的位置(pr,p)开始，将指针p左移k个结点。如果p移出链表，则将p置为NULL，并让pr停留在链表最左边的结点上

//(1)
void siftToRight(LinkList& L, LinkNode* &p, LinkNode* &pr, int k)
{
	//这里的p和pr属于指针的引用，
	//这样p和pr就能互换地址
	LinkNode* q;
	int count = 0;
	while(p != NULL && count < k)
	{
		q = p -> link;
		p -> link = pr;
		pr = p;
		p = q;
		count++;
	}
	cout << "右移了" << count << "个结点" << endl;
};

//(2)
void siftToLeft(LinkList& L, LinkNode* &p, LinkNode* &pr, int k)
{
	LinkNode* q;
	int count = 0;
	while(pr != NULL && count < k)
	{
		q = pr -> link;
		pr -> link = p;
		p = pr;
		pr = q;
		count++;
	}
	cout << "左移了" << count << "个结点" << endl;
};

//2.3.22 设有一个表头指针h的单链表，设计一个算法，通过遍历一趟链表，将链表中所有结点的链接方向逆转
//没有附加头结点
void Reverse(LinkNode* &h)
{
	//解决方案一
	if(h == NULL)
	{
		return;
	}
	LinkNode *p = h -> link, *pr = NULL; //p表示正向第二个结点
	while(p != NULL)
	{
		//逆转h指针
		h -> link = pr;
		//指针前移
		pr = h;
		h = p;
		p = p -> link;
	}
	h -> link = pr;
};

void Reverse(LinkList& L)
{
	//解决方案二(*)
	LinkNode *p = L -> link, *pr;
	L -> link = NULL;
	while(p != NULL)
	{
		//摘下剩余链的首元结点
		pr = p;
		p = p -> link;
		//作为首元结点插入结果链
		pr -> link = L -> link;
		L -> link = pr;
	}
};

//2.2.23 设在一个带头结点的单链表中所有元素结点的数据值按递增顺序排列，
//设计一个算法，删除表中所有大于min且小于max的元素(若存在)
typedef int DataType;
void rangeDelete(LinkList& L, DataType min, DataType max)
{
	LinkNode *pr = L, *p = L -> link;
	while(p != NULL && p -> data <= min)
	{
		pr = p;
		p = p -> link;
	}
	while(p != NULL && p -> data < max)
	{
		pr -> link = p -> link;
		delete p;
		 p = pr -> link;
	}
};

//2.2.24 设在一个带头结点的单链表中所有元素结点的数据值无序排列，
//设计一个算法，删除表中所有大于min且小于max的元素(若存在)
typedef int DataType;
void rangeDelete(LinkList& L, DataType min, DataType max)
{
	LinkNode *pr = L, *p = L -> link;
	while(p != NULL)
	{
		if(p -> data > min && p -> data < max)
		{
			pr -> link = p -> link;
			delete p;
			p = pr -> link;
		}
		else
		{
			pr = p;
			p = p -> link;
		}
	}
};

//2.3.26 已知一个带头结点的单链表中包含3类字符（数字字符，字母字符和其他字符），
//设计一个算法，构造3个新链表，使每个链表中只包含同一类字符。
//要求使用原表空间，表头结点可以另辟空间
#include<ctype>
void Seperate(LinkList& LA, LinkList& LB, LinkList& LC)
{
	LinkNode *pa, *pb, *pc, *p = LA -> link;
	pa = LA;
	pb = LB = new LinkNode;
	pc = LC = new LinkNode;
	while(p != NULL)
	{
		if(isdigit(p -> data))
		{
			pa -> link = p;
			pa = pa -> link;
		}
		else if(isalpha(p -> data))
		{
			pb -> link = p;
			pb = pb -> link;
		}
		else
		{
			pc -> link = p;
			pc = pc -> link;
		}
		p = p -> link;
	}
	pa -> link = NULL;
	pb -> link = NULL;
	pc -> link = NULL;
};