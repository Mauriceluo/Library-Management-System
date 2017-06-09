#ifndef ADDITIONAL_H_
#define ADDITIONAL_H_
#include"header.h"
#include"book.h"
#include"profile.h"

class Time {
private:
	int year = 0;
	int month = 0;
	int day = 0;
public:
	Time();
	~Time();
	Time(int year_, int month_, int day_);
	Time(int n);

	int get_year() { return year; }
	int get_month() { return month; }
	int get_day() { return day; }

	void set_time(int year_, int month_, int day_);

	int get_absdays(Time a);
	int get_minus(Time a, Time b);//b-a
	bool compare(Time a, Time b);//a�Ƿ����b
	bool is_leap();
	void tomorrow();
	void show();
};




class additional {//��������ε����磬�����������˽��鵥�����ã�ԭ��������һ���ڵ�������ʦ��͸��˴�
private:          //˳������һ��ԤԼ����
	string ID;
	int borrowed_num = 0;
	vector<Time> borrow;
	vector<string> borrowed_ISBN;
	int wanted_num = 0;
	vector<string> wanted_ISBN;
public:
	additional();
	~additional();
	additional(string ID_, int borrowed_num_, vector<Time> borrow_, vector<string> borrowed_ISBN_, int wanted_num_, vector<string> wanted_ISBN_);

	string get_ID() { return ID; }
	int get_borrowed_num() { return borrowed_num; }
	vector<Time> get_borrow_time() { return borrow; }
	vector<string> get_borrowed_ISBN() { return borrowed_ISBN; }
	int get_wanted_num() { return wanted_num; }
	vector<string> get_wanted_ISBN() { return wanted_ISBN; }

	void set_borrowed_num(int n) { borrowed_num = n; }
	void set_borrow_time(vector<Time> n) { borrow = n; }
	void set_borrowed_ISBN(vector<string> n) { borrowed_ISBN = n; }
	void set_wanted_num(int n) { wanted_num = n; }
	void set_wanted_ISBN(vector<string> n) { wanted_ISBN = n; }

};

#endif