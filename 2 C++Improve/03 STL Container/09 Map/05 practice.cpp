#include <iostream>
#include <vector>
#include <map>
#include <ctime>

namespace prac_space {
/*
* ����������
* 1����Ƹ10��Ա����ABCDEFGHIJ����10��Ա�����빫˾��ָ�ɵ���������
* 2��Ա����Ϣ�У������͹�����ɣ����ŷ�Ϊ���߻����������з�
* 3�������10��Ա�����䲿�ź͹���
* 4��ͨ��multimap������Ϣ�Ĳ��룬key�����ű�ţ� value��Ա����
* 5���ֲ�����ʾԱ����Ϣ
* 
* ʵ�ֲ��裺
* 1������10��Ա�����ŵ�vector��
* 2������vector������ȡ��ÿ��Ա�����з���
* 3������󣬽����ű����Ϊkey������Ա����Ϊvalue����multimap����
* 4����ʾ������Ա����Ϣ
*/

#define PLANNING 1
#define ARTS 2
#define DEVELOP 3

class Worker {
public:
	Worker() {
		this->m_Salary = 0;
	}

	std::string m_Name; //����
	int m_Salary;   //����
};

// ����Ա��
void createWorker(std::vector<Worker>& v) {
	std::string nameSeed = "ABCDEFGHIJ";
	Worker w;
	for (int i = 0; i < 10; i++) {
		w.m_Name = "Ա��";
		w.m_Name += nameSeed[i];
		w.m_Salary = rand() % 10000 + 10000; //10000 ~ 19999
		v.push_back(w);
	}
}

// ��ӡԱ����Ϣ
void showWroker(std::multimap<int, Worker>& m) {
	std::cout << "�߻�������Ϣ��\n";
	std::multimap<int, Worker>::iterator pos = m.find(PLANNING);
	int count = m.count(PLANNING);
	for (int i = 0; i < count; i++) {
		std::cout << "������" << pos->second.m_Name << " ���ʣ�" << pos->second.m_Salary << std::endl;
		pos++;
	}
	std::cout << std::endl;

	std::cout << "����������Ϣ��\n";
	pos = m.find(ARTS);
	count = m.count(ARTS);
	for (int i = 0; i < count; i++) {
		std::cout << "������" << pos->second.m_Name << " ���ʣ�" << pos->second.m_Salary << std::endl;
		pos++;
	}
	std::cout << std::endl;

	std::cout << "�з�������Ϣ��\n";
	pos = m.find(DEVELOP);
	count = m.count(DEVELOP);
	for (int i = 0; i < count; i++) {
		std::cout << "������" << pos->second.m_Name << " ���ʣ�" << pos->second.m_Salary << std::endl;
		pos++;
	}
	std::cout << std::endl;
}

void Func() {
	// ���������
	srand((unsigned int)time(NULL));

	// ��������
	std::vector<Worker> v;
	createWorker(v);

	// ���䲿��
	int key = 0; //���� 1 - �߻���2 - ������3 - �з�
	std::multimap<int, Worker> m;

	for (int i = 0; i < v.size(); i++) {
		key = rand() % 3 + 1;
		m.insert(std::make_pair(key, v[i]));
	}

	// �ֲ�����ʾ
	showWroker(m);
}

}

int main() {
	prac_space::Func();
	int a = PLANNING;

	system("pause");
	return 0;
}