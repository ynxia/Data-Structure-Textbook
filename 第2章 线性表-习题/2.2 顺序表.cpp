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