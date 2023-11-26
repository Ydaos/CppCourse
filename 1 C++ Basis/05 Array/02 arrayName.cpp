#include <iostream>

void array_name();
void multi_dimensional_array_name();

/*
* 一维数组名用途：
* 可以统计整个数组在内存中的长度  sizeof(arr)
* 可以获取数组在内存中的首地址
*/
void ArrayName() {
	std::cout << "\nThis is a one-dimensional array demo.\n";
	array_name();

	std::cout << "\nThis is a two-dimensional array demo.\n";
	multi_dimensional_array_name();
}

void array_name() {
	//1、统计整个数组在内存中的长度
	int arr[5] = { 1,2,3,4,5 };
	std::cout << sizeof(arr) << std::endl; //整个数组数据长度
	std::cout << sizeof(arr[0]) << std::endl; //数组单个元素数据长度
	std::cout << sizeof(arr) / sizeof(arr[0]) << std::endl; //数组元素个数

	//2、可以获取数组在内存中的首地址
	std::cout << arr << std::endl; //数组在内存中的首地址
	std::cout << &arr[0] << std::endl; //数组第一个元素的地址
	std::cout << &arr[1] << std::endl; //数组第二个元素的地址，比第一个元素地址大4，因为数据长度为4

	//arr = 100; error!!!数组名是个常量，不可以赋值
}

void multi_dimensional_array_name() {
	//二维数组名称用途；

	//1、可以查看占用内存空间大小
	int arr[2][3] = {
		{1,2,3},
		{4,5,6}
	};
	std::cout << "二维数组占用内存空间是：" << sizeof(arr) << std::endl;
	std::cout << "二维数组第一行元素占用内存空间是：" << sizeof(arr[0]) << std::endl;
	std::cout << "二维数组第一个元素占用内存空间是：" << sizeof(arr[0][0]) << std::endl;

	std::cout << "二维数组行数：" << sizeof(arr) / sizeof(arr[0]) << std::endl;
	std::cout << "二维数组列数：" << sizeof(arr[0]) / sizeof(arr[0][0]) << std::endl;

	//2、可以查看二维数组的首地址
	std::cout << "二维数组首地址：" << (int)arr << std::endl;
	std::cout << "二维数组第一行地址：" << (int)arr[0] << std::endl;
	std::cout << "二维数组第二行地址：" << (int)arr[1] << std::endl;
}

int main02() {
	ArrayName();

	system("pause");
	return 0;
}