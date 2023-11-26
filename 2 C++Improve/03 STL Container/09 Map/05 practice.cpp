#include <iostream>
#include <vector>
#include <map>
#include <ctime>

namespace prac_space {
/*
* 案例描述：
* 1、招聘10名员工（ABCDEFGHIJ），10名员工进入公司后被指派到各个部门
* 2、员工信息有：姓名和工资组成；部门分为：策划、美术、研发
* 3、随机给10名员工分配部门和工资
* 4、通过multimap进行信息的插入，key（部门编号） value（员工）
* 5、分部门显示员工信息
* 
* 实现步骤：
* 1、创建10名员工，放到vector中
* 2、遍历vector容器，取出每个员工进行分组
* 3、分组后，将部门编号作为key，具体员工作为value插入multimap容器
* 4、显示各部门员工信息
*/

#define PLANNING 1
#define ARTS 2
#define DEVELOP 3

class Worker {
public:
	Worker() {
		this->m_Salary = 0;
	}

	std::string m_Name; //姓名
	int m_Salary;   //工资
};

// 创建员工
void createWorker(std::vector<Worker>& v) {
	std::string nameSeed = "ABCDEFGHIJ";
	Worker w;
	for (int i = 0; i < 10; i++) {
		w.m_Name = "员工";
		w.m_Name += nameSeed[i];
		w.m_Salary = rand() % 10000 + 10000; //10000 ~ 19999
		v.push_back(w);
	}
}

// 打印员工信息
void showWroker(std::multimap<int, Worker>& m) {
	std::cout << "策划部门信息：\n";
	std::multimap<int, Worker>::iterator pos = m.find(PLANNING);
	int count = m.count(PLANNING);
	for (int i = 0; i < count; i++) {
		std::cout << "姓名：" << pos->second.m_Name << " 工资：" << pos->second.m_Salary << std::endl;
		pos++;
	}
	std::cout << std::endl;

	std::cout << "美术部门信息：\n";
	pos = m.find(ARTS);
	count = m.count(ARTS);
	for (int i = 0; i < count; i++) {
		std::cout << "姓名：" << pos->second.m_Name << " 工资：" << pos->second.m_Salary << std::endl;
		pos++;
	}
	std::cout << std::endl;

	std::cout << "研发部门信息：\n";
	pos = m.find(DEVELOP);
	count = m.count(DEVELOP);
	for (int i = 0; i < count; i++) {
		std::cout << "姓名：" << pos->second.m_Name << " 工资：" << pos->second.m_Salary << std::endl;
		pos++;
	}
	std::cout << std::endl;
}

void Func() {
	// 随机数种子
	srand((unsigned int)time(NULL));

	// 创建数据
	std::vector<Worker> v;
	createWorker(v);

	// 分配部门
	int key = 0; //部门 1 - 策划；2 - 美术；3 - 研发
	std::multimap<int, Worker> m;

	for (int i = 0; i < v.size(); i++) {
		key = rand() % 3 + 1;
		m.insert(std::make_pair(key, v[i]));
	}

	// 分部门显示
	showWroker(m);
}

}

int main() {
	prac_space::Func();
	int a = PLANNING;

	system("pause");
	return 0;
}