#include <iostream>
#include <set>

void printSet(const std::set<int>& s); //函数定义在"01 definition.cpp"

/*
* set容器大小和交换
* 函数原型：
* size();	  //返回容器元素数目
* empty();    //判断容器是否为空
* swap(s);    //交换两个容器
* 
* 注意事项：set容器不允许有重复元素，所以不能resize()容器大小，因为默认值填充会带来重复数据
*/
void MySize() {
	std::set<int> s1;
	s1.insert(10);
	s1.insert(22);
	s1.insert(20);
	s1.insert(11);
	s1.insert(50);

	if (s1.empty()) {
		std::cout << "容器为空\n";
	}
	else {
		std::cout << "容器不为空\n";
		std::cout << "容器元素个数：" << s1.size() << std::endl;
	}
}

void MySwap() {
	std::set<int> s1;
	s1.insert(10);
	s1.insert(22);
	s1.insert(20);
	s1.insert(11);
	s1.insert(50);

	std::set<int> s2;
	s2.insert(100);
	s2.insert(220);
	s2.insert(200);

	std::cout << "交换前：\n";
	printSet(s1);
	printSet(s2);

	std::cout << "交换后：\n";
	s1.swap(s2);
	printSet(s1);
	printSet(s2);
}

int main02() {
	MySize();

	std::cout << "------------------\n";
	MySwap();

	system("pause");
	return 0;
}