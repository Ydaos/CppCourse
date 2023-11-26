#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

/*
* 内建仿函数：
* 使用内建仿函数需要引入头文件 #include<functional>
* 这些仿函数产生的对象，用法和一般仿函数完全相同
* 
* 内建仿函数包含：算术仿函数、关系仿函数、逻辑仿函数
*/

/*
* 算术仿函数：实现四则运算，其中negate是一元运算，其他都是二元运算
* 
* 仿函数原型：
* template<class T> T plus<T>       // 加法仿函数
* template<class T> T minus<T>      // 减法仿函数
* template<class T> T multiplies<T> // 乘法仿函数
* template<class T> T divides<T>    // 除法仿函数
* template<class T> T modules<T>    // 取模仿函数
* template<class T> T negate<T>     // 取反仿函数
* 
* 总结：有点鸡肋，想用就用
*/
void Arithmetic() {
	// negate 一元仿函数 取反仿函数
	std::negate<int> n;
	std::cout << n(10) << std::endl;

	// plus 二元仿函数 加法仿函数
	std::plus<int> p;
	std::cout << p(10, 10) << std::endl;
}


/*
* 关系仿函数
* 函数原型：
* template<class T> bool equal_to<T>      //等于
* template<class T> bool not_equal_to<T>  //不等于
* template<class T> bool greater<T>       //大于
* template<class T> bool greater_equal<T> //大于等于
* template<class T> bool less<T>          //小于
* template<class T> bool less_equal<T>    //小于等于
* 
* 总结：关系仿函数最常用是greater<int>();因为默认sort排序是用less<T>()升序
*/
void Relationship() {
	// greater
	std::vector<int> v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(20);
	v.push_back(40);
	v.push_back(50);

	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	sort(v.begin(), v.end()); // 升序
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	sort(v.begin(), v.end(), std::greater<int>()); // 降序
	// greater<int>()  内建仿函数！不需要自己写降序的仿函数
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}


/*
* 逻辑仿函数
* 函数原型：
* template<class T> bool logical_and<T> //逻辑与
* template<class T> bool logical_or<T>  //逻辑或
* template<class T> bool logical_not<T> //逻辑非
* 
* 总结：逻辑仿函数用的比较少，了解即可；其中逻辑非仿函数可以在搬运容器时候用于取反；
*/
void Logical() {
	std::vector<bool> v;
	v.push_back(1);
	v.push_back(0);
	v.push_back(1);
	v.push_back(0);

	for (std::vector<bool>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	// 利用逻辑非 将容器v搬到v2中 并取反
	std::vector<bool> v2;
	v2.resize(v.size());
	transform(v.begin(), v.end(), v2.begin(), std::logical_not<bool>());
	// transform(); 搬运函数 搬运前需要给接收容器先开辟空间！

	for (std::vector<bool>::iterator it = v2.begin(); it != v2.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	// 利用逻辑与
	std::logical_and<bool> la;
	bool ret = la(1, 0);
	std::cout << "ret = " << ret << std::endl;
}


int main() {
	Arithmetic();

	std::cout << "-------------------\n";
	Relationship();

	std::cout << "-------------------\n";
	Logical();

	system("pause");
	return 0;
}