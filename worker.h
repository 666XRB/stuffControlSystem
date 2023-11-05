#pragma once
#include <iostream>
#include <string>

using namespace std;

class Worker {
public:
	//显示职工的个人信息
	virtual void showInfo() = 0;
	//显示职工的部门
	virtual string getDep() = 0;
	//具体的实现由子类的重写操作！


//抽象类不能实例对象，所以说构造函数也没有意义

	int m_id;
	string m_name;
	int m_DepId;
};