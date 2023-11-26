#include<iostream>

//�����������
//������������������
//�ֱ���ȫ�ֺ����ͳ�Ա�����ж������������Ƿ����

class Cube {
private:
	int m_L = 0;
	int m_W = 0;
	int m_H = 0;

public:
	//���ó����
	void setSideLength(int L, int W, int H) {
		m_L = L;
		m_W = W;
		m_H = H;
	}

	//��ȡ�߳�
	int getL()const {
		return m_L;
	}
	int getW()const {
		return m_W;
	}
	int getH()const {
		return m_H;
	}

	//��ȡ���
	int getArea() {
		return 2 * (m_L * m_W + m_L * m_H + m_W * m_H);
	}

	//��ȡ���
	int getVolume() {
		return m_L * m_W * m_H;
	}

	//���ó�Ա�����ж������������Ƿ����
	bool isSameByClass(const Cube& c) {
		//c.setSideLength(1, 2, 3);
		if (m_L == c.getL() && m_W == c.getW() && m_H == c.getH()) {
			return true;
		}
		return false;
	}
};

//����ȫ�ֺ����ж� �����������Ƿ����
bool isSame(const Cube& c1, const Cube& c2) {
	if (c1.getL() == c2.getL() && c1.getW() == c2.getW() && c1.getH() == c2.getH()) {
		return true;
	}
	return false;
}

void Practice01() {
	//����������c1
	Cube c1;
	c1.setSideLength(10, 10, 10);
	std::cout << "c1�����Ϊ��" << c1.getArea() << std::endl;
	std::cout << "c1�����Ϊ��" << c1.getVolume() << std::endl;

	//����������c2
	Cube c2;
	c2.setSideLength(5, 5, 5);
	std::cout << "c2�����Ϊ��" << c2.getArea() << std::endl;
	std::cout << "c2�����Ϊ��" << c2.getVolume() << std::endl;

	//����ȫ�ֺ����Ƚ������������Ƿ����
	bool ret = isSame(c1, c2);
	if (ret) {
		std::cout << "ȫ�ֺ����ж� c1��c2���\n";
	}
	else {
		std::cout << "ȫ�ֺ����ж� c1��c2�����\n";
	}

	//���ó�Ա�����ж������������Ƿ����
	ret = c1.isSameByClass(c2);
	if (ret) {
		std::cout << "��Ա�����ж� c1��c2���\n";
	}
	else {
		std::cout << "��Ա�����ж� c1��c2�����\n";
	}
}

int main03() {
	Practice01();

	system("pause");
	return 0;
}