#include "workerManager.h"


WorkerManager::WorkerManager() {
	fstream file;
	file.open(FILENAME, ios::in);
	//文件不存在，也就是打开失败了
	//1.文件不存在(没有创建)的情况下的初始化--------------==---------------------------------------
	if (!file.is_open()) {
		cout << "文件不存在" << endl;
		this->member = 0;
		this->fileisempty = true;
		this->stuffArray = NULL;
		file.close();
		return;
	}

	//2.文件存在但是为空的情况下的初始化--------------==---------------------------------------
	//先如何判断文件内容为空呢EOF
	char ch;
	//.eof方法回判断当文件是否读到末尾
	file >> ch;
	//读取一下会有一个eof状态
	if (file.eof()) {
		 //说明文件为空
		cout << "文件为空" << endl;
		this->member = 0;
		this->fileisempty = true;
		this->stuffArray = NULL;
		file.close();
		return;
	}

	//文件为空或者文件不存在的情况下初始化为这样，那么当写入内容后应该吧fileisempty更新为false



	//初始化一下成员变量
	//肯定不能每次都初始为这个样子
//	this->member = 0;
//	this->stuffArray = NULL;

	int num = this->getEmpNum();
	//测试代码
	cout << "职工个数为" << num << endl;
	//更新成员属性
	this->member = num;
	//3.文件存在且不为空=根据现有文件内容的情况下的初始化--------------==---------------------------------------
	//先开辟空间，将文件现有的数据存储到数组中，也就是所谓的初始化
	this->stuffArray = new Worker *[this->member];
	this->init_emp();
	
	//测试代码
	for (int i = 0; i < this->member; i++)
	{
		cout << "职工编号:" << this->stuffArray[i]->m_id
			<< "姓名：" << this->stuffArray[i]->m_name
			<< "部门编号：" << this->stuffArray[i]->m_DepId << endl;
	}


}


WorkerManager::~WorkerManager() {
	//if (this->stuffArray != NULL)//说明我们现在的堆区还没有手动释放
	//{
	//	delete[] this->stuffArray;
	//	//堆区，手动开辟，手动释放
	//	this->stuffArray = NULL;
	//}
	//新版本！,一个数组的元素也是在堆区开辟的，那么仅仅delete数组名是释放不干净的！
	if (this->stuffArray != NULL)//说明我们现在的堆区还没有手动释放
	{
		for (int i = 0; i < this->member; i++)
		{
			if (this->stuffArray[i] != NULL)
				delete this->stuffArray[i];
		}
		delete[] this->stuffArray;
		//堆区，手动开辟，手动释放
		this->stuffArray = NULL;
	}

}

void WorkerManager::showMenu()
{
	cout << "			职工管理系统			" << endl;
	cout << "			0.退出系统			" << endl;
	cout << "			1.增加职工			" << endl;
	cout << "			2.显示职工			" << endl;
	cout << "			3.删除职工			" << endl;
	cout << "			4.修改职工			" << endl;
	cout << "			5.查找职工			" << endl;
	cout << "			6.编号排序			" << endl;
	cout << "			7.清空职工			" << endl;
}

void WorkerManager::exitSystem() {
	cout << "欢迎下次使用哟" << endl;
	system("pause");
	exit(0);
	//exit(0);在代码的任意位置都可以存在，表示正常退出程序
	//exit(0)是一个用于终止程序的函数。当程序执行到exit(0)时，它会立即退出，并且返回一个状态码0给操作系统。
	//状态码0通常表示程序正常结束。
}


