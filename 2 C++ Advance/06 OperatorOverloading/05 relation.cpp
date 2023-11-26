#include<iostream>

//重载关系运算符，让两个自定义类型对象进行对比操作

//关系运算符重载
class Student {
public:
	Student(std::string name, int age) {
		m_name = name;
		m_age = age;
	}

	//重载 关系运算符
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

	// "=="关系运算符重载
	if (s1 == s2) {
		std::cout << "s1和s2相等\n";
	}
	else {
		std::cout << "s1和s2不相等\n";
	}

	// "!="关系运算符重载
	if (s1 != s2) {
		std::cout << "s1和s2不相等\n";
	}
	else {
		std::cout << "s1和s2相等\n";
	}
}

int main05() {
	Relation();

	system("pause");
	return 0;
}