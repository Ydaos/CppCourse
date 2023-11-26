#include <iostream>

void if_else_demo();
void ternary_operator_demo();
void switch_demo();

/*
* �������̽ṹ�����֣�˳��ṹ��ѡ��ṹ��ѭ���ṹ
* 
* ����ѡ��ṹ�����¼��֣�
* if else-if else
* ��Ŀ�����
* switch-case
*/
void SelectionStructure() {
	//ѡ��ṹ - ����if���
	std::cout << "\n----------- This is a if-else demo -------------\n";
	if_else_demo();
	
	//��Ŀ�����
	std::cout << "\n----------- This is a ternary operator demo -------------\n";
	ternary_operator_demo();

	//switch-case
	std::cout << "\n----------- This is a switch-case demo -------------\n";
	switch_demo();

	//if��switch����
	//switchȱ�㣺���ж�ʱ��ֻ�������ͻ��ַ��ͣ���������һ������
	//switch�ŵ㣺�ṹ������ִ��Ч�ʸ�
}

void if_else_demo() {
	//1���û��������
	int score = 0;
	std::cout << "�����һ������" << std::endl;
	std::cin >> score;

	//2����ӡ�û�����
	std::cout << "������ķ���Ϊ��" << score << std::endl;

	//3���жϷ����Ƿ����600���Ǿ����
	//ע�������if�ж������棬��Ҫ�ӷֺ�
	if (score >= 600) {
		std::cout << "��ϲ�㿼��һ����ѧ" << std::endl;
		if (score > 700) {
			std::cout << "���ܿ����廪��ѧ" << std::endl;
		}
		else if (score > 650) {
			std::cout << "���ܿ��뱱����ѧ" << std::endl;
		}
		else {
			std::cout << "���ܿ��������ѧ" << std::endl;
		}
	}
	else if (score >= 500) {
		std::cout << "��ϲ�㿼�϶�����ѧ" << std::endl;
	}
	else if (score >= 400) {
		std::cout << "��ϲ�㿼��������ѧ" << std::endl;
	}
	else {
		std::cout << "���ź���δ���ϱ��ƴ�ѧ�����ٽ�����" << std::endl;
	}
}

void ternary_operator_demo() {
	//��Ŀ�����

	//������������ a b c
	//��a b���ֵ��ֵ��c
	int a = 10;
	int b = 20;
	int c = 0;

	c = (a > b ? a : b);
	std::cout << "c = " << c << std::endl;

	//��C++����Ŀ��������ص��Ǳ��������Լ�����ֵ
	(a > b ? a : b) = 100;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
}

void switch_demo() {
	//����Ӱ��֣�10~9 ���䣻8~7 �ǳ���;6~5 һ�㣻5���� ��Ƭ

	//1������Ӱ���
	int score = 0;
	std::cout << "���0~10��ѡһ�����ָ���Ӱ���" << std::endl;
	std::cin >> score;
	std::cout << "���ķ���" << score << std::endl;

	//2�������û���������ʾ��Ӱ���Ľ��
	switch (score) {
	case 10:
		std::cout << "����Ϊ�Ǿ����Ӱ" << std::endl;
		break; //�˳���ǰ��֧�����������ִ�У�����
	case 9:
		std::cout << "����Ϊ�Ǿ����Ӱ" << std::endl;
		break;
	case 8:
		std::cout << "����Ϊ��Ӱ�ǳ���" << std::endl;
		break;
	case 7:
		std::cout << "����Ϊ��Ӱ�ǳ���" << std::endl;
		break;
	case 6:
		std::cout << "����Ϊ��Ӱһ��" << std::endl;
		break;
	case 5:
		std::cout << "����Ϊ��Ӱһ��" << std::endl;
		break;
	default:
		std::cout << "����Ϊ��Ӱ����Ƭ" << std::endl;
		break;
	}
}

int main01() {
	SelectionStructure();

	system("pause");
	return 0;
}