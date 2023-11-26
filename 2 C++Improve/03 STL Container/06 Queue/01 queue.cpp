#include <iostream>
#include <queue>

/*
* queue���queue�������Ƚ��ȳ������ݽṹ��������������
* �������������һ������Ԫ�أ�����һ���Ƴ�Ԫ��
* ����ֻ�ж�ͷ�Ͷ�β���Ա������ʣ���˶��в����������Ϊ
* �����н����ݳ�Ϊ -- ��� push
* �����г����ݳ�Ϊ -- ���� pop
* 
* queue���ýӿ�
* ���캯����
* queue<T> que;            //Ĭ�Ϲ��캯��
* queue(const queue &que); //�������캯��
* 
* ��ֵ������
* queue& operator=(const queue &que); //����=�����
* 
* ���ݴ�ȡ��
* push(elem); //���β���Ԫ��
* pop();      //�Ӷ�ͷ�Ƴ���һ��Ԫ��
* back()      //�������һ��Ԫ��
* front();    //���ص�һ��Ԫ��
* 
* ��С������
* empty();    //�ж϶����Ƿ�Ϊ��
* size();     //���ض��д�С
*/
class Person {
public:
	Person(std::string name, int age) {
		m_Name = name;
		m_Age = age;
	}

	std::string m_Name;
	int m_Age;
};

void Queue() {
	// �ص㣺�Ƚ��ȳ�
	std::queue<Person> q;

	// ��������
	Person p1("Tom", 20);
	Person p2("Jerry", 18);
	Person p3("Mark", 22);
	Person p4("Lisa", 18);

	// ��β���
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	// ֻҪ���в�Ϊ�գ��鿴��ͷ�Ͷ�βԪ�أ�������
	std::cout << "���д�С��" << q.size() << std::endl;
	while (!q.empty()) {
		// �����ͷԪ��
		std::cout << "��ͷԪ�� --- ������" << q.front().m_Name << " ���䣺" << q.front().m_Age << std::endl;
		
		// �����βԪ��
		std::cout << "��βԪ�� --- ������" << q.back().m_Name << " ���䣺" << q.back().m_Age << std::endl;

		// ����
		q.pop();
		std::cout << std::endl;
	}
	std::cout << "���д�С��" << q.size() << std::endl;
}


int main() {
	Queue();

	system("pause");
	return 0;
}