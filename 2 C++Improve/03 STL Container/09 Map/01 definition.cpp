#include <iostream>
#include <map>

void printMap(std::map<int, int>& m); //函数定义在"01 definition.cpp"
/*
* map基本概念：
* 1、map中所有元素都是pair
* 2、pair中第一个元素为key（键值），起到索引作用；第二个元素为value（实值）
* 3、所有元素会按照key值自动排序
* 
* 本质：map/multimap属于关联式容器，底层结构是二叉树实现
* 优点：可以根据key值快速找到value值
* 
* map/multimap两者区别：
* map不允许容器有重复的key值；multimap允许容器有重复的key值
*/
void printMap(std::map<int, int>& m) {
	for (std::map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
		std::cout << "key = " << (*it).first << " value = " << (*it).second << std::endl;
	}
	std::cout << std::endl;
}
 

/*
* map的构造和赋值
* 函数原型：
* map<T1, T2> m;			    // 默认构造函数
* map(const map &m);		    // 拷贝构造函数
* map& operator=(const map &m); // 重载赋值运算符
* 
* 总结：map所有元素都是成对出现，插入的元素都是pair对组
*/
void Define() {
	// 默认构造
	std::map<int, int> m1;
	m1.insert(std::pair<int, int>(1, 10));
	m1.insert(std::pair<int, int>(3, 20));
	m1.insert(std::pair<int, int>(2, 30));
	m1.insert(std::pair<int, int>(4, 40));
	m1.insert(std::pair<int, int>(5, 50));
	printMap(m1);

	// 拷贝构造
	std::map<int, int> m2(m1);
	printMap(m2);

	// 赋值
	std::map<int, int> m3;
	m3 = m1;
	printMap(m3);
}


int main01() {
	Define();

	system("pause");
	return 0;
}