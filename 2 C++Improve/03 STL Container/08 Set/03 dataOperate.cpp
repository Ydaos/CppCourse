#include <iostream>
#include <set>

void printSet(const std::set<int>& s); //函数定义在"01 definition.cpp

/*
* set容器插入和删除
* insert(elem);    //向容器插入elem值的元素
* clear();         //清空容器
* erase(pos);      //删除pos迭代器指向的元素
* erase(beg, end); //删除[beg, end]区间所有元素
* erase(elem);     //删除elem值的元素，类似list里面的remove
*/
void Insert() {
	// 插入
	std::set<int> s1;
	s1.insert(10);
	s1.insert(22);
	s1.insert(20);
	s1.insert(11);
	s1.insert(50);
	printSet(s1);
}

void Delete() {
	std::set<int> s1;
	s1.insert(10);
	s1.insert(22);
	s1.insert(20);
	s1.insert(11);
	s1.insert(50);
	printSet(s1);

	// erase(pos); 
	s1.erase(++s1.begin());
	printSet(s1);

	// erase(elem)
	s1.erase(22);
	printSet(s1);

	// clear()
	s1.clear();
	printSet(s1);
}


/*
* set容器查找和统计
* 函数原型：
* find(key);    //查找key元素是否存在，返回该键的元素的迭代器；不存在则返回set.end()
* count(key);   //统计key的元素个数
*/
void FindAndCount() {

	std::set<int> s1;
	s1.insert(10);
	s1.insert(22);
	s1.insert(20);
	s1.insert(11);
	s1.insert(50);
	printSet(s1);

	// find(key)
	std::set<int>::iterator pos = s1.find(10); //返回的是迭代器
	if (pos != s1.end()) {
		std::cout << "找到元素：" << *pos << std::endl;
	}
	else {
		std::cout << "未找到元素" << std::endl;
	}

	// count(key)
	int num = s1.count(22);
	// 对于set而言，不允许插重复数，所以返回结果非0即1
	std::cout << "num = " << num << std::endl;
}

int main03() {
	Insert();

	std::cout << "---------------\n";
	Delete();

	std::cout << "---------------\n";
	FindAndCount();

	system("pause");
	return 0;
}