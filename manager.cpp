#include "manager.h"



Manager::Manager(int id, string name, int depid) {
	this->m_id = id;
	this->m_name = name;
	this->m_DepId = depid;
};
Manager::~Manager() {


};


string Manager::getDep() {
	return string("经理");
};

void Manager::showInfo() {
	cout << "职工编号:" << this->m_id
		<< "\t职工姓名:" << this->m_name
		<< "\t职工岗位:" << this->m_DepId
		<< "\t职工职责是完成老板交给的任务，下发给员工" << endl;
};

