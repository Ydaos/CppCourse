#include<iostream>

//引用的基本语法
//数据类型 &别名 = 原名
//注意事项：引用必须初始化，初始化后，不可以改变

void Reference() {
	int a = 10;
	int b = 20;

	//创建引用
	//int& ref1; error!引用必须初始化
	int& ref1 = a;
	//&ref1 = b; error! 引用初始化后不可以更改引用对象

	std::cout << "a = " << a << std::endl;
	std::cout << "ref1 = " << ref1 << std::endl;

	ref1 = 100;
	std::cout << "a = " << a << std::endl;
	std::cout << "ref1 = " << ref1 << std::endl;

	//引用的本质是一个指针常量
	int& ref2 = a;//自动转换为：int* const ref = &a
	ref2 = 20;    //内部发现ref是引用，自动帮我们转换为：*ref = 20;

	//总结C++推荐用引用技术，因为比指针方便，引用本质是指针常量，但是所有的指针操作编译器帮我们做了
}

int main() {
	Reference();

	system("pause");
	return 0;
}