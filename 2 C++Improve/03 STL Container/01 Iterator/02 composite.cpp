#include <iostream>
#include <vector>

// ����Ƕ����������������������
void Composite() {
	std::vector<std::vector<int>>v;

	// ����С����
	std::vector<int>v1;
	std::vector<int>v2;
	std::vector<int>v3;
	std::vector<int>v4;
	std::vector<int>v5;

	// ��С�����������
	for (int i = 0; i < 5; i++) {
		v1.push_back(i);
		v2.push_back(i + 10);
		v3.push_back(i + 20);
		v4.push_back(i + 30);
		v5.push_back(i + 40);
	}

	// ��С�������뵽��������
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	v.push_back(v5);

	// ͨ��������������������
	for (std::vector<std::vector<int>>::iterator it = v.begin(); it != v.end(); it++) {
		for (std::vector<int>::iterator it_t = (*it).begin(); it_t != (*it).end(); it_t++) {
			std::cout << *it_t << " ";
		}
		std::cout << std::endl;
	}
}

int main() {
	Composite();

	system("pause");
	return 0;
}