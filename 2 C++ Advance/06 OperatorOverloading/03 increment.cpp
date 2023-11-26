#include<iostream>

//递增运算符重载：实现自己的整型数据

//自定义整型
class MyInteger {
	friend std::ostream& operator<<(std::ostream& out, MyInteger myint);
public:
	MyInteger() {
		m_num = 0;
	}

	//重载前置++运算符,返回引用是为了一直对一个数据进行操作
	MyInteger& operator++() {
		m_num++;
		return *this;
	}

	//重载后置++运算符
	//MyInteger& operator++(int) int代表占位参数，可以用来区分前置和后置递增
	MyInteger operator++(int) {
		//先记录结果
		MyInteger temp = *this;

		//后递增
		this->m_num++;

		//最后将记录结果返回
		return temp;

		//注意：temp为局部变量，只能返回值不能返回地址
	}

private:
	int m_num;
};

//重载左移运算符
std::ostream& operator<<(std::ostream& out, MyInteger myint) {
	out << myint.m_num;
	return out;
}

void Increment() {
	MyInteger myint;
	std::cout << myint << std::endl;
	std::cout << ++myint << std::endl;
	std::cout << myint++ << std::endl;
	std::cout << myint << std::endl;
	
	std::cout << ++(++myint) << std::endl; //链表有意义，一直对myint进行递增操作
	std::cout << (myint++)++ << std::endl; //链表无意义，一直对旧的temp进行temp操作
	std::cout << myint << std::endl;
}
//总结：前置递增返回引用，后置递增返回值

int main03() {
	Increment();

	system("pause");
	return 0;
}