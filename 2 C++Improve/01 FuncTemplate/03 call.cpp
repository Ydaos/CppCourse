#include <iostream>

namespace my_src3 {

	/*
	* 普通函数和函数模板调用规则
	* 1、如果普通函数和函数模板都可以实现，优先调用普通函数
	* 2、可以通过空模板参数列表来强制调用函数模板
	* 3、函数模板可以发生重载
	* 4、如果函数模板可以产生更好的匹配，优先调用函数模板
	* 
	* 如果提供函数模板，最好不要再提供普通函数，避免产生二义性
	*/

	int myPrint(int a, int b) {
		std::cout << "调用的是普通函数" << std::endl;
		return a + b;
	}

	template<class T>
	T myPrint(T a, T b) {
		std::cout << "调用的是函数模板" << std::endl;
		return a + b;
	}

	template<typename T>
	void myPrint(T a, T b, T c) {
		std::cout << "调用的是重载的函数模板" << std::endl;
	}

	void Func() {
		int a = 10;
		int b = 20;
		// 优先调用普通函数
		myPrint(a, b);

		// 通过空模板参数列表强制调用函数模板
		myPrint<>(a, b);

		// 函数模板可以发生重载
		myPrint(a, b, 1);

		// 如果函数模板可以产生更好的匹配，优先调用函数模板
		char c1 = 'a';
		char c2 = 'b';
		myPrint(c1, c2);
	}

	// 总结：如果提供函数模板，最好不要再提供普通函数，否则容易产生二义性
}

int main03() {
	my_src3::Func();

	system("pause");
	return 0;
}