//3.5.9 已知函数定义：
//(1)根据定义写出它的递归求解算法
//(2)利用栈，写出它的非递归求解算法

//(1)
int Ackerman(int m, int n)
{
	//直接根据定义指出
	if(m == 0)
	{
		return n + 1;
	}
	if(n == 0)
	{
		return Ackerman(m - 1, 1);
	}
	return Ackerman(m - 1, Ackerman(m, n - 1));
};

//利用栈的递归算法
int Ackerman(int m, int n)
{
	int i, j, k, top = -1;
	int Sm[10], Sn[10]; //top是栈顶指针，Sm,Sn是栈
	while(1)
	{
		i = Sm[top]; //出栈
		j = Sn[top];
		top--;
		if(i == 0)
		{
			k = j + 1;
			if(top != -1)
			{
				S[top] = k;
			}
			else
			{
				return k;
			}
		}
		else if(j == 0)
		{
			Sm[++top] = i - 1;
			Sn[top] = 1;
		}
		else
		{
			Sm[++top] = i - 1;
			Sm[++top] = i;
			Sn[top] = j - 1;
		}
	}
};

//3.5.10 设勒让得多项式定义
//(1)编写一个多项式算法，计算多项式的值
//(2)编写一个非递归算法，计算多项式的值

//(1)
float Legendre(float x, int n)
{
	if(n == 0)
	{
		return 1;
	}
	if(n == 1)
	{
		return x;
	}
	return ((2 * n - 1) * x Legendre(x, n - 1) - (n - 1) * Legendre(x, n - 2)) / n;
};

//(2)使用迭代法的非递归运算
float Legendre(float x, int n)
{
	float current, backone, backtwo;
	int i;
	if(n == 0)
	{
		return 1;
	}
	if(n == 1)
	{
		return x;
	}
	backone = x; //n = 1
	backtwo = 1; //n = 0
	for(i = 2; i <= n; i++)
	{
		current = ((2 * i - 1) * x * backone - (i - 1) * backtwo) / n;
		backtwo = backone;
		backone = current;
	}
	return current;
};

//3.5.12 八皇后问题[使用回溯法]
void Queen(int G[], int i)
{
	int j, k, conflict;
	if(i == 8)
	{
		for(j = 0; j < 8; j++)
		{
			cout << j << "row," << G[j] << " column" << endl;
			return;
		}
	}
	for(j = 0; j < 8; j++)
	{
		conflict = 0;
		for(k = 0; k < 1; k++)
		{
			if(j == G[k] || i - k == j - G[k] || i - k == G[k] - j)
			{
				conflict = 1;
			}
		}
		if(!conflict)
		{
			G[i] = j;
			Queen(G, i + 1);
		}
	}
};