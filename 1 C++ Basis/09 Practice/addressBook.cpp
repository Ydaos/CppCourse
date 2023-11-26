#include "addressBook.h"

void addContact(Contact* cArr, int& num) {
	int gender = 0;
	Contact cTemp;
	cout << "����������" << endl;
	cin >> cTemp.name;

	cout << "�������Ա�" << endl;
	cout << "1 -- ��" << endl;
	cout << "2 -- Ů" << endl;
	do {
		cin >> gender;
		if (gender == 1) {
			cTemp.gender = "��";
		}
		else if (gender == 2) {
			cTemp.gender = "Ů";
		}
		else {
			cout << "�Ա𲻴��ڣ�����������" << endl;
		}
	} while (gender != 1 && (gender != 2));

	cout << "����������" << endl;
	cin >> cTemp.age;

	cout << "������绰" << endl;
	cin >> cTemp.phone;

	cout << "�������ͥסַ" << endl;
	cin >> cTemp.address;

	cTemp.idx = num + 1;
	cArr[num] = cTemp;
	num += 1;

	cout << "��ӳɹ�" << endl;
}

void showContact(Contact* cArr, int num) {
	if (num == 0) {
		cout << "��ǰͨѶ¼Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < num; i++) {
			cout << "������" << cArr[i].name << "\t"
				<< "�Ա�" << cArr[i].gender << "\t"
				<< "���䣺" << cArr[i].age << "\t"
				<< "�绰��" << cArr[i].phone << "\t"
				<< "סַ��" << cArr[i].address << endl;
		}
	}
}

void deleteContact(Contact* cArr, int& num) {
	int idx = -1;
	string name;
	bool flag = false;
	cout << "������Ҫɾ������ϵ������" << endl;
	cin >> name;
	for (int i = 0; i < num; i++) {
		if (cArr[i].name == name) {
			flag = true;
			cout << "��ţ�" << cArr[i].idx << "\t"
				<< "������" << cArr[i].name << "\t"
				<< "�Ա�" << cArr[i].gender << "\t"
				<< "���䣺" << cArr[i].age << "\t"
				<< "�绰��" << cArr[i].phone << "\t"
				<< "סַ��" << cArr[i].address << endl;
		}
	}
	if (flag) {
		cout << "��ѡ��Ҫɾ������ϵ�˱��" << endl;
		cin >> idx;
		for (int j = idx - 1; j < num - 1; j++) {
			cArr[j] = cArr[j + 1];
			cArr[j].idx = j + 1;
		}
		num -= 1;
		cout << "ɾ���ɹ�" << endl;
	}
	else {
		cout << "��ϵ�˲�����" << endl;
	}
}

void seekContact(Contact* cArr, int num) {
	string name;
	bool flag = false;
	cout << "������Ҫ���ҵ���ϵ������" << endl;
	cin >> name;
	for (int i = 0; i < num; i++) {
		if (cArr[i].name == name) {
			flag = true;
			cout << "������" << cArr[i].name << "\t"
				<< "�Ա�" << cArr[i].gender << "\t"
				<< "���䣺" << cArr[i].age << "\t"
				<< "�绰��" << cArr[i].phone << "\t"
				<< "סַ��" << cArr[i].address << endl;
		}
	}
	if (!flag) {
		cout << "��ϵ�˲�����" << endl;
	}
}

void alterContact(Contact* cArr, int num) {
	int idx = -1;
	string name;
	bool flag = false;
	cout << "������Ҫ�޸ĵ���ϵ������" << endl;
	cin >> name;
	for (int i = 0; i < num; i++) {
		if (cArr[i].name == name) {
			flag = true;
			cout << "��ţ�" << cArr[i].idx << "\t"
				<< "������" << cArr[i].name << "\t"
				<< "�Ա�" << cArr[i].gender << "\t"
				<< "���䣺" << cArr[i].age << "\t"
				<< "�绰��" << cArr[i].phone << "\t"
				<< "סַ��" << cArr[i].address << endl;
		}
	}
	if (flag) {
		cout << "��ѡ��Ҫ�޸ĵ���ϵ�˱��" << endl;
		cin >> idx;

		int gender = 0;
		Contact cTemp;
		cout << "����������" << endl;
		cin >> cTemp.name;

		cout << "�������Ա�" << endl;
		cout << "1 -- ��" << endl;
		cout << "2 -- Ů" << endl;
		do {
			cin >> gender;
			if (gender == 1) {
				cTemp.gender = "��";
			}
			else if (gender == 2) {
				cTemp.gender = "Ů";
			}
			else {
				cout << "�Ա𲻴��ڣ�����������" << endl;
			}
		} while (gender != 1 && (gender != 2));

		cout << "����������" << endl;
		cin >> cTemp.age;

		cout << "������绰" << endl;
		cin >> cTemp.phone;

		cout << "�������ͥסַ" << endl;
		cin >> cTemp.address;

		cTemp.idx = idx;
		cArr[idx - 1] = cTemp;
		cout << "�޸ĳɹ�" << endl;
	}
	else {
		cout << "��ϵ�˲�����" << endl;
	}
}

void clearContact(Contact* cArr, int& num) {
	cout << "ȷ�����ͨѶ¼��" << endl;
	cout << "y -- ȷ��" << endl;
	cout << "n -- ȡ��" << endl;

	string flag;
	cin >> flag;
	if (flag == "y") {
		memset(cArr, '\0', sizeof(Contact) * num);
		num = 0;
		cout << "�����ϵ�˳ɹ�" << endl;
	}
	else if (flag == "n") {
		cout << "�����ϵ��ʧ��" << endl;
	}
	else {
		cout << "��Чָ��˳�..." << endl;
	}
}