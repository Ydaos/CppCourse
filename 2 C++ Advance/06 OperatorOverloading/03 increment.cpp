#include<iostream>

//������������أ�ʵ���Լ�����������

//�Զ�������
class MyInteger {
	friend std::ostream& operator<<(std::ostream& out, MyInteger myint);
public:
	MyInteger() {
		m_num = 0;
	}

	//����ǰ��++�����,����������Ϊ��һֱ��һ�����ݽ��в���
	MyInteger& operator++() {
		m_num++;
		return *this;
	}

	//���غ���++�����
	//MyInteger& operator++(int) int����ռλ������������������ǰ�úͺ��õ���
	MyInteger operator++(int) {
		//�ȼ�¼���
		MyInteger temp = *this;

		//�����
		this->m_num++;

		//��󽫼�¼�������
		return temp;

		//ע�⣺tempΪ�ֲ�������ֻ�ܷ���ֵ���ܷ��ص�ַ
	}

private:
	int m_num;
};

//�������������
std::ostream& operator<<(std::ostream& out, MyInteger myint) {
	out << myint.m_num;
	return out;
}

void Increment() {
	MyInteger myint;
	std::cout << myint << std::endl;
	std::cout << ++myint << std::endl;
	std::cout << myint++ << std::endl;
	std::cout << myint << std::endl;
	
	std::cout << ++(++myint) << std::endl; //���������壬һֱ��myint���е�������
	std::cout << (myint++)++ << std::endl; //���������壬һֱ�Ծɵ�temp����temp����
	std::cout << myint << std::endl;
}
//�ܽ᣺ǰ�õ����������ã����õ�������ֵ

int main03() {
	Increment();

	system("pause");
	return 0;
}