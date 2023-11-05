#include "workerManager.h"


WorkerManager::WorkerManager() {
	fstream file;
	file.open(FILENAME, ios::in);
	//�ļ������ڣ�Ҳ���Ǵ�ʧ����
	//1.�ļ�������(û�д���)������µĳ�ʼ��--------------==---------------------------------------
	if (!file.is_open()) {
		cout << "�ļ�������" << endl;
		this->member = 0;
		this->fileisempty = true;
		this->stuffArray = NULL;
		file.close();
		return;
	}

	//2.�ļ����ڵ���Ϊ�յ�����µĳ�ʼ��--------------==---------------------------------------
	//������ж��ļ�����Ϊ����EOF
	char ch;
	//.eof�������жϵ��ļ��Ƿ����ĩβ
	file >> ch;
	//��ȡһ�»���һ��eof״̬
	if (file.eof()) {
		 //˵���ļ�Ϊ��
		cout << "�ļ�Ϊ��" << endl;
		this->member = 0;
		this->fileisempty = true;
		this->stuffArray = NULL;
		file.close();
		return;
	}

	//�ļ�Ϊ�ջ����ļ������ڵ�����³�ʼ��Ϊ��������ô��д�����ݺ�Ӧ�ð�fileisempty����Ϊfalse



	//��ʼ��һ�³�Ա����
	//�϶�����ÿ�ζ���ʼΪ�������
//	this->member = 0;
//	this->stuffArray = NULL;

	int num = this->getEmpNum();
	//���Դ���
	cout << "ְ������Ϊ" << num << endl;
	//���³�Ա����
	this->member = num;
	//3.�ļ������Ҳ�Ϊ��=���������ļ����ݵ�����µĳ�ʼ��--------------==---------------------------------------
	//�ȿ��ٿռ䣬���ļ����е����ݴ洢�������У�Ҳ������ν�ĳ�ʼ��
	this->stuffArray = new Worker *[this->member];
	this->init_emp();
	
	//���Դ���
	for (int i = 0; i < this->member; i++)
	{
		cout << "ְ�����:" << this->stuffArray[i]->m_id
			<< "������" << this->stuffArray[i]->m_name
			<< "���ű�ţ�" << this->stuffArray[i]->m_DepId << endl;
	}


}


WorkerManager::~WorkerManager() {
	//if (this->stuffArray != NULL)//˵���������ڵĶ�����û���ֶ��ͷ�
	//{
	//	delete[] this->stuffArray;
	//	//�������ֶ����٣��ֶ��ͷ�
	//	this->stuffArray = NULL;
	//}
	//�°汾��,һ�������Ԫ��Ҳ���ڶ������ٵģ���ô����delete���������ͷŲ��ɾ��ģ�
	if (this->stuffArray != NULL)//˵���������ڵĶ�����û���ֶ��ͷ�
	{
		for (int i = 0; i < this->member; i++)
		{
			if (this->stuffArray[i] != NULL)
				delete this->stuffArray[i];
		}
		delete[] this->stuffArray;
		//�������ֶ����٣��ֶ��ͷ�
		this->stuffArray = NULL;
	}

}

void WorkerManager::showMenu()
{
	cout << "			ְ������ϵͳ			" << endl;
	cout << "			0.�˳�ϵͳ			" << endl;
	cout << "			1.����ְ��			" << endl;
	cout << "			2.��ʾְ��			" << endl;
	cout << "			3.ɾ��ְ��			" << endl;
	cout << "			4.�޸�ְ��			" << endl;
	cout << "			5.����ְ��			" << endl;
	cout << "			6.�������			" << endl;
	cout << "			7.���ְ��			" << endl;
}

void WorkerManager::exitSystem() {
	cout << "��ӭ�´�ʹ��Ӵ" << endl;
	system("pause");
	exit(0);
	//exit(0);�ڴ��������λ�ö����Դ��ڣ���ʾ�����˳�����
	//exit(0)��һ��������ֹ����ĺ�����������ִ�е�exit(0)ʱ�����������˳������ҷ���һ��״̬��0������ϵͳ��
	//״̬��0ͨ����ʾ��������������
}


