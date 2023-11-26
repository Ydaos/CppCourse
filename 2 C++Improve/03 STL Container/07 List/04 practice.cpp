#include <iostream>
#include <list>
#include <string>

namespace prac_space {

	/*
	* List��������
	* ��Person�Զ����������ͽ�������Person�����������������䡢���
	* ������򣺰�����������������������ͬ������߽��н���
	*/

	class Person {
	public:
		Person(std::string name, int age, int height) {
			this->m_Name = name;
			this->m_Age = age;
			this->m_Height = height;
		}

		std::string m_Name;
		int m_Age;
		int m_Height;
	};

	void printList(const std::list<Person>& l) {
		for (std::list<Person>::const_iterator it = l.begin(); it != l.end(); it++) {
			std::cout << "������" << (*it).m_Name << " ���䣺" << (*it).m_Age << " ��ߣ�" << (*it).m_Height << std::endl;
		}
		std::cout << std::endl;
	}

	//ָ������ ����
	bool myCompare(Person& p1, Person& p2) {
		// ����������
		if (p1.m_Age == p2.m_Age) {
			// ������ͬ ����߽���
			return p1.m_Height > p2.m_Height;
		}
		return p1.m_Age < p2.m_Age;
	}

	void Func() {
		// ׼������
		Person p1("Tom", 18, 170);
		Person p2("Jerry", 17, 150);
		Person p3("Tony", 20, 170);
		Person p4("Mark", 20, 168);
		Person p5("Hans", 22, 180);

		// ��������������������
		std::list<Person>L;
		L.push_back(p1);
		L.push_back(p2);
		L.push_back(p3);
		L.push_back(p4);
		L.push_back(p5);
		std::cout << "����ǰ��" << std::endl;
		printList(L);

		// ����
		std::cout << "�����" << std::endl;
		L.sort(myCompare); //��ν�ʿ���ָ���������
		printList(L);
	}
}


/*
* �ܽ᣺
* �����Զ����������ͣ�����Ҫָ��������򣬷����������֪����ν�������
* �߼�����ֻ��������������ٽ���һ���߼������ƶ�����������
*/
int main() {
	prac_space::Func();

	system("pause");
	return 0;
}