#include <iostream>

//������������أ���������Զ�������
class Point {
	// ����˽�б������ʣ�������Ҫʹ����Ԫ
	friend std::ostream& operator<<(std::ostream& out, Point p);
public:
	Point(int a, int b) :X(a), Y(b) {}

private:
	//1����Ա��������<<�� p.operator<<(cout) �򻯰汾 p << cout
	//��˲������ó�Ա��������<<���������Ϊ�޷�ʵ��cout�����
	/*void operator<<(ostream& cout) {

	}*/

	int X = 0;
	int Y = 0;
};

//2��ȫ�ֺ����������������
std::ostream& operator<<(std::ostream& out, Point p) { //���� operator<<(cout, p) ��cout << p;
	out << p.X << "," << p.Y;
	return out;
}

void LeftShift() {
	Point p(10, 20);

	//��ʽ����˼�룡����
	std::cout << p << std::endl;
}

int main02() {
	LeftShift();

	system("pause");
	return 0;
}