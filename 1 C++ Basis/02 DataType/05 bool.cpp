#include <iostream>

/*
* �����������ʹ������ٵ�ֵ
* true �棨������1��
* false �٣�������0��
* bool������ֻռ��һ���ֽڴ�С
*/

void Bool() {
	//1����������������
	bool flag = true; //��
	std::cout << flag << std::endl;
	flag = false;
	std::cout << flag << std::endl;
	//������1���������ֵ��0����ٵ�ֵ

	//����������ռ�ڴ�ռ�
	std::cout << "��������ռ�ڴ�ռ� " << sizeof(bool) << std::endl;
}

int main05() {
	Bool();

	system("pause");
	return 0;
}