#include <iostream>
#include <map>

void printMap(std::map<int, int>& m); //函数定义在"01 definition.cpp"

/*
* map的插入和删除
* 函数原型：
* insert(elem);	   // 在容器中插入元素
* erase(pos);	   // 删除pos迭代器所指元素，返回下一个元素的迭代器
* erase(beg, end); // 删除[beg, end]区间所有元素
* erase(key);      // 删除容器中值为key的元素
* clear();         // 清空容器
*/
void InsertDel() {
	// 插入
	// 第一种
	std::map<int, int> m1;
	m1.insert(std::pair<int, int>(1, 10));
	m1.insert(std::pair<int, int>(3, 20));

	// 第二种
	m1.insert(std::make_pair(2, 30));
	m1.insert(std::make_pair(4, 40));

	// 第三种
	m1.insert(std::map<int, int>::value_type(5, 50));

	// 第四种
	m1[6] = 60;
	// 不建议[]插入，若不存在key值它会创建这个key并用0来作为value；
	// 用途：可以利用key访问value eg：m1[key];
	std::cout << m1[7] << std::endl;
	printMap(m1);

	// 删除
	m1.erase(m1.begin()); //pos迭代器删除
	printMap(m1);

	m1.erase(3);         //按照key值删除
	printMap(m1);

	m1.erase(m1.begin(), m1.end()); // 区间删除
	// m1.clear();                  //清空容器
	printMap(m1);

	/*
	* 总结：
	* 插入方式有很多种，推荐记前两种；第四种不建议拿来插入，但可以用来访问value值
	* 插入 -- insert
	* 删除 -- erase
	* 清空 -- clear
	*/
}


/*
* map的查找和统计
* 函数原型：
* find(key);   // 查找key是否存在，返回该键的迭代器；不存在则返回set.end()
* count(key);  // 统计key个数，对于map而言非1即0
* 
* map不允许插入重复key值，count统计结果非1即0；multimap统计结果可能 > 1
*/
void FindAndCount() {
	std::map<int, int> m1;
	m1.insert(std::pair<int, int>(1, 10));
	m1.insert(std::pair<int, int>(3, 20));
	m1.insert(std::pair<int, int>(2, 30));
	m1.insert(std::pair<int, int>(4, 40));
	m1.insert(std::pair<int, int>(5, 50));

	// 查找
	std::map<int, int>::iterator pos = m1.find(3);
	if (pos != m1.end()) {
		std::cout << "查到了元素 key = " << (*pos).first << " value = " << (*pos).second << std::endl;
	}
	else {
		std::cout << "未找到元素" << std::endl;
	}

	// 统计
	int num = m1.count(4);
	std::cout << "num = " << num << std::endl;
}

int main03() {
	InsertDel();

	std::cout << "-------------------\n";
	FindAndCount();

	system("pause");
	return 0;
}