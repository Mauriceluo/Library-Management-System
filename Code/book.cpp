#include "function.h"

Book::Book()
{
}

Book::~Book()
{
}

Book::Book(string ID_, string ISBN_, string name_, string author_, string publisher_, string introduction_, string bought_time_, int origin_num_, int remain_num_)
{
	ID = ID_;
	ISBN = ISBN_;
	name = name_;
	author = author_;
	publisher = publisher_;
	introduction = introduction_;
	bought_time = bought_time_;
	origin_num = origin_num_;
	remain_num = remain_num_;
}

bool Book::isForeign()
{
	string a = author;
	if (a[0] == '(' || a[0] == '[')
		return true;
	return false;
}

void Book::ShowAllInfo()
{
	double percent = (double)(origin_num - remain_num) / origin_num;
	cout << "������" << name << "\tISBN��" << ISBN << "\t���ߣ�" << author << "\t�����磺" << publisher << "\t���ܣ�" << introduction << "\t����ʱ�䣺" << bought_time << "\tʣ�౾����" << remain_num << "\t�����ʣ�" << setiosflags(ios::fixed) << setprecision(2) << percent * 100 << "%" << endl;
}
