#include <iostream>
#include <string> //2019VS����Ҫ��������string���� ��Ӧ���������ϰ��

void String() {

	//C����ַ����� char ������[] = "�ַ���ֵ"
	//ע�����char�ַ�����[]
	//ע������2���Ⱥź����˫���Ű��������ַ���ֵ
	char str1[] = "Hello World";
	std::cout << "str1 = " << str1 << std::endl;

	//C++����ַ�����string ������ = "�ַ���ֵ"
	//����ͷ�ļ� #include <string>
	std::string str2 = "Hello World";
	std::cout << "str2 = " << str2 << std::endl;
}

int main04() {
	String();

	system("pause");
	return 0;
}