#include<iostream>

//�����������ķ���ֵ
//1����Ҫ���ؾֲ�����������
int& test1() {
	int a = 10; //�ֲ������������ջ��
	return a;
}

//2�������ĵ��ÿ�����Ϊ��ֵ
int& test2() {
	static int a = 10; //��̬�����������ȫ����
	return a;
}

void FuncReturn() {

	int& ref1 = test1();
	std::cout << "ref = " << ref1 << std::endl; //��һ�ν����ȷ����Ϊ�������������ݱ���
	std::cout << "ref = " << ref1 << std::endl; //�ڶ��ν��������Ϊ�ڴ��Ѿ��ͷ�

	int& ref2 = test2();
	std::cout << "ref = " << ref2 << std::endl;
	std::cout << "ref = " << ref2 << std::endl;

	test2() = 1000; //��������ķ���ֵ�����ã�����������ÿ�����Ϊ��ֵ
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