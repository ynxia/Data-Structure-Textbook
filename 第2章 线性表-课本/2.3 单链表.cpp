// 单链表的类定义
// (1)复合类
class List; //List的前置声明

class LinkNode{
friend class List;
private:
	int data;
	LinkNode* link;
};

class List{
public:
	//链表的公共操作
private:
	LinkNode* first;
};

// (2)嵌套类
class List{
public:
	//链表操作
private:
	class LinkNode{
	public:
		int data;
		LinkNode* link;
	};
	LinkNode* first;
};

// (3)基类和派生类
class LinkNode{
protected:
	int data;
	LinkNode* link;
};

class List:public class LinkNode{
private:
	LinkNode* first;
public:
	//链表操作
};

// (4)用struct定义LinkNode类
struct LinkNode{
	int data;
	LinkNode* link;
};

class List{
private:
	LinkNode* first;
public:
	//链表操作
};

//没有头节点的单链表的插入和删除


