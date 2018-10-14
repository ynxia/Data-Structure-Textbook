// 循环链表的类定义
template<class T>
struct CircLinkNode{
	T data;
	CircLinkNode<T>* link;
	CircLinkNode(CircLinkNode<T>* next = NULL):link(next){}
	CircLinkNode(T d, CircLinkNode<T>* next = NULL):data(d), link(next){}
};

template<class T>
class CircList:public LinearList<T>{
public:
	CircList(const T& x);
	CircList(CircList<T>& L);
	~CircList();
	int Length() const;
	bool Empty
}