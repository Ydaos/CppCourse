#include<iostream>

//���õĻ����﷨
//�������� &���� = ԭ��
//ע��������ñ����ʼ������ʼ���󣬲����Ըı�

void Reference() {
	int a = 10;
	int b = 20;

	//��������
	//int& ref1; error!���ñ����ʼ��
	int& ref1 = a;
	//&ref1 = b; error! ���ó�ʼ���󲻿��Ը������ö���

	std::cout << "a = " << a << std::endl;
	std::cout << "ref1 = " << ref1 << std::endl;

	ref1 = 100;
	std::cout << "a = " << a << std::endl;
	std::cout << "ref1 = " << ref1 << std::endl;

	//���õı�����һ��ָ�볣��
	int& ref2 = a;//�Զ�ת��Ϊ��int* const ref = &a
	ref2 = 20;    //�ڲ�����ref�����ã��Զ�������ת��Ϊ��*ref = 20;

	//�ܽ�C++�Ƽ������ü�������Ϊ��ָ�뷽�㣬���ñ�����ָ�볣�����������е�ָ���������������������
}

int main() {
	Reference();

	system("pause");
	return 0;
}