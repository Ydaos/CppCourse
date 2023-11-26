#include <iostream>
#include <string>

/*
* string查找
* 函数原型：
* int find(const string &str, int pos = 0)const;      //查找str第一次出现位置，从pos开始查找
* int find(const char* str, int pos = 0)const;        //查找str第一次出现位置，从pos开始查找
* int find(const char* str, int pos, int n)const;     //从pos位置查找str前n个字符第一次出现位置
* int find(const char c, int pos = 0)const;           //查找字符c第一次出现位置
* int rfind(const string &str, int pos = npos)const;  //查找str最后一次出现位置，从pos开始查找
* int rfind(const char* str, int pos = npos)const;    //查找str最后一次出现位置，从pos开始查找
* int rfind(const char* str, int pos, int n)const;    //查找str前n个字符最后一次出现位置
* int rfind(const char c, int pos = 0)const;          //查找字符c最后一次出现位置
* 
* 两者区别：rfind从右往左查找，find从左往右查找
* find（rfind）找到字符串后返回查找的第一个字符的位置，找不到返回 -1；
*/
void myFind() {
	// find();
	std::string str1 = "abcdefgcd";
	int pos1 = str1.find("cd");  // pos有初值 pos = 0;可以不填
	std::cout << "pos1 = " << pos1 << std::endl;

	int pos2 = str1.find("cd", 3);
	std::cout << "pos2 = " << pos2 << std::endl;
	//返回pos2 = 7，因为从str1第三位字符'd'开始找，所以找不到第一个"cd"。

	int pos3 = str1.find('c');  //查找字符 'c'
	std::cout << "pos3 = " << pos3 << std::endl;

	// rfind
	int pos4 = str1.rfind("cd");
	std::cout << "pos4 = " << pos4 << std::endl;

	int ret = str1.rfind("1");
	if (ret == -1) {
		std::cout << "未找到指定字符\n";
	}
}


/*
* string字符串比较
* 通过ASCII码进行比较，字符逐个比较；
* = 返回 0；> 返回1；< 返回-1
* 字符串对比主要是为了判断是否相等，判断大小基本没意义
*
* 函数原型：
* int compare(const string &str)const; //与字符串str比较
* int compare(const char* str)const;   //与字符串str比较
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
* string字符存取
* 函数原型：
* char& operator[](int n); //通过[]方式取字符
* char& at(int n);         //通过at方法获取字符
*/
void CharAccess() {
	std::string str = "hello";

	// 1、通过[]方式取字符
	for (int i = 0; i < str.size(); i++) {
		std::cout << str[i] << " ";
	}
	std::cout << std::endl;

	// 2、通过at方法获取字符
	for (int i = 0; i < str.size(); i++) {
		std::cout << str.at(i) << " ";
	}
	std::cout << std::endl;

	// 修改字符
	str[0] = 'x'; // xello
	std::cout << str << std::endl;

	str.at(0) = 's'; // sello
	std::cout << str << std::endl;
}


/*
* 从字符串中获取想要的子串
* 函数原型：
* string substr(int pos = 0, int n = npos)const; //返回从pos位置开始的n个字符组成的字符串
* 
* 灵活运用子串功能，可以在实际开发中获得有效信息
*/
void mySubstr() {
	std::string str = "hello";
	std::string subs = str.substr(1, 3);
	std::cout << "subs = " << subs << std::endl;

	// 从邮件地址中获取用户名信息
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