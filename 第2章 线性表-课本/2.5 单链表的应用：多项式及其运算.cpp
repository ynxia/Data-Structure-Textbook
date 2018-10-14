// 多项式的类定义
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include<iostream>

struct Term{ //多项式节点的定义
	//系数 coefficient
	//指数 exponent/index
	float coef;
	int exp;
	Term* link;
	Term(float c, int e, Term* next = NULL)
	{
		coef = c;
		exp = e;
		link = next;
	}
	Term* InsertAfter(float c, int e);
	friend ostream& operator<<(ostream&, const Term&);
};

class Polynomial{
public:
	Polynomial()
	{
		first = new Term(0, -1); //构造函数，建立空链表
	}
	Polynomial(Polynomial& R);
	int maxOrder();
	Term *getHead() const
	{
		return first;
	}
private:
	Term* first;
	//重载过程中，括号内表示变量
	friend ostream& operator<<(ostream&, const Polynomial&);
	friend istream& operator>>(istream&, Polynomial&);
	friend Polynomial operator+(Polynomial&, Polynomial&);
	friend Polynomial operator-(Polynomial&, Polynomial&);
};

Term* Term::InsertAfter(float c, int e)
{
	//在当前由this指针指向的项后面插入一个新项
	link = new Term(c, e, link); //创建一个新节点，自动链接
	return link; //插入到this节点后面
};

ostream& operator<<(ostream& out, const Term& x)
{
	//输出一个项x的内容到输出流out中
	if(x.coef == 0.0)
	{
		return out;
	}
	out << x.coef;
	switch(x.coef){
		case 0:break;
		case 1:cout << "X";break;
		default:out << "X^" << x.exp;break;
	}
	return out;
};

Polynomial::Polynomial(Polynomial& R)
{
	//复制构造函数，用已有多项式R初始化当前多项式对象R
	first = new Term(0, -1);
	Term *targetptr = first;
	Term *sourceptr = R.getHead() -> link;
	while(sourceptr != NULL)
	{
		targetptr -> InsertAfter(sourceptr -> coef, sourceptr -> exp);
		// 上面的一行：
		// targetptr = new Term(sourceptr -> coef, sourceptr -> exp);
		sourceptr = sourceptr -> link;
		targetptr = targetptr -> link;
	}
};

//计算最大阶数，当多项式按升序排列时，最后一项中是指数最大者
int Polynomial::maxOrder()
{
	Term* current = first;
	while(current -> link != NULL)
	{
		current = current -> link;
	}
	//空表情形，current停留在first，否则current停留在表尾节点
	return current -> exp;
};

//Polynomial类的友元函数，从输入流in输入各项，用尾插法建立一个多项式
istream& operator>>(istream& in, Polynomial& x)
{
	Term *rear = x.getHead();
	int c, e;
	while(1)
	{
		cout << "input a term(coef, exp)" << endl;
		in >> c >> e;
		if(e < 0)
		{
			break;
		}
		rear = rear -> InsertAfter(c,e);
	}
	return in;
};

//Polynomial类的友元函数：输出附加头结点的多项式链表x
ostream& operator<<(ostream& out, Polynomial& x)
{
	Term* current = x.getHead() -> link;
	cout << "The polynomial is:" << endl;
	bool h = true;
	while(current != NULL)
	{
		if(h == false && current -> coed > 0.0)
		{
			out << "+";
		}
		h = false;
		out << *current;
		current = current -> link;
	}
	out << endl;
	return out;
};
#endif

//多项式加法

Polynomial operator+(Polynomial& A, Polynomial& B)
{
	Term *pa, *pb, *pc, *p; //pa、pb定位于A与B的第一个节点，是两链的检测指针
	float temp;
	Polynomial C;
	pc = C.first; //pc为结果多项式在创建过程中的尾指针
	pa = A.getHead() -> link;
	pb = B.getHead() -> link;
	while(pa != NULL && pb != NULL)
	{
		//根据e1和e2的大小分为三种情况
		if(pa -> exp == pb -> exp)
		{
			temp = pa.coef +pb.coef;
			if(fabs(temp) > 0.001) //如果相加后系数不为0
			{
				
			}
		}
	}
}