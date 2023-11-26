#include <iostream>
#include <list>

void printList(const std::list<int>& l); //函数定义在文件"01 definition.cpp"


/*
* List容器大小操作
* 函数原型：
* size();			     //返回容器大小
* empty();               //判断容器是否为空
* resize(int num);       //重新指定容器大小为num，若变长则以默认值填充新位置；若变短则删除超过容器长度的元素；
* resize(int num, elem); //重新指定容器大小为num，若变长则以elem值填充新位置；若变短则删除超过容器长度的元素；
*/
void ListSize() {
	std::list<int> L;
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	L.push_back(40);
	L.push_back(50);
	printList(L);

	// 判断容器是否为空
	if (L.empty()) {
		std::cout << "容器为空" << std::endl;
	}
	else {
		std::cout << "容器不为空" << std::endl;

		// size
		std::cout << "容器大小为：" << L.size() << std::endl;
	}

	// 重新指定大小
	L.resize(3);
	printList(L);
	std::cout << "重新指定的容器大小为：" << L.size() << std::endl;

	L.resize(5, 10);
	printList(L);
	std::cout << "重新指定的容器大小为：" << L.size() << std::endl;
}


/*
* List容器交换
* 函数原型：
* swap(lst); //将lst与本身元素交换
*/
void ListSwap() {
	std::cout << "交换前" << std::endl;
	std::list<int> L;
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	L.push_back(40);
	L.push_back(50);
	printList(L);

	std::list<int>L2;
	L2.assign(10, 66);
	printList(L2);

	std::cout << "交换后" << std::endl;
	L.swap(L2);
	printList(L);
	printList(L2);
}

int main02() {
	ListSize();

	std::cout << "--------------------------\n";
	ListSwap();

	system("pause");
	return 0;
}