#include <iostream>
#include <deque>

void printDeque(const std::deque<int>& d);// 函数定义在"01 definition.cpp"

/*
* deque 大小操作
* 函数原型：
* deque.empty();              //判断容器是否为空
* deque.size();				  //返回容器中元素的个数
* deque.resize(int num);	  //重新指定容器大小为num.若容器变长则以默认值填充新位置；变短则删除多出来的元素
* deque.resize(int num, ele,) //重新指定容器大小为num，若容器变长则以elem值填充新位置；变短则删除多出来的元素
*/
void mySize() {
	std::deque<int> d1;
	for (int i = 0; i < 10; i++) {
		d1.push_back(i);
	}
	printDeque(d1);

	if (d1.empty()) {
		std::cout << "d1为空" << std::endl;
	}
	else {
		std::cout << "d1不为空" << std::endl;
		std::cout << "d1大小：" << d1.size() << std::endl;
		// deque没有容量概念
	}

	// 重新指定大小
	d1.resize(15, 2); //加长部分用2来填充
	printDeque(d1);

	d1.resize(5);     //变短会删掉多出的元素
	printDeque(d1);
}

int main02() {
	mySize();

	system("pause");
	return 0;
}