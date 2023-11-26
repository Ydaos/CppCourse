#include <iostream>
#include <deque>

/*
* deque������˫�����飬���Զ�ͷ�˽��в����ɾ������
* deque�ڲ�����ԭ��
* deque�ڲ��и��п�����ά��ÿ�λ������е����ݣ��������д����ʵ����
* �п���ά������ÿ���������ĵ�ַ��ʹ��ʹ��dequeʱ��һƬ�������ڴ�ռ�
* deque�ĵ�����Ҳ��֧��������ʵ�
* 
* deque��vector����
* 1��vector����ͷ������ɾ��Ч�ʵͣ�������Խ��Ч��Խ��
* 2��deque��Զ��ԣ���ͷ���Ĳ���ɾ���ٶȻ��vector��
* 3��vector����Ԫ��ʱ���ٶȻ��deque�죬�����ڲ�ʵ�ֲ�ͬ����
*/

void printDeque(const std::deque<int>& d) {
	for (std::deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}


/*
* deque�������캯��
* ����ԭ�ͣ�
* deque<T> deqT;           //Ĭ�Ϲ�����ʽ
* deque<beg, end>;         //���캯����[beg, end]�����е�Ԫ�ؿ���������
* deque(n, elem);          //���캯����n��elem������������
* deque(const deque &deq); //�������캯��
*/
void Constructor() {
	std::deque<int> d;
	for (int i = 0; i < 10; i++) {
		d.push_back(i);
	}
	printDeque(d);

	std::deque<int>d2(d.begin(), d.end());
	printDeque(d2);

	std::deque<int>d3(10, 6);
	printDeque(d3);

	std::deque<int>d4(d);
	printDeque(d4);
}


/*
* deque��ֵ����
* ����ԭ�ͣ�
* deque& operator=(const deque &deq); //����=�����
* assign(beg, end);				      //��[beg, end]�����е�Ԫ�ؿ���������
* assign(n, elem);			          //��n��elem������������
*/
void Assignment() {
	std::deque<int> d1;
	for (int i = 0; i < 10; i++) {
		d1.push_back(i);
	}
	printDeque(d1);

	// operator =
	std::deque<int>d2;
	d2 = d1;
	printDeque(d2);

	// assign(beg, end)
	std::deque<int>d3;
	d3.assign(d1.begin(), d1.end());
	printDeque(d3);

	// assign(n, elem)
	std::deque<int>d4;
	d4.assign(10, 6);
	printDeque(d4);
}

int main01() {
	Constructor();

	std::cout << "----------------------------\n";
	Assignment();

	system("pause");
	return 0;
}