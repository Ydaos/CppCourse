#include <iostream>

namespace my_src3 {

	/*
	* ��ģ��ʵ�������Ķ����������εķ�ʽ
	* 1��ָ����������� --- ֱ����ʾ�������������
	* 2������ģ�廯     --- �������еĲ�����Ϊģ����д���
	* 3��������ģ�廯   --- �������������ģ�廯���д���
	* 
	* ʹ����㷺�ǵ�һ�֣��ɶ������
	*/

	template<class T1, class T2>
	class Person {
	public:
		Person(T1 name, T2 age) {
			m_name = name;
			m_age = age;
		}

		void showPerson() {
			std::cout << "������" << m_name << " ���䣺" << m_age << std::endl;
		}

		T1 m_name;
		T2 m_age;
	};

	// 1��ָ�����������
	void printPerson1(Person<std::string, int>& p) {
		p.showPerson();
	}

	// 2������ģ�廯
	template<class T1, class T2>
	void printPerson2(Person<T1, T2>& p) {
		p.showPerson();

		// ��ӡT1��T2���������Ϳ��Ե��� typeid().name();
		std::cout << "T1�����ͣ�" << typeid(T1).name() << std::endl;
		std::cout << "T2�����ͣ�" << typeid(T2).name() << std::endl;
	}

	// 3��������ģ�廯
	template<class T>
	void printPerson3(T& p) {
		p.showPerson();

		std::cout << "T�����ͣ�" << typeid(T).name() << std::endl;
	}

	void Func() {
		Person<std::string, int> p1("�����", 100);
		printPerson1(p1);

		Person<std::string, int> p2("��˽�", 90);
		printPerson2(p2);

		Person<std::string, int> p3("������", 30);
		printPerson3(p3);
	}
}

int main03() {
	my_src3::Func();

	system("pause");
	return 0;
}