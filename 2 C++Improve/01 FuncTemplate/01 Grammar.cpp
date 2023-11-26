#include <iostream>

namespace my_src1{

/*
* C++另一种编程思想为泛型编程，主要利用技术就是模板
* C++提供两种模板机制：函数模板和类模板
*
* 1、函数模板：
* 建立一个通用函数，其函数返回值类型和形参可以不具体制定，用一个虚拟的类型来代表
* 语法： template <typename T>
* 
* 注意事项：
* 自动类型推导必须推导出一致的数据类型才可以使用
* 模板必须确定T数据类型才能使用
*/

	// 传统编程：交换函数
	void swapInt(int& a, int& b) {
		int temp = a;
		a = b;
		b = temp;
	}
	void swapDouble(double& a, double& b) {
		double temp = a;
		a = b;
		b = temp;
	}

	void case01() {
		int a = 10;
		int b = 20;
		swapInt(a, b);
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;

		double c = 1.1;
		double d = 2.1;
		swapDouble(c, d);
		std::cout << "c = " << c << std::endl;
		std::cout << "d = " << d << std::endl;
	}


	// 泛型编程
	// 声明一个模板，告诉编译器后面的代码中紧跟着的T不要报错，T是一个数据类型
	template<typename T>  // typename 可以替换为 class；即类模板
	void mySwap(T& a, T& b) {
		T temp = a;
		a = b;
		b = temp;
	}

	void case02() {
		// 利用函数模板交换
		// 两种方式使用模板
		// 1、自动类型推导
		int a = 10;
		int b = 20;
		mySwap(a, b);
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;

		double c = 1.1;
		//mySwap(a, c); error!!!推导不出一致的T
		// 注意事项：自动类型推导必须推导出一致的数据类型才可以使用！！！

		// 2、显示指定类型
		mySwap<int>(a, b);
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
	}

	template<typename T>
	void func() {
		std::cout << "fun 调用" << std::endl;
	}

	void case03() {
		//func(); Error!!! 模板必须确定T数据类型才能使用！
		func<int>(); // TRUE 确定了数据类型
	}

}

namespace prac_space {
	
/* 
* 实现通用 对数组进行排序的函数
* 规则：从大到小
* 算法：选择排序
* 测试：char数组、int数组
*/

	// 交换函数模板
	template<typename T>
	void mySwap(T& a, T& b) {
		T temp = a;
		a = b;
		b = temp;
	}

	// 打印数组模板
	template<typename T>
	void printArr(T arr[], int len) {
		for (int i = 0; i < len; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}

	// 选择排序算法
	template<typename T>
	void mySort(T arr[], int len) {
		for (int i = 0; i < len; i++) {
			int max = i; //认定最大值下标
			for (int j = i + 1; j < len; j++) {
				if (arr[max] < arr[j]) {
					max = j; // 更新最大值下标
				}
			}
			if (max != i) {
				mySwap(arr[max], arr[i]);
			}
		}
	}

	void test() {
		// 测试char数组
		char c_arr[] = "adjgex";
		int len = sizeof(c_arr) / sizeof(char);
		mySort(c_arr, len);
		printArr(c_arr, len);

		// 测试int数组
		int i_arr[5] = { 2,3,1,5,4 };
		mySort(i_arr, 5);
		printArr(i_arr, 5);
	}
}

int main01() {
	std::cout << "---------------------\n";
	my_src1::case01();

	std::cout << "---------------------\n";
	my_src1::case02();

	std::cout << "---------------------\n";
	my_src1::case03();

	std::cout << "---------------------\n";
	prac_space::test();

	system("pause");
	return 0;
}