#include <iostream>
#include <set>

void printSet(const std::set<int>& s); //函数定义在"01 definition.cpp

/*
* pair对组：成对出现的数据，利用对组可以返回两个数据
* 两种创建方式：
* pair<type, type> p(val1, val2);             
* pair<type, type> p = make_pair(val1, val2); 
*/
void PairDefine() {
	// 第一种方式
	std::pair<std::string, int>p("Tom", 20);
	std::cout << "姓名：" << p.first << " 年龄：" << p.second << std::endl;

	// 第二种方式
	std::pair<std::string, int>p2 = std::make_pair("Jerry", 16);
	std::cout << "姓名：" << p2.first << " 年龄：" << p2.second << std::endl;
}


/*
* set和multiset区别
* 1、set不可以插重复数据，multiset可以
* 2、set插入数据的同时会返回插入结果，表示插入是否成功，返回结果为 pair<set<T>::iterator, bool>
* 3、multiset不会检测数据，返回结果为迭代器set<T>::iterator；因此可以插入重复数据
*/
void Diff() {
	std::set<int> s1;
	std::pair<std::set<int>::iterator, bool>ret = s1.insert(10);
	if (ret.second) {
		std::cout << "第一次插入成功\n";
	}
	else {
		std::cout << "第一次插入失败\n";
	}

	ret = s1.insert(10);
	if (ret.second) {
		std::cout << "第二次插入成功\n";
	}
	else {
		std::cout << "第二次插入失败\n";
	}

	std::multiset<int> ms;
	ms.insert(10);
	ms.insert(10); //insert返回的是迭代器，不对数据插入进行检测
	for (std::multiset<int>::const_iterator it = ms.begin(); it != ms.end(); it++) {
		std::cout << (*it) << " ";
	}
	std::cout << std::endl;
}


int main04() {
	PairDefine();

	std::cout << "------------------\n";
	Diff();

	system("pause");
	return 0;
}