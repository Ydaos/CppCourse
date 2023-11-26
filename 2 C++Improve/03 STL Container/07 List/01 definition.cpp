#include <iostream>
#include <list>

/*
* List概念：将数据进行链式存储
* 链表(list)是一种物理存储单元上非连续的存储结构，数据元素的逻辑顺序是通过链表中的指针链接实现的
* 链表由一系列结点组成
* 结点：一个存储数据元素的数据域，另一个是存储下一个结点地址的指针域
* 
* STL中的链表是一个双向循环链表
* 双向链表：结点的指针域中不仅存储了下一个结点的地址，还存储了上一个结点的地址
* 由于链表的存储方式不是连续的内存空间，因此链表list中的迭代器只支持前移和后移，是双向迭代器
* 
* 优点：可以对任意位置进行快速插入或删除元素；采用动态存储分配，不会造成内存浪费和溢出
* 缺点：容器遍历速度慢，没有数组快；占用的空间也会比数组大（指针域）
* 
* List重要特性：插入和删除操作都不会造成原有list迭代器的失效，这在vector是不存在的
* List和Vector是最常用两个容器，各有所长！要灵活应用
*/
void printList(const std::list<int>& l) {
	for (std::list<int>::const_iterator it = l.begin(); it != l.end(); it++) {
		std::cout << (*it) << " ";
	}
	std::cout << std::endl;
}


/*
* List构造函数
* 函数原型：
* list<T> lst;           //默认构造函数
* list(beg, end);        //将[beg, end]区间元素拷贝给本身
* list(n, elem);         //将n个elem元素拷贝给本身
* list(const list &lst); //拷贝构造函数
*/
void Constructor() {
	// 默认构造
	std::list<int> L;
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	L.push_back(40);
	L.push_back(50);
	printList(L);

	// 拷贝构造
	std::list<int>L2(L);
	printList(L2);

	// list(beg, end); 
	std::list<int>L3(L.begin(), L.end());
	printList(L3);

	// list(n, elem);
	std::list<int>L4(5, 6);
	printList(L4);
}


/*
* List容器赋值
* 函数原型：
* list& operator=(const list &lst); //重载=运算符
* assign(beg, end);			     //将[beg, end]区间内元素赋值给本身
* assign(n, elem);                  //将n个elem元素赋值给本身
*/
void Assignment() {
	std::list<int> L;
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	L.push_back(40);
	L.push_back(50);
	printList(L);

	// list& operator=(const list &lst);
	std::list<int>L2;
	L2 = L;
	printList(L2);

	// assign(beg, end);
	std::list<int>L3;
	L3.assign(L.begin(), L.end());
	printList(L3);

	// assign(n, elem); 
	std::list<int>L4;
	L4.assign(5, 6);
	printList(L4);
}


int main01() {
	Constructor();

	std::cout << "--------------------------\n";
	Assignment();

	system("pause");
	return 0;
}