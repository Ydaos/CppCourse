#include <iostream>

/*
* 类对象作为另一个类成员
* 构造时：先构造类对象，再构造自身。
* 析构时：先析构自身，再析构类对象。
*/
class Phone {
public:
	Phone(std::string pName) {
		std::cout << "Phone的构造函数调用\n";
		m_Pname = pName;
	}

	~Phone() {
		std::cout << "Phone的析构函数调用\n";
	}

	//手机品牌
	std::string m_Pname;
};

class Person {
public:
	//列表初始化 m_phone(pName) === Phone m_phone = pName; //隐式转换 
	Person(std::string name, std::string pName) :m_name(name), m_phone(pName) {
		std::cout << "Person构造函数调用\n";
	}

	~Person() {
		std::cout << "Person的析构函数调用\n";
	}

	std::string m_name;
	Phone m_phone;
};

void ClassObject() {
	Person p("King", "iphone13");
	std::cout << p.m_name << "拿着" << p.m_phone.m_Pname << std::endl;
}

int main04() {
	ClassObject();

	system("pause");
	return 0;
}