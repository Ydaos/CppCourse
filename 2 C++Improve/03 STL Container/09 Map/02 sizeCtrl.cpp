#include <iostream>
#include <map>

void printMap(std::map<int, int>& m); //函数定义在"01 definition.cpp"

/*
* map的大小和交换
* 函数原型：
* size();	 // 返回容器元素个数
* empty();	 // 判断容器是否为空
* swap(st); // 交换两个容器
*/
void MySize() {
	std::map<int, int> m1;
	m1.insert(std::pair<int, int>(1, 10));
	m1.insert(std::pair<int, int>(3, 20));
	m1.insert(std::pair<int, int>(2, 30));
	m1.insert(std::pair<int, int>(4, 40));
	m1.insert(std::pair<int, int>(5, 50));
	printMap(m1);

	if (m1.empty()) {
		std::cout << "容器为空\n";
	}
	else {
		std::cout << "容器不为空\n";
		std::cout << "容器元素个数：" << m1.size() << std::endl;
	}
}

// 容器交换
void MySwap() {
	std::map<int, int> m1;
	m1.insert(std::pair<int, int>(1, 10));
	m1.insert(std::pair<int, int>(3, 20));
	m1.insert(std::pair<int, int>(2, 30));
	m1.insert(std::pair<int, int>(4, 40));
	m1.insert(std::pair<int, int>(5, 50));

	std::map<int, int>m2;
	m2.insert(std::pair<int, int>(1, 100));
	m2.insert(std::pair<int, int>(3, 200));
	m2.insert(std::pair<int, int>(2, 300));
	m2.insert(std::pair<int, int>(4, 400));
	m2.insert(std::pair<int, int>(5, 500));
	std::cout << "交换前：\n";
	printMap(m1);
	printMap(m2);

	m1.swap(m2);
	std::cout << "交换后：\n";
	printMap(m1);
	printMap(m2);
}

int main02() {
	MySize();

	std::cout << "-------------------\n";
	MySwap();

	system("pause");
	return 0;
}