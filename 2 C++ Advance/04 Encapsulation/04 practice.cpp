#include <iostream>

//设计一个圆形类(Circle)和一个点类(pointer)，计算点和圆的关系
class Pointer {
private:
	int m_x;
	int m_y;

public:
	//设置点坐标
	void setPointer(int x, int y) {
		m_x = x;
		m_y = y;
	}

	//获取点坐标
	int getX()const {
		return m_x;
	}
	int getY()const {
		return m_y;
	}
};

class Circle {
private:
	int m_X;
	int m_Y;
	int m_R;

public:
	//设置圆心和半径
	void setCircle(const Pointer& centre, int r) {
		m_X = centre.getX();
		m_Y = centre.getY();
		m_R = r;
	}

	//判断点在圆上的位置
	void getPointerLocation(const Pointer& p) {
		double dis = 0;
		dis = sqrt((p.getX() - m_X) * (p.getX() - m_X) + (p.getY() - m_Y) * (p.getY() - m_Y));
		if (dis > m_R) {
			std::cout << "点在圆外" << std::endl;
		}
		else if (dis < m_R) {
			std::cout << "点在圆内" << std::endl;
		}
		else {
			std::cout << "点在圆上" << std::endl;
		}
	}
	//注意！类的成员对象可以含有另一个类
};

void Practice02() {
	//实例化一个点
	Pointer p;
	p.setPointer(1, 2);

	//实例化一个圆
	Circle c;

	Pointer centre;
	centre.setPointer(2, 2); //创建圆心坐标

	c.setCircle(centre, 2);
	c.getPointerLocation(p);
}

int main() {
	Practice02();

	system("pause");
	return 0;
}