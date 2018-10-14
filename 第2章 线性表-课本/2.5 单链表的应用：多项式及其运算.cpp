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

