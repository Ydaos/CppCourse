#include <iostream>

//实现两个数字交换函数
void swap01(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

void swap02(int* p1, int* p2) {
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void PointerFunc() {
	//指针和函数
	//1、值传递
	int a = 10;
	int b = 20;
	swap01(a, b);
	std::cout << "a = " << a << std::endl; //a = 10
	std::cout << "b = " << b << std::endl; //b = 20

	//2、地址传递
	//如果是地址传递，可以修饰实参
	swap02(&a, &b);
	std::cout << "a = " << a << std::endl; //a = 20
	std::cout << "b = " << b << std::endl; //b = 10
}

int main04() {
	PointerFunc();

	system("pause");
	return 0;
}