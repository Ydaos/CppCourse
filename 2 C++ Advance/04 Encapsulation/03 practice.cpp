#include<iostream>

//设计立方体类
//求出立方体的面积和体积
//分别用全局函数和成员函数判断两个立方体是否相等

class Cube {
private:
	int m_L = 0;
	int m_W = 0;
	int m_H = 0;

public:
	//设置长宽高
	void setSideLength(int L, int W, int H) {
		m_L = L;
		m_W = W;
		m_H = H;
	}

	//获取边长
	int getL()const {
		return m_L;
	}
	int getW()const {
		return m_W;
	}
	int getH()const {
		return m_H;
	}

	//获取面积
	int getArea() {
		return 2 * (m_L * m_W + m_L * m_H + m_W * m_H);
	}

	//获取体积
	int getVolume() {
		return m_L * m_W * m_H;
	}

	//利用成员函数判断两个立方体是否相等
	bool isSameByClass(const Cube& c) {
		//c.setSideLength(1, 2, 3);
		if (m_L == c.getL() && m_W == c.getW() && m_H == c.getH()) {
			return true;
		}
		return false;
	}
};

//利用全局函数判断 两个立方体是否相等
bool isSame(const Cube& c1, const Cube& c2) {
	if (c1.getL() == c2.getL() && c1.getW() == c2.getW() && c1.getH() == c2.getH()) {
		return true;
	}
	return false;
}

void Practice01() {
	//创建立方体c1
	Cube c1;
	c1.setSideLength(10, 10, 10);
	std::cout << "c1的面积为：" << c1.getArea() << std::endl;
	std::cout << "c1的体积为：" << c1.getVolume() << std::endl;

	//创建立方体c2
	Cube c2;
	c2.setSideLength(5, 5, 5);
	std::cout << "c2的面积为：" << c2.getArea() << std::endl;
	std::cout << "c2的体积为：" << c2.getVolume() << std::endl;

	//利用全局函数比较两个立方体是否相等
	bool ret = isSame(c1, c2);
	if (ret) {
		std::cout << "全局函数判断 c1和c2相等\n";
	}
	else {
		std::cout << "全局函数判断 c1和c2不相等\n";
	}

	//利用成员函数判断两个立方体是否相等
	ret = c1.isSameByClass(c2);
	if (ret) {
		std::cout << "成员函数判断 c1和c2相等\n";
	}
	else {
		std::cout << "成员函数判断 c1和c2不相等\n";
	}
}

int main03() {
	Practice01();

	system("pause");
	return 0;
}