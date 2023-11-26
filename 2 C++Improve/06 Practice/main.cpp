#include "workerManager.h";

int main() {
	WorkerManager wm;
	int choice = -1;

	do {
		// 展示菜单
		wm.showMenu();

		// 输入命令
		cout << "请输入您的选择：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0: // 退出系统
			wm.exitSystem();
			break;
		case 1: // 添加职工
			wm.addEmployee();
			break;
		case 2: // 显示职工
			wm.showEmployee();
			break;
		case 3: // 删除职工
			wm.delEmployee();
			break;
		case 4: // 修改职工
			wm.modEmployee();
			break;
		case 5: // 查找职工
			wm.findEmployee();
			break;
		case 6: // 排序职工
			wm.sortEmployee();
			break;
		case 7: // 清空文件
			wm.clearEmpFile();
			break;
		default:
			break;
		}

	} while (choice != 0);

	return 0;
}