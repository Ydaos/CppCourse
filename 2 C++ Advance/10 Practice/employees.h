#pragma once
#include "worker.h"

// ������ͨԱ����̳�ְ�������࣬����д�麯��

class Employees :public Worker {
public:
	// ���캯��
	Employees(int Id, string name, int dId);

	// ��ʾ������Ϣ
	void showInfo();

	// ��ȡ��λ����
	string getDeptName();
};