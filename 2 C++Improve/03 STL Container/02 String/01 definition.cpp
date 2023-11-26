#include <iostream>
#include <string>
 
/*
* string 容器：本质是一个类，类内部封装char*来管理字符串
* 特点：
* 封装很多成员方法，如find、copy、insert等
* string管理char*分配的内存，不用担心复制越界、取值越界等，由类内部管理
* 
* string的构造函数：
* - string();                  //创建一个空的字符串
* - string(const char* s);     //使用字符数组s初始化
* - string(const string& str); //使用一个string对象初始化另一个string对象
* - string(int n, char c);     //使用n个字符c初始化
*/
void Constructor() {
	std::string s1;

	const char* s = "hello world!";
	std::string s2(s);
	std::cout << "s2 = " << s2 << std::endl;

	std::string s3(s2);
	std::cout << "s3 = " << s3 << std::endl;

	std::string s4(4, 'a');
	std::cout << "s4 = " << s4 << std::endl;

	//总结：string的多种构造方法没有可比性，灵活应用即可
	//实际上赋值操作更常用：string str = "hello world";
}


/*
* string赋值操作
* string& operator=(const char* s);     //char*类型字符串s 赋值给当前的字符串
* string& operator=(const string &s);   //字符串s 赋值给当前字符串
* string& operator=(char c);            //字符c 赋值给当前字符串
* string& assign(const char* s);        //char*类型字符串s 赋值给当前的字符串
* string& assign(const char* s, int n); //char*类型字符串s的前n个字符赋值给当前的字符串
* string& assign(const string &s);      //字符串s 赋值给当前字符串
* string& assign(int n, char c);        //用n个字符c 赋值给当前字符串
*/
void Assignment() {
	// string& operator=(const char* s);
	const char* c = "hello world!";
	std::string str1 = c;
	std::cout << "str1 = " << str1 << std::endl;

	// string& operator=(const string &s); 
	std::string str2;
	str2 = str1;
	std::cout << "str2 = " << str2 << std::endl;

	// string& operator=(char c);
	std::string str3;
	str3 = 'a';
	std::cout << "str3 = " << str3 << std::endl;

	// string& assign(const char* s); 
	std::string str4;
	str4.assign("hello C++");
	std::cout << "str4 = " << str4 << std::endl;

	// string& assign(const char* s, int n);
	std::string str5;
	str5.assign("hello C++", 5);
	std::cout << "str5 = " << str5 << std::endl;

	// string& assign(const string &s);
	std::string str6;
	str6.assign(str5);
	std::cout << "str6 = " << str6 << std::endl;

	// string& assign(int n, char c);
	std::string str7;
	str7.assign(5, 'a');
	std::cout << "str7 = " << str7 << std::endl;
}


/*
* 字符串末尾拼接字符串
* string 字符串拼接函数原型
* string& operator+=(const char* s);               //重载+=操作符
* string& operator+=(const string &s);             //重载+=操作符
* string& operator+=(const char c);                //重载+=操作符
* string& append(const char* s);                   //把字符串s 连接到当前字符串结尾
* string& append(const char* s, int n);            //把字符串s的前n个字符连接到当前字符串结尾
* string& append(const string &s);                 //同string& operator+=(const string &s);
* string& append(const string &s, int pos, int n); //从字符串s中pos开的的n个字符连接到字符串结尾
* 
* 总结：字符串拼接重载版本很多，记一个重载+=运算符和append()实现局部字符串拼接即可
*/
void Joint() {
	// string& operator+=(const char* s);
	std::string str1 = "abc";
	str1 += "efg";
	std::cout << "str1 = " << str1 << std::endl;

	// string& operator+=(const string &s);
	std::string str2 = "str2 += ";
	str2 += str1;
	std::cout << "str2 = " << str2 << std::endl;

	// string& operator+=(const char c);
	str2 += '!';
	std::cout << "str2 = " << str2 << std::endl;

	// string& append(const char* s);
	std::string str4 = "C++";
	str4.append(" hello");
	std::cout << "str4 = " << str4 << std::endl;

	// string& append(const char* s, int n); 
	std::string str5 = "abc ";
	str5.append("hello C++", 5);
	std::cout << "str5 = " << str5 << std::endl;

	// string& append(const string &s); 
	std::string str6 = "str6 += ";
	str6.append(str5);
	std::cout << "str6 = " << str6 << std::endl;

	// string& append(const string &s, int pos, int n);
	std::string str7 = "abcdefg";
	std::string str8 = "str8 ";
	str8.append(str7, 3, 2);
	std::cout << "str8 = " << str8 << std::endl;
}


int main() {
	Constructor();

	std::cout << "\n---------------------\n";
	Assignment();

	std::cout << "\n---------------------\n";
	Joint();

	system("pause");
	return 0;
}