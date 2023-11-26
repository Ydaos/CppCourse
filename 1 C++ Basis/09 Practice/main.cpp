#include "addressBook.h"

void showMenu() {
	cout << "*****************************" << endl;
	cout << "*****" << "\t1、添加联系人\t" << "*****" << endl;
	cout << "*****" << "\t2、显示联系人\t" << "*****" << endl;
	cout << "*****" << "\t3、删除联系人\t" << "*****" << endl;
	cout << "*****" << "\t4、查找联系人\t" << "*****" << endl;
	cout << "*****" << "\t5、修改联系人\t" << "*****" << endl;
	cout << "*****" << "\t6、清空联系人\t" << "*****" << endl;
	cout << "*****" << "\t0、退出联系人\t" << "*****" << endl;
	cout << "*****************************" << endl;
}

int main() {
	int select = -1;
	int m_size = 0;
	Contact* cArr = new Contact[Max];

	while (select != 0) {
		showMenu();
		cin >> select;

		switch (select)
		{
		case 0:  //退出通讯录
			cout << "通讯录关闭，欢迎再次使用！" << endl;
			break;

		case 1:  //添加联系人
			if (m_size <= 999) {
				addContact(cArr, m_size);
			}
			else {
				cout << "通讯录已满" << endl;
			}
			break;

		case 2:  //显示联系人
			showContact(cArr, m_size);
			break;

		case 3:  //删除联系人
			deleteContact(cArr, m_size);
			break;

		case 4:  //查找联系人
			seekContact(cArr, m_size);
			break;

		case 5:  //修改联系人
			alterContact(cArr, m_size);
			break;

		case 6:  //清空联系人
			clearContact(cArr, m_size);
			break;

		default:  //无效指令
			cout << "无效命令，请重新输入" << endl;
			break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}



