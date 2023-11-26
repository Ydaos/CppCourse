#include <iostream>
#include <vector>

void printVector(std::vector<int>& v);// 函数定义在01 definition.cpp

								 
/*
* vector插入和删除
* 函数原型：
* push_back(ele);								   //尾部插入元素ele
* pop_back();									   //删除最后一个元素
* insert(const_iterator pos, ele);                 //迭代器向指定位置pos插入元素ele
* insert(const_iterator pos, int n, ele);		   //迭代器向指定位置pos插入n个ele元素
* erase(const_iterator pos)                        //删除迭代器指向的元素
* erase(const_iterator start, const_iterator end); //删除迭代器从beg到end之间的元素
* clear();                                         //删除容器中所有元素
*/
void InsertDel() {
	std::vector<int> v;

	// 尾插
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	printVector(v);

	// 尾删
	v.pop_back();
	printVector(v);

	// 插入 第一个参数是迭代器
	v.insert(v.begin(), 100);
	printVector(v);

	// 向指定位置插入n个元素
	v.insert(v.begin() + 1, 2, 300);
	printVector(v);

	// 删除指定元素 删除也是迭代器
	v.erase(v.begin());
	printVector(v);

	// 删除某段区间的元素
	v.erase(v.begin(), v.end() - 1);
	printVector(v);

	// 清空
	v.clear();
	printVector(v);
}


/*
* vector数据存取
* 函数原型：
* operator[int idx]; //返回索引idx所指的数据
* at(int idx);       //返回索引idx所指的数据
* front();           //返回容器第一个数据元素
* back();		     //返回容器最后一个数据元素
*/
void Access() {
	std::vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	printVector(v);

	//利用[]访问容器元素
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;

	//利用at访问容器元素
	for (int i = 0; i < v.size(); i++) {
		std::cout << v.at(i) << " ";
	}
	std::cout << std::endl;

	//利用[]和at修改访问的容器元素
	v[0] = 11;
	v.at(1) = 21;
	printVector(v);

	//返回容器第一个数据元素
	std::cout << "第一个元素：" << v.front() << std::endl;

	//返回容器最后一个数据元素
	std::cout << "最后一个元素：" << v.back() << std::endl;

	/*
	* 总结:
	* 除了用迭代器获取vector容器中的元素，[]和at也可以
	* front返回容器第一个元素；back返回容器最后一个元素
	*/
}


int main03() {
	InsertDel();

	std::cout << "-------------------------\n";
	Access();

	system("pause");
	return 0;
}