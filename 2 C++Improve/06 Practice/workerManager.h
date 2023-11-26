#pragma once
#include <iostream>
#include <string>
#include "worker.h"
#include "employees.h"
#include "manager.h"
#include "boss.h"
#include <fstream>

#define FILENAME "empFile.txt"

using namespace std;

// 创建管理类，负责下面内容：
// 与用户的沟通菜单界面
// 对职工增删改查的操作
// 与文件的读写交互

class WorkerManager {
public:
	// 构造函数
	WorkerManager();

	// 析构函数
	~WorkerManager();

	// 展示菜单
	void showMenu();

	// 退出功能
	void exitSystem();

	// 增加职工
	void addEmployee();

	// 显示职工
	void showEmployee();

	// 删除职工
	void delEmployee();

	// 修改职工
	void modEmployee();

	// 查找职工
	void findEmployee();

	// 按编号进行排序
	void sortEmployee();

	// 清空职工列表文件
	void clearEmpFile();
	

private:
	// 保存文件
	void saveFile();

	// 获取文件中员工数目
	int get_FileEmpNum();

	// 初始化数组
	void Init_EmpArr();

	// 判断职工是否存在
	int IsExist(int id);
	int IsExist(string name);

public:
	int m_EmpNum;      // 职工数量
	Worker** m_EmpArr; // 指向存放worker*的指针数组
	bool m_fileIsEmpty;// 标志文件是否为空
};