#include "boss.h"


Boss::Boss(int id, string name, int depid)
{
	this->m_id = id;
	this->m_name = name;
	this->m_DepId = depid;
};
Boss::~Boss()
{

};

void Boss::showInfo() {
	cout << "职工编号是" << this->m_id
		<< "\t职工姓名" << this->m_name
		<< "\t岗位:" << this->m_DepId
		<< "\t岗位职责:管理公司所有事" << endl;
};

string Boss::getDep() {

	return string("CEO");
};