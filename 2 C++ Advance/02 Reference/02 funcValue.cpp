#include<iostream>

//���ã���������ʱ�������������õļ������β�����ʵ��
//�ŵ㣺���Լ�ָ���޸�ʵ��

//��������
//1��ֵ����
void mySwap1(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
	std::cout << "swap1 a = " << a << " b = " << b << std::endl;
}

//2����ַ����
void mySwap2(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
	std::cout << "swap2 a = " << *a << " b = " << *b << std::endl;
}

//3�����ô���
void mySwap3(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
	std::cout << "swap3 a = " << a << " b = " << b << std::endl;
}

//���ã�����������Ҫ���������βΣ���ֹ�����
//�ں����β��У����Լ�const�����βΣ���ֹ�βθı�ʵ��

//��ӡ����
void showValue(const int& val) {
	//val = 1000; ��const��ֹ���޸�
	std::cout << "val = " << val << std::endl;
}

void FuncValue() {
	int a = 10;
	int b = 20;
	mySwap1(a, b); //ֵ���ݣ��ββ�����ʵ��
	std::cout << "a = " << a << "\tb = " << b << std::endl;

	mySwap2(&a, &b); //��ַ���ݣ��βλ�����ʵ��
	std::cout << "a = " << a << "\tb = " << b << std::endl;

	mySwap3(a, b); //���ô��ݣ��βλ�����ʵ��
	std::cout << "a = " << a << "\tb = " << b << std::endl;
	//�ܽ᣺ͨ�����ò���������Ч��ͬ����ַ������һ���ġ����õ��﷨�������
	
	//int& b = 10; error! ���ñ�����һ��Ϸ����ڴ�ռ�
	//����const֮�󣬱������������޸�Ϊ int temp = 10; const int& ref = temp;
	const int& ref = 10;
	//ref = 20; //����const֮���Ϊֻ�����������޸�
	showValue(ref);
}

int main02() {
	FuncValue();

	system("pause");
	return 0;
}