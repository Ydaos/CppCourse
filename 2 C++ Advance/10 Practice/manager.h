#pragma once
#include "worker.h"

// ����������̳�ְ�������࣬����д�麯��

class Manager :public Worker {
public:
	// ���캯��
	Manager(int Id, string name, int dId);

	// ��ʾ������Ϣ
	void showInfo();

	// ��ȡ��λ����
	string getDeptName();
};