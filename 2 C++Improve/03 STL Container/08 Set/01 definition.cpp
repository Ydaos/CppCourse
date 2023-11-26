#include <iostream>
#include <set>

/*
* set（集合）容器：
* set容器插入数据会自动排序，且不允许有重复数据
* set容器插入只能用insert，没有push和pop的操作
* 
* 本质：set/multiset 属于关联式容器，底层结构是用二叉树实现
* 
* set和multiset区别：
* 1、set不允许容器有重复元素
* 2、multiset 允许容器中有重复的元素
*/
void printSet(const std::set<int>& s) {
	for (std::set<int>::const_iterator it = s.begin(); it != s.end(); it++) {
		std::cout << (*it) << " ";
	}
	std::cout << std::endl;
}


/*
* set构造和赋值
* 函数原型：
* set<T> st;					 //默认构造函数
* set(const set &st);		     //拷贝构造函数
* set& operator=(const set &st); //重载=运算符
*/
void Definition() {
	std::set<int> s1;

	// 插入数据只有insert方式
	s1.insert(10);
	s1.insert(22);
	s1.insert(20);
	s1.insert(11);
	s1.insert(50);

	// 遍历容器
	// 特点：所有元素插入时候自动排序
	// set容器不允许插入重复的值！！！
	printSet(s1);

	// 拷贝构造
	std::set<int> s2(s1);
	printSet(s2);

	// 赋值
	std::set<int> s3;
	s3 = s2;
	printSet(s3);
}

int main01() {
	Definition();

	system("pause");
	return 0;
}