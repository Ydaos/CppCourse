#include <iostream>
#include <vector>

void printVector(std::vector<int>& v);// 函数定义在01 definition.cpp

/*
* vector互换容器
* 函数原型：
* swap(v);  -- 将v与本身的元素互换
* swap本质是指针交换，结果是容器交换
*/

// 1、基本使用
void Swap01() {
	std::cout << "交换前\n";
	std::vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	printVector(v1);

	std::vector<int>v2;
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	v2.push_back(4);
	v2.push_back(5);
	printVector(v2);

	std::cout << "交换后\n";
	v1.swap(v2);
	printVector(v1);
	printVector(v2);
}

// 2、实际用途：巧用swap收缩内存
void Swap02() {
	std::vector<int>v;
	for (int i = 0; i < 100000; i++) {
		v.push_back(i);
	}
	std::cout << "v的容量：" << v.capacity() << std::endl;
	std::cout << "v的大小：" << v.size() << std::endl;

	v.resize(3); //重新指定大小
	std::cout << "v的容量：" << v.capacity() << std::endl;
	std::cout << "v的大小：" << v.size() << std::endl;
	// 结果size=3，但容量依旧为13W+ 造成内存空间浪费！！！

	// 巧用swap可以收缩内存
	std::vector<int>(v).swap(v); //vector<int>(v) 匿名对象！当前行执行完会立即回收
	std::cout << "v的容量：" << v.capacity() << std::endl;
	std::cout << "v的大小：" << v.size() << std::endl;

	// 总结:swap本质是指针交换，结果是使两个容器交换，可以达到实际的收缩内存效果
}


int main04() {
	Swap01();
	std::cout << "--------------------------\n";
	Swap02();

	system("pause");
	return 0;
}