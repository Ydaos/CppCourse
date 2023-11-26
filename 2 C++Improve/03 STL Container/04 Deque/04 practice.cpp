#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <algorithm> //标准算法头文件

/*
* 案例 - 评委打分
* 案例描述：5名选手：ABCDE，10个评委分别对每一个选手打分，去除最高分和最低分取评价分作为结果
*
* 实现步骤
* 1、创建5名选手，放到vector中
* 2、遍历vector容器，取出每个选手，执行for循环将10个评委打分存到deque容器中
* 3、sort算法对deque容器中分数排序，去除最高分和最低分
* 4、deque容器遍历一遍，累加总分
* 5、获取平均分
*/
class Person {
public:
	Person(std::string name, int score) {
		this->m_Name = name;
		this->m_Score = score;
	}

	std::string m_Name; // 选手姓名
	int m_Score;   // 平均分
};

void createPerson(std::vector<Person>& v) {
	std::string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++) {
		// 创建选手
		std::string name = "选手";
		name += nameSeed[i];
		int score = 0;
		Person p(name, score);

		//将选手放进容器里
		v.push_back(p);
	}
}

void printVector(const std::vector<Person>& v) {
	for (std::vector<Person>::const_iterator it = v.begin(); it != v.end(); it++) {
		std::cout << "姓名：" << (*it).m_Name << " 平均分：" << (*it).m_Score << std::endl;
	}
}

void setScore(std::vector<Person>& v) {
	// 随机数种子
	srand((unsigned int)time(NULL));

	for (int i = 0; i < v.size(); i++) {
		// 将评委分数放入deque容器中
		std::deque<int> d;
		for (int j = 0; j < 10; j++) {
			int score = rand() % 41 + 60;
			d.push_back(score);
		}
		// 排序
		sort(d.begin(), d.end());

		// 去除最高分和最低分
		d.pop_back();
		d.pop_front();

		// 取平均分
		int sum = 0;
		for (int k = 0; k < d.size(); k++) {
			sum += d[k];
		}
		v[i].m_Score = sum / d.size();
	}
}

//指定位置插入
void Func() {
	//1、创建5名选手
	std::vector<Person> v;
	createPerson(v);

	//2、测试创建是否完成
	printVector(v);

	//3、给选手打分
	setScore(v);

	//4、显示最后得分
	std::cout << "评分结果：\n";
	printVector(v);
}
// 总结：sort算法非常常用，使用时包含头文件<algorithm>即可

int main() {
	Func();

	system("pause");
	return 0;
}