#include <iostream>
#include <string>

/*
* string����
* ����ԭ�ͣ�
* int find(const string &str, int pos = 0)const;      //����str��һ�γ���λ�ã���pos��ʼ����
* int find(const char* str, int pos = 0)const;        //����str��һ�γ���λ�ã���pos��ʼ����
* int find(const char* str, int pos, int n)const;     //��posλ�ò���strǰn���ַ���һ�γ���λ��
* int find(const char c, int pos = 0)const;           //�����ַ�c��һ�γ���λ��
* int rfind(const string &str, int pos = npos)const;  //����str���һ�γ���λ�ã���pos��ʼ����
* int rfind(const char* str, int pos = npos)const;    //����str���һ�γ���λ�ã���pos��ʼ����
* int rfind(const char* str, int pos, int n)const;    //����strǰn���ַ����һ�γ���λ��
* int rfind(const char c, int pos = 0)const;          //�����ַ�c���һ�γ���λ��
* 
* ��������rfind����������ң�find�������Ҳ���
* find��rfind���ҵ��ַ����󷵻ز��ҵĵ�һ���ַ���λ�ã��Ҳ������� -1��
*/
void myFind() {
	// find();
	std::string str1 = "abcdefgcd";
	int pos1 = str1.find("cd");  // pos�г�ֵ pos = 0;���Բ���
	std::cout << "pos1 = " << pos1 << std::endl;

	int pos2 = str1.find("cd", 3);
	std::cout << "pos2 = " << pos2 << std::endl;
	//����pos2 = 7����Ϊ��str1����λ�ַ�'d'��ʼ�ң������Ҳ�����һ��"cd"��

	int pos3 = str1.find('c');  //�����ַ� 'c'
	std::cout << "pos3 = " << pos3 << std::endl;

	// rfind
	int pos4 = str1.rfind("cd");
	std::cout << "pos4 = " << pos4 << std::endl;

	int ret = str1.rfind("1");
	if (ret == -1) {
		std::cout << "δ�ҵ�ָ���ַ�\n";
	}
}


/*
* string�ַ����Ƚ�
* ͨ��ASCII����бȽϣ��ַ�����Ƚϣ�
* = ���� 0��> ����1��< ����-1
* �ַ����Ա���Ҫ��Ϊ���ж��Ƿ���ȣ��жϴ�С����û����
*
* ����ԭ�ͣ�
* int compare(const string &str)const; //���ַ���str�Ƚ�
* int compare(const char* str)const;   //���ַ���str�Ƚ�
*/
void Comparison() {
	std::string str1 = "bac";
	std::string str2 = "abc";

	if (str1.compare(str2) == 0) {
		std::cout << "str1 = str2\n";
	}
	else if (str1.compare(str2) == 1) {
		std::cout << "str1 > str2\n";
	}
	else if (str1.compare(str2) == -1) {
		std::cout << "str1 < str2\n";
	}
}


/*
* string�ַ���ȡ
* ����ԭ�ͣ�
* char& operator[](int n); //ͨ��[]��ʽȡ�ַ�
* char& at(int n);         //ͨ��at������ȡ�ַ�
*/
void CharAccess() {
	std::string str = "hello";

	// 1��ͨ��[]��ʽȡ�ַ�
	for (int i = 0; i < str.size(); i++) {
		std::cout << str[i] << " ";
	}
	std::cout << std::endl;

	// 2��ͨ��at������ȡ�ַ�
	for (int i = 0; i < str.size(); i++) {
		std::cout << str.at(i) << " ";
	}
	std::cout << std::endl;

	// �޸��ַ�
	str[0] = 'x'; // xello
	std::cout << str << std::endl;

	str.at(0) = 's'; // sello
	std::cout << str << std::endl;
}


/*
* ���ַ����л�ȡ��Ҫ���Ӵ�
* ����ԭ�ͣ�
* string substr(int pos = 0, int n = npos)const; //���ش�posλ�ÿ�ʼ��n���ַ���ɵ��ַ���
* 
* ��������Ӵ����ܣ�������ʵ�ʿ����л����Ч��Ϣ
*/
void mySubstr() {
	std::string str = "hello";
	std::string subs = str.substr(1, 3);
	std::cout << "subs = " << subs << std::endl;

	// ���ʼ���ַ�л�ȡ�û�����Ϣ
	std::string email = "zhangsan@sina.com";
	int pos = email.find('@');
	std::string name = email.substr(0, pos);
	std::cout << name << std::endl;
}


int main02() {
	myFind();

	std::cout << "\n---------------------\n";
	Comparison();

	std::cout << "\n---------------------\n";
	CharAccess();

	std::cout << "\n---------------------\n";
	mySubstr();

	system("pause");
	return 0;
}