#include <iostream>
#include <vector>

/*
* vector ��������
* ���ܣ�vector ���ݽṹ������ǳ����ƣ�Ҳ��Ϊ��������
* ���������Ǿ�̬�ռ䣬��vector���Զ�̬��չ
* ��̬��չ��������ԭ�ռ�֮�������¿ռ䣬�����Ҹ���Ŀռ䣨ԭ������1.5������Ȼ��ԭ���ݿ������ͷ�ԭ�ռ�
* vector ������֧���������
*/
void printVector(std::vector<int>& v) {
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}


/* 
* vector���캯��
* ����ԭ�ͣ�
* vector<T> v;                //����ģ��ʵ����ʵ�֣�Ĭ�Ϲ��캯��
* vector(v.begin(), v.end()); //��v[begin(), end()]�����е�Ԫ�ؿ���������
* vector(n, elem);            //���캯����n��elem����������
* vector(const vector &vec);  //�������캯��
* 
* ���һ����Ĭ�Ϲ��� + ��������
*/
void Constructor() {
	// Ĭ�Ϲ��� �޲ι���
	std::vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	printVector(v1);

	// ͨ�����䷽ʽ����
	std::vector<int> v2(v1.begin(), v1.end());
	printVector(v2);

	// n��elem��ʽ����
	std::vector<int>v3(10, 6);
	printVector(v3);

	// ��������
	std::vector<int>v4(v3);
	printVector(v4);
}

 
/*
* vector��ֵ����
* ����ԭ�ͣ�
* vector& operator=(const vector &v); //���������
* assign(beg, end);                   //��[beg, end]�����е����ݿ�������������
* assign(n, elem);                    //��n��elem������ֵ������
*/
void Assignment() {
	std::vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
	}
	printVector(v1);

	// operator=
	std::vector<int> v2 = v1;
	printVector(v2);

	// assign
	std::vector<int> v3;
	v3.assign(v1.begin(), v1.end());
	printVector(v3);

	// n��elem ��ʽ��ֵ
	std::vector<int> v4;
	v4.assign(10, 6);
	printVector(v4);
}

int main01() {
	Constructor();

	std::cout << "\n----------------------\n";
	Assignment();

	system("pause");
	return 0;
}