#pragma once
#include "worker.h"

// 创建普通员工类继承职工抽象类，并重写虚函数

class Employees :public Worker {
public:
	// 构造函数
	Employees(int Id, string name, int dId);

	// 显示个人信息
	void showInfo();

	// 获取岗位名称
	string getDeptName();
};