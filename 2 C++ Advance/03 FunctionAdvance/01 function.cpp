#include<iostream>

/*
* ������Ĭ�ϲ���
* ��������Լ��������ݣ������Լ����ݣ����ޣ�����Ĭ��ֵ
* ע��1�����ĳ��λ���Ѿ�����Ĭ�ϲ�������ô�����λ����������Ҷ�������Ĭ��ֵ
* ע��2�����������������Ĭ�ϲ���������ʵ�־Ͳ�����Ĭ�ϲ�����������ж�����
*/
int func(int a, int b = 20, int c = 30) {//���� int func(int a, int b = 20, int c)...
	return a + b + c;
}

int func2(int a = 10, int b = 20);
int func2(int a, int b) { //������Ĭ�ϲ�������Ϊ������������Ĭ�ϲ���
	return a + b;
}

/*
* ռλ����
* C++�к������β��б������ռλ����������ռλ�����ú���ʱ�������λ��
* ռλ��������������Ĭ�ϲ�������Ĭ��ֵ�����Բ���ռλ����
* 
* �﷨������ֵ���� ������(��������){}
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
	func4(10); //��Ĭ��ֵ�����Բ���ռλ����
}

int main01() {
	Function01();

	system("pause");
	return 0;
}
