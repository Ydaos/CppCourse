#include<iostream>

//��ʼ���б�
//�﷨�����캯��():����1(ֵ1),����2(ֵ2),����3(ֵ3)...{}

class Person {
public:
	//��ͳ��ʼ������
	/*Person(int a,int b,int c) {
		m_A = a;
		m_B = b;
		m_C = c;
	}*/

	//��ʼ���б��ʼ������
	Person(int a, int b, int c) :m_A(a), m_B(b), m_C(c) {

	}

	~Person() {
		std::cout << "Person��������������\n";
	}

public:
	int m_A;
	int m_B;
	int m_C;
};

void InitList() {
	Person p1(10, 20, 30);
	std::cout << p1.m_A << std::endl;
	std::cout << p1.m_B << std::endl;
	std::cout << p1.m_C << std::endl;
}

int main03() {
	InitList();

	system("pause");
	return 0;
}