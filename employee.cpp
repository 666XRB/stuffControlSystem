#include "employee.h"


Employee::Employee(int id,string name,int depid) {
	this->m_id = id;
	this->m_name = name;
	this->m_DepId = depid;
};

Employee::~Employee() {

};

void Employee::showInfo() {
	cout << "ְ�������" << this->m_id
		<< "\tְ������" << this->m_name
		<< "\t��λ:" << this->m_DepId
		<< "\t��λְ��:��ɾ�����������" << endl;
};

string Employee::getDep() {

	//return "Ա��";
	return string("Ա��");
	//c�ַ���ת��Ϊc++���ַ���
};