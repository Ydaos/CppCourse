#include <iostream>
#include <algorithm>
#include <vector>

/*
* STL_查找算法
* find;          //查找元素
* find_if;       //按条件查找元素
* adjacent_find; //查找相邻重复元素
* binary_serach; //二分查找元素是否存在
* 
* count;         //统计元素个数
* count_if;      //按条件统计元素个数
*/

namespace space_find {

	class Person {
	public:
		Person(std::string name, int age) {
			this->m_Name = name;
			this->m_Age = age;
		}

		// 重载 == 让find知道怎么对比Person数据类型
		bool operator==(const Person& p) {
			if (this->m_Name == p.m_Name && this->m_Age == p.m_Age) {
				return true;
			}
			return false;
		}

		std::string m_Name;
		int m_Age;
	};

	// 比较大小的仿函数
	class MyGreater {
	public:
		bool operator()(int val) {
			return val > 5;
		}
		bool operator()(Person& p) {
			return p.m_Age > 20;
		}
	};


	/*
	* find 查找元素
	* 函数原型：
	* iterator find(iterator beg, iterator end, value);
	* 
	* find 可以在容器中找到指定元素，返回值是迭代器
	* find 查找自定义数据类型时，要重载==运算符，否则find不知道怎么判断相等条件
	*/
	void MyFind() {
		// 1、find 查找内置数据类型，不管找到与否都会返回迭代器
		std::vector<int> v;
		for (int i = 0; i < 10; i++) {
			v.push_back(i);
		}

		// 查找容器中是否有'5'这个元素
		std::vector<int>::iterator it = find(v.begin(), v.end(), 5);
		if (it == v.end()) {
			std::cout << "不存在这个元素\n";
		}
		else {
			std::cout << "找到元素 " << *it << std::endl;
		}

		// 2、find 查找自定义数据类型
		std::vector<Person> v2;
		// 创建数据
		Person p1("Tom", 18);
		Person p2("Jery", 16);
		Person p3("Tony", 20);
		Person p4("Hans", 22);

		// 放入容器中
		v2.push_back(p1);
		v2.push_back(p2);
		v2.push_back(p3);
		v2.push_back(p4);

		// 查找容器中是否有'p2'这个元素
		std::vector<Person>::iterator it_p = find(v2.begin(), v2.end(), p2);
		if (it_p == v2.end()) {
			std::cout << "不存在这个元素\n";
		}
		else {
			std::cout << "找到元素p2 姓名：" << it_p->m_Name << " 年龄：" << it_p->m_Age << std::endl;
		}
	}
	

	/*
	* find_if 按条件查找元素
	* 函数原型：
	* iterator find_if(iterator beg, iterator end, _Pred); //按条件查找元素
	* 按条件查找元素，不管找到与否都会返回迭代器（_Pred bool函数或谓词）
	* find_if 通过谓词可以自定义查找条件，返回找到元素的迭代器
	*/
	void MyFind_IF() {
		// 1、find_if 查找内置数据类型
		std::vector<int> v;
		for (int i = 0; i < 10; i++) {
			v.push_back(i);
		}

		// 查找容器中是否有大于5的元素
		std::vector<int>::iterator it = find_if(v.begin(), v.end(), MyGreater());
		if (it == v.end()) {
			std::cout << "没找到元素\n";
		}
		else {
			std::cout << "找到大于5的元素 " << *it << std::endl;
		}

		// 2、find_if 查找自定义数据类型
		std::vector<Person> v2;
		// 创建数据
		Person p1("Tom", 18);
		Person p2("Jery", 16);
		Person p3("Tony", 20);
		Person p4("Hans", 22);

		// 放入容器中
		v2.push_back(p1);
		v2.push_back(p2);
		v2.push_back(p3);
		v2.push_back(p4);

		// 查找年龄大于20的人
		std::vector<Person>::iterator it_p = find_if(v2.begin(), v2.end(), MyGreater());
		if (it == v.end()) {
			std::cout << "不存在这个元素\n";
		}
		else {
			std::cout << "找到目标元素 姓名：" << it_p->m_Name << " 年龄：" << it_p->m_Age << std::endl;
		}
	}


	/*
	* adjacent_find 查找相邻重复元素
	* 函数原型：
	* iterator adjacent_find(iterator beg, iterator end);
	* 查找相邻重复元素，返回相邻元素第一个位置的迭代器
	*/
	void MyAdjacent_Find() {
		std::vector<int> v;
		v.push_back(1);
		v.push_back(0);
		v.push_back(1);
		v.push_back(3);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(5);

		std::vector<int>::iterator it = adjacent_find(v.begin(), v.end());
		if (it == v.end()) {
			std::cout << "没找到元素\n";
		}
		else {
			std::cout << "找到相邻元素 " << *it << std::endl;
		}
	}


