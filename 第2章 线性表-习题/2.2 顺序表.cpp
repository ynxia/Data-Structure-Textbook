//2.2.11 将顺序表原地转置
void Reverse(SeqList& L)
{
	if(L.n == 0)
	{
		cerr << "空表不需交换" << endl;
		return;
	}
	DataType tmp;
	for(int i = 1; i <= L.n / 2; i++)
	{
		tmp = L.data[i-1];
		L.data[i-1] = L.data[n-i];
		L.data[n-i] = tmp;
	}
}

//2.2.12 从顺序表中删除具有最小值的元素并由函数返回最小元素的值，空出的位置由最后一个元素填补
int deleteMin(SeqList& L, DataType& x)
{
	if(L.n == 0)
	{
		cerr << "表空不能删除" << endl;
		return;
	}
	int i, pos = 0;
	for(i = 2; i <= L.n; i++)
	{
		if(L,data[i-1] < L.data[pos])
		{
			pos = i-1;
		}
	}
	x = L.data[pos];
	L.n--;
	L.data[pos] = L.data[L.n];
	return 1;
};

//2.2.13 从顺序表中删除第i个元素，并返回该元素的值
int deleteNo_i(SeqList& L, int i, DataType& x)
{
	if(L.n == 0)
	{
		cerr << "表空不能删除" << endl;
		return 0;
	}
	if(i < 1 || i > L.n)
	{
		cout << "i的值不合理！" << endl;
		return 0;
	}
	x = L.data[i-1];
	L.n--;
	for(int j = i; j <= L.n; j++)
	{
		L.data[j-1] = L.data[j];
	}
	return 1;
};

//2.2.14 向顺序表中第i个位置插入一个新元素x
int InsNo_i(SeqList& L, int i, DataType x)
{
	if(L.n == L.maxSize)
	{
		cout << "表满不能插入" << endl;
		return 0;
	}
	if(i < 1 || i > L.n + 1)
	{
		cerr << "参数i不合理" << endl;
		return 0;
	}
	for(int j = L.n; j >= i; j--)
	{
		L.data[j] = L.data[j-1];
	}
	data[i-1] = x;
	L.n++;
	return 1;
};

//2.2.15 从顺序表中删除具有给定值i的所有元素
void deleteValue(SeqList& L, DataType x)
{
	int i, k = 0;
	for(int i = 0; i < L.n; i++)
	{
		if(L.data[i] != x)
		{
			if(i != k)
			{
				L.data[k] = L.data[i];
				k++;
			}
		}
	}
	L.n = k;
};

//2.2.16 删除一个顺序表中在s和t之间的值
int deleteNo_sto_t(SeqList& L, DataType s, DataType t)
{
	if(L.n == 0)
	{
		cerr << "空表不能删除" << endl;
		return 0;
	}
	if(s > T)
	{
		DataType tenp = s;
		s = t;
		t = temp;
	}
	int i, k = 0;
	for(int i = 0; i < L.n; i++)
	{
		if(L.data[i] < s || L.data[i] > t) //保留区间之外的值
		{
			if(k != i)
			{
				L.data[k] = L.data[i];
				k++;
			}
		}
	}
	L.n = k;
	return 1;
};

//2.2.17 删除一个 有序 顺序表中在s和t之间的值
int deleteNo_sto_t1(SeqList& L, DataType s, DataType t)
{
	if(L.n == 0)
	{
		cerr << "空表不能删除" << endl;
		return 0;
	}
	if(s > t)
	{
		DataType = temp;
		temp = s;
		s = t;
		t = temp;
	}
	int i, j, u, v;
	for(int i = 0; i < L.n && L.data[i] < s; i++);  //寻找值大于等于s的第一个元素
	if(i >= L.n)
	{
		cout << "所有元素的值都小于s" << endl;
		return 0;
	}
	for(j = i; j < L.n && L.data[j] < t; j++); //寻找值大于t的第一个元素
	for(u = i, v = j; v < L.n; u++, v++)
	{
		L.data[u] = L.data[v];
	}
	L.n = L.n - j + i;
	return 1;
};

//2.2.18 将两个有序(升序)顺序表合并成一个新的有序顺序表并由函数返回结果顺序表
int Merge(SeqList& A, SeqList& B, SeqList& C)
{
	if(A.n + B.n > C.maxSize)
	{
		return 0;
	}
	int i = 0, j = 0, k = 0;
	while(i < A.n && j < B.n)
	{
		if(A.data[i] <= B.data[j])
		{
			C.data[k++] = A.data[i++];
		}
		else{
			C.data[k++] = B.data[j++];
		}
	}
	while(i <= A.n)
	{
		C.data[k++] = A.data[i++];
	}
	while(j <= B.n)
	{
		C.data[k++] = B.data[i++];
	}
	C.n = k;
	return 1;
};

//2.2.19 从有序顺序表中删除所有其值重复的元素，使表中所有元素均不相同
int deleteSame(SeqList& A)
{
	if(A.n == 0)
	{
		cerr << "空表不能删除" << endl;
		return 0;
	}
	int i, k = 1;
	for(i = 1; i < A.n; i++)
	{
		if(A.data[i-1] != A.data[i]) //A.data[i]与之前的元素不重复
		{
			if(k != i)
			{
				A.data[k] = A.data[i]
				k++;
			}
		}
	}
	A.n = k;
	return 1;
};

//2.2.20 以不多于3n/2的平均比较次数，在一个有n个整数的顺序表A中找出具有最大值和最小值的整数
void FindMaxMin(SeqList& A, int &max, int &min)
{
	max = min = A.data[0];
	for(int i = 0; i < A.n; i++)
	{
		if(A.data[i] > max)
		{
			max = A.data[i];
		}
		else if(A.data[i] < min)
		{
			min = A.data[i];
		}
	}
};

//2.2.21 除去最大公共前缀之后，对A’和B’的大小进行比较
char Compare(SeqList& A, SeqList& B)
{
	int i = 0;
	while(i < A.n && i < B.n)
	{
		if(A.data[i] == B.data[i])
		{
			i++;
		}
		else{
			break;
		}
	}
	if(i >= A.n && i>= B.n)
	{
		return '=';
	}
	if(i >= A.n || A.data[i] < B.data[i])
	{
		return '<';
	}
	else
	{
		return '>';
	}
};