#include <iostream>

void ArithmeticOperator() {
	//�Ӽ��˳�
	int a1 = 10;
	int b1 = 3;
	std::cout << "a1 + b1 = " << a1 + b1 << std::endl;
	std::cout << "a1 - b1 = " << a1 - b1 << std::endl;
	std::cout << "a1 * b1 = " << a1 * b1 << std::endl;
	std::cout << "a1 / b1 = " << a1 / b1 << std::endl; //���Ϊ3������������������ȻΪ����

	int a3 = 10;
	int b3 = 0;
	//std::cout << a3 / b3 << std::endl; //error!��������Ϊ0

	double d1 = 0.5;
	double d2 = 0.22;
	std::cout << "d1 / d2 = " << d1 / d2 << std::endl; //������Ҳ������С��

	//ȡģ��ȡ�ࣩ���� 
	int a4 = 10;
	int b4 = 3;
	std::cout << "a4 % b4 = " << a4 % b4 << std::endl; //���Ϊ1��ȡģ���㱾�ʾ���������

	int a5 = 10;
	int b5 = 0;
	//std::cout << a5 % b5 << std::endl; //ȡģ���㣬��������Ϊ0

	/*double d3 = 5;
	double d4 = 1;
	std::cout << d3 % d4 << std::endl;
	//error!!!����С��������ȡģ����*/

	//1��ǰ�õ���
	int a6 = 10;
	++a6; //�ñ���+1
	std::cout << "++a6 = " << a6 << std::endl;

	//2�����õ���
	int b6 = 10;
	b6++; //�ñ���+1
	std::cout << "b6++ = " << b6 << std::endl;

	//3��ǰ�õ����ͺ��õ�������
	//ǰ�õ������ñ���+1��Ȼ���������
	int a7 = 10;
	int b7 = ++a7 * 10;
	std::cout << "b7 = " << b7 << std::endl;

	//���õ����Ȳ������㣬�ٶԱ�������+1��
	int a8 = 10;
	int b8 = a8++ * 10;
	std::cout << "b8 = " << b8 << std::endl;
}

int main01() {
	ArithmeticOperator();

	system("pause");
	return 0;
}