#include <iostream>

//作用：使用指针访问数组中元素
void PointerArray() {
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	std::cout << "第一个元素为：" << arr[0] << std::endl;

	int* p = arr;//arr就是数组的首地址
	std::cout << "利用指针访问第一个元素为：" << *p << std::endl;
	p++; //让指针向后偏移4个字节
	std::cout << "利用指针访问第二个元素为：" << *p << std::endl;

	int* p2 = arr;
	for (int i = 0; i < 10; i++) {
		std::cout << "利用指针访问第" << i + 1 << "个元素为：" << *p2 << std::endl;
		p2++;
	}
}

int main03() {
	PointerArray();

	system("pause");
	return 0;
}