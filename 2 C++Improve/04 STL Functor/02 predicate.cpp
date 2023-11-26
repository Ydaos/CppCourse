#include <iostream>
#include <vector>
#include <algorithm>

/*
* ν�ʣ�����bool���͵ķº���
* ���operator()����һ����������ΪһԪν��
* ���operator()����������������Ϊ��Ԫν��
*/

// 1��һԪν��
class GreatFive {
public:
	bool operator()(int val) {
		return val > 5;
	}
};

void Predicate01() {
	std::vector<int>v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}

	// ������������û�д���5������
	// �����ĺ�������GreatFive()
	std::vector<int>::iterator pos = find_if(v.begin(), v.end(), GreatFive());
	if (pos == v.end()) {
		std::cout << "δ�ҵ�����5������" << std::endl;
	}
	else {
		std::cout << "�ҵ�����5�����֣�" << *pos << std::endl;
	}
}

// 2����Ԫν��
class MySort {
public:
	bool operator()(int v1, int v2) {
		// ����
		return v1 > v2;
	}
};

void Predicate02() {
	std::vector<int>v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(20);
	v.push_back(50);
	v.push_back(40);

	sort(v.begin(), v.end());
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	// ʹ�ú�������ı��㷨���ԣ���Ϊ�������Ϊ����
	sort(v.begin(), v.end(), MySort());
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

int main02() {
	Predicate01();

	std::cout << "-------------------\n";
	Predicate02();

	system("pause");
	return 0;
}