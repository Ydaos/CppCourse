#include <iostream>

/*
* ���غ������ò������࣬������Ϊ��������
* ��������ʹ������()ʱ����Ϊ���ƺ����ĵ��ã�Ҳ�зº���
* �������󣨷º�����������һ���࣬����һ������
* 
* �ص㣺
* ����������ʹ��ʱ����������ͨ�����������ã������в����������з���ֵ
* �������󳬳���ͨ�����ĸ����������������Լ���״̬
* �������������Ϊ��������
*/

// 1������������ʹ��ʱ����������ͨ�����������ã������в����������з���ֵ
class MyAdd {
public:
	int operator()(int v1, int v2) {
		return v1 + v2;
	}
};

void Case01() {
	MyAdd ad;
	std::cout << ad(10, 20) << std::endl;
}

// 2���������󳬳���ͨ�����ĸ����������������Լ���״̬
class MyPrint {
public:
	MyPrint() {
		this->count = 0;
	}

	void operator()(std::string str) {
		std::cout << str << std::endl;
		this->count++; // ͳ�Ƶ��ô���
	}

	int count; // �ڲ��Լ�״̬
};

void Case02() {
	MyPrint mp;
	for (size_t i = 0; i < 4; i++)
	{
		mp("Hello World!");
	}
	std::cout << "myPrint���ô�����" << mp.count << std::endl;
}

// 3���������������Ϊ��������
void doPrint(MyPrint& mp, std::string str) {
	mp(str);
}

void Case03() {
	MyPrint mp;
	doPrint(mp, "Hello C++");
}
// �ܽ᣺�º������÷ǳ���������Ϊ��������

int main01() {
	Case01();

	std::cout << "---------------------\n";
	Case02();

	std::cout << "---------------------\n";
	Case03();

	system("pause");
	return 0;
}