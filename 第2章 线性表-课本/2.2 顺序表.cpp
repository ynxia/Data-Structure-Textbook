// 顺序表的动态存储
typedef int T;
typedef struct {
	T *data;
	int maxSize, n;
} SeqList;

// 顺序表的类声明
#include<iostream>
#include<stdlib>
#include"linearList"

const int defaultSize = 100;
class SeqList: public LinearList<T>{
protected:
	T *x;
	int maxSize;
	int last; //当前已存表项最后位置，从0开始计算
	void reSize(int newSize);
public:
	SeqList(int sz = defaultSize);
	SeqList(SeqList<T>& L);
	~SeqList(delete[] data);
	int Size() const{
		return maxSize;
	}
	int Length() const{
		return last + 1;
	}
	int Search(T& x) const;
	int Locate(int i) const;
	bool getData(int i, T& x) const{
		if(i > o && i <= last + 1)
		{
			x = data[i - 1];
			return true;
		}
		else
		{
			return false;
		}
	}
	void setData(int i, T& x)
	{
		if(i > 0 && i <= last + 1)
		{
			data[i - 1] = x;
		}
	}
	bool Insert(int i, T& x);
	bool Remove(int i, T& x);
	bool IsEmpty()
	{
		return (last == -1) ? true:false;
	}
	bool IsFull()
	{
		return (last = maxSize - 1) ? true:false;
	}
	void input();
	void output();
	SeqList<T> operator=(SeqList<T>& L); //表整体赋值
}

// 构造函数和复制构造函数
template<class T>
SeqList<T>::SeqList(int sz){
	if(sz > 0)
	{
		maxSize = sz;
		last = -1; //置表的实际长度为空
		data = new T[maxSize]; //创建顺序表存储数组，也就是说顺序表还是数组
		if(data == NULL)
		{
			cerr << "存储分配错误" << endl;
		}	
	}
}
template<class T>
SeqList<T>::SeqList(SeqList<T>& L)
{
	maxSize = L.Size();
	last = L.Length() - 1;
	T value;
	data = new T[maxSize]; // 创建顺序表存储数组
	if(data == NULL)
	{
		cerr << "存储分配错误" << endl;
	}
	for(int i = 1; i < last + 1; i++)
	{
		L.getData(i, value);
		data[i - 1] = value;
	}
}

template<class T>
void SeqList<T>::reSize(int newSize)
{
	if(newSize <= 0)
	{
		cerr << "无效的数组大小" << endl;
	}
	if(newSize != maxSize)
	{
		T* newarray = new T[newSize];
		if(newarray == NULL)
		{
			cerr << "存储分配错误" << endl;
			exit(1);
		}
		int n = last + 1;
		T* srcptr = data; //源数组首地址
		T* destptr = newarray; // 目的数组首地址
		while(n--) //仅仅是从小数组搬运到大数组
		{
			*destptr++ = *srcptr++;
		}
		delete[] data;
		data = newarray;
		maxSize = newSize;
	}
}

// 搜索和定位操作
template<class T>
int SeqList<T>::search(T& x) const 
{
	for(int i = 0; i <= last; i++)
	{
		if(data[i] == x)
		{
			return i + 1;
		}
	}
	return 0;
}

template<class T>
int SeqList<T>::Locate(int i) const
{
	if(i >= 1 && i <= last + 1)
	{
		return i;
	}
	else{
		return 0;
	}
}

// 插入与删除操作
template<class T>
bool SeqList<T>::Insert(int i, T& x)
{
	if(last == maxSize - 1)
	{
		return false;
	}
	if(i < 0 || i > last + 1)
	{
		return false;
	}
	for(int j = last; j >= i; j--) //直接向后移一位，再往空格中插入新数据
	{
		data[j + 1] = date[j];
	}
	data[i] = x;
	last++;
	return true;
}

template<class T>
bool SeqList<T>::Remove(int i,T& x)
{
	if(last == -1)
	{
		return false;
	}
	if(i < 1 || i > last + 1)
	{
		return false;
	}
	x = data[i - 1]；
	for(int j = i; j <= last; j++)
	{
		data[j - 1] = date[j];
	}
	last--;
	return true;
}

// 输入输出操作和赋值操作
template<class T>
void SeqList<T>::input() //从标准输入逐个数据输入，建立顺序表
{
	cout << "开始建立顺序表，请输入元素的个数：";
	while(1)
	{
		cin >> last;
		if(last <= maxSize - 1)
		{
			break;
		}
		cout << "表元素个数输入错误，范围不能超过" << maxSize - 1 << ":";
	}
	for(int i = 0; i < last; i++)
	{
		cin >> data[i];
		cout << i+1 << endl;
	}
};

template<class T>
void SeqList<T>::output()
{
	cout << "顺序表当前元素最后位置为：" << last << endl;
	for(int i = 0; i <= last; i++)
	{
		cout << "#" << i + 1 << ":" << data[i] << endl;
	}
};

template<class T>
SeqList<T> SeqList<T>::operator=(SeqList& L)
{
	swap(L, *this);
	return *this;
}

// 将顺序表作为集合的典型运算
// 合并顺序表LA与LB，结果存于LA，重复元素只留一个
void union(SeqList<int>& LA, SeqList<int>& LB)
{
	int n = LA.Length(), m = LB.Length(), i, k, x;
	for(int i; i <= m; i++)
	{
		LB.getData(i, x); //在LB中取一元素
		k = LA.Search(x); //在LA中搜索它
		if(k == 0)
		{
			LA.Insert(n, x);
			n++;
		}
	}
};

//求顺序表LA与LB中的共有元素，结果存于LA
void Intersection(SeqList<int>& LA, SeqList<int>& LB)
{
	int n = LA.Length(), m = LB.Length(), i = 1, k, x;
	while(i <= n)
	{
		LA.getData(i,x);
		k = LB.Search(x);
		if(k == 0)
		{
			LA.Remove(i, x);
			n--;
		}
		else
		{
			i++;
		}
	}
};