	/*
	* binary_serach 二分查找元素
	* 函数原型：
	* bool binary_serach(iterator beg, iterator end, value); 
	* 二分查找法，查找指定元素，查到返回true，否则返回false
	* 二分查找法效率很高，但查找元素必须是有序序列，否则返回结果不一定正确
	*/
	void MyBinary_Search() {
		std::vector<int> v;
		for (int i = 0; i < 10; i++) {
			v.push_back(i);
		}

		// 查找容器是否存在元素 9
		bool ret = binary_search(v.begin(), v.end(), 9);
		if (ret) {
			std::cout << "找到了元素\n";
		}
		else {
			std::cout << "未找到元素\n";
		}

		// 注意：容器必须是有序序列！！！
		v.push_back(2);
		ret = binary_search(v.begin(), v.end(), 9);
		if (ret) {
			std::cout << "找到了元素 \n";
		}
		else {
			std::cout << "未找到元素\n";
		}
		// return false!如果是无序序列，返回结果不一定正确
	}

}

namespace space_count {

	class Person {
	public:
		Person(std::string name, int age) {
			this->m_Name = name;
			this->m_Age = age;
		}

		// 重载 == 运算符，让count知道怎么判断相等条件
		bool operator==(const Person& p) {
			if (this->m_Age == p.m_Age) {
				return true;
			}
			return false;
		}

		std::string m_Name;
		int m_Age;
	};

	// 比较大小的仿函数
	class MyCreater {
	public:
		bool operator()(int val) {
			return val > 20;
		}

		bool operator()(const Person& p) {
			if (p.m_Age > 20) {
				return true;
			}
			return false;
		}
	};


	/*
	* count 统计元素出现次数
	* 函数原型：
	* int count(iterator beg, iterator end, value); //统计元素出现次数
	* 对于统计自定义类型时候，需要重载==运算符，才可以判断返回条件
	*/
	void MyCount() {
		// 1、count统计内置数据类型
		std::vector<int> v;
		v.push_back(10);
		v.push_back(40);
		v.push_back(30);
		v.push_back(40);
		v.push_back(20);

		int num = count(v.begin(), v.end(), 40);
		std::cout << "num = " << num << std::endl;

		// 2、count统计自定义数据类型
		Person p1("Tom", 18);
		Person p2("Jery", 16);
		Person p3("Mark", 18);
		Person p4("Hans", 22);
		Person p5("Tony", 18);

		std::vector<Person> v2;
		v2.push_back(p1);
		v2.push_back(p2);
		v2.push_back(p3);
		v2.push_back(p4);
		v2.push_back(p5);

		// 统计和 Lisa 同岁数的人数
		Person p("Lisa", 18);
		num = count(v2.begin(), v2.end(), p);
		std::cout << "和Lisa同岁数的人数：" << num << std::endl;
	}


	/*
	* count_if 统计符合条件的元素个数
	* 函数原型：
	* int count_if(iterator beg, iterator end, _Pred);
	* _Pred 谓词
	*/
	void MyCount_IF() {
		// 1、count_if 统计内置数据类型
		std::vector<int> v;
		v.push_back(10);
		v.push_back(40);
		v.push_back(30);
		v.push_back(40);
		v.push_back(20);
		v.push_back(40);

		int num = count_if(v.begin(), v.end(), MyCreater());
		std::cout << "大于20的元素个数：" << num << std::endl;

		// 2、count_if 统计自定义数据类型
		Person p1("Tom", 18);
		Person p2("Jery", 16);
		Person p3("Mark", 18);
		Person p4("Hans", 22);
		Person p5("Tony", 21);

		std::vector<Person> v2;
		v2.push_back(p1);
		v2.push_back(p2);
		v2.push_back(p3);
		v2.push_back(p4);
		v2.push_back(p5);

		// 统计大于20岁人数
		num = count_if(v2.begin(), v2.end(), MyCreater());
		std::cout << "大于20岁人数：" << num << std::endl;
	}

}

int main02() {
	space_find::MyFind();

	std::cout << "-----------------------------------\n";
	space_find::MyFind_IF();

	std::cout << "-----------------------------------\n";
	space_find::MyAdjacent_Find();

	std::cout << "-----------------------------------\n";
	space_find::MyBinary_Search();

	std::cout << "-----------------------------------\n";
	space_count::MyCount();

	std::cout << "-----------------------------------\n";
	space_count::MyCount_IF();

	system("pause");
	return 0;
}