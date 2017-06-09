#include "function.h"

extern Time now(1);//获取当前系统时间

int main()
{
	/*读取模式打开默认配置，输出模式打开新的文件*/
	ifstream book_origin, user_origin, addition;
	ofstream journal;
	fstream book_current, user_current;

	book_origin.open("book_origin.ini", ios::in);
	user_origin.open("user_origin.ini", ios::in);
	addition.open("additional.ini", ios::in);

	book_current.open("book_current.ini");
	user_current.open("user_current.ini");
	journal.open("journal.log", ios::app);

	/*将数据写入内存*/
	vector<Book> books;
	vector<User> users;
	vector<additional> addinfo;

	if (isFileEmpty(book_current))
	{//尚无操作，读取默认配置
		cout << "即将读取默认书目设置...\n";
		LoadInfo(book_origin, books);
		cout << "默认书目设置读取完成！\n";
		book_origin.close();//读取到内存后关闭文件
	}

	else
	{//已有操作，读取当前配置
		cout << "即将读取当前书目设置...\n";
		LoadInfo(book_current, books);
		cout << "当前书目设置读取完成！\n";
		book_current.close();
	}

	if (isFileEmpty(user_current))
	{//尚无操作，读取默认配置
		cout << "\n即将读取默认用户设置...\n";
		LoadInfo(user_origin, users, 0);
		cout << "默认书目设置读取完成！\n";
		user_origin.close();//读取完成后关闭文件
	}

	else
	{//已有操作，读取当前配置
		cout << "\n即将读取当前用户设置...\n";
		LoadInfo(user_current, users);
		cout << "当前用户设置读取完成！\n";
		user_current.close();
	}

	//读取附加信息，包括已经借书或者预定的信息
	cout << "\n即将读取附加信息...\n";
	LoadInfo(addition, addinfo, 'c');
	cout << "附加信息读取完成！\n";
	addition.close();

	/*用户提示信息*/
	cout << "\n即将进入图书馆系统...\n";
	system("pause");
	system("cls");

	cout << "--------------------------图书馆守则-------------------------\n";
	cout << "1、按时归还图书，违者罚款1元/天\n";
	cout << "2、学生只能借" << MAX_STU_LENT_NUM << "本书，且只能借中文的书籍，教师和管理员无借阅限制\n";
	cout << "3、预约图书再次上线即可看到通知\n";
	cout << "4、借阅图书时间一律为一个星期\n";
	cout << "5、拖欠书款大于" << MAX_OWE_MONEY << "元视为不诚信\n";
	gotoxy(100, 25);
	now.show();
	system("pause");
	system("cls");

	/*操作*/
	operation(books, users, addinfo, now, journal);
	system("cls");

	/*用户退出，所有信息写入current文件*/
	ofstream book_now("book_current.ini", ios::trunc);
	ofstream user_now("user_current.ini", ios::trunc);
	ofstream addinfo_now("additional.ini", ios::trunc);

	WriteInfo(book_now, books);
	cout << "书目数据已经保存到\"book_current.ini\"\n";
	book_now.close();

	WriteInfo(user_now, users, 0);
	cout << "用户数据已经保存到\"user_current.ini\"\n";
	user_now.close();

	WriteInfo(addinfo_now, addinfo, 'c');
	cout << "附加数据已经保存到\"addtional.ini\"\n";
	addinfo_now.close();
	journal.close();

	system("pause");
	return 0;
}