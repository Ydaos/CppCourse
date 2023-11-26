#include <iostream>
#include <vector>
#include <algorithm>

/*
* 谓词：返回bool类型的仿函数
* 如果operator()接受一个参数，称为一元谓词
* 如果operator()接受两个参数，称为二元谓词
*/

// 1、一元谓词
class GreatFive {
public:
	bool operator()(int val) {
		return val > 5;
	}
};

void Predicate01() {
	std::vector<int>v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}

	// 查找容器中有没有大于5的数字
	// 匿名的函数对象：GreatFive()
	std::vector<int>::iterator pos = find_if(v.begin(), v.end(), GreatFive());
	if (pos == v.end()) {
		std::cout << "未找到大于5的数字" << std::endl;
	}
	else {
		std::cout << "找到大于5的数字：" << *pos << std::endl;
	}
}

// 2、二元谓词
class MySort {
public:
	bool operator()(int v1, int v2) {
		// 降序
		return v1 > v2;
	}
};

void Predicate02() {
	std::vector<int>v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(20);
	v.push_back(50);
	v.push_back(40);

	sort(v.begin(), v.end());
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	// 使用函数对象改变算法策略，变为排序规则为降序
	sort(v.begin(), v.end(), MySort());
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

int main02() {
	Predicate01();

	std::cout << "-------------------\n";
	Predicate02();

	system("pause");
	return 0;
}