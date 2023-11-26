#include <iostream>

/*
* 重载函数调用操作的类，其对象称为函数对象
* 函数对象使用重载()时，行为类似函数的调用，也叫仿函数
* 函数对象（仿函数）本质是一个类，不是一个函数
* 
* 特点：
* 函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
* 函数对象超出普通函数的概念，函数对象可以有自己的状态
* 函数对象可以作为参数传递
*/

// 1、函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
class MyAdd {
public:
	int operator()(int v1, int v2) {
		return v1 + v2;
	}
};

void Case01() {
	MyAdd ad;
	std::cout << ad(10, 20) << std::endl;
}

// 2、函数对象超出普通函数的概念，函数对象可以有自己的状态
class MyPrint {
public:
	MyPrint() {
		this->count = 0;
	}

	void operator()(std::string str) {
		std::cout << str << std::endl;
		this->count++; // 统计调用次数
	}

	int count; // 内部自己状态
};

void Case02() {
	MyPrint mp;
	for (size_t i = 0; i < 4; i++)
	{
		mp("Hello World!");
	}
	std::cout << "myPrint调用次数：" << mp.count << std::endl;
}

// 3、函数对象可以作为参数传递
void doPrint(MyPrint& mp, std::string str) {
	mp(str);
}

void Case03() {
	MyPrint mp;
	doPrint(mp, "Hello C++");
}
// 总结：仿函数调用非常灵活，可以作为参数传递

int main01() {
	Case01();

	std::cout << "---------------------\n";
	Case02();

	std::cout << "---------------------\n";
	Case03();

	system("pause");
	return 0;
}