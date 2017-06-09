#include "function.h"

Time::Time()
{
}

Time::~Time()
{
	//cout << "ha ";
}

Time::Time(int year_, int month_, int day_)
{
	year = year_;
	month = month_;
	day = day_;
}

Time::Time(int n)
{
	time_t tt = time(NULL);//这句返回的只是一个时间cuo
	tm* t = localtime(&tt);
	year = t->tm_year + 1900;
	month = t->tm_mon+1;
	day = t->tm_mday;
}

int Time::get_absdays(Time a)
{
	int i;
	int month_day[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int year = a.get_year() - 1;
	int days = year * 365 + year / 4 - year / 100 + year / 400;
	if (a.get_year() % 4 == 0 && a.get_year() % 100 != 0 || a.get_year() % 400 == 0) 
		month_day[1]++;
	for (i = 0; i<a.get_month() - 1; i++)
		days += month_day[i];
	days += a.get_day() - 1;
	return days;
}

int Time::get_minus(Time a, Time b)
{
	return get_absdays(b) - get_absdays(a);
}

bool Time::compare(Time a, Time b)
{
	if (a.get_absdays(a) > b.get_absdays(b))
		return true;
	return false;
}

bool Time::is_leap()
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return true;
	return false;
}

void Time::tomorrow()
{
	if (month == 2 && day == 28 && !is_leap())
	{
		day = 1;
		month = 3;
	}
	else if (month == 2 && day == 29)
	{
		day = 1;
		month = 3;
	}
	else if (month == 12 && day == 31)
	{
		year += 1;
		month = 1;
		day = 1;
	}
	else if ((month == 1 && day == 31) || (month == 3 && day == 31) || (month == 5 && day == 31) || (month == 7 && day == 31) || (month == 8 && day == 31) || (month == 10 && day == 31))
	{
		month += 1;
		day = 1;
	}
	else if ((month == 4 && day == 30) || (month == 6 && day == 30) || (month == 9 && day == 30) || (month == 11 && day == 30))
	{
		month += 1;
		day = 1;
	}
	else
		day += 1;
}

void Time::show()
{
	cout << year << "-" << month << "-" << day << endl;
}

void Time::set_time(int year_, int month_, int day_)
{
	year = year_;
	month = month_;
	day = day_;
}

additional::additional()
{
}

additional::~additional()
{
}

additional::additional(string ID_, int borrowed_num_, vector<Time> borrow_, vector<string> borrowed_ISBN_, int wanted_num_,vector<string> wanted_ISBN_)
{
	ID = ID_;
	borrowed_num = borrowed_num_;
	borrow.swap(borrow_);
	borrowed_ISBN.swap(borrowed_ISBN_);
	wanted_num = wanted_num_;
	wanted_ISBN.swap(wanted_ISBN_);
}
