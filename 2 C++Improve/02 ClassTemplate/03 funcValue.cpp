#include <iostream>

namespace my_src3 {

	/*
	* 类模板实例化出的对象，向函数传参的方式
	* 1、指定传入的类型 --- 直接显示对象的数据类型
	* 2、参数模板化     --- 将对象中的参数变为模板进行传递
	* 3、整个类模板化   --- 将这个对象类型模板化进行传递
	* 
	* 使用最广泛是第一种，可读性最好
	*/

	template<class T1, class T2>
	class Person {
	public:
		Person(T1 name, T2 age) {
			m_name = name;
			m_age = age;
		}

		void showPerson() {
			std::cout << "姓名：" << m_name << " 年龄：" << m_age << std::endl;
		}

		T1 m_name;
		T2 m_age;
	};

	// 1、指定传入的类型
	void printPerson1(Person<std::string, int>& p) {
		p.showPerson();
	}

	// 2、参数模板化
	template<class T1, class T2>
	void printPerson2(Person<T1, T2>& p) {
		p.showPerson();

		// 打印T1和T2的数据类型可以调用 typeid().name();
		std::cout << "T1的类型：" << typeid(T1).name() << std::endl;
		std::cout << "T2的类型：" << typeid(T2).name() << std::endl;
	}

	// 3、整个类模板化
	template<class T>
	void printPerson3(T& p) {
		p.showPerson();

		std::cout << "T的类型：" << typeid(T).name() << std::endl;
	}

	void Func() {
		Person<std::string, int> p1("孙悟空", 100);
		printPerson1(p1);

		Person<std::string, int> p2("猪八戒", 90);
		printPerson2(p2);

		Person<std::string, int> p3("唐玄奘", 30);
		printPerson3(p3);
	}
}

int main03() {
	my_src3::Func();

	system("pause");
	return 0;
}