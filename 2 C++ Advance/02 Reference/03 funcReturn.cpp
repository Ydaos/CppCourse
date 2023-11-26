#include<iostream>

//引用做函数的返回值
//1、不要返回局部变量的引用
int& test1() {
	int a = 10; //局部变量，存放在栈区
	return a;
}

//2、函数的调用可以作为左值
int& test2() {
	static int a = 10; //静态变量，存放在全局区
	return a;
}

void FuncReturn() {

	int& ref1 = test1();
	std::cout << "ref = " << ref1 << std::endl; //第一次结果正确，因为编译器做了数据保留
	std::cout << "ref = " << ref1 << std::endl; //第二次结果错误，因为内存已经释放

	int& ref2 = test2();
	std::cout << "ref = " << ref2 << std::endl;
	std::cout << "ref = " << ref2 << std::endl;

	test2() = 1000; //如果函数的返回值是引用，这个函数调用可以作为左值
	std::cout << "ref = " << ref2 << std::endl;
	std::cout << "ref = " << ref2 << std::endl;
	static int a = 20;
	std::cout << a << std::endl;
}

int main03() {
	FuncReturn();

	system("pause");
	return 0;
}