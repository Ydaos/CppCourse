#include <iostream>
#include <vector>

void printVector(std::vector<int>& v);// ����������01 definition.cpp

								 
/*
* vector�����ɾ��
* ����ԭ�ͣ�
* push_back(ele);								   //β������Ԫ��ele
* pop_back();									   //ɾ�����һ��Ԫ��
* insert(const_iterator pos, ele);                 //��������ָ��λ��pos����Ԫ��ele
* insert(const_iterator pos, int n, ele);		   //��������ָ��λ��pos����n��eleԪ��
* erase(const_iterator pos)                        //ɾ��������ָ���Ԫ��
* erase(const_iterator start, const_iterator end); //ɾ����������beg��end֮���Ԫ��
* clear();                                         //ɾ������������Ԫ��
*/
void InsertDel() {
	std::vector<int> v;

	// β��
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	printVector(v);

	// βɾ
	v.pop_back();
	printVector(v);

	// ���� ��һ�������ǵ�����
	v.insert(v.begin(), 100);
	printVector(v);

	// ��ָ��λ�ò���n��Ԫ��
	v.insert(v.begin() + 1, 2, 300);
	printVector(v);

	// ɾ��ָ��Ԫ�� ɾ��Ҳ�ǵ�����
	v.erase(v.begin());
	printVector(v);

	// ɾ��ĳ�������Ԫ��
	v.erase(v.begin(), v.end() - 1);
	printVector(v);

	// ���
	v.clear();
	printVector(v);
}


/*
* vector���ݴ�ȡ
* ����ԭ�ͣ�
* operator[int idx]; //��������idx��ָ������
* at(int idx);       //��������idx��ָ������
* front();           //����������һ������Ԫ��
* back();		     //�����������һ������Ԫ��
*/
void Access() {
	std::vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);
	printVector(v);

	//����[]��������Ԫ��
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;

	//����at��������Ԫ��
	for (int i = 0; i < v.size(); i++) {
		std::cout << v.at(i) << " ";
	}
	std::cout << std::endl;

	//����[]��at�޸ķ��ʵ�����Ԫ��
	v[0] = 11;
	v.at(1) = 21;
	printVector(v);

	//����������һ������Ԫ��
	std::cout << "��һ��Ԫ�أ�" << v.front() << std::endl;

	//�����������һ������Ԫ��
	std::cout << "���һ��Ԫ�أ�" << v.back() << std::endl;

	/*
	* �ܽ�:
	* �����õ�������ȡvector�����е�Ԫ�أ�[]��atҲ����
	* front����������һ��Ԫ�أ�back�����������һ��Ԫ��
	*/
}


int main03() {
	InsertDel();

	std::cout << "-------------------------\n";
	Access();

	system("pause");
	return 0;
}