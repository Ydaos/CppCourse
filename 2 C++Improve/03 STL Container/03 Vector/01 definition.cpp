#include <iostream>
#include <vector>

/*
* vector 基本概念
* 功能：vector 数据结构和数组非常相似，也称为单端数组
* 区别：数组是静态空间，而vector可以动态扩展
* 动态扩展：不是在原空间之后续接新空间，而是找更大的空间（原容量的1.5倍），然后将原数据拷贝并释放原空间
* vector 迭代器支持随机访问
*/
void printVector(std::vector<int>& v) {
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}


/* 
* vector构造函数
* 函数原型：
* vector<T> v;                //采用模板实现类实现，默认构造函数
* vector(v.begin(), v.end()); //将v[begin(), end()]区间中的元素拷贝给本身
* vector(n, elem);            //构造函数将n个elem拷贝给本身
* vector(const vector &vec);  //拷贝构造函数
* 
* 最常用一般是默认构造 + 拷贝构造
*/
void Constructor() {
	// 默认构造 无参构造
	std::vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	printVector(v1);

	// 通过区间方式构造
	std::vector<int> v2(v1.begin(), v1.end());
	printVector(v2);

	// n个elem方式构造
	std::vector<int>v3(10, 6);
	printVector(v3);

	// 拷贝构造
	std::vector<int>v4(v3);
	printVector(v4);
}

 
/*
* vector赋值操作
* 函数原型：
* vector& operator=(const vector &v); //重载运算符
* assign(beg, end);                   //将[beg, end]区间中的数据拷贝拷贝给本身
* assign(n, elem);                    //将n个elem拷贝赋值给本身
*/
void Assignment() {
	std::vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	printVector(v1);

	// operator=
	std::vector<int> v2 = v1;
	printVector(v2);

	// assign
	std::vector<int> v3;
	v3.assign(v1.begin(), v1.end());
	printVector(v3);

	// n个elem 方式赋值
	std::vector<int> v4;
	v4.assign(10, 6);
	printVector(v4);
}

int main01() {
	Constructor();

	std::cout << "\n----------------------\n";
	Assignment();

	system("pause");
	return 0;
}