#include <iostream>

void ComparisonOperator() {
	// �Ƚ������
	// ==
	int a = 10;
	int b = 20;
	std::cout << (a == b) << std::endl; //���0

	// !=
	std::cout << (a != b) << std::endl; //���1

	// >
	std::cout << (a > b) << std::endl; //���0

	// < 
	std::cout << (a < b) << std::endl; //���1

	// >=
	std::cout << (a >= b) << std::endl; //���0

	// <=
	std::cout << (a <= b) << std::endl; //���1
}

int main03() {
	ComparisonOperator();

	system("pause");
	return 0;
}