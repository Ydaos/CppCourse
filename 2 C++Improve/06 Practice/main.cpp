#include "workerManager.h";

int main() {
	WorkerManager wm;
	int choice = -1;

	do {
		// չʾ�˵�
		wm.showMenu();

		// ��������
		cout << "����������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0: // �˳�ϵͳ
			wm.exitSystem();
			break;
		case 1: // ���ְ��
			wm.addEmployee();
			break;
		case 2: // ��ʾְ��
			wm.showEmployee();
			break;
		case 3: // ɾ��ְ��
			wm.delEmployee();
			break;
		case 4: // �޸�ְ��
			wm.modEmployee();
			break;
		case 5: // ����ְ��
			wm.findEmployee();
			break;
		case 6: // ����ְ��
			wm.sortEmployee();
			break;
		case 7: // ����ļ�
			wm.clearEmpFile();
			break;
		default:
			break;
		}

	} while (choice != 0);

	return 0;
}