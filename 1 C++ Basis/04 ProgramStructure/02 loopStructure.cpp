#include <iostream>

void while_demo();
void do_while_demo();
void for_demo();

/*
* ����ѭ���ṹ�����¼��֣�
* while
* do-while
* for
* 
* do-while��while�������� do-while����ִ��һ��ѭ�����
*/
void LoopStructure() {
	std::cout << "\n----------- This is a loop-while demo -------------\n";
	while_demo();

	std::cout << "\n----------- This is a loop-do_while demo -------------\n";
	do_while_demo();

	std::cout << "\n----------- This is a loop-for demo -------------\n";
	for_demo();
}

void while_demo() {
	//����Ļ�д�ӡ0~9��10������

	int num = 0;
	//��while()�м���ѭ������
	//ע�����дѭ��һ��Ҫ������ѭ���ĳ���
	while (num < 10) {
		std::cout << num << " ";
		num++;
	}
	std::cout << std::endl;
}

void do_while_demo() {
	//ˮ�ɻ�����3λ����ÿ��λ�����ֵ�������֮�͵���������
	int num = 100;
	int a = 0; //��λ
	int b = 0; //ʮλ
	int c = 0; //��λ

	do {
		a = num % 10; //��ȡ��λ����
		b = (num / 10) % 10; //��ȡʮλ����
		c = num / 100; //��ȡ��λ����

		if ((a * a * a + b * b * b + c * c * c) == num) {
			std::cout << num << " ";
		}
		num++;
	} while (num < 1000);
	std::cout << std::endl;
}

void for_demo() {
	//forѭ��
	//��ӡ����0~9
	for (int i = 0; i < 10; i++) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

	//����Ƕ��ѭ����ӡ9*9�˷���
	//���ѭ��ִ��һ�Σ��ڲ�ѭ��ִ��һ��
	for (int i = 1; i < 10; i++) { //���ѭ��
		for (int j = 1; j <= i; j++) { //�ڲ�ѭ��
			std::cout << j << "*" << i << "=" << j * i << " ";
		}
		std::cout << std::endl;
	}
}

int main02() {
	LoopStructure();

	system("pause");
	return 0;
}