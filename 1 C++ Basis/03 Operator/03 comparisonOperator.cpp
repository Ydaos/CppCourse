#include <iostream>

void ComparisonOperator() {
	// 比较运算符
	// ==
	int a = 10;
	int b = 20;
	std::cout << (a == b) << std::endl; //输出0

	// !=
	std::cout << (a != b) << std::endl; //输出1

	// >
	std::cout << (a > b) << std::endl; //输出0

	// < 
	std::cout << (a < b) << std::endl; //输出1

	// >=
	std::cout << (a >= b) << std::endl; //输出0

	// <=
	std::cout << (a <= b) << std::endl; //输出1
}

int main03() {
	ComparisonOperator();

	system("pause");
	return 0;
}