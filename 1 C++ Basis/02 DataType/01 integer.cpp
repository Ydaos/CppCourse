#include <iostream>

/*
* �������ʹ�������: ������������ʵ��ڴ�ռ�
* 
* sizeof����������ڴ���ռ�ڴ��С
* �﷨��sizeof(�������� / ����)
* 
* ת���ַ������ڱ�ʾһЩ������ʾ��ASCII�ַ� \n \t \\
* ���з� \n 
* ��б�� \\
* ˮƽ�Ʊ�� \t ���ÿ��������������� \tһ��ռ�˸��ո�
*/

void Integer() {
	//����
	//1�������� short��-32768~32767��2�ֽ�16λ
	short num1 = 32769;//������ݷ�Χ����ӡ���-32767

	//2������ int 4�ֽ�32λ
	int num2 = 32789;

	//3�������� long win 4�ֽ�32λ��Linux��x32��4�ֽڣ���x64��8�ֽ�
	long num3 = 10;

	//4���������� long long 8�ֽ�64λ
	long long num4 = 10;

	std::cout << num1 << "\t" << num2 << "\t" << num3 << "\t" << num4 << std::endl;
}

int main01() {
	std::cout << "intռ���ڴ�ռ�Ϊ��" << sizeof(int) << std::endl;

	//ת���ַ������ڱ�ʾһЩ������ʾ��ASCII�ַ�
	std::cout << "aaaa\tHello World\n";
	std::cout << "aa\tHello World\n";

	Integer();

	system("pause");
	return 0;
}