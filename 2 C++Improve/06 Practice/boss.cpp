#include "boss.h"

Boss::Boss(int Id, string name, int dId) {
	this->m_id = Id;
	this->m_name = name;
	this->m_deptId = dId;
}

void Boss::showInfo() {
	cout << "职工编号：" << this->m_id
		<< "\t职工姓名：" << this->m_name
		<< "\t职工岗位：" << this->getDeptName()
		<< "\t职工职责：给经理下发任务" << endl;
}

string Boss::getDeptName() {
	string str = "老板";
	return str;
}