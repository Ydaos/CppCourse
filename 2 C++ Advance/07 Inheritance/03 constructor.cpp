#include<iostream>

//子类继承父类后，当创建子类对象，也会调用父类的构造函数
//继承中先调用父类构造函数，再调用子类构造函数，析构顺序与构造相反

namespace my_src3 {

	class Base {
	public:
		Base() {
			std::cout << "Base构造函数！\n";
		}

		~Base() {
			std::cout << "Base析构函数！\n";
		}
	};

	class Son :public Base {
	public:
		Son() {
			std::cout << "Son构造函数！\n";
		}

		~Son() {
			std::cout << "Son析构函数！\n";
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