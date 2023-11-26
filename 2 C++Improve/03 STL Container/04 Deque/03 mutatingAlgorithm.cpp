#include <iostream>
#include <deque>
#include <algorithm> //标准算法头文件

void printDeque(const std::deque<int>& d);// 函数定义在"01 definition.cpp"

/*
* deque 插入删除数据
* 
* 两端插入删除操作：
* 函数原型：
* push_back(elem);  //在容器尾部插入一个数据
* push_front(elem); //在容器头部插入一个数据
* pop_back();	    //删除容器尾部一个数据
* pop_front();      //删除容器头部一个数据
* 
* 指定位置插入删除操作：
* insert(pos, elem);     //在pos位置插入一个elem元素的拷贝，返回新的数据位置
* insert(pos, n, elem);  //在pos位置插入n个elem元素的拷贝，无返回值
* insert(pos, beg, end); //在pos位置插入[beg, end]区间的数据，无返回值
* clear();               //清空容器所有数据
* erase(beg, end);       //删除[beg, end]区间的数据，返回下一个数据的位置
* erase(pos);            //删除pos位置的数据，返回下一个数据的位置
*/
void Insert() {
	//1、两端插入删除操作
	std::deque<int> d1;

	//尾插
	d1.push_back(10);
	d1.push_back(20);

	//头插
	d1.push_front(100);
	d1.push_front(200);
	printDeque(d1);

	//2、指定位置插入删除操作
	std::cout << "------------------------\n";
	std::deque<int> d2;
	d2.push_back(10);
	d2.push_back(20);
	d2.push_back(30);
	d2.push_back(40);
	d2.push_back(50);
	printDeque(d2);

	// insert(pos, elem); 
	d2.insert(d2.begin(), 100);
	printDeque(d2);

	// insert(pos, n, elem); 
	d2.insert(d2.begin(), 2, 200);
	printDeque(d2);

	// insert(pos, beg, end);
	std::deque<int>d3;
	d3.push_back(1);
	d3.push_back(2);
	d3.push_back(3);

	d2.insert(d2.begin(), d3.begin(), d3.end());
	printDeque(d2);
}

void Delete () {
	std::deque<int> d1;
	for (size_t i = 0; i < 10; i++)
	{
		d1.push_back(10 * i);
	}
	printDeque(d1);

	//尾删
	d1.pop_back();
	printDeque(d1);

	//头删
	d1.pop_front();
	printDeque(d1);

	// erase(pos);
	d1.erase(d1.begin() + 1);
	printDeque(d1);

	// erase(beg, end); 
	d1.erase(d1.begin() + 1, d1.end());
	printDeque(d1);

	//clear
	d1.clear();
	printDeque(d1);
}


/*
* deque 数据存取
* 函数原型：
* operator[];    //在容器头部插入一个数据
* at(int index); //返回索引index所指的数据
* front();	     //返回容器中第一个数据
* back();        //返回容器中最后一个数据
*/
void Access() {
	std::deque<int> d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_back(40);
	d1.push_back(50);

	//通过operator[]方式访问元素
	for (int i = 0; i < d1.size(); i++) {
		std::cout << d1[i] << " ";
	}
	std::cout << std::endl;

	//通过at方式访问元素
	for (int i = 0; i < d1.size(); i++) {
		std::cout << d1.at(i) << " ";
	}
	std::cout << std::endl;

	// 访问容器第一个元素
	std::cout << "第一个元素为：" << d1.front() << std::endl;

	//访问容器最后一个元素
	std::cout << "最后一个元素为：" << d1.back() << std::endl;
}


/*
* 利用算法对deque 容器进行排序
* 函数原型：
* sort(iterator beg, iterator end) //对[beg, end]区间内元素进行排序
*
* 注意：排序默认升序排序，从小到大
* 对于支持随机访问的迭代器容器（包括vector），都可以利用sort算法直接对其进行排序；使用时包含头文件<algorithm>
*/
void Sort() {
	std::deque<int> d;
	d.push_back(10);
	d.push_back(30);
	d.push_back(40);
	d.push_back(20);
	d.push_back(50);
	printDeque(d);


	sort(d.begin(), d.end());
	std::cout << "排序后：\n";
	printDeque(d);
}


int main03() {
	Insert();

	std::cout << "---------------- \n";
	Delete();

	std::cout << "---------------- \n";
	Access();

	std::cout << "---------------- \n";
	Sort();

	system("pause");
	return 0;
}