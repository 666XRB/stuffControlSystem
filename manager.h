#pragma once
#include "worker.h"

class Manager :public Worker {
public:

	//经理的构造和析构
	Manager(int id, string name, int depid);
	~Manager();



	//继承Worker的两个即将要重写的函数先声明一下，在外部重写。
	virtual void showInfo();
	virtual string getDep();



};