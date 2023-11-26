#include "workerManager.h"

WorkerManager::WorkerManager() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	// �ļ�������
	if (!ifs.is_open()) {
		cout << "�ļ�������" << endl;
		this->m_fileIsEmpty = true; //��ʼ���ļ�Ϊ�ձ�־
		this->m_EmpNum = 0;         // ��ʼ������
		this->m_EmpArr = NULL;      // ��ʼ������
		
		return;
	}

	// �ļ����ڣ�������Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "�ļ�Ϊ�գ�" << endl;
		this->m_fileIsEmpty = true; //��ʼ���ļ�Ϊ�ձ�־
		this->m_EmpNum = 0;         // ��ʼ������
		this->m_EmpArr = NULL;      // ��ʼ������
		return;
	}
	ifs.close();

	// �ļ����ڣ��Ҽ�¼����
	this->m_EmpNum = get_FileEmpNum(); // ��ʼ������
	cout << "�ļ����ڣ���" << this->m_EmpNum << "����¼" << endl;
	this->m_fileIsEmpty = false;

	this->m_EmpArr = new Worker * [m_EmpNum];  //��ʼ������
	Init_EmpArr();
}

WorkerManager::~WorkerManager() {
	if (this->m_EmpArr != NULL) {
		delete[] this->m_EmpArr;
		this->m_EmpArr = NULL;
	}
}

void WorkerManager::showMenu() {
	cout << "****************************************" << endl;
	cout << "********  " << "��ӭʹ��ְ������ϵͳ" << "  ********" << endl;
	cout << "***********  " << "0.�˳��������" << "  ***********" << endl;
	cout << "***********  " << "1.����ְ����Ϣ" << "  ***********" << endl;
	cout << "***********  " << "2.��ʾְ����Ϣ" << "  ***********" << endl;
	cout << "***********  " << "3.ɾ����ְְ��" << "  ***********" << endl;
	cout << "***********  " << "4.�޸�ְ����Ϣ" << "  ***********" << endl;
	cout << "***********  " << "5.����ְ����Ϣ" << "  ***********" << endl;
	cout << "***********  " << "6.���ձ������" << "  ***********" << endl;
	cout << "***********  " << "7.��������ĵ�" << "  ***********" << endl;
	cout << "****************************************" << endl;
	cout << endl;
}

void WorkerManager::exitSystem() {
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
}

void WorkerManager::addEmployee() {
	cout << "����������ְ������" << endl;
	
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0) {
		// ����ռ��С
		int newSize = this->m_EmpNum + addNum;

		// �����¿ռ�
		Worker** newSpace = new Worker * [newSize];

		// ��ԭ���ռ������ݿ������¿ռ�
		if (this->m_EmpArr != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				newSpace[i] = this->m_EmpArr[i];
			}
		}

		// ���������
		for (int i = 0; i < addNum; i++) {
			int id;      // ��ְ�����
			string name; // ��ְ������
			int dSelect; // ��ְ������

			cout << "�������" << i + 1 << "λְ���ı��" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "λְ��������" << endl;
			cin >> name;
			cout << "��ѡ���ְ���Ĳ��ű��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employees(id, name, dSelect);
				break;
			case 2:
				worker = new Manager(id, name, dSelect);
				break;
			case 3:
				worker = new Boss(id, name, dSelect);
				break;
			default:
				break;
			}

			// ������ְ��ָ�뱣�浽������
			newSpace[this->m_EmpNum + i] = worker;
		}

		// ���ͷ�ԭ�еĿռ�
		delete[] this->m_EmpArr;
		
		// �����¿ռ�ָ��
		this->m_EmpArr = newSpace;

		// ������ְ������
		this->m_EmpNum = newSize;

		// �����ļ�
		saveFile();

		// ��ʾ��ӳɹ�
		cout << "��ӳɹ��������" << addNum << "��ְ��" << endl;
		this->m_fileIsEmpty = false;
	}
	else {
		cout << "��������" << endl;
	}

	// ������������������ϼ�Ŀ¼
	system("pause");
	system("cls");
}

void WorkerManager::saveFile() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out); // �������ʽ���ļ� -- д�ļ�

	// ��ÿ��������д�뵽�ļ���
	for (int i = 0; i < this->m_EmpNum; i++) {
		ofs << this->m_EmpArr[i]->m_id << " "
			<< this->m_EmpArr[i]->m_name << " "
			<< this->m_EmpArr[i]->m_deptId << endl;
	}

	// �ر��ļ�
	ofs.close();
}

int WorkerManager::get_FileEmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int num = 0;
	string buf;
	while (getline(ifs, buf)) {
		num++;
	}

	ifs.close();
	return num;
}

void WorkerManager::Init_EmpArr() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;      // ְ�����
	string name; // ְ������
	int dSelect; // ְ������
	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> dSelect) {
		Worker* worker = NULL;
		switch (dSelect)
		{
		case 1:
			worker = new Employees(id, name, dSelect);
			break;
		case 2:
			worker = new Manager(id, name, dSelect);
			break;
		case 3:
			worker = new Boss(id, name, dSelect);
			break;
		default:
			break;
		}
		// ��������ְ�����ݱ��浽������
		m_EmpArr[index] = worker;
		index++;
	}
	ifs.close();
}

