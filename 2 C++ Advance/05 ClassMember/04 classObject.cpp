#include <iostream>

/*
* �������Ϊ��һ�����Ա
* ����ʱ���ȹ���������ٹ�������
* ����ʱ�����������������������
*/
class Phone {
public:
	Phone(std::string pName) {
		std::cout << "Phone�Ĺ��캯������\n";
		m_Pname = pName;
	}

	~Phone() {
		std::cout << "Phone��������������\n";
	}

	//�ֻ�Ʒ��
	std::string m_Pname;
};

class Person {
public:
	//�б��ʼ�� m_phone(pName) === Phone m_phone = pName; //��ʽת�� 
	Person(std::string name, std::string pName) :m_name(name), m_phone(pName) {
		std::cout << "Person���캯������\n";
	}

	~Person() {
		std::cout << "Person��������������\n";
	}

	std::string m_name;
	Phone m_phone;
};

void ClassObject() {
	Person p("King", "iphone13");
	std::cout << p.m_name << "����" << p.m_phone.m_Pname << std::endl;
}

int main04() {
	ClassObject();

	system("pause");
	return 0;
}