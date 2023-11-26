#include <iostream>

/*
* 内存分区模型
* 代码区：存放函数体的二进制的代码，由操作系统进行管理
* 全局区：存放全局变量和静态变量以及常量
* 栈区：由编译器自动分配释放，存放函数的参数值、局部变量等
* 堆区：由程序员分配和释放，若程序员不释放，程序结束时由操作系统回收
* 内存四区意义：不同的区域存放的数据，赋予不同的生命周期，给我们更大的灵活编程
*/

/*
* 程序运行前
* 在程序编译后会生成 .exe可执行程序，未执行该程序之前分为两个区域：代码区和全局区
* 
* 代码区：
* 存放CPU执行的机器指令
* 代码区是共享的，共享的目的是对于频繁被执行的程序，只需要在内存中有一份代码即可
* 代码区是只读的，防止程序意外地修改了它的指令
* 
* 全局区：
* 全局变量和静态变量存放在此
* 全局区还包含了常量区,包括字符串常量和const修饰的全局常量也存放在此
* 该区域的数据在程序结束后由操作系统释放
*/

//全局变量
int g_a = 10;
int g_b = 20;

//const修饰的全局变量
const int c_g_a = 10;
const int c_g_b = 20;

void Memory01() {
	//全局区
	//全局变量、静态变量、常量

	//创建普通变量
	int a = 10;
	int b = 20;
	std::cout << "a的地址：" << &a << std::endl;
	std::cout << "b的地址：" << &b << std::endl;

	std::cout << "g_a的地址：" << &g_a << std::endl;
	std::cout << "g_b的地址：" << &g_b << std::endl;

	//静态变量 在普通变量前面加static，属于静态变量
	static int s_a = 10;
	static int s_b = 20;
	std::cout << "s_a的地址：" << &s_a << std::endl;
	std::cout << "s_b的地址：" << &s_b << std::endl;

	//常量
	//字符串常量
	std::cout << "字符串常量地址： " << &"hello world" << std::endl;

	//const修饰的全局变量、const修饰的局部变量
	std::cout << "c_g_a的地址：" << &c_g_a << std::endl;
	std::cout << "c_g_b的地址：" << &c_g_b << std::endl;
	//const修饰的局部变量不存放到全局区

	const int c_l_a = 10;
	const int c_l_b = 20;
	std::cout << "c_l_a的地址：" << &c_l_a << std::endl;
	std::cout << "c_l_b的地址：" << &c_l_b << std::endl;
}

int main01() {
	Memory01();

	system("pause");
	return 0;
}