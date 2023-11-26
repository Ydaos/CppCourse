#include <iostream>
#include <deque>

/*
* deque容器：双端数组，可以对头端进行插入和删除操作
* deque内部工作原理
* deque内部有个中控器，维护每段缓冲区中的内容，缓冲区中存放真实数据
* 中控器维护的是每个缓冲区的地址，使得使用deque时像一片连续的内存空间
* deque的迭代器也是支持随机访问的
* 
* deque与vector区别：
* 1、vector对于头部插入删除效率低，数据量越大效率越低
* 2、deque相对而言，对头部的插入删除速度会比vector快
* 3、vector访问元素时的速度会比deque快，两者内部实现不同导致
*/

void printDeque(const std::deque<int>& d) {
	for (std::deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}


/*
* deque容器构造函数
* 函数原型：
* deque<T> deqT;           //默认构造形式
* deque<beg, end>;         //构造函数将[beg, end]区间中的元素拷贝给本身
* deque(n, elem);          //构造函数将n个elem拷贝个给本身
* deque(const deque &deq); //拷贝构造函数
*/
void Constructor() {
	std::deque<int> d;
	for (int i = 0; i < 10; i++) {
		d.push_back(i);
	}
	printDeque(d);

	std::deque<int>d2(d.begin(), d.end());
	printDeque(d2);

	std::deque<int>d3(10, 6);
	printDeque(d3);

	std::deque<int>d4(d);
	printDeque(d4);
}


/*
* deque赋值操作
* 函数原型：
* deque& operator=(const deque &deq); //重载=运算符
* assign(beg, end);				      //将[beg, end]区间中的元素拷贝给本身
* assign(n, elem);			          //将n个elem拷贝个给本身
*/
void Assignment() {
	std::deque<int> d1;
	for (int i = 0; i < 10; i++) {
		d1.push_back(i);
	}
	printDeque(d1);

	// operator =
	std::deque<int>d2;
	d2 = d1;
	printDeque(d2);

	// assign(beg, end)
	std::deque<int>d3;
	d3.assign(d1.begin(), d1.end());
	printDeque(d3);

	// assign(n, elem)
	std::deque<int>d4;
	d4.assign(10, 6);
	printDeque(d4);
}

int main01() {
	Constructor();

	std::cout << "----------------------------\n";
	Assignment();

	system("pause");
	return 0;
}