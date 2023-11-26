#include <iostream>

/*
* ��������أ������е���������½��ж��壬��������һ�ֹ�������Ӧ��ͬ��������
* 
* ������������أ�+ - * /
* ���ַ�ʽ��
* 1����Ա�������أ��ԼӺ�Ϊ����
* 2��ȫ�ֺ������أ��Գ˺�Ϊ����
* 
* ע�����
* �������õ��������͵ı��ʽ��������ǲ����ܸı��
* ��Ҫ�������������
*/

//1����Ա��������+��
class Person {
public:
	Person(int a, int b) {
		m_A = a;
		m_B = b;
	}

	Person operator+(Person& p) {
		Person temp(m_A + p.m_A, m_B + p.m_B);
		return temp;
	}

	int m_A = 0;
	int m_B = 0;
};

//2��ȫ�ֺ�������*��
Person operator*(Person& p1, Person& p2) {
	Person temp(p1.m_A * p2.m_A, p1.m_B * p2.m_B);
	return temp;
}

Person operator*(Person& p1, int num) {
	Person temp(p1.m_A * num, p1.m_B * num);
	return temp;
}

void Arithmetic() {
	//1����Ա��������+��
	Person p1(10, 20);
	Person p2(10, 20);

	//��Ա�������ر��ʵ��ã�Person p3 = p1.operator+(p2);
	Person p3 = p1 + p2;
	std::cout << "p3:" << p3.m_A << " " << p3.m_B << std::endl;
	
	//2��ȫ�ֺ�������*��
	//ȫ�ֺ������ر��ʵ��ã�Person p4 = operator*(p1, p2);
	Person p4 = p1 * p2;
	std::cout << "p4:" << p4.m_A << " " << p4.m_B << std::endl;

	//���������Ҳ���Է�����������
	Person p5 = p1 * 10;
	std::cout << "p5:" << p5.m_A << " " << p5.m_B << std::endl;
}

int main() {
	Arithmetic();

	system("pause");
	return 0;
}