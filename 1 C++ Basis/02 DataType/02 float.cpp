#include <iostream>

/*
* ʵ�ͣ������ͣ�
* 1�������� float 4�ֽ�
* 2��˫���� double 8�ֽ�
* �����������ڱ�ʾ����Ч���ַ�Χ��ͬ 3.14 ��Ч����Ϊ3��
*/

void RealType() {

	float f1 = 3.1415926f;//����f����С�������ݱ�����Ĭ��Ϊdouble Ȼ��ת��Ϊfloat��
	std::cout << "f1 = " << f1 << std::endl;

	double d1 = 3.1415926;
	std::cout << "d1 = " << d1 << std::endl;

	//Ĭ������� ���һ��С��������ʾ��6 λ��Ч����
	std::cout << "float ռ�õ��ڴ�ռ�Ϊ" << sizeof(float) << std::endl; //4�ֽ�
	std::cout << "double ռ�õ��ڴ�ռ�Ϊ" << sizeof(double) << std::endl; //8�ֽ�

	//��ѧ������
	float f2 = 3e2; //3 * 10 ^ 2;
	std::cout << "f2 = " << f2 << std::endl;

	float f3 = 3e-2f; //3 * 0.1 ^ 2;
	std::cout << "f3 = " << f3 << std::endl;
}

int main02() {
	RealType();

	system("pause");
	return 0;
}