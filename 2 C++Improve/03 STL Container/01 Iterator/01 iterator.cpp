#include <iostream>
#include <vector>
#include <algorithm> // ��׼�㷨ͷ�ļ���

/*
* STL (Standard Template Library,��׼ģ���)
* Ϊ��߸����ԣ�����һ�����ݽṹ���㷨�ı�׼����STL
* �����Ϊ���������㷨�͵�����
* 
*  STL��Ϊ����������������㷨����������α�������������Ϳռ���������
* 1���������������ݽṹ����vector��list��map��
* 2���㷨�����ֳ����㷨����sort��find��copy��for_each��
* 3�����������������������㷨֮��Ľ��ϼ�
* 4���º��������ƺ���������Ϊ�㷨��ĳ�ֲ���
* 5����������һ�����������������º�����������ӿڵĶ���
* 6���ռ�������������ռ�����ú͹���
* 
* STL����������㷺��һЩ���ݽṹʵ�ֳ���
* �������ݽṹ�����顢��������ջ�����С����ϡ�ӳ����
* ������Ϊ������ʽ�����͹���ʽ����
* ����ʽ������ǿ��ֵ������˳������ʽ����ÿ��Ԫ�ؾ��й̶�λ��
* ����ʽ�������������ṹ������Ԫ��֮��û���ϸ�������ϵ�˳���ϵ
* 
* �㷨(Algorithms):���޲������߼�����ѧ�ϵ�����
* �㷨��Ϊ�ʱ��㷨�ͷ��ʱ��㷨
* �ʱ��㷨����������л�ı������ڵ�Ԫ�����ݡ����翽�����滻��ɾ���ȵ�
* ���ʱ��㷨����������в���ı�������Ԫ�����ݡ�������ҡ�������������Ѱ�Ҽ�ֵ�ȵ�
* 
* ���������ṩһ�ַ�����ʹ֮�ܹ�����������������ĸ���Ԫ�أ��������豩¶���������ڲ���﷽ʽ
* ÿ�����������Լ�ר���ĵ�������������ʹ������ָ�롣
* 
* ���������ࣺ
* 1�������������������ֻ������
* 2�������������������ֻд����
* 3��ǰ�����������д������������ǰ�ƽ�������
* 4��˫�����������д������������ǰ��������
* 5��������ʵ���������д������������Ծ�ķ�ʽ�����������ݣ�������ǿ
* ���������е���������Ϊ˫���������������ʵ�������
*/

// vector������������������ͣ�����������

void myPrint(int val) {
	std::cout << val << std::endl;
}

void test() {
	// ����һ��vector����
	std::vector<int> v;

	// �������в�������
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	// ͨ�����������������е�����
	std::vector<int>::iterator itBegin = v.begin(); // ��ʼ��������ָ�������е�һ��Ԫ��
	std::vector<int>::iterator itEnd = v.end(); // ������������ָ�����������һ��Ԫ�ص���һ��λ��

	// ��һ�ֱ�����ʽ
	std::cout << "---------------------first way\n";
	while (itBegin != itEnd) {
		std::cout << *itBegin << std::endl;
		itBegin++;
	}

	// �ڶ��ֱ�����ʽ
	std::cout << "---------------------second way\n";
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << std::endl;
	}

	// �����ֱ�����ʽ ����STL�ṩ�����㷨
	std::cout << "---------------------third way\n";
	for_each(v.begin(), v.end(), myPrint);
}

// vector��������Զ����������ͣ�����������
class Person {
public:
	Person(std::string name, int age) {
		m_Name = name;
		m_Age = age;
	}

	std::string m_Name;
	int m_Age;
};

void myPersonPrint(Person p) {
	std::cout << "������" << p.m_Name << " ���䣺" << p.m_Age << std::endl;
}

void test2() {
	// ����һ��vector����
	std::vector<Person> v;

	Person p1("Tom", 20);
	Person p2("Jerry", 20);
	Person p3("Mark", 20);
	Person p4("Tony", 20);
	Person p5("Hans", 20);

	// �������в�������
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	// ͨ�����������������е�����
	std::vector<Person>::iterator itBegin = v.begin(); // ��ʼ��������ָ�������е�һ��Ԫ��
	std::vector<Person>::iterator itEnd = v.end(); // ������������ָ�����������һ��Ԫ�ص���һ��λ��

	// ��һ�ֱ�����ʽ
	std::cout << "---------------------first way\n";
	while (itBegin != itEnd) {
		std::cout << "������" << (*itBegin).m_Name << " ���䣺" << (*itBegin).m_Age << std::endl;
		itBegin++;
	}

	// �ڶ��ֱ�����ʽ
	std::cout << "---------------------second way" << std::endl;
	for (std::vector<Person>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << "������" << (*it).m_Name << " ���䣺" << (*it).m_Age << std::endl;
	}

	// �����ֱ�����ʽ ����STL�ṩ�����㷨
	std::cout << "---------------------third way\n";
	for_each(v.begin(), v.end(), myPersonPrint);
}

// ����Զ�������ָ��
void test3() {
	// ����һ��vector����
	std::vector<Person*> v;

	Person p1("Tom", 20);
	Person p2("Jerry", 20);
	Person p3("Mark", 20);
	Person p4("Tony", 20);
	Person p5("Hans", 20);

	// �������в�������
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

	// ��������
	for (std::vector<Person*>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << "������" << (*it)->m_Name << " ���䣺" << (*it)->m_Age << std::endl;
	}
}

int main01() {
	std::cout << "---------------------vector<int>\n";
	test();

	std::cout << "---------------------vector<Person>\n";
	test2();

	std::cout << "---------------------vector<Pointer*>\n";
	test3();

	system("pause");
	return 0;
}