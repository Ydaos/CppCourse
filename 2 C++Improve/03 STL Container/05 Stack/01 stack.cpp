#include <iostream>
#include <stack>

/*
* stack概念：栈容器stack是先进后出的数据结构，它只有一个出口
* 栈不允许有遍历行为，因为只有栈顶元素才能被访问
* 栈可以判断是否为空 -- empty
* 栈可以返回元素个数 -- size
* 栈中进入数据称为入栈 -- push
* 栈中弹出数据称为出栈 -- pop
*
* stack常用接口
* 构造函数：
* stack<T> stk;            //默认构造函数
* stack(const stack &std); //拷贝构造函数
*
* 赋值操作：
* stack& operator=(const stack &stk); //重载=运算符

* 数据存取：
* push(elem); //向栈顶添加元素
* pop();      //从栈顶移除第一个元素
* top();      //返回栈顶元素

* 大小操作：
* empty();    //判断堆栈是否为空
* size();     //返回堆栈大小
*/
void MyStack() {
	// 特点：先进后出
	std::stack<int> s;

	// 入栈
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);

	// 只要栈不为空，查看栈顶，并出栈
	std::cout << "栈的元素个数：" << s.size() << std::endl;
	while (!s.empty()) {
		std::cout << "栈顶元素：" << s.top() << std::endl;
		s.pop();
	}
	std::cout << "栈的元素个数：" << s.size() << std::endl;
}


int main() {
	MyStack();

	system("pause");
	return 0;
}