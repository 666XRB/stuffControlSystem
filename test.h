#pragma once
#include "worker.h"

#include "boss.h"
#include "employee.h"
#include "manager.h"


void test()
{
	//��������ָ��(��Ϊû��Ĭ�ϵĹ��캯��)
	//C++�ĳ�����û��Ĭ�ϵĹ��캯������������һ�ֲ��ܱ�ʵ��������
	Worker* worker = NULL;

	worker = new Employee(1, "����", 1);
	worker->showInfo();
	cout << worker->m_name << "�Ĳ�����" << worker->getDep() << endl;
	delete worker;



	worker = new Manager(2, "ţ��", 2);
	worker->showInfo();
	cout << worker->m_name << "�Ĳ�����" << worker->getDep() << endl;
	delete worker;



	worker = new Boss(3, "����", 3);
	worker->showInfo();
	cout << worker->m_name << "�Ĳ�����" << worker->getDep() << endl;
	delete worker;

	//worker = NULL;



}
