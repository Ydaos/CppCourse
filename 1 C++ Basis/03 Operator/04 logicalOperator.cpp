#include <iostream>

void LogicalOperator() {
	//�߼������
	// ! ��
	int a = 1;
	std::cout << !a << std::endl; //aΪ�棬!aΪ��

	// && ��
	int b = 0;
	std::cout << (a && b) << std::endl; //a��b��ͬʱΪ�棬(a && b)Ϊ��

	// || ��
	std::cout << (a || b) << std::endl; //a��b��ͬʱΪ�٣�(a || b)Ϊ��
}

int main() {
	LogicalOperator();

	system("pause");
	return 0;
}