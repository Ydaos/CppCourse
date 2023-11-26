#include "workerManager.h"

WorkerManager::WorkerManager() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	// 文件不存在
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		this->m_fileIsEmpty = true; //初始化文件为空标志
		this->m_EmpNum = 0;         // 初始化人数
		this->m_EmpArr = NULL;      // 初始化数组
		
		return;
	}

	// 文件存在，但数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "文件为空！" << endl;
		this->m_fileIsEmpty = true; //初始化文件为空标志
		this->m_EmpNum = 0;         // 初始化人数
		this->m_EmpArr = NULL;      // 初始化数组
		return;
	}
	ifs.close();

	// 文件存在，且记录数据
	this->m_EmpNum = get_FileEmpNum(); // 初始化人数
	cout << "文件存在，有" << this->m_EmpNum << "条记录" << endl;
	this->m_fileIsEmpty = false;

	this->m_EmpArr = new Worker * [m_EmpNum];  //初始化数组
	Init_EmpArr();
}

WorkerManager::~WorkerManager() {
	if (this->m_EmpArr != NULL) {
		delete[] this->m_EmpArr;
		this->m_EmpArr = NULL;
	}
}

void WorkerManager::showMenu() {
	cout << "****************************************" << endl;
	cout << "********  " << "欢迎使用职工管理系统" << "  ********" << endl;
	cout << "***********  " << "0.退出管理程序" << "  ***********" << endl;
	cout << "***********  " << "1.增加职工信息" << "  ***********" << endl;
	cout << "***********  " << "2.显示职工信息" << "  ***********" << endl;
	cout << "***********  " << "3.删除离职职工" << "  ***********" << endl;
	cout << "***********  " << "4.修改职工信息" << "  ***********" << endl;
	cout << "***********  " << "5.查找职工信息" << "  ***********" << endl;
	cout << "***********  " << "6.按照编号排序" << "  ***********" << endl;
	cout << "***********  " << "7.清空所有文档" << "  ***********" << endl;
	cout << "****************************************" << endl;
	cout << endl;
}

void WorkerManager::exitSystem() {
	cout << "欢迎下次使用" << endl;
	system("pause");
}

void WorkerManager::addEmployee() {
	cout << "请输入增加职工数量" << endl;
	
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0) {
		// 计算空间大小
		int newSize = this->m_EmpNum + addNum;

		// 开辟新空间
		Worker** newSpace = new Worker * [newSize];

		// 将原来空间下数据拷贝到新空间
		if (this->m_EmpArr != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				newSpace[i] = this->m_EmpArr[i];
			}
		}

		// 添加新数据
		for (int i = 0; i < addNum; i++) {
			int id;      // 新职工编号
			string name; // 新职工姓名
			int dSelect; // 新职工部门

			cout << "请输入第" << i + 1 << "位职工的编号" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "位职工的姓名" << endl;
			cin >> name;
			cout << "请选择该职工的部门编号" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employees(id, name, dSelect);
				break;
			case 2:
				worker = new Manager(id, name, dSelect);
				break;
			case 3:
				worker = new Boss(id, name, dSelect);
				break;
			default:
				break;
			}

			// 将创建职工指针保存到数组中
			newSpace[this->m_EmpNum + i] = worker;
		}

		// 先释放原有的空间
		delete[] this->m_EmpArr;
		
		// 更改新空间指向
		this->m_EmpArr = newSpace;

		// 更新新职工人数
		this->m_EmpNum = newSize;

		// 保存文件
		saveFile();

		// 提示添加成功
		cout << "添加成功，添加了" << addNum << "新职工" << endl;
		this->m_fileIsEmpty = false;
	}
	else {
		cout << "输入有误" << endl;
	}

	// 按任意键继续，返回上级目录
	system("pause");
	system("cls");
}

void WorkerManager::saveFile() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out); // 用输出方式打开文件 -- 写文件

	// 将每个人数据写入到文件中
	for (int i = 0; i < this->m_EmpNum; i++) {
		ofs << this->m_EmpArr[i]->m_id << " "
			<< this->m_EmpArr[i]->m_name << " "
			<< this->m_EmpArr[i]->m_deptId << endl;
	}

	// 关闭文件
	ofs.close();
}

int WorkerManager::get_FileEmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int num = 0;
	string buf;
	while (getline(ifs, buf)) {
		num++;
	}

	ifs.close();
	return num;
}

void WorkerManager::Init_EmpArr() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;      // 职工编号
	string name; // 职工姓名
	int dSelect; // 职工部门
	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> dSelect) {
		Worker* worker = NULL;
		switch (dSelect)
		{
		case 1:
			worker = new Employees(id, name, dSelect);
			break;
		case 2:
			worker = new Manager(id, name, dSelect);
			break;
		case 3:
			worker = new Boss(id, name, dSelect);
			break;
		default:
			break;
		}
		// 将读到的职工数据保存到数组中
		m_EmpArr[index] = worker;
		index++;
	}
	ifs.close();
}

