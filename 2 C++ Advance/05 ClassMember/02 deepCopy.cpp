#include<iostream>

//ǳ�������򵥸�ֵ�Ŀ�������
//������ڶ�����������ռ䣬���п�������

class Person {
public:
	Person() {
		std::cout << "Person��Ĭ�Ϲ��캯������\n";
	}
	Person(int age, int height) {
		std::cout << "Person���вι��캯������\n";
		m_age = age;
		m_height = new int(height);
	}

	//�Լ�ʵ������Ŀ������캯�������ǳ��������������
	Person(const Person& p) {
		std::cout << "Person�Ŀ������캯������\n";
		m_age = p.m_age;
		//m_height = p.m_height; ������Ĭ�ϲ�����ǳ����
		m_height = new int(*p.m_height);
	}

	~Person() {
		//�������룬�����������������ͷŲ���
		if (m_height != NULL) {
			delete m_height;
			m_height = NULL;
		}
		std::cout << "Person��������������\n";
	}

public:
	int m_age = 0; //����
	int* m_height = NULL; //���
};


void DeepCopy() {
	Person p1(18, 170);
	std::cout << "p1������Ϊ��" << p1.m_age << std::endl;
	std::cout << "p1�����Ϊ��" << *p1.m_height << std::endl;

	Person p2(p1);
	std::cout << "p2������Ϊ��" << p2.m_age << std::endl;
	std::cout << "p2�����Ϊ��" << *p2.m_height << std::endl;
	//p2����ñ�����Ĭ�ϵĿ������캯����ִ�е���ǳ������
	//ǳ����������������Ƕ������ڴ��ظ��ͷţ�

	//ջ���Ƚ������p2���ȱ��ͷţ���ִ������
}
//�ܽ᣺�����Ķ������ڶ������ٵģ�һ��Ҫ�Լ��ṩ�������캯������ֹǳ���������Ķ����ڴ��ظ��ͷ����⡣

int main02() {
	DeepCopy();

	system("pause");
	return 0;
}