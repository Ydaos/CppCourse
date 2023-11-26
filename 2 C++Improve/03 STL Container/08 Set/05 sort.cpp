#include <iostream>
#include <set>

/*
* set��������
* set����Ĭ�������С����
* ���÷º��������Ըı��������
* �����Զ����������ͣ�set����ָ���������ſ��Բ�������
*/

// 1�����÷º������ı䳣�������������
class MyCompare {
public:
	bool operator()(int v1, int v2)const {
		return v1 > v2;
	}
};

void MySort01() {
	std::set<int> s1;
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(50);
	s1.insert(40);
	
	for (std::set<int>::const_iterator it = s1.begin(); it != s1.end(); it++) {
		std::cout << (*it) << " ";
	}
	std::cout << std::endl;

	// ָ���������Ϊ����
	std::set<int, MyCompare>s2;
	s2.insert(10);
	s2.insert(30);
	s2.insert(20);
	s2.insert(50);
	s2.insert(40);

	for (std::set<int, MyCompare>::iterator it = s2.begin(); it != s2.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

// 2�����÷º������ı��Զ��������������
class Person {
public:
	Person(std::string name, int age) {
		this->m_Name = name;
		this->m_Age = age;
	}

	std::string m_Name;
	int m_Age;
};

class MyCompare2 {
public:
	bool operator()(const Person& p1, const Person& p2)const {
		// ������������
		return p1.m_Age > p2.m_Age;
	}
};

void MySort02() {
	// �Զ������� ��Ҫָ���������
	std::set<Person, MyCompare2> s;

	// ��������
	Person p1("Tom", 18);
	Person p2("Jerry", 16);
	Person p3("Hans", 22);
	Person p4("Mark", 20);

	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);

	for (std::set<Person, MyCompare2>::iterator it = s.begin(); it != s.end(); it++) {
		std::cout << "������" << it->m_Name << " ���䣺" << it->m_Age << std::endl;
	}
}

// �ܽ᣺
// ���÷º�������ָ��set�����������
// �����Զ����������ͣ�set����ָ���������ſ��Բ�������
int main() {
	MySort01();

	std::cout << "-------------------\n";
	MySort02();

	system("pause");
	return 0;
}