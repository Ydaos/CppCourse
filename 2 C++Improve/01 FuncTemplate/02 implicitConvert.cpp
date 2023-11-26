#include <iostream>

namespace my_src2 {

	/*
	* ��ͨ�����뺯��ģ������
	* 1����ͨ�������ÿ��Է�����ʽ����ת��
	* 2������ģ�� ���Զ������Ƶ��������Է�����ʽ����ת��
	* 3������ģ�� ����ʾָ�����ͣ����Է�����ʽ����ת��
	*/

	// ��ͨ����
	int myAdd(int a, int b) {
		return a + b;
	}

	// ģ�庯��
	template<typename T>
	T myAdd2(T a, T b) {
		return a + b;
	}

	void Func() {
		int a = 10;
		int b = 20;
		char c = 'c';

		std::cout << myAdd(a, b) << std::endl;
		// ��ʽת����c��ת��ΪASIIC������ͷ������� c - 99
		std::cout << myAdd(a, c) << std::endl;

		// �Զ������Ƶ�
		std::cout << myAdd2(a, b) << std::endl;
		// std::cout << myAdd2(a, c) << std::endl; Error!!! �޷��Ƶ�T�����ͣ����޷�������ʽ����ת��

		// ��ʾָ������
		std::cout << myAdd2<int>(a, c) << std::endl;
		// ȷ��T�����ͣ����Է�����ʽ����ת�����Ὣ char ���͵�ǿת��Ϊint ��
	}
	// �ܽ᣺����ʹ����ʾָ�����͵ķ�ʽ�����ú���ģ�塣���Լ�ȷ�����ͺͷ�����ʽ����ת��

}

int main02() {
	my_src2::Func();

	system("pause");
	return 0;
}