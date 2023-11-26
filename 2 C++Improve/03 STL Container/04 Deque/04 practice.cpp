#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <algorithm> //��׼�㷨ͷ�ļ�

/*
* ���� - ��ί���
* ����������5��ѡ�֣�ABCDE��10����ί�ֱ��ÿһ��ѡ�ִ�֣�ȥ����߷ֺ���ͷ�ȡ���۷���Ϊ���
*
* ʵ�ֲ���
* 1������5��ѡ�֣��ŵ�vector��
* 2������vector������ȡ��ÿ��ѡ�֣�ִ��forѭ����10����ί��ִ浽deque������
* 3��sort�㷨��deque�����з�������ȥ����߷ֺ���ͷ�
* 4��deque��������һ�飬�ۼ��ܷ�
* 5����ȡƽ����
*/
class Person {
public:
	Person(std::string name, int score) {
		this->m_Name = name;
		this->m_Score = score;
	}

	std::string m_Name; // ѡ������
	int m_Score;   // ƽ����
};

void createPerson(std::vector<Person>& v) {
	std::string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++) {
		// ����ѡ��
		std::string name = "ѡ��";
		name += nameSeed[i];
		int score = 0;
		Person p(name, score);

		//��ѡ�ַŽ�������
		v.push_back(p);
	}
}

void printVector(const std::vector<Person>& v) {
	for (std::vector<Person>::const_iterator it = v.begin(); it != v.end(); it++) {
		std::cout << "������" << (*it).m_Name << " ƽ���֣�" << (*it).m_Score << std::endl;
	}
}

void setScore(std::vector<Person>& v) {
	// ���������
	srand((unsigned int)time(NULL));

	for (int i = 0; i < v.size(); i++) {
		// ����ί��������deque������
		std::deque<int> d;
		for (int j = 0; j < 10; j++) {
			int score = rand() % 41 + 60;
			d.push_back(score);
		}
		// ����
		sort(d.begin(), d.end());

		// ȥ����߷ֺ���ͷ�
		d.pop_back();
		d.pop_front();

		// ȡƽ����
		int sum = 0;
		for (int k = 0; k < d.size(); k++) {
			sum += d[k];
		}
		v[i].m_Score = sum / d.size();
	}
}

//ָ��λ�ò���
void Func() {
	//1������5��ѡ��
	std::vector<Person> v;
	createPerson(v);

	//2�����Դ����Ƿ����
	printVector(v);

	//3����ѡ�ִ��
	setScore(v);

	//4����ʾ���÷�
	std::cout << "���ֽ����\n";
	printVector(v);
}
// �ܽ᣺sort�㷨�ǳ����ã�ʹ��ʱ����ͷ�ļ�<algorithm>����

int main() {
	Func();

	system("pause");
	return 0;
}