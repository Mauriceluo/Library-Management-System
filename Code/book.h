/*
���������
*/
#ifndef BOOK_H_
#define BOOK_H_
#include "header.h"

class Book {
private:
	string ID;            //ͼ����룬Ҫ�Զ�����
	string ISBN;          //ISBN
	string name;          //����
	string author;        //����
	string publisher;     //������
	string introduction;  //���
	string bought_time;   //����ʱ��
	int origin_num;		  //���������
	int remain_num;       //����
public:
	Book();
	~Book();
	Book(string ID_, string ISBN_, string name_, string author_, string publisher_, string introduction_, string bought_time_, int origin_num_, int remain_num_);
	string get_ID() { return ID; }
	string get_ISBN() { return ISBN; }
	string get_name() { return name; }
	string get_author() { return author; }
	string get_publisher() { return publisher; }
	string get_introduction() { return introduction; }
	string get_bought_time() { return bought_time; }
	int get_origin_num() { return origin_num; }
	int get_remain_num() { return remain_num; }

	bool isForeign();
	void ShowAllInfo();
	
	void set_remain_num(int n) { remain_num = n; }
}; 

#endif