#include <iostream>

/*
* �﷨��char ch = 'a'; 
* �ַ��ͱ���ֻռ��һ���ֽ��ڴ�
* �ַ��ͱ������ǰ��ַ�����浽�ڴ��У����ǽ���Ӧ��ASCII�������洢��Ԫ
*/

void Character() {
	//1���ַ��ͱ���������ʽ
	char ch = 'A';
	std::cout << "ch = " << ch << std::endl;

	//2���ַ��ͱ�����ռ�ռ��С
	std::cout << "�ַ��ͱ�����ռ�ڴ� " << sizeof(ch) << std::endl;

	//3���ַ��ͱ�����������
	//char ch2 = "b"; error! �����ַ��ͱ���Ҫ�õ�����
	//char ch3 = 'abcde'; error! �����ַ��ͱ�������������ֻ����һ���ַ�

	//4���ַ��ͱ�����Ӧ��ASCII����
	std::cout << "ASCII�룺" << (int)ch << std::endl;
	//A - 65
	//a - 97
}

int main03() {
	Character();

	system("pause");
	return 0;
}