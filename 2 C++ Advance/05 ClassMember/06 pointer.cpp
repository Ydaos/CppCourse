#include<iostream>

/*
* thisָ��
* thisָ��������ÿһ���Ǿ�̬��Ա�����ڵ�һ��ָ��
* thisָ�벻��Ҫ���壬ֱ��ʹ�ü���
* ��;��������Ƴ�ͻ�����ض�����
* 
* ��ָ����ó�Ա����
*/

class Person {
public:
	//1��������Ƴ�ͻ 
	Person(int age) {
		//thisָ��ָ����Ǳ����õĳ�Ա������������
		this->age = age;
	}

	//2�����ض�������*this
	Person& PersonAddPerson(Person& p) {
		age += p.age;
		return *this;
	}

	void showClassName() {
		std::cout << "this is Person class\n";
	}

	void showClassAge() {
		//��������Ϊ�����ָ����NULL
		if (this == NULL) { //��߳���׳��
			return;
		}
		std::cout << "age = " << this->age << std::endl;
	}

	int age = 0;
};

void ClassPointer() {
	Person p1(10);
	Person p2(20);

	//��ʽ���˼��
	p2.PersonAddPerson(p1).PersonAddPerson(p1).PersonAddPerson(p1);
	std::cout << "p2�����䣺" << p2.age << std::endl;

	//��ָ����ó�Ա����
	Person* p = NULL;
	p->showClassAge();
	p->showClassName();
}

int main06() {
	ClassPointer();

	system("pause");
	return 0;
}