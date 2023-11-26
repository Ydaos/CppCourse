#pragma once
#include "worker.h"

// 创建老板类继承职工抽象类，并重写虚函数

class Boss :public Worker {
public:
	// 构造函数
	Boss(int Id, string name, int dId);

	// 显示个人信息
	void showInfo();

	// 获取岗位名称
	string getDeptName();
};