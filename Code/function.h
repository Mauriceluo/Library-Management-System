#ifndef FUNCTION_H_
#define FUNCTION_H_

#include"profile.h"
#include"book.h"
#include"additional.h"

#define MAX_STU_LENT_NUM 2  //学生最多能借多少本书
#define MAX_OWE_MONEY 20    //最大欠费，高于视为不诚实

bool isFileEmpty(fstream &f);
void LoadInfo(ifstream &book_f, vector<Book> &books);
void LoadInfo(fstream &book_f, vector<Book> &books);
void LoadInfo(ifstream &user_f, vector<User> &users, int n);
void LoadInfo(fstream &user_f, vector<User> &users);
void LoadInfo(ifstream &addinfo, vector<additional> &add, char c);
void WriteInfo(ofstream &book_f, vector<Book> books);
void WriteInfo(ofstream &user_f, vector<User> user, int n);
void WriteInfo(ofstream &addinfo, vector<additional> add, char c);

void operation(vector<Book> &book, vector<User> &user, vector<additional> &addinfo, Time &now, ofstream &journal);
void gotoxy(int x, int y);
int login(vector<User> user);
void ShowMenu1(int n);
void ShowInfo(int n, vector<Book> book, vector<User> user);
void ShowInfo(User user, vector<Book> book, additional addinfo);
bool All_Patch(string a, vector<string> b);
int kmp(string str, string substr, vector<int> &next);
void getNext(string substr, vector<int> &next);
int Search_ISBN(string isbn, vector<Book> book);
int Search_name(string name, vector<Book> book);
vector<int> Search_author(string author, vector<Book> book);
vector<int> Search_publisher(string publisher, vector<Book> book);
vector<int> Search_name_vague(vector<string> name, vector<Book> book);
vector<int> Search_name_KMP(string name, vector<Book> book);
vector<int> Search_author_vague(string author, vector<Book> book);
vector<int> Search_publisher_vague(string publisher, vector<Book> book);
int Search_ID(string ID, vector<User> user);
vector<int> Search(vector<Book> book);

void AddBook(vector<Book> &book, ofstream &journal, Time now);
void ChangeNum(vector<Book> &book, ofstream &journal, Time now);
bool IsHonest(vector<User> user);
void Borrow(Book &book, User &user,additional &addinfo,Time now, ofstream &journal);
void order(additional &addinfo, Book book);
void returnbook(Book &book, User &user, additional &addinfo, Time now, ofstream &journal);
void cancel_order(additional &addinfo, int n);

#endif
