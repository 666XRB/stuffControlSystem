#pragma once
#include <iostream>
#include <string>

using namespace std;

class Worker {
public:
	//��ʾְ���ĸ�����Ϣ
	virtual void showInfo() = 0;
	//��ʾְ���Ĳ���
	virtual string getDep() = 0;
	//�����ʵ�����������д������


//�����಻��ʵ����������˵���캯��Ҳû������

	int m_id;
	string m_name;
	int m_DepId;
};