void WorkerManager::add_stuff() {
	cout << "��Ҫ���ְ���������Ƕ����أ�" << endl;
	int addnum = 0;
	cin >> addnum;

	if (addnum > 0)
	{
		//����ռ��С
		int newsize = this->member + addnum;

		//�����µĿռ�
		Worker** newspace = new Worker*[newsize];

		//ԭ���ڴ�����ݷŵ��¼���
		if (this->stuffArray != NULL)//�ɼһ�����
		{
			//�����ϼң���ÿһ���˷ŵ��¼���
			for (int i = 0; i < this->member; i++)
			{
				newspace[i] = this->stuffArray[i];
			}
		}

		//����µ���
		for (int i = 0; i < addnum; i++)
		{
			int id;
			string name;
			int depselect;

			cout << "�������" << i + 1 << "����Ա����ְ�����" << endl;
			cin >> id;

			cout << "�������" << i + 1 << "����Ա����ְ������" << endl;
			cin >> name;

			cout << "��ѡ���ְ���ĸ�λ" << endl;
			cout << "1:��ְͨ��" << endl;
			cout << "2:����" << endl;
			cout << "3:Bosss����" << endl;
			cin >> depselect;

			//��ΪWorker�ǳ����࣬û��Ĭ�Ϲ��캯��������NULL
			Worker* fatherPoint = NULL;
			switch (depselect)
			{
			case 1://��ͨԱ��
				fatherPoint = new Employee(id, name, depselect);
				break;
			case 2://����
				fatherPoint = new Manager(id, name, depselect);
				break;
			case 3://Boss
				fatherPoint = new Boss(id, name, depselect);
				break;
			default:
				break;
			}
			 
			//��������Worker*��ӵ���������������Ǵ�ͷ��ӣ��Ժ��Ǵӵ�ǰλ�����
			newspace[this->member + i] = fatherPoint;
		}
		//forѭ������

		//�ͷŵ��ϵķ��Ӱɣ��Ҿ߶�������
		delete[] this->stuffArray;

		//���������·��ӵ�����
		this->member = newsize;

		//�Ѽ�ͥ��ַ���ָ���޸�Ϊ���ڵ��¼ҿ�
		this->stuffArray = newspace;

		//д���ļ���
		this->save();
		//����fileisempty��ֵ��
		this->fileisempty = false;



		cout << "�ɹ������" << addnum << "����Ա��" << endl;
		

	}
	else
	{
		cout << "�������" << endl;
	}

	//�ȴ��û������������������!
	system("pause");

	system("cls");
}



void WorkerManager::save() {

	fstream file;
	file.open(FILENAME, ios::out);
	//file << "ְ�����		ְ������		ְ����λ" << endl;

	for (int i = 0; i < this->member; i++)
	{
		file << this->stuffArray[i]->m_id << "			"
			<< this->stuffArray[i]->m_name << "			"
			<< this->stuffArray[i]->m_DepId << "		" << endl;

	}
	file.close();
}

int WorkerManager::getEmpNum(){
	fstream file;
	file.open(FILENAME, ios::in);

	int id;
	string name;
	int dep;
	int num = 0;

	//string line;
	//getline(file, line);
	//��ȡ��������һ��
	//file��ifstream�����(��i/fstream������������������cin�������е������������ܶ�����
	//cin>>�ڶ�ȡ��ʱ��Ĭ���Կո�tab,����Ϊ�ָ�����file>>Ҳһ����
	while (file >> id && file >> name && file >> dep)
	{
		num++;
	};

	file.close();
	return num;

}

