#include <iostream>

namespace my_src6 {

	/*
	* ��ģ�������Ԫ���������ں�����ʵ��
	* 1��ȫ�ֺ�������ʵ�� - ֱ��������������Ԫ����
	* 2��ȫ�ֺ�������ʵ�� - ��Ҫ��ǰ�ñ�����֪��ȫ�ֺ����Ĵ���
	* 
	* ����ȫ�ֺ�������ʵ�֣��÷��򵥶��ұ���������ֱ��ʶ��
	*/

	// 2��ȫ�ֺ�������ʵ��
	// ���ñ�����֪��Person���ڣ�������������ʵ�ֵ�ȫ�ֺ���ģ��
	template<class T1, class T2>
	class Person;

	// ȫ�ֺ�������ʵ�����ඨ��ǰ�����������֪�������������
	template<class T1, class T2>
	void printPerson2(Person<T1, T2> p) {
		std::cout << "����ʵ��" << std::endl;
		std::cout << "������" << p.m_name << " ���䣺" << p.m_age << std::endl;
	}

	// ͨ��ȫ�ֺ��� ��ӡperson��Ϣ
	template<class T1, class T2>
	class Person {
		// ȫ�ֺ�������ʵ��
		friend void printPerson(Person<T1, T2> p) {
			std::cout << "����ʵ��" << std::endl;
			std::cout << "������" << p.m_name << " ���䣺" << p.m_age << std::endl;
		}

		// ȫ�ֺ�������ʵ��
		// ���ȫ�ֺ���������ʵ�֣���Ҫ�ñ�����֪����������Ĵ���
		// �ӿ�ģ������б� ���߱������Ǻ���ģ�������
		friend void printPerson2<>(Person<T1, T2> p);

	public:
		Person(T1 name, T2 age) {
			m_name = name;
			m_age = age;
		}

	private:
		T1 m_name;
		T2 m_age;
	};

	void Func() {
		Person<std::string, int> p("Tom", 20);
		printPerson(p);

		printPerson2(p);
	}
}

int main06() {
	my_src6::Func();

	system("pause");
	return 0;
}