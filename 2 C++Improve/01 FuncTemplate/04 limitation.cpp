#include <iostream>

namespace my_src4 {

	/*
	* 模板的局限性
	* 模板并不是万能的，某些特定数据类型需要具体化方式做特殊实现
	*/

	class Person {
	public:
		Person(std::string name, int age) {
			m_name = name;
			m_age = age;
		}

		std::string m_name;
		int m_age;
	};

	// 对比两个数据是否相等函数
	template<typename T>
	bool myCompare(T& a, T& b) {
		if (a == b) {
			return true;
		}
		return false;
	}

	// 利用具体化Person版本实现代码，具体化优先调用
	template<> bool myCompare(Person& p1, Person& p2) {
		if (p2.m_name == p2.m_name && p1.m_age == p2.m_age) {
			return true;
		}
		return false;
	}

	void Func() {
		int a = 10;
		int b = 20;
		bool ret = myCompare(a, b);

		if (ret) {
			std::cout << "a == b" << std::endl;
		}
		else {
			std::cout << "a != b" << std::endl;
		}

		// 自定义类型
		Person p1("Tom", 10);
		Person p2("Tom", 10);
		ret = myCompare(p1, p2);

		if (ret) {
			std::cout << "p1 == p2" << std::endl;
		}
		else {
			std::cout << "p1 != p2" << std::endl;
		}
	}

	// 总结：
	// 利用具体化的模板，可以解决自定义类型的 通用化
	// 学习模板并不是为了写模板，而是在STL能够系统提供的模板
}

int main() {
	my_src4::Func();

	system("pause");
	return 0;
}