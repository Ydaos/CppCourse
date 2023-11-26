#include<iostream>

/*
* C++���������ٸ�һ��������ĸ�������
* 1��Ĭ�Ϲ��캯��(�޲Σ�������Ϊ��)
* 2��Ĭ����������(�޲Σ�������Ϊ��)
* 3��Ĭ�Ͽ������캯���������Խ���ֵ����
* 4����ֵ�����operator= �������Խ���ֵ����
* 
* �����������ָ�����������ֵ����Ҳ�������ǳ��������
*/

//��ֵ���������
class Person {
public:
	Person(int age) {
		m_age = new int(age);
	}

	~Person() {
		if (m_age != NULL) {
			delete m_age;
			m_age = NULL;
		}
	}

	//���� ��ֵ�����
	Person& operator=(Person& p) {
		//���������ṩǳ����
		//m_age = p.m_age;

		//Ӧ�����ж��Ƿ��������ڶ�������������ͷŸɾ����ٽ����������
		if (m_age != NULL) {
			delete m_age;
			m_age = NULL;
		}
		//���
		m_age = new int(*p.m_age);

		//���ض����� ��ʽ����˼�룡����
		return *this;
	}

	int* m_age;
};

void Assignment() {
	Person p1(18);
	Person p2(20);
	Person p3(30);

	p3 = p2 = p1;   //��ʽ����˼�룡����
	std::cout << "p1�����䣺" << *p1.m_age << std::endl;
	std::cout << "p2�����䣺" << *p2.m_age << std::endl;
	std::cout << "p3�����䣺" << *p3.m_age << std::endl;
}

int main04() {
	Assignment();

	system("pause");
	return 0;
}