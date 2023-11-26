#pragma once
#include "worker.h"

// 创建经理类继承职工抽象类，并重写虚函数

class Manager :public Worker {
public:
	// 构造函数
	Manager(int Id, string name, int dId);

	// 显示个人信息
	void showInfo();

	// 获取岗位名称
	string getDeptName();
};