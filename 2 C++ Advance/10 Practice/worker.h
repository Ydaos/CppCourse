#pragma once
#include <iostream>
using namespace std;

// ��������ְ����
// ְ�����ͷ�Ϊ����ͨԱ���������ϰ�
// ������ְҵ����һ�����У����ö�̬����ͬ��ְ������
// ְ������Ϊ��ְ����š�ְ��������ְ�����ڲ��ű��
// ְ����ΪΪ����λְ����Ϣ��������ȡ��λ����

// ְ��������
class Worker {
public:
	// ��ʾ������Ϣ
	virtual void showInfo() = 0;

	// ��ȡ��λ����
	virtual string getDeptName() = 0;

public:
	int m_id;      // ְ�����
	string m_name; // ְ������
	int m_deptId;  // ְ�����ڲ������Ʊ��
};