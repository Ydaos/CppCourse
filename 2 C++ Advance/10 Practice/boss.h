#pragma once
#include "worker.h"

// �����ϰ���̳�ְ�������࣬����д�麯��

class Boss :public Worker {
public:
	// ���캯��
	Boss(int Id, string name, int dId);

	// ��ʾ������Ϣ
	void showInfo();

	// ��ȡ��λ����
	string getDeptName();
};