void WorkerManager::add_stuff() {
	cout << "咱要添加职工的数量是多少呢？" << endl;
	int addnum = 0;
	cin >> addnum;

	if (addnum > 0)
	{
		//计算空间大小
		int newsize = this->member + addnum;

		//开辟新的空间
		Worker** newspace = new Worker*[newsize];

		//原来内存的内容放到新家里
		if (this->stuffArray != NULL)//旧家还有人
		{
			//遍历老家，把每一个人放到新家里
			for (int i = 0; i < this->member; i++)
			{
				newspace[i] = this->stuffArray[i];
			}
		}

		//添加新的人
		for (int i = 0; i < addnum; i++)
		{
			int id;
			string name;
			int depselect;

			cout << "请输入第" << i + 1 << "个新员工的职工编号" << endl;
			cin >> id;

			cout << "请输入第" << i + 1 << "个新员工的职工姓名" << endl;
			cin >> name;

			cout << "请选择该职工的岗位" << endl;
			cout << "1:普通职工" << endl;
			cout << "2:经理" << endl;
			cout << "3:Bosss！！" << endl;
			cin >> depselect;

			//因为Worker是抽象类，没有默认构造函数，所以NULL
			Worker* fatherPoint = NULL;
			switch (depselect)
			{
			case 1://普通员工
				fatherPoint = new Employee(id, name, depselect);
				break;
			case 2://经理
				fatherPoint = new Manager(id, name, depselect);
				break;
			case 3://Boss
				fatherPoint = new Boss(id, name, depselect);
				break;
			default:
				break;
			}
			 
			//把这样的Worker*添加到数组里，但是现在是从头添加，以后是从当前位置添加
			newspace[this->member + i] = fatherPoint;
		}
		//for循环结束

		//释放掉老的房子吧，家具都搬走了
		delete[] this->stuffArray;

		//更新现在新房子的人数
		this->member = newsize;

		//把家庭地址这个指针修改为现在的新家咯
		this->stuffArray = newspace;

		//写在文件内
		this->save();
		//更新fileisempty的值！
		this->fileisempty = false;



		cout << "成功添加了" << addnum << "名新员工" << endl;
		

	}
	else
	{
		cout << "输入错误" << endl;
	}

	//等待用户按下任意键后再清屏!
	system("pause");

	system("cls");
}



void WorkerManager::save() {

	fstream file;
	file.open(FILENAME, ios::out);
	//file << "职工编号		职工姓名		职工岗位" << endl;

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
	//读取并丢弃第一行
	//file是ifstream类对象(从i/fstream类派生出来的类似于cin），所有的输入流对象功能都类似
	//cin>>在读取的时候默认以空格、tab,换行为分隔符，file>>也一样。
	while (file >> id && file >> name && file >> dep)
	{
		num++;
	};

	file.close();
	return num;

}

//初始化我们的职工数组
void WorkerManager::init_emp()
{
	fstream file;
	file.open(FILENAME, ios::in);

	int id;
	string name;
	int depid;
	//不要第一行,表头
	//string line;
	//file >> line;

	int index = 0;
	while (file >> id && file >> name&&file>>depid)
	{
		//创建父类指针,开始玩多态
		//Worker是抽象类，没有默认构造函数
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
		//把得到的这样一个多态的子类存储到数组里
		this->stuffArray[index] = fatherpoint;
		//索引+1;
		index++;

	}

}


void WorkerManager::show_stuff() {
	if (this->fileisempty)
	{
		cout << "文件不存在或记录为空" << endl;
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
	//找到不找到都先赋值为没找到..
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
		cout << "文件为空" << endl;

	}
	else
	{
		cout << "请输入要删除职工的编号" << endl;
		int id;
		cin >> id;
		int index = this->IsExit(id);
		if ( index!= -1)//说明找到这个职工了并且返回了对应的index
		{
			//删除就是从要删除的位置开始后面的依次往前挪一个位置
			for (int i = index; i < this->member - 1; i++)
			{
				this->stuffArray[i] = this->stuffArray[i + 1];
			}
			//删除完毕，更新一下员工总个数和文件内容
			cout << "删除成功！从今往后，你再也见不到他了！" << endl;

			this->member--;
			this->save();
		}
		else
		{
			cout << "抱歉，没找到这个职工捏" << endl;
		}

		system("pause");
		system("cls");



	}

}


