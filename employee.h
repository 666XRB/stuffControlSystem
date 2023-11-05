#pragma once

#include "worker.h"


class Employee :public Worker {
public:


	Employee(int id, string name, int depid);
	//职工的构造函数


	~Employee();
	//职工的析构函数

	//职工自己的显示个人信息
	virtual void showInfo();

	//职工自己的显示部门
	virtual string getDep();

};