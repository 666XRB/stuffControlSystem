#include <iostream>
#include <fstream>
#include "workerManager.h"
//��������
#include "test.h"

using namespace std;

int main()
{
	//���Զ�̬�Ƿ�ɹ���
	//test();
	//exit(0);


	WorkerManager workerManager;
//	workerManager.showMenu();
	//choice��¼�û�ѡ��
	int choice = 0;

	//ʵ�ֽӿ�ѡ����
	while (true)
	{
		//ѭ����ʾ�˵�
		workerManager.showMenu();
		cout << "�������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://�˳�ϵͳ
			workerManager.exitSystem();
			break;
		case 1://���ְ��
			workerManager.add_stuff();
			break;
		case 2://��ʾְ��
			workerManager.show_stuff();
			break;
		case 3://ɾ��ְ��
		{
			//���ж�ְ��������
			workerManager.del_stuff();
		}
		case 4://�޸�ְ��
			workerManager.mod_stuff();
			break;
		case 5://����ְ��
			workerManager.find_stuff();
			break;
		case 6://�������
			workerManager.sort_stuff();
			break;
		case 7://���ְ��
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