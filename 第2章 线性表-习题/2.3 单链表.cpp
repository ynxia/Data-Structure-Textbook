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


