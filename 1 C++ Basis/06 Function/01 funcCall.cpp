#include <iostream>

/*
* �������岽��
* 1������ֵ���� void int double bool ...
* 2�������� add
* 3�������б�
* 4�����������
* 5��return���ʽ
*/

/* 
* ���������﷨��
* ����ֵ���� ��������(�����б�)
* {
*	���������
* }
*/

/*
* ����ӷ�����
* ��������ʱ��num1��num2��û����ʵ����
* a��bֻ��һ����ʽ�Ĳ���������β�
*/
int add(int num1, int num2)
{
	int sum = num1 + num2;
	return sum;
}

/*
* main�����е���add���� �﷨���������� (����)
* a��b��Ϊʵ�ʲ��������ʵ��
* �����ú���ʱ��ʵ�ε�ֵ�ᴫ�ݸ��β�
*/
int main01() {
	int a = 10;
	int b = 20;
	int sum = add(a, b);
	std::cout << "a + b = " << sum << std::endl;

	system("pause");
	return 0;
}



