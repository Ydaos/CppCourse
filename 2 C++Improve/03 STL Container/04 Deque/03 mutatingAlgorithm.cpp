#include <iostream>
#include <deque>
#include <algorithm> //��׼�㷨ͷ�ļ�

void printDeque(const std::deque<int>& d);// ����������"01 definition.cpp"

/*
* deque ����ɾ������
* 
* ���˲���ɾ��������
* ����ԭ�ͣ�
* push_back(elem);  //������β������һ������
* push_front(elem); //������ͷ������һ������
* pop_back();	    //ɾ������β��һ������
* pop_front();      //ɾ������ͷ��һ������
* 
* ָ��λ�ò���ɾ��������
* insert(pos, elem);     //��posλ�ò���һ��elemԪ�صĿ����������µ�����λ��
* insert(pos, n, elem);  //��posλ�ò���n��elemԪ�صĿ������޷���ֵ
* insert(pos, beg, end); //��posλ�ò���[beg, end]��������ݣ��޷���ֵ
* clear();               //���������������
* erase(beg, end);       //ɾ��[beg, end]��������ݣ�������һ�����ݵ�λ��
* erase(pos);            //ɾ��posλ�õ����ݣ�������һ�����ݵ�λ��
*/
void Insert() {
	//1�����˲���ɾ������
	std::deque<int> d1;

	//β��
	d1.push_back(10);
	d1.push_back(20);

	//ͷ��
	d1.push_front(100);
	d1.push_front(200);
	printDeque(d1);

	//2��ָ��λ�ò���ɾ������
	std::cout << "------------------------\n";
	std::deque<int> d2;
	d2.push_back(10);
	d2.push_back(20);
	d2.push_back(30);
	d2.push_back(40);
	d2.push_back(50);
	printDeque(d2);

	// insert(pos, elem); 
	d2.insert(d2.begin(), 100);
	printDeque(d2);

	// insert(pos, n, elem); 
	d2.insert(d2.begin(), 2, 200);
	printDeque(d2);

	// insert(pos, beg, end);
	std::deque<int>d3;
	d3.push_back(1);
	d3.push_back(2);
	d3.push_back(3);

	d2.insert(d2.begin(), d3.begin(), d3.end());
	printDeque(d2);
}

void Delete () {
	std::deque<int> d1;
	for (size_t i = 0; i < 10; i++)
	{
		d1.push_back(10 * i);
	}
	printDeque(d1);

	//βɾ
	d1.pop_back();
	printDeque(d1);

	//ͷɾ
	d1.pop_front();
	printDeque(d1);

	// erase(pos);
	d1.erase(d1.begin() + 1);
	printDeque(d1);

	// erase(beg, end); 
	d1.erase(d1.begin() + 1, d1.end());
	printDeque(d1);

	//clear
	d1.clear();
	printDeque(d1);
}


/*
* deque ���ݴ�ȡ
* ����ԭ�ͣ�
* operator[];    //������ͷ������һ������
* at(int index); //��������index��ָ������
* front();	     //���������е�һ������
* back();        //�������������һ������
*/
void Access() {
	std::deque<int> d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_back(40);
	d1.push_back(50);

	//ͨ��operator[]��ʽ����Ԫ��
	for (int i = 0; i < d1.size(); i++) {
		std::cout << d1[i] << " ";
	}
	std::cout << std::endl;

	//ͨ��at��ʽ����Ԫ��
	for (int i = 0; i < d1.size(); i++) {
		std::cout << d1.at(i) << " ";
	}
	std::cout << std::endl;

	// ����������һ��Ԫ��
	std::cout << "��һ��Ԫ��Ϊ��" << d1.front() << std::endl;

	//�����������һ��Ԫ��
	std::cout << "���һ��Ԫ��Ϊ��" << d1.back() << std::endl;
}


/*
* �����㷨��deque ������������
* ����ԭ�ͣ�
* sort(iterator beg, iterator end) //��[beg, end]������Ԫ�ؽ�������
*
* ע�⣺����Ĭ���������򣬴�С����
* ����֧��������ʵĵ���������������vector��������������sort�㷨ֱ�Ӷ����������ʹ��ʱ����ͷ�ļ�<algorithm>
*/
void Sort() {
	std::deque<int> d;
	d.push_back(10);
	d.push_back(30);
	d.push_back(40);
	d.push_back(20);
	d.push_back(50);
	printDeque(d);


	sort(d.begin(), d.end());
	std::cout << "�����\n";
	printDeque(d);
}


int main03() {
	Insert();

	std::cout << "---------------- \n";
	Delete();

	std::cout << "---------------- \n";
	Access();

	std::cout << "---------------- \n";
	Sort();

	system("pause");
	return 0;
}