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
	cout << "ְ�������" << this->m_id
		<< "\tְ������" << this->m_name
		<< "\t��λ:" << this->m_DepId
		<< "\t��λְ��:����˾������" << endl;
};

string Boss::getDep() {

	return string("CEO");
};