//��ʼ�����ǵ�ְ������
void WorkerManager::init_emp()
{
	fstream file;
	file.open(FILENAME, ios::in);

	int id;
	string name;
	int depid;
	//��Ҫ��һ��,��ͷ
	//string line;
	//file >> line;

	int index = 0;
	while (file >> id && file >> name&&file>>depid)
	{
		//��������ָ��,��ʼ���̬
		//Worker�ǳ����࣬û��Ĭ�Ϲ��캯��
		Worker* fatherpoint = NULL;
		if (depid == 1)
		{
			fatherpoint = new Employee(id, name, depid);
		}
		else if (depid == 2)
		{
			fatherpoint = new Manager(id, name, depid);
		}
		else//CEO
		{
			fatherpoint = new Boss(id, name, depid);
		}
		//�ѵõ�������һ����̬������洢��������
		this->stuffArray[index] = fatherpoint;
		//����+1;
		index++;

	}

}


void WorkerManager::show_stuff() {
	if (this->fileisempty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < this->member; i++)
		{
			this->stuffArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}


int WorkerManager::IsExit(int id) {
	//�ҵ����ҵ����ȸ�ֵΪû�ҵ�..
	int index = -1;
	for (int i = 0; i < this ->member; i++)
	{
		if (this->stuffArray[i]->m_id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}


void  WorkerManager::del_stuff() {

	if (this->fileisempty)
	{
		cout << "�ļ�Ϊ��" << endl;

	}
	else
	{
		cout << "������Ҫɾ��ְ���ı��" << endl;
		int id;
		cin >> id;
		int index = this->IsExit(id);
		if ( index!= -1)//˵���ҵ����ְ���˲��ҷ����˶�Ӧ��index
		{
			//ɾ�����Ǵ�Ҫɾ����λ�ÿ�ʼ�����������ǰŲһ��λ��
			for (int i = index; i < this->member - 1; i++)
			{
				this->stuffArray[i] = this->stuffArray[i + 1];
			}
			//ɾ����ϣ�����һ��Ա���ܸ������ļ�����
			cout << "ɾ���ɹ����ӽ���������Ҳ���������ˣ�" << endl;

			this->member--;
			this->save();
		}
		else
		{
			cout << "��Ǹ��û�ҵ����ְ����" << endl;
		}

		system("pause");
		system("cls");



	}

}


void  WorkerManager::mod_stuff() {

	if (this->fileisempty)
	{
		cout << "�ļ�Ϊ��" << endl;

	}
	else
	{
		cout << "������Ҫ�޸�ְ���ı��" << endl;
		int id;
		cin >> id;
		int index = this->IsExit(id);
		if (index != -1)//˵���ҵ����ְ���˲��ҷ����˶�Ӧ��index
		{
			//��Ϊ��������Worker*��һ��ָ�룬����Ҫָ����һ���ط���
			delete this->stuffArray[index];

			int id;
			string name;
			int depselect;

			cout << "�������µ�ְ�����" << endl;
			cin >> id;

			cout << "�������µ�ְ������" << endl;
			cin >> name;

			cout << "��ѡ����¸�ְ���ĸ�λ" << endl;
			cout << "1:��ְͨ��" << endl;
			cout << "2:����" << endl;
			cout << "3:Bosss����" << endl;
			cin >> depselect;

			//��ΪWorker�ǳ����࣬û��Ĭ�Ϲ��캯��������NULL
			Worker* fatherPoint = NULL;
			switch (depselect)
			{
			case 1://��ͨԱ��
				fatherPoint = new Employee(id, name, depselect);
				break;
			case 2://����
				fatherPoint = new Manager(id, name, depselect);
				break;
			case 3://Boss
				fatherPoint = new Boss(id, name, depselect);
				break;
			default:
				break;
			}

			this->stuffArray[index] = fatherPoint;



			//�޸���ϣ�����һ��Ա���ܸ������ļ�����
			cout << "�޸ĳɹ����ӽ�������������һ�ַ�ʽ��������ߣ�" << endl;

			this->save();
		}
		else
		{
			cout << "��Ǹ��û�ҵ����ְ����" << endl;
		}

		system("pause");
		system("cls");



	}





}


void WorkerManager::find_stuff() {

	if (this->fileisempty)
	{
		cout << "�ļ�Ϊ��" << endl;

	}
	else
	{
		cout << "ѡ����Ҫ���ҵķ�ʽ" << endl;
		cout << "1 : ����ְ���ı�Ų���" << endl;
		cout << "2 : ����ְ�������ֲ���" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)//����ְ����Ų���
		{
			int id;
			cout << "������Ҫ����ְ���ı��ID" << endl;

			cin >> id;


			int temp = this->IsExit(id);
			if (temp != -1)//�ҵ���
			{
				this->stuffArray[temp]->showInfo();
			}
			else
			{
				cout << "���ˣ��Ҳ��������" << endl;
			}

		}
		else if (select == 2)
		{
			string name;
			cout << "������Ҫ����ְ��������Name" << endl;
			cin.ignore();
			getline(cin, name);
			bool flag = false;
			for (int i = 0; i < this->member; i++)
			{
				if (this->stuffArray[i]->m_name == name)//�ҵ���
				{
					flag = true;
					this->stuffArray[i]->showInfo();
					break;
				}
			}
			if (!flag)
			{
				cout << "�����������ˣ�û���ţ�" << endl;

			}
		}
		else
		{
			cout << "��������б�Ĳ��ҷ�ʽ����д��" << endl;
		}
	}
	system("pause");
	system("cls");
}


void  WorkerManager ::sort_stuff() {


	if (this->fileisempty)
	{
		cout << "�ļ�Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "����Ҫѡ����һ�������أ�" << endl;
		cout << "1.���ձ������" << endl;
		cout << "2.���ձ�Ž���" << endl;
		int select;
		int temp;
		cin >> select;

		for (int i = 0; i < this->member - 1; i++)
		{
			for (int j = i; j < this->member - i - 1; j++)
			{
				if (select == 1)
				{
					if (this->stuffArray[j]->m_id > this->stuffArray[j + 1]->m_id)
					{
						temp = this->stuffArray[j]->m_id;
						this->stuffArray[j]->m_id = this->stuffArray[j + 1]->m_id;
						this->stuffArray[j + 1]->m_id = temp;
					}
				}
				else
				{
					if (this->stuffArray[j]->m_id < this->stuffArray[j + 1]->m_id)
					{
						temp = this->stuffArray[j]->m_id;
						this->stuffArray[j]->m_id = this->stuffArray[j + 1]->m_id;
						this->stuffArray[j + 1]->m_id = temp;
					}
				}
			}

		}

		cout << "����ɹ��������Ľ����" << endl;
		//�����ļ�������
		this->save();
		this->show_stuff();
	}

}


void WorkerManager::clean_stuff() {

	//��ֹ�������
	cout << "?���Ҫ�������ְ��ϵͳ��" << endl;
	cout << "1:ȷ�����Ҿ�Ҫ���������ϵͳ" << endl;
	cout << "2����Ҫ�������㣬�Ұ�����T_T" << endl;
	int select;
	cin >> select;

	if (select == 1)
	{
		fstream file;
		file.open(FILENAME, ios::trunc);
		//truc��ʾ�����Դ�ļ����ھ�ɾ����
		file.close();


		//���Ƕ�������һ������ݻ�û���ͷ��أ�

		//�ƺ����

		for (int i = 0; i < this->member; i++)
		{
			if(this->stuffArray[i]!=NULL)
			delete this->stuffArray[i];
			//�ͷ��������ÿһ���ڶ������ٵ��ڴ�
		}

		delete[]this->stuffArray;
		this->stuffArray = NULL;

		this->fileisempty = true;
		this->member = 0;
		cout << "CLEAN�ɹ�������" << endl;

		system("pause");
		system("cls");
	}
	else
	{
		system("pause");
		system("cls");
	}



}

