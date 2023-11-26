#include <iostream>
#include <map>

void printMap(std::map<int, int>& m); //����������"01 definition.cpp"
/*
* map�������
* 1��map������Ԫ�ض���pair
* 2��pair�е�һ��Ԫ��Ϊkey����ֵ�������������ã��ڶ���Ԫ��Ϊvalue��ʵֵ��
* 3������Ԫ�ػᰴ��keyֵ�Զ�����
* 
* ���ʣ�map/multimap���ڹ���ʽ�������ײ�ṹ�Ƕ�����ʵ��
* �ŵ㣺���Ը���keyֵ�����ҵ�valueֵ
* 
* map/multimap��������
* map�������������ظ���keyֵ��multimap�����������ظ���keyֵ
*/
void printMap(std::map<int, int>& m) {
	for (std::map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
		std::cout << "key = " << (*it).first << " value = " << (*it).second << std::endl;
	}
	std::cout << std::endl;
}
 

/*
* map�Ĺ���͸�ֵ
* ����ԭ�ͣ�
* map<T1, T2> m;			    // Ĭ�Ϲ��캯��
* map(const map &m);		    // �������캯��
* map& operator=(const map &m); // ���ظ�ֵ�����
* 
* �ܽ᣺map����Ԫ�ض��ǳɶԳ��֣������Ԫ�ض���pair����
*/
void Define() {
	// Ĭ�Ϲ���
	std::map<int, int> m1;
	m1.insert(std::pair<int, int>(1, 10));
	m1.insert(std::pair<int, int>(3, 20));
	m1.insert(std::pair<int, int>(2, 30));
	m1.insert(std::pair<int, int>(4, 40));
	m1.insert(std::pair<int, int>(5, 50));
	printMap(m1);

	// ��������
	std::map<int, int> m2(m1);
	printMap(m2);

	// ��ֵ
	std::map<int, int> m3;
	m3 = m1;
	printMap(m3);
}


int main01() {
	Define();

	system("pause");
	return 0;
}