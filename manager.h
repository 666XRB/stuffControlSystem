#pragma once
#include "worker.h"

class Manager :public Worker {
public:

	//����Ĺ��������
	Manager(int id, string name, int depid);
	~Manager();



	//�̳�Worker����������Ҫ��д�ĺ���������һ�£����ⲿ��д��
	virtual void showInfo();
	virtual string getDep();



};