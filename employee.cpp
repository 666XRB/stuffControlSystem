#include "employee.h"


Employee::Employee(int id,string name,int depid) {
	this->m_id = id;
	this->m_name = name;
	this->m_DepId = depid;
};

Employee::~Employee() {

};

void Employee::showInfo() {
	cout << "职工编号是" << this->m_id
		<< "\t职工姓名" << this->m_name
		<< "\t岗位:" << this->m_DepId
		<< "\t岗位职责:完成经理交给的任务" << endl;
};

string Employee::getDep() {

	//return "员工";
	return string("员工");
	//c字符串转化为c++的字符串
};