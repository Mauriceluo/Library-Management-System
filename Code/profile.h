/*
����ѧ��/��ʦ����
*/
#ifndef PROFILE_H_
#define PROFILE_H_
#include "header.h"

class User {
private:
	string name;        //����
	string ID;          //����֤��
	string academy;     //ѧԺ
	int authority;      //Ȩ��Ϊ0--��ʦ��Ȩ��Ϊ1--ѧ��
	int lent_number;    //�ѽ�����Ŀ
	double money_delay; //��Ƿ���
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
