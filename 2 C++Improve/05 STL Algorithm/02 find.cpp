#include <iostream>
#include <algorithm>
#include <vector>

/*
* STL_�����㷨
* find;          //����Ԫ��
* find_if;       //����������Ԫ��
* adjacent_find; //���������ظ�Ԫ��
* binary_serach; //���ֲ���Ԫ���Ƿ����
* 
* count;         //ͳ��Ԫ�ظ���
* count_if;      //������ͳ��Ԫ�ظ���
*/

namespace space_find {

	class Person {
	public:
		Person(std::string name, int age) {
			this->m_Name = name;
			this->m_Age = age;
		}

		// ���� == ��find֪����ô�Ա�Person��������
		bool operator==(const Person& p) {
			if (this->m_Name == p.m_Name && this->m_Age == p.m_Age) {
				return true;
			}
			return false;
		}

		std::string m_Name;
		int m_Age;
	};

	// �Ƚϴ�С�ķº���
	class MyGreater {
	public:
		bool operator()(int val) {
			return val > 5;
		}
		bool operator()(Person& p) {
			return p.m_Age > 20;
		}
	};


	/*
	* find ����Ԫ��
	* ����ԭ�ͣ�
	* iterator find(iterator beg, iterator end, value);
	* 
	* find �������������ҵ�ָ��Ԫ�أ�����ֵ�ǵ�����
	* find �����Զ�����������ʱ��Ҫ����==�����������find��֪����ô�ж��������
	*/
	void MyFind() {
		// 1��find ���������������ͣ������ҵ���񶼻᷵�ص�����
		std::vector<int> v;
		for (int i = 0; i < 10; i++) {
			v.push_back(i);
		}

		// �����������Ƿ���'5'���Ԫ��
		std::vector<int>::iterator it = find(v.begin(), v.end(), 5);
		if (it == v.end()) {
			std::cout << "���������Ԫ��\n";
		}
		else {
			std::cout << "�ҵ�Ԫ�� " << *it << std::endl;
		}

		// 2��find �����Զ�����������
		std::vector<Person> v2;
		// ��������
		Person p1("Tom", 18);
		Person p2("Jery", 16);
		Person p3("Tony", 20);
		Person p4("Hans", 22);

		// ����������
		v2.push_back(p1);
		v2.push_back(p2);
		v2.push_back(p3);
		v2.push_back(p4);

		// �����������Ƿ���'p2'���Ԫ��
		std::vector<Person>::iterator it_p = find(v2.begin(), v2.end(), p2);
		if (it_p == v2.end()) {
			std::cout << "���������Ԫ��\n";
		}
		else {
			std::cout << "�ҵ�Ԫ��p2 ������" << it_p->m_Name << " ���䣺" << it_p->m_Age << std::endl;
		}
	}
	

	/*
	* find_if ����������Ԫ��
	* ����ԭ�ͣ�
	* iterator find_if(iterator beg, iterator end, _Pred); //����������Ԫ��
	* ����������Ԫ�أ������ҵ���񶼻᷵�ص�������_Pred bool������ν�ʣ�
	* find_if ͨ��ν�ʿ����Զ�����������������ҵ�Ԫ�صĵ�����
	*/
	void MyFind_IF() {
		// 1��find_if ����������������
		std::vector<int> v;
		for (int i = 0; i < 10; i++) {
			v.push_back(i);
		}

		// �����������Ƿ��д���5��Ԫ��
		std::vector<int>::iterator it = find_if(v.begin(), v.end(), MyGreater());
		if (it == v.end()) {
			std::cout << "û�ҵ�Ԫ��\n";
		}
		else {
			std::cout << "�ҵ�����5��Ԫ�� " << *it << std::endl;
		}

		// 2��find_if �����Զ�����������
		std::vector<Person> v2;
		// ��������
		Person p1("Tom", 18);
		Person p2("Jery", 16);
		Person p3("Tony", 20);
		Person p4("Hans", 22);

		// ����������
		v2.push_back(p1);
		v2.push_back(p2);
		v2.push_back(p3);
		v2.push_back(p4);

		// �����������20����
		std::vector<Person>::iterator it_p = find_if(v2.begin(), v2.end(), MyGreater());
		if (it == v.end()) {
			std::cout << "���������Ԫ��\n";
		}
		else {
			std::cout << "�ҵ�Ŀ��Ԫ�� ������" << it_p->m_Name << " ���䣺" << it_p->m_Age << std::endl;
		}
	}


	/*
	* adjacent_find ���������ظ�Ԫ��
	* ����ԭ�ͣ�
	* iterator adjacent_find(iterator beg, iterator end);
	* ���������ظ�Ԫ�أ���������Ԫ�ص�һ��λ�õĵ�����
	*/
	void MyAdjacent_Find() {
		std::vector<int> v;
		v.push_back(1);
		v.push_back(0);
		v.push_back(1);
		v.push_back(3);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(5);

		std::vector<int>::iterator it = adjacent_find(v.begin(), v.end());
		if (it == v.end()) {
			std::cout << "û�ҵ�Ԫ��\n";
		}
		else {
			std::cout << "�ҵ�����Ԫ�� " << *it << std::endl;
		}
	}


