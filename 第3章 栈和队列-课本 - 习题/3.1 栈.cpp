//3.1.22 改写顺序栈的进栈成员函数Push(x)，要求当栈满时执行一个stackFull()操作进行溢出处理
//其功能是：动态创建一个比原来的栈数组大一倍的新数组，代替原来的栈数组，原来栈数组的元素占据新数组的前maxSize个位置
void Push(SeqStack& S, SElemType x)
{
	if(S.top == maxSize - 1)
	{
		StackFull(S); //栈满，做溢出处理
	}
	S.elem[++S.top] = x; //进栈
};

void StackFull(SeqStack& S)
{
	SElemType *temp = new SElemType[2 * S.maxSize];
	if(temp == NULL)
	{
		cerr << "存储分配失败" << endl;
		exit(1);
	}
	for(int i = 0; i < S.top; i++)
	{
		temp[i] = S.elem[i]; //传送栈内数据
	}
	delete []S.elem; //删去原数组
	S.maxSize = 2 * S.maxSize; //数组体积扩大一倍
	S.elem = temp; //新数组成为栈的数组空间
};

//借助栈实现单链表的逆置运算
//方法：首先遍历单链表，逐个节点删除并把被删结点存入栈中，再从栈中取出存放的结点把它们依次链入单链表中
void Reverse(LinkList& L)
{
	LinkStack S;
	LinkNode *p = L -> link, *q;
	if(p != NULL)
	{
		L -> link = p -> link;
		Push(S, p);
		p = L -> link;
	}
	p = L;
	while(!StackEmpty(S))
	{
		Pop(S, q);
		p -> link = q;
		p = q;
	}
	p -> NULL;
};


