#include <iostream>

namespace my_src1 {

	/*
	* ��ģ��
	* �﷨��template<class T1, class T2, ...>
	* 
	* ��ģ���뺯��ģ������
	* 1����ģ��û���Զ������Ƶ��ķ�ʽ
	* 2����ģ����ģ������б��п�����Ĭ�ϲ���
	* 3����ģ���Ա������������ʵ��
	*/

	template<class NameType, class AgeType>
	class Person {
	public:
		Person(NameType name, AgeType age) {
			m_name = name;
			m_age = age;
		}

		void showPerson() {
			std::cout << "name: " << m_name << " age: " << m_age << std::endl;
		}

		NameType m_name;
		AgeType m_age;
	};

	// 2����ģ����ģ������б��п�����Ĭ�ϲ���
	template<class NameType, class AgeType = int>
	class Person2 {
	public:
		Person2(NameType name, AgeType age) {
			m_name = name;
			m_age = age;
		}

		void showPerson() {
			std::cout << "name: " << m_name << " age: " << m_age << std::endl;
		}

		NameType m_name;
		AgeType m_age;
	};

	// 3����ģ���Ա����������ʵ��
	template<class T1, class T2>
	class Person3 {
	public:
		Person3(T1 name, T2 age);

		void showPerson();

		T1 m_name;
		T2 m_age;
	};

	// ��ģ�幹�캯������ʵ��
	template<class T1, class T2>
	Person3<T1, T2>::Person3(T1 name, T2 age) {
		m_name = name;
		m_age = age;
	}

	// ��ģ���Ա��������ʵ��
	template<class T1, class T2>
	void Person3<T1, T2>::showPerson() {
		std::cout << "name: " << m_name << " age: " << m_age << std::endl;
	}

	void Func() {
		// Person p1("Tom", 20); Error!!! �޷�ʹ���Զ������Ƶ�
		Person<std::string, int> p1("Tom", 20);// True! ֻ��ʹ����ʾָ������
		p1.showPerson();

		// Person2 ����ģ������б�ָ����int�ͣ���������ʱֻ��Ҫ��ʾָ��string���ͼ���
		Person2<std::string> p2("Jerry", 20);
		p2.showPerson();

		Person3<std::string, int>p3("Lisa", 22);
		p3.showPerson();
	}
}

int main01() {
	my_src1::Func();

	system("pause");
	return 0;
}