void  WorkerManager::mod_stuff() {

	if (this->fileisempty)
	{
		cout << "文件为空" << endl;

	}
	else
	{
		cout << "请输入要修改职工的编号" << endl;
		int id;
		cin >> id;
		int index = this->IsExit(id);
		if (index != -1)//说明找到这个职工了并且返回了对应的index
		{
			//因为本质上是Worker*的一个指针，现在要指向另一个地方了
			delete this->stuffArray[index];

			int id;
			string name;
			int depselect;

			cout << "请输入新的职工编号" << endl;
			cin >> id;

			cout << "请输入新的职工姓名" << endl;
			cin >> name;

			cout << "请选择更新该职工的岗位" << endl;
			cout << "1:普通职工" << endl;
			cout << "2:经理" << endl;
			cout << "3:Bosss！！" << endl;
			cin >> depselect;

			//因为Worker是抽象类，没有默认构造函数，所以NULL
			Worker* fatherPoint = NULL;
			switch (depselect)
			{
			case 1://普通员工
				fatherPoint = new Employee(id, name, depselect);
				break;
			case 2://经理
				fatherPoint = new Manager(id, name, depselect);
				break;
			case 3://Boss
				fatherPoint = new Boss(id, name, depselect);
				break;
			default:
				break;
			}

			this->stuffArray[index] = fatherPoint;



			//修改完毕，更新一下员工总个数和文件内容
			cout << "修改成功！从今往后，他会以另一种方式陪在你身边！" << endl;

			this->save();
		}
		else
		{
			cout << "抱歉，没找到这个职工捏" << endl;
		}

		system("pause");
		system("cls");



	}





}


void WorkerManager::find_stuff() {

	if (this->fileisempty)
	{
		cout << "文件为空" << endl;

	}
	else
	{
		cout << "选择你要查找的方式" << endl;
		cout << "1 : 按照职工的编号查找" << endl;
		cout << "2 : 按照职工的名字查找" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)//按照职工编号查找
		{
			int id;
			cout << "请输入要查找职工的编号ID" << endl;

			cin >> id;


			int temp = this->IsExit(id);
			if (temp != -1)//找到啦
			{
				this->stuffArray[temp]->showInfo();
			}
			else
			{
				cout << "查了，找不到这个人" << endl;
			}

		}
		else if (select == 2)
		{
			string name;
			cout << "请输入要查找职工的名字Name" << endl;
			cin.ignore();
			getline(cin, name);
			bool flag = false;
			for (int i = 0; i < this->member; i++)
			{
				if (this->stuffArray[i]->m_name == name)//找到啦
				{
					flag = true;
					this->stuffArray[i]->showInfo();
					break;
				}
			}
			if (!flag)
			{
				cout << "按照姓名找了，没找着！" << endl;

			}
		}
		else
		{
			cout << "输入错误！有别的查找方式你来写！" << endl;
		}
	}
	system("pause");
	system("cls");
}


void  WorkerManager ::sort_stuff() {


	if (this->fileisempty)
	{
		cout << "文件为空" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "阁下要选择哪一种排序呢？" << endl;
		cout << "1.按照编号升序" << endl;
		cout << "2.按照编号降序" << endl;
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

		cout << "排序成功！排序后的结果是" << endl;
		//更新文件的内容
		this->save();
		this->show_stuff();
	}

}


void WorkerManager::clean_stuff() {

	//防止误操作！
	cout << "?真的要清除整个职工系统吗？" << endl;
	cout << "1:确定，我就要清空整个鸟系统" << endl;
	cout << "2：不要！，哒咩，我按错了T_T" << endl;
	int select;
	cin >> select;

	if (select == 1)
	{
		fstream file;
		file.open(FILENAME, ios::trunc);
		//truc表示：如果源文件存在就删掉！
		file.close();


		//但是堆区的那一大堆数据还没有释放呢！

		//善后操作

		for (int i = 0; i < this->member; i++)
		{
			if(this->stuffArray[i]!=NULL)
			delete this->stuffArray[i];
			//释放数组里的每一个在堆区开辟的内存
		}

		delete[]this->stuffArray;
		this->stuffArray = NULL;

		this->fileisempty = true;
		this->member = 0;
		cout << "CLEAN成功！！！" << endl;
		this->save();
		system("pause");
		system("cls");
	}
	else
	{
		system("pause");
		system("cls");
	}



}

