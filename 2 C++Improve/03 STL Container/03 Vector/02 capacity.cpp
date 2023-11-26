#include <iostream>
#include <vector>

void printVector(std::vector<int>& v);// 函数定义在01 definition.cpp

/*
* vector容量和大小
* 函数原型：
* empty();			     //判断容器是否为空
* capacity();            //容器的容量
* size();                //返回容器中元素的个数
* resize(int num);       //重新指定容器的长度为num。若容器变长则以默认值来填充；若容器变短则尾部超出容器长度的元素会被删除
* resize(int num, elem); //重新指定容器的长度为num，若容器变长则以elem值来填充；若容器变短则尾部超出容器长度的元素会被删除
* 
* vector预留空间：减速vector在动态扩展容量时的扩展次数
* 函数原型：
* reserve(int len);      //容器预留len个元素长度，预留位置不初始化，元素不可访问
*/
void Capacity() {
	std::vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	printVector(v1);

	if (v1.empty()) {
		std::cout << "v1为空" << std::endl;
	}
	else {
		std::cout << "v1不为空" << std::endl;
		std::cout << "v1 容量：" << v1.capacity() << std::endl;
		std::cout << "v1 大小：" << v1.size() << std::endl;
	}

	// 重新指定大小
	v1.resize(15);
	printVector(v1); //如果重新指定的比原来长，默认用0填充新的位置

	v1.resize(20, 6);
	printVector(v1); //用重载版本可以使用指定值填充新的位置

	v1.resize(5);
	printVector(v1); //如果重新指定比原来短，会删掉多出来的尾巴


	// 利用reserve预留空间
	std::vector<int> v;
	v.reserve(100000);

	int num = 0; // 统计开辟次数
	int* p = NULL;
	for (int i = 0; i < 100000; i++) {
		v.push_back(i);
		if (p != &v[0]) {
			p = &v[0];
			num++;
		}
	}
	std::cout << "\n开辟次数:" << num << std::endl;
	// 总结:如果数据量比较大，可以一开始就用reserve预留空间
}

int main() {
	Capacity();

	system("pause");
	return 0;
}