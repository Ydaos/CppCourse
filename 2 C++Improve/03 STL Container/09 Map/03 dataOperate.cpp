#include <iostream>
#include <map>

void printMap(std::map<int, int>& m); //����������"01 definition.cpp"

/*
* map�Ĳ����ɾ��
* ����ԭ�ͣ�
* insert(elem);	   // �������в���Ԫ��
* erase(pos);	   // ɾ��pos��������ָԪ�أ�������һ��Ԫ�صĵ�����
* erase(beg, end); // ɾ��[beg, end]��������Ԫ��
* erase(key);      // ɾ��������ֵΪkey��Ԫ��
* clear();         // �������
*/
void InsertDel() {
	// ����
	// ��һ��
	std::map<int, int> m1;
	m1.insert(std::pair<int, int>(1, 10));
	m1.insert(std::pair<int, int>(3, 20));

	// �ڶ���
	m1.insert(std::make_pair(2, 30));
	m1.insert(std::make_pair(4, 40));

	// ������
	m1.insert(std::map<int, int>::value_type(5, 50));

	// ������
	m1[6] = 60;
	// ������[]���룬��������keyֵ���ᴴ�����key����0����Ϊvalue��
	// ��;����������key����value eg��m1[key];
	std::cout << m1[7] << std::endl;
	printMap(m1);

	// ɾ��
	m1.erase(m1.begin()); //pos������ɾ��
	printMap(m1);

	m1.erase(3);         //����keyֵɾ��
	printMap(m1);

	m1.erase(m1.begin(), m1.end()); // ����ɾ��
	// m1.clear();                  //�������
	printMap(m1);

	/*
	* �ܽ᣺
	* ���뷽ʽ�кܶ��֣��Ƽ���ǰ���֣������ֲ������������룬��������������valueֵ
	* ���� -- insert
	* ɾ�� -- erase
	* ��� -- clear
	*/
}


/*
* map�Ĳ��Һ�ͳ��
* ����ԭ�ͣ�
* find(key);   // ����key�Ƿ���ڣ����ظü��ĵ��������������򷵻�set.end()
* count(key);  // ͳ��key����������map���Է�1��0
* 
* map����������ظ�keyֵ��countͳ�ƽ����1��0��multimapͳ�ƽ������ > 1
*/
void FindAndCount() {
	std::map<int, int> m1;
	m1.insert(std::pair<int, int>(1, 10));
	m1.insert(std::pair<int, int>(3, 20));
	m1.insert(std::pair<int, int>(2, 30));
	m1.insert(std::pair<int, int>(4, 40));
	m1.insert(std::pair<int, int>(5, 50));

	// ����
	std::map<int, int>::iterator pos = m1.find(3);
	if (pos != m1.end()) {
		std::cout << "�鵽��Ԫ�� key = " << (*pos).first << " value = " << (*pos).second << std::endl;
	}
	else {
		std::cout << "δ�ҵ�Ԫ��" << std::endl;
	}

	// ͳ��
	int num = m1.count(4);
	std::cout << "num = " << num << std::endl;
}

int main03() {
	InsertDel();

	std::cout << "-------------------\n";
	FindAndCount();

	system("pause");
	return 0;
}