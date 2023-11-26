#include <iostream>

void LogicalOperator() {
	//逻辑运算符
	// ! 非
	int a = 1;
	std::cout << !a << std::endl; //a为真，!a为假

	// && 与
	int b = 0;
	std::cout << (a && b) << std::endl; //a与b不同时为真，(a && b)为假

	// || 或
	std::cout << (a || b) << std::endl; //a与b不同时为假，(a || b)为真
}

int main() {
	LogicalOperator();

	system("pause");
	return 0;
}