#include "boss.h"

Boss::Boss(int Id, string name, int dId) {
	this->m_id = Id;
	this->m_name = name;
	this->m_deptId = dId;
}

void Boss::showInfo() {
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ��������" << this->m_name
		<< "\tְ����λ��" << this->getDeptName()
		<< "\tְ��ְ�𣺸������·�����" << endl;
}

string Boss::getDeptName() {
	string str = "�ϰ�";
	return str;
}