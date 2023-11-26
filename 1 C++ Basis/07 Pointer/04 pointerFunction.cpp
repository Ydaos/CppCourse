#include <iostream>

//ʵ���������ֽ�������
void swap01(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
}

void swap02(int* p1, int* p2) {
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

void PointerFunc() {
	//ָ��ͺ���
	//1��ֵ����
	int a = 10;
	int b = 20;
	swap01(a, b);
	std::cout << "a = " << a << std::endl; //a = 10
	std::cout << "b = " << b << std::endl; //b = 20

	//2����ַ����
	//����ǵ�ַ���ݣ���������ʵ��
	swap02(&a, &b);
	std::cout << "a = " << a << std::endl; //a = 20
	std::cout << "b = " << b << std::endl; //b = 10
}

int main04() {
	PointerFunc();

	system("pause");
	return 0;
}