void WorkerManager::showEmployee() {
	if (this->m_fileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else {
		for (int i = 0; i < this->m_EmpNum; i++) {
			// ���ö�̬���ýӿ�
			this->m_EmpArr[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::delEmployee() {
	if (this->m_fileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else {
		cout << "������Ҫɾ����Ա�����" << endl;
		int id = -1;
		cin >> id;

		int index = IsExist(id);
		if (index < 0) {
			cout << "���޴��ˣ�" << endl;
		}
		else { // ˵��ְ�����ڣ�����Ҫɾ��indexλ���ϵ�ְ��
			// ����ɾ������������ǰ��
			for (int i = index; i < this->m_EmpNum - 1; i++) {
				this->m_EmpArr[i] = this->m_EmpArr[i + 1];
			}
			this->m_EmpNum--; //���������¼��Ա����

			// ͬ���������ݵ��ļ���
			saveFile();

			cout << "ɾ���ɹ���" << endl;
		}
	}
	system("pause");
	system("cls");
}

int WorkerManager::IsExist(int id) {
	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArr[i]->m_id == id) {
			return i;
		}
	}
	return -1;
}

int WorkerManager::IsExist(string name) {
	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArr[i]->m_name == name) {
			return i;
		}
	}
	return -1;
}

void WorkerManager::modEmployee() {
	if (m_fileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else {
		cout << "������Ҫ�޸ĵ�Ա�����" << endl;
		int id = -1;
		cin >> id;

		int index = IsExist(id);
		if (index < 0) {
			cout << "���޴��ˣ�" << endl;
		}
		else {
			delete this->m_EmpArr[index];

			int newId = 0;
			string newName;
			int dSelect = 0;
			cout << "�������޸ĺ��ְ�����" << endl;
			cin >> newId;
			cout << "�������޸ĺ��ְ������" << endl;
			cin >> newName;
			cout << "��ѡ���ְ���Ĳ��ű��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employees(newId, newName, dSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, dSelect);
				break;
			default:
				break;
			}

			// ������ְ��ָ�뱣�浽������
			this->m_EmpArr[index] = worker;

			// ͬ���������ݵ��ļ���
			saveFile();

			cout << "�޸ĳɹ���" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::findEmployee() {
	if (m_fileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else {
		int select = 0;
		while (true) {
			cout << "��������ҵķ�ʽ��" << endl;
			cout << "1����ְ����Ų���" << endl;
			cout << "2����ְ����������" << endl;
			cin >> select;

			if (select == 1) { // ����Ų���
				cout << "������Ҫ���ҵ�ְ�����" << endl;
				int id = 0;
				cin >> id;

				int index = IsExist(id);
				if (index < 0) {
					cout << "���޴��ˣ�" << endl;
				}
				else {
					this->m_EmpArr[index]->showInfo();
				}
				break;
			}
			else if (select == 2) { // ����������
				cout << "������Ҫ���ҵ�ְ������" << endl;
				string name;
				cin >> name;

				int index = IsExist(name);
				if (index < 0) {
					cout << "���޴��ˣ�" << endl;
				}
				else {
					this->m_EmpArr[index]->showInfo();
				}
				break;
			}
			else {
				cout << "���ҷ�ʽ������������������" << endl;
			}
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::sortEmployee() {
	if (m_fileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
	}
	else {
		int select = 0;
		while (true) {
			cout << "����������ķ�ʽ��" << endl;
			cout << "1����ְ�������������" << endl;
			cout << "2����ְ����Ž�������" << endl;
			cin >> select;

			if (select == 1 || select == 2) {
				Worker* w_temp = NULL;
				for (int i = 0; i < this->m_EmpNum - 1; i++) {
					int minOrMax = this->m_EmpArr[i]->m_id;
					for (int j = i + 1; j < this->m_EmpNum; j++) {
						if (select == 1) { // ��������
							if (minOrMax > m_EmpArr[j]->m_id) {
								minOrMax = m_EmpArr[j]->m_id;
								w_temp = m_EmpArr[j];
								m_EmpArr[j] = m_EmpArr[i];
								m_EmpArr[i] = w_temp;
							}
						}
						else if (select == 2) { // ��������
							if (minOrMax < m_EmpArr[j]->m_id) {
								minOrMax = m_EmpArr[j]->m_id;
								w_temp = m_EmpArr[j];
								m_EmpArr[j] = m_EmpArr[i];
								m_EmpArr[i] = w_temp;
							}
						}
					}
				}
				break;
			}
			else {
				cout << "����ʽ������������������" << endl;
			}
		}
		// �����ļ�����ʾ�������
		cout << "����ɹ���" << endl;
		this->saveFile();
		this->showEmployee();
	}
}

void WorkerManager::clearEmpFile() {
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;
	int select = 0;
	cin >> select;

	if (select == 1) {
		// ��ģʽ ios::trunc ������ڣ�ɾ���ļ������´���
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_EmpArr != NULL) {
			// ɾ������ÿ��ְ������
			for (int i = 0; i < m_EmpNum; i++) {
				if (this->m_EmpArr[i] != NULL) {
					delete this->m_EmpArr[i];
				}
			}

			// ɾ����������ָ��
			this->m_EmpNum = 0;
			delete[] this->m_EmpArr;
			this->m_EmpArr = NULL;
			this->m_fileIsEmpty = true;
		}
		cout << "����ɹ���" << endl;
	}

	system("pause");
	system("cls");
}