#include <iostream>

//���ã��Ӽ��̻�ȡ����
//�﷨�� cin >> ����;
void InputData() {
	//1������
	int a = 0;
	std::cout << "������ͱ���a��ֵ��\n";
	std::cin >> a;
	std::cout << "a = " << a << std::endl;

	//2��������
	float f = 3.14f;
	std::cout << "��������ͱ���f��ֵ��\n";
	std::cin >> f;
	std::cout << "f = " << f << std::endl;

	//3���ַ���
	char ch = 'a';
	std::cout << "����ַ��ͱ���ch��ֵ��\n";
	std::cin >> ch;
	std::cout << "ch = " << ch << std::endl;

	//4���ַ�����
	std::string str = "hello";
	std::cout << "����ַ����ͱ���str��ֵ��\n";
	std::cin >> str;
	std::cout << "str = " << str << std::endl;

	//5����������
	bool flag = false;
	std::cout << "����������ͱ���flag��ֵ��\n";
	std::cin >> flag; //��������ֻҪ�Ƿ�0��ֵ��Ϊ��
	std::cout << "flag = " << flag << std::endl;
}

int main() {
	InputData();

	system("pause");
	return 0;
}