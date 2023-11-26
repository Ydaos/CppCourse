#include <iostream>
#include <list>

void printList(const std::list<int>& l); //函数定义在文件"01 definition.cpp"

/*
* List容器插入和删除
* 函数原型：
* push_back(elem);          //在容器尾部插入一个elem值元素
* pop_back();               //删除容器最后一个元素
* push_front(elem);         //在容器头部插入一个elem值元素
* pop_front();              //删除头部一个元素
*
* insert(pos, elem);        //在迭代器pos位置插入一个elem值元素
* insert(pos, int n, elem); //在迭代器pos位置插入n个elem值元素
* insert(pos, beg, end);    //在迭代器pos位置插入[beg, end]区间所有元素
*
* clear();                  //清除容器所有元素
* erase(beg, end);          //删除[beg, end]区间所有元素
* erase(pos);               //删除在迭代器pos位置上的元素
* remove(elem);             //删除容器所有与elem值匹配的元素
* 
* List重要特性：插入和删除操作都不会造成原有list迭代器的失效，这在vector是不存在的
*/
void Insert() {
	std::list<int> L;

	// 1、List两端插入数据
	// 尾部插入
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);

	// 头部插入
	L.push_front(100);
	L.push_front(200);
	L.push_front(300);
	printList(L);

	// 2、List随机位置插入数据
	// insert(pos, elem);
	std::list<int>::iterator it = L.begin();
	L.insert(++it, 1000);
	printList(L);

	// insert(pos, int n, elem)
	L.insert(it, 3, 2000);
	printList(L);

	// insert(pos, beg, end)
	std::list<int>L2;
	L2.insert(L2.begin(), it, L.end());
	printList(L2); // 100 10 20 

	// 注意事项：
	// List重要特性：插入和删除操作都不会造成原有list迭代器的失效，这在vector是不存在的
	// 因此it由始至终指向的一直是100，而不是下标为1的元素！
}

void Delete() {
	std::list<int> L;
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	L.push_back(40);
	L.push_back(50);
	printList(L);

	// 尾部删除
	L.pop_back();
	printList(L);

	// 头部删除
	L.pop_front();
	printList(L);

	// erase(pos);
	L.erase(++L.begin());
	printList(L);

	// erase(beg, end) || clear()
	L.clear();  //等价于 L.erase(L.begin(), L.end());
	printList(L);

	// remove(elem)
	std::list<int>L2;
	L2.push_back(10);
	L2.push_back(20);
	L2.push_back(10);
	L2.push_back(40);
	L2.push_back(10);
	printList(L2);

	L2.remove(10);
	printList(L2);
}


/*
* List容器元素存取
* 函数原型：
* front();  //返回第一个元素
* back();   //返回最后一个元素
* 链表迭代器是双向迭代器不是随机的，因为数据结构导致内存空间不连续，无法随机访问
* 也就是说不支持[]运算符重载及at()函数
*/
void Access() {
	std::list<int> L;
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);

	// L[0];    Error!!!不可以用[]访问
	// L.at(0); Error!!!没这个成员函数
	// 原因：list本质是链表，每个数据不是连续空间存储，不支持随机访问

	std::cout << "list第一个元素为：" << L.front() << std::endl;
	std::cout << "list最后一个元素为：" << L.back() << std::endl;

	// 验证list不支持随机访问
	std::list<int>::iterator it = L.begin();
	it++;
	// it += 1; Error!!!不能随机访问，只能累加来找到下一个结点
}


/*
* List容器反转和排序
* 函数原型：
* reverse();  //反转链表
* sort();     //链表排序
*
* 注意事项：
* 对于支持随机访问迭代器的容器，可以使用标准排序算法：sort(L.begin(), L.end());
* 不支持随机访问迭代器的容器，内部会提供一些成员函数算法
*/
bool myCompare(int v1, int v2) {
	// 降序 就让第一个数 > 第二个数
	return v1 > v2;
}

void MySort() {
	std::list<int> L;
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	L.push_back(25);
	std::cout << "反转前\n";
	printList(L);

	// reserve反转链表
	L.reverse();
	std::cout << "反转后\n";
	printList(L);

	// 成员函数sort排序
	L.sort(); //默认升序操作
	std::cout << "排序后\n";
	printList(L);

	L.sort(myCompare); //降序操作
	std::cout << "排序后\n";
	printList(L);
}

int main03() {
	Insert();

	std::cout << "------------------\n";
	Delete();

	std::cout << "------------------\n";
	Access();

	std::cout << "------------------\n";
	MySort();

	system("pause");
	return 0;
}