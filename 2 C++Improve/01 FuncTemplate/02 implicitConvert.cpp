#include <iostream>

namespace my_src2 {

	/*
	* 普通函数与函数模板区别
	* 1、普通函数调用可以发生隐式类型转换
	* 2、函数模板 用自动类型推导，不可以发生隐式类型转换
	* 3、函数模板 用显示指定类型，可以发生隐式类型转换
	*/

	// 普通函数
	int myAdd(int a, int b) {
		return a + b;
	}

	// 模板函数
	template<typename T>
	T myAdd2(T a, T b) {
		return a + b;
	}

	void Func() {
		int a = 10;
		int b = 20;
		char c = 'c';

		std::cout << myAdd(a, b) << std::endl;
		// 隐式转换，c会转换为ASIIC码和整型发生运算 c - 99
		std::cout << myAdd(a, c) << std::endl;

		// 自动类型推导
		std::cout << myAdd2(a, b) << std::endl;
		// std::cout << myAdd2(a, c) << std::endl; Error!!! 无法推导T的类型！即无法发生隐式类型转换

		// 显示指定类型
		std::cout << myAdd2<int>(a, c) << std::endl;
		// 确定T的类型，可以发生隐式类型转换，会将 char 类型的强转换为int 型
	}
	// 总结：建议使用显示指定类型的方式，调用函数模板。能自己确定类型和发生隐式类型转换

}

int main02() {
	my_src2::Func();

	system("pause");
	return 0;
}