	/*
	* binary_serach ���ֲ���Ԫ��
	* ����ԭ�ͣ�
	* bool binary_serach(iterator beg, iterator end, value); 
	* ���ֲ��ҷ�������ָ��Ԫ�أ��鵽����true�����򷵻�false
	* ���ֲ��ҷ�Ч�ʺܸߣ�������Ԫ�ر������������У����򷵻ؽ����һ����ȷ
	*/
	void MyBinary_Search() {
		std::vector<int> v;
		for (int i = 0; i < 10; i++) {
			v.push_back(i);
		}

		// ���������Ƿ����Ԫ�� 9
		bool ret = binary_search(v.begin(), v.end(), 9);
		if (ret) {
			std::cout << "�ҵ���Ԫ��\n";
		}
		else {
			std::cout << "δ�ҵ�Ԫ��\n";
		}

		// ע�⣺�����������������У�����
		v.push_back(2);
		ret = binary_search(v.begin(), v.end(), 9);
		if (ret) {
			std::cout << "�ҵ���Ԫ�� \n";
		}
		else {
			std::cout << "δ�ҵ�Ԫ��\n";
		}
		// return false!������������У����ؽ����һ����ȷ
	}

}

namespace space_count {

	class Person {
	public:
		Person(std::string name, int age) {
			this->m_Name = name;
			this->m_Age = age;
		}

		// ���� == ���������count֪����ô�ж��������
		bool operator==(const Person& p) {
			if (this->m_Age == p.m_Age) {
				return true;
			}
			return false;
		}

		std::string m_Name;
		int m_Age;
	};

	// �Ƚϴ�С�ķº���
	class MyCreater {
	public:
		bool operator()(int val) {
			return val > 20;
		}

		bool operator()(const Person& p) {
			if (p.m_Age > 20) {
				return true;
			}
			return false;
		}
	};


	/*
	* count ͳ��Ԫ�س��ִ���
	* ����ԭ�ͣ�
	* int count(iterator beg, iterator end, value); //ͳ��Ԫ�س��ִ���
	* ����ͳ���Զ�������ʱ����Ҫ����==��������ſ����жϷ�������
	*/
	void MyCount() {
		// 1��countͳ��������������
		std::vector<int> v;
		v.push_back(10);
		v.push_back(40);
		v.push_back(30);
		v.push_back(40);
		v.push_back(20);

		int num = count(v.begin(), v.end(), 40);
		std::cout << "num = " << num << std::endl;

		// 2��countͳ���Զ�����������
		Person p1("Tom", 18);
		Person p2("Jery", 16);
		Person p3("Mark", 18);
		Person p4("Hans", 22);
		Person p5("Tony", 18);

		std::vector<Person> v2;
		v2.push_back(p1);
		v2.push_back(p2);
		v2.push_back(p3);
		v2.push_back(p4);
		v2.push_back(p5);

		// ͳ�ƺ� Lisa ͬ����������
		Person p("Lisa", 18);
		num = count(v2.begin(), v2.end(), p);
		std::cout << "��Lisaͬ������������" << num << std::endl;
	}


	/*
	* count_if ͳ�Ʒ���������Ԫ�ظ���
	* ����ԭ�ͣ�
	* int count_if(iterator beg, iterator end, _Pred);
	* _Pred ν��
	*/
	void MyCount_IF() {
		// 1��count_if ͳ��������������
		std::vector<int> v;
		v.push_back(10);
		v.push_back(40);
		v.push_back(30);
		v.push_back(40);
		v.push_back(20);
		v.push_back(40);

		int num = count_if(v.begin(), v.end(), MyCreater());
		std::cout << "����20��Ԫ�ظ�����" << num << std::endl;

		// 2��count_if ͳ���Զ�����������
		Person p1("Tom", 18);
		Person p2("Jery", 16);
		Person p3("Mark", 18);
		Person p4("Hans", 22);
		Person p5("Tony", 21);

		std::vector<Person> v2;
		v2.push_back(p1);
		v2.push_back(p2);
		v2.push_back(p3);
		v2.push_back(p4);
		v2.push_back(p5);

		// ͳ�ƴ���20������
		num = count_if(v2.begin(), v2.end(), MyCreater());
		std::cout << "����20��������" << num << std::endl;
	}

}

int main02() {
	space_find::MyFind();

	std::cout << "-----------------------------------\n";
	space_find::MyFind_IF();

	std::cout << "-----------------------------------\n";
	space_find::MyAdjacent_Find();

	std::cout << "-----------------------------------\n";
	space_find::MyBinary_Search();

	std::cout << "-----------------------------------\n";
	space_count::MyCount();

	std::cout << "-----------------------------------\n";
	space_count::MyCount_IF();

	system("pause");
	return 0;
}