#include<iostream>

/*
* ���μ̳и��
* 1������������̳�ͬһ������
* 2������ĳ����ͬʱ�̳�����������
* 3�����ּ̳г�Ϊ���μ̳У��ֳ�Ϊ��ʯ�̳�
* 4��ͨ����̳п��Խ�����μ̳ж���������
*/

namespace my_src6 {

	//������
	class Animal {
	public:
		int m_age;
	};

	//������̳п��Խ�����μ̳е�����
	// �̳�֮ǰ���Ϲؼ��� virtual ��Ϊ��̳�
	// Animal ���Ϊ�����

	//����
	class Sheep :virtual public Animal {

	};

	//����
	class Tuo :virtual public Animal {

	};

	//���������գ�
	class SheepTuo :public Sheep, public Tuo {

	};

	void Diamond() {
		SheepTuo st;
		st.Sheep::m_age = 10;
		st.Tuo::m_age = 20;

		//���μ̳У���������ӵ����ͬ���ԣ���Ҫ������������
		std::cout << "st.Sheep::m_age = " << st.Sheep::m_age << std::endl;
		std::cout << "st.Tuo::m_age = " << st.Tuo::m_age << std::endl;

		//��������ֻ����һ�ݼ��ɣ����μ̳е������������ݣ���Դ�˷ѣ�
		//��̳�֮�����ݹ���ֻ��һ�ݣ����Կ���ֱ�ӷ���
		std::cout << "st.m_age = " << st.m_age << std::endl;
	}
}

/*
* �ܽ᣺
* 1�����μ̳д�����Ҫ�������������������ͬ���ݣ�������Դ�˷��Ѿ�������
* 2��������̳п��Խ�����μ̳�����
* 
* ��̳н�����μ̳�ԭ��
* SheepTuo��ֱ������������̳м̳е������������ָ�룬�����������ݾ������ݣ�
* �����ָ��ָ���Ӧ����������������ŵ��������ڴ�ƫ�ƣ�
* ͨ��������������ݣ����������ָ���ָ�������Animal�е�ͬһ������m_age����˲��������Դ�˷ѣ���̳еĶ�����Ҳ�����ڡ�
* �ʣ�ֱ�ӷ������� s.m_age ����������Ҳ���ᱨ���ˣ�����
*/

int main() {
	my_src6::Diamond();

	system("pause");
	return 0;
}