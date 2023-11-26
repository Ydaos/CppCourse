#include<iostream>

/*
* ��̳У�C++����һ����̳ж����
* �﷨��class ���� :�̳з�ʽ ����1, �̳з�ʽ ����2 ...
* ��̳п��ܻ�������������ͬ����Ա���֣���Ҫ������������
* C++ʵ�ʿ����в��Ƽ���̳�
*/

namespace my_src5 {
	class Base1 {
	public:
		Base1() {
			m_A = 100;
		}

		int m_A;
	};

	class Base2 {
	public:
		Base2() {
			m_A = 150;
			m_B = 200;
		}

		int m_A;
		int m_B;
	};

	class Son :public  Base1, public Base2 {
	public:
		Son() {
			m_C = 300;
			m_D = 400;
		}

		int m_C;
		int m_D;
	};

	void Super() {
		Son s;
		std::cout << "sizeof Son = " << sizeof(Son) << std::endl;
		
		//���������������Ա����Ҫ������������
		std::cout << "Base1 m_A = " << s.Base1::m_A << std::endl;
		std::cout << "Base2 m_A = " << s.Base2::m_A << std::endl;
	}
}

int main05() {
	my_src5::Super();

	system("pause");
	return 0;
}