#pragma once
#include <iostream>
#include <string>
#include "worker.h"
#include "employees.h"
#include "manager.h"
#include "boss.h"
#include <fstream>

#define FILENAME "empFile.txt"

using namespace std;

// ���������࣬�����������ݣ�
// ���û��Ĺ�ͨ�˵�����
// ��ְ����ɾ�Ĳ�Ĳ���
// ���ļ��Ķ�д����

class WorkerManager {
public:
	// ���캯��
	WorkerManager();

	// ��������
	~WorkerManager();

	// չʾ�˵�
	void showMenu();

	// �˳�����
	void exitSystem();

	// ����ְ��
	void addEmployee();

	// ��ʾְ��
	void showEmployee();

	// ɾ��ְ��
	void delEmployee();

	// �޸�ְ��
	void modEmployee();

	// ����ְ��
	void findEmployee();

	// ����Ž�������
	void sortEmployee();

	// ���ְ���б��ļ�
	void clearEmpFile();
	

private:
	// �����ļ�
	void saveFile();

	// ��ȡ�ļ���Ա����Ŀ
	int get_FileEmpNum();

	// ��ʼ������
	void Init_EmpArr();

	// �ж�ְ���Ƿ����
	int IsExist(int id);
	int IsExist(string name);

public:
	int m_EmpNum;      // ְ������
	Worker** m_EmpArr; // ָ����worker*��ָ������
	bool m_fileIsEmpty;// ��־�ļ��Ƿ�Ϊ��
};