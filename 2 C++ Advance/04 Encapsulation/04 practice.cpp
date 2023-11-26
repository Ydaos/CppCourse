#include <iostream>

//���һ��Բ����(Circle)��һ������(pointer)��������Բ�Ĺ�ϵ
class Pointer {
private:
	int m_x;
	int m_y;

public:
	//���õ�����
	void setPointer(int x, int y) {
		m_x = x;
		m_y = y;
	}

	//��ȡ������
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
	//����Բ�ĺͰ뾶
	void setCircle(const Pointer& centre, int r) {
		m_X = centre.getX();
		m_Y = centre.getY();
		m_R = r;
	}

	//�жϵ���Բ�ϵ�λ��
	void getPointerLocation(const Pointer& p) {
		double dis = 0;
		dis = sqrt((p.getX() - m_X) * (p.getX() - m_X) + (p.getY() - m_Y) * (p.getY() - m_Y));
		if (dis > m_R) {
			std::cout << "����Բ��" << std::endl;
		}
		else if (dis < m_R) {
			std::cout << "����Բ��" << std::endl;
		}
		else {
			std::cout << "����Բ��" << std::endl;
		}
	}
	//ע�⣡��ĳ�Ա������Ժ�����һ����
};

void Practice02() {
	//ʵ����һ����
	Pointer p;
	p.setPointer(1, 2);

	//ʵ����һ��Բ
	Circle c;

	Pointer centre;
	centre.setPointer(2, 2); //����Բ������

	c.setCircle(centre, 2);
	c.getPointerLocation(p);
}

int main() {
	Practice02();

	system("pause");
	return 0;
}