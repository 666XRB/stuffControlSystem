#pragma once

#include "worker.h"

class Boss :public Worker {
public:

	Boss(int id, string name, int depid);
	~Boss();


	//ְ���Լ�����ʾ������Ϣ
	virtual void showInfo();

	//ְ���Լ�����ʾ����
	virtual string getDep();


};