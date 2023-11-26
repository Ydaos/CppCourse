#include <iostream>

namespace my_src3 {

	/*
	* ��ͨ�����ͺ���ģ����ù���
	* 1�������ͨ�����ͺ���ģ�嶼����ʵ�֣����ȵ�����ͨ����
	* 2������ͨ����ģ������б���ǿ�Ƶ��ú���ģ��
	* 3������ģ����Է�������
	* 4���������ģ����Բ������õ�ƥ�䣬���ȵ��ú���ģ��
	* 
	* ����ṩ����ģ�壬��ò�Ҫ���ṩ��ͨ�������������������
	*/

	int myPrint(int a, int b) {
		std::cout << "���õ�����ͨ����" << std::endl;
		return a + b;
	}

	template<class T>
	T myPrint(T a, T b) {
		std::cout << "���õ��Ǻ���ģ��" << std::endl;
		return a + b;
	}

	template<typename T>
	void myPrint(T a, T b, T c) {
		std::cout << "���õ������صĺ���ģ��" << std::endl;
	}

	void Func() {
		int a = 10;
		int b = 20;
		// ���ȵ�����ͨ����
		myPrint(a, b);

		// ͨ����ģ������б�ǿ�Ƶ��ú���ģ��
		myPrint<>(a, b);

		// ����ģ����Է�������
		myPrint(a, b, 1);

		// �������ģ����Բ������õ�ƥ�䣬���ȵ��ú���ģ��
		char c1 = 'a';
		char c2 = 'b';
		myPrint(c1, c2);
	}

	// �ܽ᣺����ṩ����ģ�壬��ò�Ҫ���ṩ��ͨ�������������ײ���������
}

int main03() {
	my_src3::Func();

	system("pause");
	return 0;
}