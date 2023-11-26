#include <iostream>
#include <queue>

/*
* queue概念：queue队列是先进先出的数据结构，它有两个出口
* 队列容器允许从一端新增元素，从另一端移除元素
* 队列只有队头和队尾可以被外界访问，因此队列不允许遍历行为
* 队列中进数据称为 -- 入队 push
* 队列中出数据称为 -- 出队 pop
* 
* queue常用接口
* 构造函数：
* queue<T> que;            //默认构造函数
* queue(const queue &que); //拷贝构造函数
* 
* 赋值操作：
* queue& operator=(const queue &que); //重载=运算符
* 
* 数据存取：
* push(elem); //向队尾添加元素
* pop();      //从队头移除第一个元素
* back()      //返回最后一个元素
* front();    //返回第一个元素
* 
* 大小操作：
* empty();    //判断队列是否为空
* size();     //返回队列大小
*/
class Person {
public:
	Person(std::string name, int age) {
		m_Name = name;
		m_Age = age;
	}

	std::string m_Name;
	int m_Age;
};

void Queue() {
	// 特点：先进先出
	std::queue<Person> q;

	// 创建数据
	Person p1("Tom", 20);
	Person p2("Jerry", 18);
	Person p3("Mark", 22);
	Person p4("Lisa", 18);

	// 队尾入队
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	// 只要队列不为空，查看队头和队尾元素，并出队
	std::cout << "队列大小：" << q.size() << std::endl;
	while (!q.empty()) {
		// 输出队头元素
		std::cout << "队头元素 --- 姓名：" << q.front().m_Name << " 年龄：" << q.front().m_Age << std::endl;
		
		// 输出队尾元素
		std::cout << "队尾元素 --- 姓名：" << q.back().m_Name << " 年龄：" << q.back().m_Age << std::endl;

		// 出队
		q.pop();
		std::cout << std::endl;
	}
	std::cout << "队列大小：" << q.size() << std::endl;
}


int main() {
	Queue();

	system("pause");
	return 0;
}