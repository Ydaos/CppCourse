#include<iostream>

//���ع�ϵ��������������Զ������Ͷ�����жԱȲ���

//��ϵ���������
class Student {
public:
	Student(std::string name, int age) {
		m_name = name;
		m_age = age;
	}

	//���� ��ϵ�����
	bool operator==(Student& p) {
		if (this->m_name == p.m_name && this->m_age == p.m_age) {
			return true;
		}
		return false;
	}

	bool operator!=(Student& p) {
		if (this->m_name != p.m_name || this->m_age != p.m_age) {
			return true;
		}
		return false;
	}

	std::string m_name;
	int m_age;
};

void Relation() {
	Student s1("Tom", 18);
	Student s2("Tom", 18);

	// "=="��ϵ���������
	if (s1 == s2) {
		std::cout << "s1��s2���\n";
	}
	else {
		std::cout << "s1��s2�����\n";
	}

	// "!="��ϵ���������
	if (s1 != s2) {
		std::cout << "s1��s2�����\n";
	}
	else {
		std::cout << "s1��s2���\n";
	}
}

int main05() {
	Relation();

	system("pause");
	return 0;
}