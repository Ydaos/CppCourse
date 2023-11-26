#include "manager.h"

Manager::Manager(int Id, string name, int dId) {
	this->m_id = Id;
	this->m_name = name;
	this->m_deptId = dId;
}

void Manager::showInfo() {
	cout << "职工编号：" << this->m_id
		<< "\t职工姓名：" << this->m_name
		<< "\t职工岗位：" << this->getDeptName()
		<< "\t职工职责：完成老板交给的任务，并下发任务给普通员工" << endl;
}

string Manager::getDeptName() {
	string str = "经理";
	return str;
}