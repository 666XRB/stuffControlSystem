#pragma once

#include "worker.h"

class Boss :public Worker {
public:

	Boss(int id, string name, int depid);
	~Boss();


	//职工自己的显示个人信息
	virtual void showInfo();

	//职工自己的显示部门
	virtual string getDep();


};