void WorkerManager::showEmployee() {
	if (this->m_fileIsEmpty) {
		cout << "文件不存在或记录为空！" << endl;
	}
	else {
		for (int i = 0; i < this->m_EmpNum; i++) {
			// 利用多态调用接口
			this->m_EmpArr[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::delEmployee() {
	if (this->m_fileIsEmpty) {
		cout << "文件不存在或记录为空！" << endl;
	}
	else {
		cout << "请输入要删除的员工编号" << endl;
		int id = -1;
		cin >> id;

		int index = IsExist(id);
		if (index < 0) {
			cout << "查无此人！" << endl;
		}
		else { // 说明职工存在，并且要删除index位置上的职工
			// 数组删除本质是数据前移
			for (int i = index; i < this->m_EmpNum - 1; i++) {
				this->m_EmpArr[i] = this->m_EmpArr[i + 1];
			}
			this->m_EmpNum--; //更新数组记录人员个数

			// 同步更新数据到文件中
			saveFile();

			cout << "删除成功！" << endl;
		}
	}
	system("pause");
	system("cls");
}

int WorkerManager::IsExist(int id) {
	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArr[i]->m_id == id) {
			return i;
		}
	}
	return -1;
}

int WorkerManager::IsExist(string name) {
	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArr[i]->m_name == name) {
			return i;
		}
	}
	return -1;
}

void WorkerManager::modEmployee() {
	if (m_fileIsEmpty) {
		cout << "文件不存在或记录为空！" << endl;
	}
	else {
		cout << "请输入要修改的员工编号" << endl;
		int id = -1;
		cin >> id;

		int index = IsExist(id);
		if (index < 0) {
			cout << "查无此人！" << endl;
		}
		else {
			delete this->m_EmpArr[index];

			int newId = 0;
			string newName;
			int dSelect = 0;
			cout << "请输入修改后的职工编号" << endl;
			cin >> newId;
			cout << "请输入修改后的职工姓名" << endl;
			cin >> newName;
			cout << "请选择该职工的部门编号" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employees(newId, newName, dSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, dSelect);
				break;
			default:
				break;
			}

			// 将创建职工指针保存到数组中
			this->m_EmpArr[index] = worker;

			// 同步更新数据到文件中
			saveFile();

			cout << "修改成功！" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::findEmployee() {
	if (m_fileIsEmpty) {
		cout << "文件不存在或记录为空！" << endl;
	}
	else {
		int select = 0;
		while (true) {
			cout << "请输入查找的方式：" << endl;
			cout << "1、按职工编号查找" << endl;
			cout << "2、按职工姓名查找" << endl;
			cin >> select;

			if (select == 1) { // 按编号查找
				cout << "请输入要查找的职工编号" << endl;
				int id = 0;
				cin >> id;

				int index = IsExist(id);
				if (index < 0) {
					cout << "查无此人！" << endl;
				}
				else {
					this->m_EmpArr[index]->showInfo();
				}
				break;
			}
			else if (select == 2) { // 按姓名查找
				cout << "请输入要查找的职工姓名" << endl;
				string name;
				cin >> name;

				int index = IsExist(name);
				if (index < 0) {
					cout << "查无此人！" << endl;
				}
				else {
					this->m_EmpArr[index]->showInfo();
				}
				break;
			}
			else {
				cout << "查找方式输入有误，请重新输入" << endl;
			}
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::sortEmployee() {
	if (m_fileIsEmpty) {
		cout << "文件不存在或记录为空！" << endl;
		system("pause");
		system("cls");
	}
	else {
		int select = 0;
		while (true) {
			cout << "请输入排序的方式：" << endl;
			cout << "1、按职工编号升序排序" << endl;
			cout << "2、按职工编号降序排序" << endl;
			cin >> select;

			if (select == 1 || select == 2) {
				Worker* w_temp = NULL;
				for (int i = 0; i < this->m_EmpNum - 1; i++) {
					int minOrMax = this->m_EmpArr[i]->m_id;
					for (int j = i + 1; j < this->m_EmpNum; j++) {
						if (select == 1) { // 升序排序
							if (minOrMax > m_EmpArr[j]->m_id) {
								minOrMax = m_EmpArr[j]->m_id;
								w_temp = m_EmpArr[j];
								m_EmpArr[j] = m_EmpArr[i];
								m_EmpArr[i] = w_temp;
							}
						}
						else if (select == 2) { // 降序排序
							if (minOrMax < m_EmpArr[j]->m_id) {
								minOrMax = m_EmpArr[j]->m_id;
								w_temp = m_EmpArr[j];
								m_EmpArr[j] = m_EmpArr[i];
								m_EmpArr[i] = w_temp;
							}
						}
					}
				}
				break;
			}
			else {
				cout << "排序方式输入有误，请重新输入" << endl;
			}
		}
		// 更新文件，显示排序后结果
		cout << "排序成功！" << endl;
		this->saveFile();
		this->showEmployee();
	}
}

void WorkerManager::clearEmpFile() {
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;
	int select = 0;
	cin >> select;

	if (select == 1) {
		// 打开模式 ios::trunc 如果存在？删除文件并重新创建
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_EmpArr != NULL) {
			// 删除堆区每个职工对象
			for (int i = 0; i < m_EmpNum; i++) {
				if (this->m_EmpArr[i] != NULL) {
					delete this->m_EmpArr[i];
				}
			}

			// 删除堆区数组指针
			this->m_EmpNum = 0;
			delete[] this->m_EmpArr;
			this->m_EmpArr = NULL;
			this->m_fileIsEmpty = true;
		}
		cout << "清楚成功！" << endl;
	}

	system("pause");
	system("cls");
}