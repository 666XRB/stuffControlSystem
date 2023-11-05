#pragma once
#include "worker.h"

#include "boss.h"
#include "employee.h"
#include "manager.h"


void test()
{
	//创建父类指针(因为没有默认的构造函数)
	//C++的抽象类没有默认的构造函数。抽象类是一种不能被实例化的类
	Worker* worker = NULL;

	worker = new Employee(1, "张三", 1);
	worker->showInfo();
	cout << worker->m_name << "的部门是" << worker->getDep() << endl;
	delete worker;



	worker = new Manager(2, "牛马", 2);
	worker->showInfo();
	cout << worker->m_name << "的部门是" << worker->getDep() << endl;
	delete worker;



	worker = new Boss(3, "李四", 3);
	worker->showInfo();
	cout << worker->m_name << "的部门是" << worker->getDep() << endl;
	delete worker;

	//worker = NULL;



}
