#include "employees.h"

Employees::Employees(int Id, string name, int dId) {
	this->m_id = Id;
	this->m_name = name;
	this->m_deptId = dId;
}

void Employees::showInfo() {
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ��������" << this->m_name
		<< "\tְ����λ��" << this->getDeptName()
		<< "\tְ��ְ����ɾ�����������" << endl;
}

string Employees::getDeptName() {
	string str = "Ա��";
	return str;
}