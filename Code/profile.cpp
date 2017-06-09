#include "function.h"

User::User()
{
}

User::~User()
{
	//cout << "hahah";
}

User::User(string name_, string ID_, string academy_, int authority_, int lent_number_,double money_delay_)
{
	name = name_;
	ID = ID_;
	academy = academy_;
	authority = authority_;
	lent_number = lent_number_;
	money_delay = money_delay_;
}
