#include "manager.h"



Manager::Manager(int id, string name, int depid) {
	this->m_id = id;
	this->m_name = name;
	this->m_DepId = depid;
};
Manager::~Manager() {


};


string Manager::getDep() {
	return string("����");
};

void Manager::showInfo() {
	cout << "ְ�����:" << this->m_id
		<< "\tְ������:" << this->m_name
		<< "\tְ����λ:" << this->m_DepId
		<< "\tְ��ְ��������ϰ彻���������·���Ա��" << endl;
};

