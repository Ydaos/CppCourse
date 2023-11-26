#include <iostream>

void ArithmeticOperator() {
	//加减乘除
	int a1 = 10;
	int b1 = 3;
	std::cout << "a1 + b1 = " << a1 + b1 << std::endl;
	std::cout << "a1 - b1 = " << a1 - b1 << std::endl;
	std::cout << "a1 * b1 = " << a1 * b1 << std::endl;
	std::cout << "a1 / b1 = " << a1 / b1 << std::endl; //结果为3，两个整型相除结果任然为整型

	int a3 = 10;
	int b3 = 0;
	//std::cout << a3 / b3 << std::endl; //error!除数不能为0

	double d1 = 0.5;
	double d2 = 0.22;
	std::cout << "d1 / d2 = " << d1 / d2 << std::endl; //运算结果也可以是小数

	//取模（取余）运算 
	int a4 = 10;
	int b4 = 3;
	std::cout << "a4 % b4 = " << a4 % b4 << std::endl; //结果为1，取模运算本质就是求余数

	int a5 = 10;
	int b5 = 0;
	//std::cout << a5 % b5 << std::endl; //取模运算，除数不能为0

	/*double d3 = 5;
	double d4 = 1;
	std::cout << d3 % d4 << std::endl;
	//error!!!两个小数不能做取模运算*/

	//1、前置递增
	int a6 = 10;
	++a6; //让变量+1
	std::cout << "++a6 = " << a6 << std::endl;

	//2、后置递增
	int b6 = 10;
	b6++; //让变量+1
	std::cout << "b6++ = " << b6 << std::endl;

	//3、前置递增和后置递增区别
	//前置递增先让变量+1，然后参与运算
	int a7 = 10;
	int b7 = ++a7 * 10;
	std::cout << "b7 = " << b7 << std::endl;

	//后置递增先参与运算，再对变量进行+1；
	int a8 = 10;
	int b8 = a8++ * 10;
	std::cout << "b8 = " << b8 << std::endl;
}

int main01() {
	ArithmeticOperator();

	system("pause");
	return 0;
}