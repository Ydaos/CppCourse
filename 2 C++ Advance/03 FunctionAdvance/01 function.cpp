#include<iostream>

/*
* 函数的默认参数
* 如果我们自己传入数据，就用自己数据，若无，则用默认值
* 注意1：如果某个位置已经有了默认参数，那么从这个位置往后从左到右都必须有默认值
* 注意2：如果函数声明有了默认参数，函数实现就不能有默认参数，否则会有二义性
*/
int func(int a, int b = 20, int c = 30) {//不能 int func(int a, int b = 20, int c)...
	return a + b + c;
}

int func2(int a = 10, int b = 20);
int func2(int a, int b) { //不能有默认参数，因为声明函数以有默认参数
	return a + b;
}

/*
* 占位参数
* C++中函数的形参列表可以有占位参数，用来占位，调用函数时必须填补该位置
* 占位参数，还可以有默认参数；有默认值，可以不填占位参数
* 
* 语法：返回值类型 函数名(数据类型){}
*/

void func3(int a, int) {
	std::cout << "this is func3.\n";
}

void func4(int a, int = 10) {
	std::cout << "this is func4.\n";
}

void Function01() {
	std::cout << func(10, 30) << std::endl;
	std::cout << func2(10) << std::endl;

	func3(10, 10);
	func4(10); //有默认值，可以不填占位参数
}

int main01() {
	Function01();

	system("pause");
	return 0;
}
