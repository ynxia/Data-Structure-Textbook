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

//3.1.23 借助栈实现单链表的逆置运算
//方法：首先遍历单链表，逐个结点删除并把被删结点存入栈中，再从栈中取出存放的结点把它们依次链入单链表中
void Reverse(LinkList& L)
{
	LinkStack S;
	LinkNode *p = L -> link, *q; //p指向链表首元素
	if(p != NULL) //检测原链表
	{
		//结点p从原链表摘下，进栈
		L -> link = p -> link; //取下附加头结点之后的第一个结点
		Push(S, p); //把第一个结点进栈
		p = L -> link; //移向下一个结点
	}
	p = L; //p指向附加头结点
	while(!StackEmpty(S)) //栈非空时
	{
		Pop(S, q); //出栈
		p -> link = q; //链入结果链尾
		p = q; //即p=p->link，将p指向下一个结点
	}
	p -> link = NULL; //链收尾
};

//3.1.24 设一个栈的输入序列为1,2，...，n，编写一个算法，判断一个序列p1，p2，...，pn，是否是一个合理的栈输出序列
int Decision(int p[], int n)
{
	//算法判断序列p[0]，p[1]，...，p[n]是否合理的出栈序列，如果合理，则函数返回0
	//如果不合理，则函数返回1
	SeqStack S;
	InitStack(S);
	int i = 1, k = 0, j;
	Push(S, i);
	do{
		getTop(S, j); //出栈并把栈顶元素保存在j中，出栈操作不改变栈顶元素的性质
		if(j < p[k])
		{
			i++;
			Push(S, i);
		}
		else
		{
			if(j == p[k])
			{
				Pop(S, j);
				k++;
			}
		}
		else
		{
			cout << "不合理的" << endl;
			break;
		}
	}while(!StackEmpty(S) && i <= n);
	cout << "输出序列:";
	for(j = 0; j < n; j++)
	{
		cout << p[j];
	}
	cout << endl;
};


