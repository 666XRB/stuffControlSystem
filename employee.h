#pragma once

#include "worker.h"


class Employee :public Worker {
public:


	Employee(int id, string name, int depid);
	//ְ���Ĺ��캯��


	~Employee();
	//ְ������������

	//ְ���Լ�����ʾ������Ϣ
	virtual void showInfo();

	//ְ���Լ�����ʾ����
	virtual string getDep();

};