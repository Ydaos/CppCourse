#include "manager.h"

Manager::Manager(int Id, string name, int dId) {
	this->m_id = Id;
	this->m_name = name;
	this->m_deptId = dId;
}

void Manager::showInfo() {
	cout << "ְ����ţ�" << this->m_id
		<< "\tְ��������" << this->m_name
		<< "\tְ����λ��" << this->getDeptName()
		<< "\tְ��ְ������ϰ彻�������񣬲��·��������ͨԱ��" << endl;
}

string Manager::getDeptName() {
	string str = "����";
	return str;
}