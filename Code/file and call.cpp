#include "function.h"

extern Time now(1);//��ȡ��ǰϵͳʱ��

int main()
{
	/*��ȡģʽ��Ĭ�����ã����ģʽ���µ��ļ�*/
	ifstream book_origin, user_origin, addition;
	ofstream journal;
	fstream book_current, user_current;

	book_origin.open("book_origin.ini", ios::in);
	user_origin.open("user_origin.ini", ios::in);
	addition.open("additional.ini", ios::in);

	book_current.open("book_current.ini");
	user_current.open("user_current.ini");
	journal.open("journal.log", ios::app);

	/*������д���ڴ�*/
	vector<Book> books;
	vector<User> users;
	vector<additional> addinfo;

	if (isFileEmpty(book_current))
	{//���޲�������ȡĬ������
		cout << "������ȡĬ����Ŀ����...\n";
		LoadInfo(book_origin, books);
		cout << "Ĭ����Ŀ���ö�ȡ��ɣ�\n";
		book_origin.close();//��ȡ���ڴ��ر��ļ�
	}

	else
	{//���в�������ȡ��ǰ����
		cout << "������ȡ��ǰ��Ŀ����...\n";
		LoadInfo(book_current, books);
		cout << "��ǰ��Ŀ���ö�ȡ��ɣ�\n";
		book_current.close();
	}

	if (isFileEmpty(user_current))
	{//���޲�������ȡĬ������
		cout << "\n������ȡĬ���û�����...\n";
		LoadInfo(user_origin, users, 0);
		cout << "Ĭ����Ŀ���ö�ȡ��ɣ�\n";
		user_origin.close();//��ȡ��ɺ�ر��ļ�
	}

	else
	{//���в�������ȡ��ǰ����
		cout << "\n������ȡ��ǰ�û�����...\n";
		LoadInfo(user_current, users);
		cout << "��ǰ�û����ö�ȡ��ɣ�\n";
		user_current.close();
	}

	//��ȡ������Ϣ�������Ѿ��������Ԥ������Ϣ
	cout << "\n������ȡ������Ϣ...\n";
	LoadInfo(addition, addinfo, 'c');
	cout << "������Ϣ��ȡ��ɣ�\n";
	addition.close();

	/*�û���ʾ��Ϣ*/
	cout << "\n��������ͼ���ϵͳ...\n";
	system("pause");
	system("cls");

	cout << "--------------------------ͼ�������-------------------------\n";
	cout << "1����ʱ�黹ͼ�飬Υ�߷���1Ԫ/��\n";
	cout << "2��ѧ��ֻ�ܽ�" << MAX_STU_LENT_NUM << "���飬��ֻ�ܽ����ĵ��鼮����ʦ�͹���Ա�޽�������\n";
	cout << "3��ԤԼͼ���ٴ����߼��ɿ���֪ͨ\n";
	cout << "4������ͼ��ʱ��һ��Ϊһ������\n";
	cout << "5����Ƿ������" << MAX_OWE_MONEY << "Ԫ��Ϊ������\n";
	gotoxy(100, 25);
	now.show();
	system("pause");
	system("cls");

	/*����*/
	operation(books, users, addinfo, now, journal);
	system("cls");

	/*�û��˳���������Ϣд��current�ļ�*/
	ofstream book_now("book_current.ini", ios::trunc);
	ofstream user_now("user_current.ini", ios::trunc);
	ofstream addinfo_now("additional.ini", ios::trunc);

	WriteInfo(book_now, books);
	cout << "��Ŀ�����Ѿ����浽\"book_current.ini\"\n";
	book_now.close();

	WriteInfo(user_now, users, 0);
	cout << "�û������Ѿ����浽\"user_current.ini\"\n";
	user_now.close();

	WriteInfo(addinfo_now, addinfo, 'c');
	cout << "���������Ѿ����浽\"addtional.ini\"\n";
	addinfo_now.close();
	journal.close();

	system("pause");
	return 0;
}