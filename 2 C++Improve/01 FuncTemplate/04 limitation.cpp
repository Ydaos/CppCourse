#include <iostream>

namespace my_src4 {

	/*
	* ģ��ľ�����
	* ģ�岢�������ܵģ�ĳЩ�ض�����������Ҫ���廯��ʽ������ʵ��
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

	// �Ա����������Ƿ���Ⱥ���
	template<typename T>
	bool myCompare(T& a, T& b) {
		if (a == b) {
			return true;
		}
		return false;
	}

	// ���þ��廯Person�汾ʵ�ִ��룬���廯���ȵ���
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

		// �Զ�������
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

	// �ܽ᣺
	// ���þ��廯��ģ�壬���Խ���Զ������͵� ͨ�û�
	// ѧϰģ�岢����Ϊ��дģ�壬������STL�ܹ�ϵͳ�ṩ��ģ��
}

int main() {
	my_src4::Func();

	system("pause");
	return 0;
}