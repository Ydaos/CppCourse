#include<iostream>

/*
* ��������
* ��Ա�������const ���ǳ��������Ϊ������
* �������������޸ĳ�Ա����
* ��Ա��������ʱ�ӹؼ���mutable���ڳ���������Ȼ�����޸�
*
* ������
* ��������ǰ��const �Ƹö���Ϊ������
* ������ֻ�ܵ��ó�����
*/

class Person {
public:
	//thisָ�뱾����ָ�볣�� ָ���ָ���ǲ������޸ĵ�
	void showPerson() {
		this->m_A = 100;
		this->m_B = 100;
		//this = NULL; //error������thisָ�벻�����޸�ָ���ָ��
	}

	//�ڳ�Ա���������const�����ε���thisָ�롣��ָ��ָ���ֵҲ�������޸�
	void showPerson2()const {
		//this->m_A = 100; //error������
		this->m_B = 200;
	}

	int m_A;
	mutable int m_B; //�����������ʹ�ڳ���������Ȼ�����޸�
};

void ConstFunc() {
	Person p1;
	p1.showPerson();
	p1.showPerson2();

	// �����󣨲����ã�
	const Person p2; //�ڶ���ǰ��const����Ϊ������
	//p2.m_A = 100;  //error!!!�����󲻿����޸�
	p2.m_B = 200;    //�����������������������޸�

	//p2.showPerson();
	p2.showPerson2(); //������ֻ�ܵ��ó�����
}

int main07() {
	ConstFunc();

	system("pause");
	return 0;
}