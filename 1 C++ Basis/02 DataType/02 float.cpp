#include <iostream>

/*
* 实型（浮点型）
* 1、单精度 float 4字节
* 2、双精度 double 8字节
* 两者区别在于表示的有效数字范围不同 3.14 有效数字为3；
*/

void RealType() {

	float f1 = 3.1415926f;//不加f，带小数的数据编译器默认为double 然后转换为float；
	std::cout << "f1 = " << f1 << std::endl;

	double d1 = 3.1415926;
	std::cout << "d1 = " << d1 << std::endl;

	//默认情况下 输出一个小数，会显示出6 位有效数字
	std::cout << "float 占用的内存空间为" << sizeof(float) << std::endl; //4字节
	std::cout << "double 占用的内存空间为" << sizeof(double) << std::endl; //8字节

	//科学记数法
	float f2 = 3e2; //3 * 10 ^ 2;
	std::cout << "f2 = " << f2 << std::endl;

	float f3 = 3e-2f; //3 * 0.1 ^ 2;
	std::cout << "f3 = " << f3 << std::endl;
}

int main02() {
	RealType();

	system("pause");
	return 0;
}