#include <iostream>
#include <list>
#include <string>

namespace prac_space {

	/*
	* List排序案例：
	* 将Person自定义数据类型进行排序，Person中属性有姓名、年龄、身高
	* 排序规则：按照年龄进行升序，如果年龄相同则按照身高进行降序
	*/

	class Person {
	public:
		Person(std::string name, int age, int height) {
			this->m_Name = name;
			this->m_Age = age;
			this->m_Height = height;
		}

		std::string m_Name;
		int m_Age;
		int m_Height;
	};

	void printList(const std::list<Person>& l) {
		for (std::list<Person>::const_iterator it = l.begin(); it != l.end(); it++) {
			std::cout << "姓名：" << (*it).m_Name << " 年龄：" << (*it).m_Age << " 身高：" << (*it).m_Height << std::endl;
		}
		std::cout << std::endl;
	}

	//指定排序 规则
	bool myCompare(Person& p1, Person& p2) {
		// 按年龄升序
		if (p1.m_Age == p2.m_Age) {
			// 年龄相同 按身高降序
			return p1.m_Height > p2.m_Height;
		}
		return p1.m_Age < p2.m_Age;
	}

	void Func() {
		// 准备数据
		Person p1("Tom", 18, 170);
		Person p2("Jerry", 17, 150);
		Person p3("Tony", 20, 170);
		Person p4("Mark", 20, 168);
		Person p5("Hans", 22, 180);

		// 创建容器，并插入数据
		std::list<Person>L;
		L.push_back(p1);
		L.push_back(p2);
		L.push_back(p3);
		L.push_back(p4);
		L.push_back(p5);
		std::cout << "排序前：" << std::endl;
		printList(L);

		// 排序
		std::cout << "排序后：" << std::endl;
		L.sort(myCompare); //加谓词可以指定排序规则
		printList(L);
	}
}


/*
* 总结：
* 对于自定义数据类型，必须要指定排序规则，否则编译器不知道如何进行排序
* 高级排序只是在排序规则上再进行一次逻辑规则制定，并不复杂
*/
int main() {
	prac_space::Func();

	system("pause");
	return 0;
}