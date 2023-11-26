#include <iostream>
#include <map>

/*
* map������
* mapĬ�������ǰ���keyֵ��С�����������÷º������Ըı��������
* �����Զ������ͣ�map����ָ���������ͬset����
*/

// 1�����÷º����ı�Ĭ���������
class MyCompare {// ����
public:
	bool operator()(int v1, int v2)const {
		return v1 > v2;
	}
};

void MySort01() {
	std::map<int, int, MyCompare> m1;
	m1.insert(std::pair<int, int>(1, 10));
	m1.insert(std::pair<int, int>(3, 20));
	m1.insert(std::pair<int, int>(2, 30));
	m1.insert(std::pair<int, int>(4, 40));
	m1.insert(std::pair<int, int>(5, 50));

	for (std::map<int, int, MyCompare>::iterator it = m1.begin(); it != m1.end(); it++) {
		std::cout << "key = " << (*it).first << " value = " << (*it).second << std::endl;
	}
	std::cout << std::endl;
}

// 2�����Զ����������ݣ�ָ���������
class Person {
public:
	Person(std::string name, int age) {
		this->m_Name = name;
		this->m_Age = age;
	}

	std::string m_Name;
	int m_Age;
};

class MyCompare2 {// �����併��
public:
	bool operator()(const Person& p1, const Person& p2)const {
		return p1.m_Age > p2.m_Age;
	}
};

void MySort02() {
	// ��������
	Person p1("Tom", 18);
	Person p2("Jersey", 16);
	Person p3("Hans", 20);
	Person p4("Mark", 22);

	// ����
	std::map<Person, int, MyCompare2> m1;
	m1.insert(std::pair<Person, int>(p1, 170));
	m1.insert(std::pair<Person, int>(p3, 160));
	m1.insert(std::pair<Person, int>(p2, 180));
	m1.insert(std::pair<Person, int>(p4, 175));

	for (std::map<Person, int, MyCompare2>::iterator it = m1.begin(); it != m1.end(); it++) {
		std::cout << "������" << (*it).first.m_Name << " ���䣺" << (*it).first.m_Age << " ��ߣ�" << (*it).second << std::endl;
	}
	std::cout << std::endl;
}

int main04() {
	MySort01();

	std::cout << "-------------------\n";
	MySort02();

	system("pause");
	return 0;
}