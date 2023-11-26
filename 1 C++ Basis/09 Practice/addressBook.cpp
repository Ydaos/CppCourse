#include "addressBook.h"

void addContact(Contact* cArr, int& num) {
	int gender = 0;
	Contact cTemp;
	cout << "请输入姓名" << endl;
	cin >> cTemp.name;

	cout << "请输入性别" << endl;
	cout << "1 -- 男" << endl;
	cout << "2 -- 女" << endl;
	do {
		cin >> gender;
		if (gender == 1) {
			cTemp.gender = "男";
		}
		else if (gender == 2) {
			cTemp.gender = "女";
		}
		else {
			cout << "性别不存在，请重新输入" << endl;
		}
	} while (gender != 1 && (gender != 2));

	cout << "请输入年龄" << endl;
	cin >> cTemp.age;

	cout << "请输入电话" << endl;
	cin >> cTemp.phone;

	cout << "请输入家庭住址" << endl;
	cin >> cTemp.address;

	cTemp.idx = num + 1;
	cArr[num] = cTemp;
	num += 1;

	cout << "添加成功" << endl;
}

void showContact(Contact* cArr, int num) {
	if (num == 0) {
		cout << "当前通讯录为空" << endl;
	}
	else {
		for (int i = 0; i < num; i++) {
			cout << "姓名：" << cArr[i].name << "\t"
				<< "性别：" << cArr[i].gender << "\t"
				<< "年龄：" << cArr[i].age << "\t"
				<< "电话：" << cArr[i].phone << "\t"
				<< "住址：" << cArr[i].address << endl;
		}
	}
}

void deleteContact(Contact* cArr, int& num) {
	int idx = -1;
	string name;
	bool flag = false;
	cout << "请输入要删除的联系人姓名" << endl;
	cin >> name;
	for (int i = 0; i < num; i++) {
		if (cArr[i].name == name) {
			flag = true;
			cout << "编号：" << cArr[i].idx << "\t"
				<< "姓名：" << cArr[i].name << "\t"
				<< "性别：" << cArr[i].gender << "\t"
				<< "年龄：" << cArr[i].age << "\t"
				<< "电话：" << cArr[i].phone << "\t"
				<< "住址：" << cArr[i].address << endl;
		}
	}
	if (flag) {
		cout << "请选择要删除的联系人编号" << endl;
		cin >> idx;
		for (int j = idx - 1; j < num - 1; j++) {
			cArr[j] = cArr[j + 1];
			cArr[j].idx = j + 1;
		}
		num -= 1;
		cout << "删除成功" << endl;
	}
	else {
		cout << "联系人不存在" << endl;
	}
}

void seekContact(Contact* cArr, int num) {
	string name;
	bool flag = false;
	cout << "请输入要查找的联系人姓名" << endl;
	cin >> name;
	for (int i = 0; i < num; i++) {
		if (cArr[i].name == name) {
			flag = true;
			cout << "姓名：" << cArr[i].name << "\t"
				<< "性别：" << cArr[i].gender << "\t"
				<< "年龄：" << cArr[i].age << "\t"
				<< "电话：" << cArr[i].phone << "\t"
				<< "住址：" << cArr[i].address << endl;
		}
	}
	if (!flag) {
		cout << "联系人不存在" << endl;
	}
}

void alterContact(Contact* cArr, int num) {
	int idx = -1;
	string name;
	bool flag = false;
	cout << "请输入要修改的联系人姓名" << endl;
	cin >> name;
	for (int i = 0; i < num; i++) {
		if (cArr[i].name == name) {
			flag = true;
			cout << "编号：" << cArr[i].idx << "\t"
				<< "姓名：" << cArr[i].name << "\t"
				<< "性别：" << cArr[i].gender << "\t"
				<< "年龄：" << cArr[i].age << "\t"
				<< "电话：" << cArr[i].phone << "\t"
				<< "住址：" << cArr[i].address << endl;
		}
	}
	if (flag) {
		cout << "请选择要修改的联系人编号" << endl;
		cin >> idx;

		int gender = 0;
		Contact cTemp;
		cout << "请输入姓名" << endl;
		cin >> cTemp.name;

		cout << "请输入性别" << endl;
		cout << "1 -- 男" << endl;
		cout << "2 -- 女" << endl;
		do {
			cin >> gender;
			if (gender == 1) {
				cTemp.gender = "男";
			}
			else if (gender == 2) {
				cTemp.gender = "女";
			}
			else {
				cout << "性别不存在，请重新输入" << endl;
			}
		} while (gender != 1 && (gender != 2));

		cout << "请输入年龄" << endl;
		cin >> cTemp.age;

		cout << "请输入电话" << endl;
		cin >> cTemp.phone;

		cout << "请输入家庭住址" << endl;
		cin >> cTemp.address;

		cTemp.idx = idx;
		cArr[idx - 1] = cTemp;
		cout << "修改成功" << endl;
	}
	else {
		cout << "联系人不存在" << endl;
	}
}

void clearContact(Contact* cArr, int& num) {
	cout << "确定清空通讯录？" << endl;
	cout << "y -- 确定" << endl;
	cout << "n -- 取消" << endl;

	string flag;
	cin >> flag;
	if (flag == "y") {
		memset(cArr, '\0', sizeof(Contact) * num);
		num = 0;
		cout << "清空联系人成功" << endl;
	}
	else if (flag == "n") {
		cout << "清空联系人失败" << endl;
	}
	else {
		cout << "无效指令，退出..." << endl;
	}
}