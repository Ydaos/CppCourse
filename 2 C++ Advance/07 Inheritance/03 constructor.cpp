#include<iostream>

//����̳и���󣬵������������Ҳ����ø���Ĺ��캯��
//�̳����ȵ��ø��๹�캯�����ٵ������๹�캯��������˳���빹���෴

namespace my_src3 {

	class Base {
	public:
		Base() {
			std::cout << "Base���캯����\n";
		}

		~Base() {
			std::cout << "Base����������\n";
		}
	};

	class Son :public Base {
	public:
		Son() {
			std::cout << "Son���캯����\n";
		}

		~Son() {
			std::cout << "Son����������\n";
		}
	};

	void Order() {
		Son s;
	}
}

int main03() {
	my_src3::Order();

	system("pause");
	return 0;
}