#include <iostream>
#include <fstream>
#include "workerManager.h"
//包含测试
#include "test.h"

using namespace std;

int main()
{
	//测试多态是否成功？
	//test();
	//exit(0);


	WorkerManager workerManager;
//	workerManager.showMenu();
	//choice记录用户选项
	int choice = 0;

	//实现接口选择功能
	while (true)
	{
		//循环显示菜单
		workerManager.showMenu();
		cout << "输入你的选择" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://退出系统
			workerManager.exitSystem();
			break;
		case 1://添加职工
			workerManager.add_stuff();
			break;
		case 2://显示职工
			workerManager.show_stuff();
			break;
		case 3://删除职工
		{
			//先判断职工存在吗？
			workerManager.del_stuff();
		}
		case 4://修改职工
			workerManager.mod_stuff();
			break;
		case 5://查找职工
			workerManager.find_stuff();
			break;
		case 6://编号排序
			workerManager.sort_stuff();
			break;
		case 7://清空职工
			workerManager.clean_stuff();
			break;
		default:
			system("cls");
			break;
		}
	}


	system("pause");
	return 0;
}