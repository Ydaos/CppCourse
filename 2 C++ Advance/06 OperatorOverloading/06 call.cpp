#include<iostream>

/*
* �����������������
* �������غ�ʹ�õķ����ǳ������ĵ��ã���˳�Ϊ�º���
* �º���û�й̶�д�����ǳ����
*/

class MyPrint {
public:
	//���غ������������
	void operator()(std::string str) {
		std::cout << str << std::endl;
	}
};

void Print(std::string str) { //��ӡ����
	std::cout << str << std::endl;
}

class MyAdd {
public:
	int operator()(int num1, int num2) {
		return num1 + num2;
	}
};

void CallOperator() {
	// First demo
	MyPrint myPrint;
	myPrint("Hello World"); // ����ʹ�������ǳ����ƺ�������˳�Ϊ�º���
	Print("Hello World");	// ��ͨ����

	// Second demo
	MyAdd myAdd;
	int ret = myAdd(10, 20);
	std::cout << "ret = " << ret << std::endl;

	//���������������
	std::cout << MyAdd()(100, 100) << std::endl; //�������󣬵���ִ����ͻᱻ�ͷ�
}

int main06() {
	CallOperator();

	system("pause");
	return 0;
}