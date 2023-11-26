#pragma once
#include <iostream>
using namespace std;

// 创建抽象职工类
// 职工类型分为：普通员工、经理、老板
// 将三种职业抽象到一个类中，利用多态管理不同的职工种类
// 职工属性为：职工编号、职工姓名和职工所在部门编号
// 职工行为为：岗位职责信息描述，获取岗位名称

// 职工抽象类
class Worker {
public:
	// 显示个人信息
	virtual void showInfo() = 0;

	// 获取岗位名称
	virtual string getDeptName() = 0;

public:
	int m_id;      // 职工编号
	string m_name; // 职工姓名
	int m_deptId;  // 职工所在部门名称编号
};