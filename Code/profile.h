/*
定义学生/老师的类
*/
#ifndef PROFILE_H_
#define PROFILE_H_
#include "header.h"

class User {
private:
	string name;        //姓名
	string ID;          //工作证号
	string academy;     //学院
	int authority;      //权限为0--老师，权限为1--学生
	int lent_number;    //已借书数目
	double money_delay; //已欠书款
public:
	User();
	~User();
	User(string name_, string ID_, string academy_, int authority_, int lent_number, double money_delay);
	string get_name() { return name; }
	string get_ID() { return ID; }
	string get_academy() { return academy; }
	int get_authority() { return authority; }
	int get_lent_number() { return lent_number; }
	double get_money_delay() { return money_delay; }
	
	void set_lent_number(int n) { lent_number = n; }
	void set_money_delay(double n) { money_delay = n; }
};


#endif
