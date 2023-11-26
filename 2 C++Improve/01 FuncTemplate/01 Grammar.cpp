#include <iostream>

namespace my_src1{

/*
* C++��һ�ֱ��˼��Ϊ���ͱ�̣���Ҫ���ü�������ģ��
* C++�ṩ����ģ����ƣ�����ģ�����ģ��
*
* 1������ģ�壺
* ����һ��ͨ�ú������亯������ֵ���ͺ��βο��Բ������ƶ�����һ�����������������
* �﷨�� template <typename T>
* 
* ע�����
* �Զ������Ƶ������Ƶ���һ�µ��������Ͳſ���ʹ��
* ģ�����ȷ��T�������Ͳ���ʹ��
*/

	// ��ͳ��̣���������
	void swapInt(int& a, int& b) {
		int temp = a;
		a = b;
		b = temp;
	}
	void swapDouble(double& a, double& b) {
		double temp = a;
		a = b;
		b = temp;
	}

	void case01() {
		int a = 10;
		int b = 20;
		swapInt(a, b);
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;

		double c = 1.1;
		double d = 2.1;
		swapDouble(c, d);
		std::cout << "c = " << c << std::endl;
		std::cout << "d = " << d << std::endl;
	}


	// ���ͱ��
	// ����һ��ģ�壬���߱���������Ĵ����н����ŵ�T��Ҫ����T��һ����������
	template<typename T>  // typename �����滻Ϊ class������ģ��
	void mySwap(T& a, T& b) {
		T temp = a;
		a = b;
		b = temp;
	}

	void case02() {
		// ���ú���ģ�彻��
		// ���ַ�ʽʹ��ģ��
		// 1���Զ������Ƶ�
		int a = 10;
		int b = 20;
		mySwap(a, b);
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;

		double c = 1.1;
		//mySwap(a, c); error!!!�Ƶ�����һ�µ�T
		// ע������Զ������Ƶ������Ƶ���һ�µ��������Ͳſ���ʹ�ã�����

		// 2����ʾָ������
		mySwap<int>(a, b);
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
	}

	template<typename T>
	void func() {
		std::cout << "fun ����" << std::endl;
	}

	void case03() {
		//func(); Error!!! ģ�����ȷ��T�������Ͳ���ʹ�ã�
		func<int>(); // TRUE ȷ������������
	}

}

namespace prac_space {
	
/* 
* ʵ��ͨ�� �������������ĺ���
* ���򣺴Ӵ�С
* �㷨��ѡ������
* ���ԣ�char���顢int����
*/

	// ��������ģ��
	template<typename T>
	void mySwap(T& a, T& b) {
		T temp = a;
		a = b;
		b = temp;
	}

	// ��ӡ����ģ��
	template<typename T>
	void printArr(T arr[], int len) {
		for (int i = 0; i < len; i++) {
			std::cout << arr[i] << " ";
		}
		std::cout << std::endl;
	}

	// ѡ�������㷨
	template<typename T>
	void mySort(T arr[], int len) {
		for (int i = 0; i < len; i++) {
			int max = i; //�϶����ֵ�±�
			for (int j = i + 1; j < len; j++) {
				if (arr[max] < arr[j]) {
					max = j; // �������ֵ�±�
				}
			}
			if (max != i) {
				mySwap(arr[max], arr[i]);
			}
		}
	}

	void test() {
		// ����char����
		char c_arr[] = "adjgex";
		int len = sizeof(c_arr) / sizeof(char);
		mySort(c_arr, len);
		printArr(c_arr, len);

		// ����int����
		int i_arr[5] = { 2,3,1,5,4 };
		mySort(i_arr, 5);
		printArr(i_arr, 5);
	}
}

int main01() {
	std::cout << "---------------------\n";
	my_src1::case01();

	std::cout << "---------------------\n";
	my_src1::case02();

	std::cout << "---------------------\n";
	my_src1::case03();

	std::cout << "---------------------\n";
	prac_space::test();

	system("pause");
	return 0;
}