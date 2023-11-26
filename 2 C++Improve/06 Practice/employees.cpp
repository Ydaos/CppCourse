#include "employees.h"

Employees::Employees(int Id, string name, int dId) {
	this->m_id = Id;
	this->m_name = name;
	this->m_deptId = dId;
}

void Employees::showInfo() {
	cout << "职工编号：" << this->m_id
		<< "\t职工姓名：" << this->m_name
		<< "\t职工岗位：" << this->getDeptName()
		<< "\t职工职责：完成经理交给的任务" << endl;
}

string Employees::getDeptName() {
	string str = "员工";
	return str;
}