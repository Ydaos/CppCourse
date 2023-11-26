#include <iostream>

/*
* �̳���ͬ����Ա����
* 1������������ֱ�ӷ��������е�ͬ��
* 2������������������Է��ʸ���ͬ����Ա
* 3��������͸���ӵ��ͬ���ĳ�Ա��������������ظ�����ͬ����Ա����������������Է��ʵ������ͬ����Ա����
* 4��ͬ����̬��Ա����ʽ�ͷǾ�̬����ʽһ����ֻ���������ַ��ʷ�ʽ��ͨ�������ͨ��������
*/

namespace my_src4 {

	class Base {
	public:
		Base() {
			m_A = 100;
		}

		void func() {
			std::cout << "Base - func() ����\n";
		}

		void func(int a) {
			std::cout << "Base - func(int a) ����\n";
		}

		//��̬��Ա����
		static void func1() {
			std::cout << "Base - static func() ����\n";
		}

		static void func1(int a) {
			std::cout << "Base - static func(int a) ����\n";
		}

		int m_A;
		static int m_B; //�����������ⶨ��
	};
	int Base::m_B = 100;

	class Son :public Base {
	public:
		Son() {
			m_A = 200;
		}

		void func() {
			std::cout << "Son - func() ����\n";
		}

		//��̬��Ա����
		static void func1() {
			std::cout << "Son - static func() ����\n";
		}

		static void func1(int a) {
			std::cout << "Son - static func(int a) ����\n";
		}

		int m_A;
		static int m_B;
	};
	int Son::m_B = 200;

	//ͬ������̬����Ա���Դ���ʽ
	void ClassVar() {
		Son s;
		std::cout << "Son �µ�m_A = " << s.m_A << std::endl;        //ֱ�ӵ��õ��õ��������ͬ����Ա
		std::cout << "Base �µ�m_A = " << s.Base::m_A << std::endl; //���ͨ�����������ʸ����ͬ����Ա����Ҫ��������

		//1��ͨ���������ʾ�̬ͬ����Ա
		std::cout << "Son �µ�static m_B = " << s.m_B << std::endl;
		std::cout << "Base �µ�static m_B = " << s.Base::m_B << std::endl;

		//2��ͨ�����������ͬ����̬��Ա
		std::cout << "ͨ����������� Son �µ�static m_B = " << Son::m_B << std::endl;

		//��һ��::����ͨ��������ʽ���ʣ��ڶ���::������������
		std::cout << "ͨ����������� Base �µ�static m_B = " << Son::Base::m_B << std::endl;
	}

	//ͬ������̬����Ա��������ʽ
	void ClassFunc() {
		Son s;
		s.func();       //ֱ�ӵ��õ��õ��������ͬ����Ա
		s.Base::func(); //���ͨ�����������ʸ����ͬ����Ա����Ҫ��������

		//��������г����˺͸���ͬ���ĳ�Ա�����������ͬ����Ա���������ε���������ͬ����Ա����
		//�������ʸ����б����ص�ͬ����Ա��������Ҫ��������
		s.Base::func(10);

		//1��ͨ���������ʾ�̬ͬ������
		std::cout << "ͨ����������\n";
		s.func1();
		s.Base::func1();

		//2��ͨ�����������ͬ����̬��Ա����
		std::cout << "ͨ�����������\n";
		Son::func1();
		Son::Base::func1();
	}
}

int main04() {
	std::cout << "\n-------------- Demo of class variable --------------\n";
	my_src4::ClassVar();

	std::cout << "\n-------------- Demo of class function --------------\n";
	my_src4::ClassFunc();

	system("pause");
	return 0;
}