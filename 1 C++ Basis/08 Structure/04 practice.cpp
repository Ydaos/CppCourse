#include <iostream>

/*
* ���������һ��Ӣ�۵Ľṹ�壬������Ա���������䡢�Ա�
* �����ṹ�����飬�����д�����Ӣ��
* ͨ��ð�������㷨���������е�Ӣ�۰�����������������򣬲���ӡ���ս��
*/

struct Hero {
	std::string name;
	int age = 0;
	std::string gender;
};

//��ӡ������Ϣ����
void printInfo(Hero hArr[], int len) {
	for (int i = 0; i < len; i++) {
		std::cout << "Ӣ��������" << hArr[i].name
			<< " Ӣ�����䣺" << hArr[i].age
			<< " Ӣ���Ա�" << hArr[i].gender << std::endl;
	}
}

//ð�������������鰴���������������
void bubbleSort(Hero hArr[], int len) {
	for (int i = 0; i < len - 1; i++) {
		Hero temp;
		for (int j = i + 1; j < len; j++) {
			if (hArr[i].age > hArr[j].age) {
				temp = hArr[i];
				hArr[i] = hArr[j];
				hArr[j] = temp;
			}
		}
	}
}

void Practice() {
	//����5��Ӣ�۵�����
	Hero h_arr[5] = { {"����",23,"��"},{"����",22,"��"}, {"�ŷ�",20,"��"}, {"����",21,"��"}, {"����",19,"Ů"} };
	int len = sizeof(h_arr) / sizeof(h_arr[0]);

	//ð�����������������򣬰����������������
	bubbleSort(h_arr, len);

	//ͨ���������������Ϣ
	printInfo(h_arr, len);
}

int main() {
	Practice();

	system("pause");
	return 0;
}