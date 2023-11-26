#include <iostream>

void break_demo();
void continue_demo();
void goto_demo();

/*
* �������̿��ƹؼ����У�break��continue��goto
*/
void Keyword() {
	std::cout << "\n----------- This is a break statement demo -------------\n";
	break_demo();

	std::cout << "\n----------- This is a continue statement demo -------------\n";
	continue_demo();

	std::cout << "\n----------- This is a goto statement demo -------------\n";
	goto_demo();
}

//break: ��������ѡ��ṹ��ѭ���ṹ
void break_demo() {
	//breakʹ��ʱ��
	//1������switch
	std::cout << "��ѡ�񸱱��Ѷ�" << std::endl;
	std::cout << "1����ͨ" << std::endl;
	std::cout << "2���е�" << std::endl;
	std::cout << "3������" << std::endl;

	int select = 0;
	std::cin >> select;
	switch (select)
	{
	case 1:
		std::cout << "��ѡ�������ͨ�Ѷ�" << std::endl;
		break;
	case 2:
		std::cout << "��ѡ������е��Ѷ�" << std::endl;
		break;
	case 3:
		std::cout << "��ѡ����������Ѷ�" << std::endl;
		break;
	default:
		break;
	}

	//2��������ѭ�������
	for (int i = 0; i < 10; i++) {
		if (i == 5) {
			break; //�˳�ѭ��
		}
		std::cout << i << std::endl;
	}

	//3��������Ƕ�������
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 5) {
				break; //�˳��ڲ�ѭ��
			}
			std::cout << "* ";
		}
		std::cout << std::endl;
	}
}

void continue_demo() {
	//continue���
	for (int i = 0; i < 20; i++) {
		if (i % 2 == 0) {
			continue; //��ɸѡ������ִ����һ��ѭ��
			//break;���˳�ѭ��
		}
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

void goto_demo() {
	//goto���
	std::cout << "1" << std::endl;
	std::cout << "2" << std::endl;
	goto FLAG;
	std::cout << "3" << std::endl;
	std::cout << "4" << std::endl;
FLAG:
	std::cout << "5" << std::endl;
	//������ʹ�ã����״����߼�����
}

int main() {
	Keyword();

	system("pause");
	return 0;
}