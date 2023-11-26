#include "addressBook.h"

void showMenu() {
	cout << "*****************************" << endl;
	cout << "*****" << "\t1�������ϵ��\t" << "*****" << endl;
	cout << "*****" << "\t2����ʾ��ϵ��\t" << "*****" << endl;
	cout << "*****" << "\t3��ɾ����ϵ��\t" << "*****" << endl;
	cout << "*****" << "\t4��������ϵ��\t" << "*****" << endl;
	cout << "*****" << "\t5���޸���ϵ��\t" << "*****" << endl;
	cout << "*****" << "\t6�������ϵ��\t" << "*****" << endl;
	cout << "*****" << "\t0���˳���ϵ��\t" << "*****" << endl;
	cout << "*****************************" << endl;
}

int main() {
	int select = -1;
	int m_size = 0;
	Contact* cArr = new Contact[Max];

	while (select != 0) {
		showMenu();
		cin >> select;

		switch (select)
		{
		case 0:  //�˳�ͨѶ¼
			cout << "ͨѶ¼�رգ���ӭ�ٴ�ʹ�ã�" << endl;
			break;

		case 1:  //�����ϵ��
			if (m_size <= 999) {
				addContact(cArr, m_size);
			}
			else {
				cout << "ͨѶ¼����" << endl;
			}
			break;

		case 2:  //��ʾ��ϵ��
			showContact(cArr, m_size);
			break;

		case 3:  //ɾ����ϵ��
			deleteContact(cArr, m_size);
			break;

		case 4:  //������ϵ��
			seekContact(cArr, m_size);
			break;

		case 5:  //�޸���ϵ��
			alterContact(cArr, m_size);
			break;

		case 6:  //�����ϵ��
			clearContact(cArr, m_size);
			break;

		default:  //��Чָ��
			cout << "��Ч�������������" << endl;
			break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}



