#include <iostream>

//左移运算符重载：可以输出自定义类型
class Point {
	// 对于私有变量访问，我们需要使用友元
	friend std::ostream& operator<<(std::ostream& out, Point p);
public:
	Point(int a, int b) :X(a), Y(b) {}

private:
	//1、成员函数重载<<号 p.operator<<(cout) 简化版本 p << cout
	//因此不会利用成员函数重载<<运算符，因为无法实现cout在左侧
	/*void operator<<(ostream& cout) {

	}*/

	int X = 0;
	int Y = 0;
};

//2、全局函数重载左移运算符
std::ostream& operator<<(std::ostream& out, Point p) { //本质 operator<<(cout, p) 简化cout << p;
	out << p.X << "," << p.Y;
	return out;
}

void LeftShift() {
	Point p(10, 20);

	//链式变量思想！！！
	std::cout << p << std::endl;
}

int main02() {
	LeftShift();

	system("pause");
	return 0;
}