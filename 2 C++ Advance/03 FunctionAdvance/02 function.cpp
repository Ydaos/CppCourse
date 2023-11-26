#include<iostream>

/*
* 函数重载：函数名可以相同，提高复用性
* 满足条件：
* 1、同一个作用域下
* 2、函数名称相同
* 3、函数参数类型不同，或者个数不同，或者顺序不同
* 
* 注意事项：
* 函数返回值不可以作为函数重载的条件
* &和const 可以作为重载条件
* 函数的默认参数可能会导致函数调用二义性，要尽量避免
*/

namespace space_ov {

	void func() {
		std::cout << "func 的调用\n";
	}

	void func(int a) {
		std::cout << "func(int a) 的调用\n";
	}

	//int func(int a) { Error!!!
	//	std::cout << "func(int a) 的调用\n";
	//}

	void func(double a) {
		std::cout << "func(double a) 的调用\n";
	}

	void func(int a, double b) {
		std::cout << "func(int a, double b) 的调用\n";
	}

	void func(double b, int a) {
		std::cout << "func(double b, int a) 的调用\n";
	}

	//函数重载注意事项
	//1、引用或const作为重载的条件
	void func1(int& a) {
		std::cout << "func1(int& a)的调用\n";
	}

	void func1(const int& a) {
		std::cout << "func1(const int& a)的调用\n";
	}

	//2、函数重载碰到默认参数
	void func2(int a) {
		std::cout << "func2(int a)的调用\n";
	}

	void func2(int a, int b = 10) {
		std::cout << "func2(int a, int b = 10)的调用\n";
	}

	void MyFunc() {
		func();
		func(1);
		func(3.14);
		func(1, 3.14);
		func(3.14, 1);

		std::cout << "---------------------------------\n";
		int a = 10;
		func1(a); //const 可以作为函数重载条件
		func1(10);

		//func2(10); //但函数重载有默认参数，容易出现二义性，尽量避免
	}
}


int main() {
	space_ov::MyFunc();

	system("pause");
	return 0;
}