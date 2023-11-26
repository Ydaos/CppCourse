#include<iostream>

/*
* �������أ�������������ͬ����߸�����
* ����������
* 1��ͬһ����������
* 2������������ͬ
* 3�������������Ͳ�ͬ�����߸�����ͬ������˳��ͬ
* 
* ע�����
* ��������ֵ��������Ϊ�������ص�����
* &��const ������Ϊ��������
* ������Ĭ�ϲ������ܻᵼ�º������ö����ԣ�Ҫ��������
*/

namespace space_ov {

	void func() {
		std::cout << "func �ĵ���\n";
	}

	void func(int a) {
		std::cout << "func(int a) �ĵ���\n";
	}

	//int func(int a) { Error!!!
	//	std::cout << "func(int a) �ĵ���\n";
	//}

	void func(double a) {
		std::cout << "func(double a) �ĵ���\n";
	}

	void func(int a, double b) {
		std::cout << "func(int a, double b) �ĵ���\n";
	}

	void func(double b, int a) {
		std::cout << "func(double b, int a) �ĵ���\n";
	}

	//��������ע������
	//1�����û�const��Ϊ���ص�����
	void func1(int& a) {
		std::cout << "func1(int& a)�ĵ���\n";
	}

	void func1(const int& a) {
		std::cout << "func1(const int& a)�ĵ���\n";
	}

	//2��������������Ĭ�ϲ���
	void func2(int a) {
		std::cout << "func2(int a)�ĵ���\n";
	}

	void func2(int a, int b = 10) {
		std::cout << "func2(int a, int b = 10)�ĵ���\n";
	}

	void MyFunc() {
		func();
		func(1);
		func(3.14);
		func(1, 3.14);
		func(3.14, 1);

		std::cout << "---------------------------------\n";
		int a = 10;
		func1(a); //const ������Ϊ������������
		func1(10);

		//func2(10); //������������Ĭ�ϲ��������׳��ֶ����ԣ���������
	}
}


int main() {
	space_ov::MyFunc();

	system("pause");
	return 0;
}