#include"function.h"

bool isFileEmpty(fstream &f)
{
	if (f.peek() == EOF)
		return true;
	return false;
}

void LoadInfo(ifstream &book_f, vector<Book> &books)
{
	string ID_b, ISBN, name, author, publisher, introduction, bought_time;
	int origin_num, remain_num;//����book�ı���

	while (!book_f.eof())
	{
		book_f >> ID_b >> ISBN >> name >> author >> publisher >> introduction >> bought_time >> origin_num >> remain_num;
		Book book_temp(ID_b, ISBN, name, author, publisher, introduction, bought_time, origin_num, remain_num);
		books.push_back(book_temp);
	}
}

void LoadInfo(fstream &book_f, vector<Book> &books)
{
	string ID_b, ISBN, name, author, publisher, introduction, bought_time;
	int remain_num, origin_num;//����book�ı���

	while (!book_f.eof())
	{
		book_f >> ID_b >> ISBN >> name >> author >> publisher >> introduction >> bought_time >> origin_num >> remain_num;
		Book book_temp(ID_b, ISBN, name, author, publisher, introduction, bought_time, origin_num, remain_num);
		books.push_back(book_temp);
	}
}

void LoadInfo(ifstream &user_f, vector<User> &users, int n)
{
	string name, ID_u, academy;
	int authority, lent_number;//����user����
	double money_delay;

	while (!user_f.eof())
	{
		user_f >> name >> ID_u >> academy >> authority >> lent_number >> money_delay;
		User user_temp(name, ID_u, academy, authority, lent_number, money_delay);
		users.push_back(user_temp);
	}
}

void LoadInfo(fstream &user_f, vector<User> &users)
{
	string name, ID_u, academy;
	int authority, lent_number;//����user����
	double money_delay;

	while (!user_f.eof())
	{
		user_f >> name >> ID_u >> academy >> authority >> lent_number >> money_delay;
		User user_temp(name, ID_u, academy, authority, lent_number, money_delay);
		users.push_back(user_temp);
	}
}

void LoadInfo(ifstream &addinfo, vector<additional> &add, char c)
{
	string ID;
	int borrowed_num, wanted_num;
	vector<Time> borrow;
	vector<string> borrowed_ISBN;
	vector<string> wanted_ISBN;
	int year, month, day;
	string temp_s;
	Time temp_t;

	while (!addinfo.eof())
	{
		int i;
		addinfo >> ID >> borrowed_num;
		for (i = 0; i <= borrowed_num - 1; i++)
		{
			addinfo >> year >> month >> day;
			temp_t.set_time(year, month, day);
			borrow.push_back(temp_t);
		}

		for (i = 0; i <= borrowed_num - 1; i++)
		{
			addinfo >> temp_s;
			borrowed_ISBN.push_back(temp_s);
		}

		addinfo >> wanted_num;

		for (i = 0; i <= wanted_num - 1; i++)
		{
			addinfo >> temp_s;
			wanted_ISBN.push_back(temp_s);
		}
		additional temp_a(ID, borrowed_num, borrow, borrowed_ISBN, wanted_num, wanted_ISBN);
		add.push_back(temp_a);

		borrow.clear();
		borrowed_ISBN.clear();
		wanted_ISBN.clear();
	}
}

void WriteInfo(ofstream &book_f, vector<Book> books)
{
	unsigned int i;
	for (i = 0; i <= books.size() - 2; i++)
		book_f << books[i].get_ID() << "\t" << books[i].get_ISBN() << "\t" << books[i].get_name() << "\t" << books[i].get_author() << "\t" << books[i].get_publisher() << "\t" << books[i].get_introduction() << "\t" << books[i].get_bought_time() << "\t" << books[i].get_origin_num() << "\t" << books[i].get_remain_num() << endl;
	book_f << books[i].get_ID() << "\t" << books[i].get_ISBN() << "\t" << books[i].get_name() << "\t" << books[i].get_author() << "\t" << books[i].get_publisher() << "\t" << books[i].get_introduction() << "\t" << books[i].get_bought_time() << "\t" << books[i].get_origin_num() << "\t" << books[i].get_remain_num();
}

void WriteInfo(ofstream &user_f, vector<User> user, int n)
{
	unsigned int i;
	for (i = 0; i <= user.size() - 2; i++)
		user_f << user[i].get_name() << "\t" << user[i].get_ID() << "\t" << user[i].get_academy() << "\t" << user[i].get_authority() << "\t" << user[i].get_lent_number() << "\t" << user[i].get_money_delay() << endl;
	user_f << user[i].get_name() << "\t" << user[i].get_ID() << "\t" << user[i].get_academy() << "\t" << user[i].get_authority() << "\t" << user[i].get_lent_number() << "\t" << user[i].get_money_delay();
}

void WriteInfo(ofstream &addinfo, vector<additional> add, char c)
{
	unsigned int i;
	int j;
	if (add.size() == 0)
		return;
	for (i = 0; i <= add.size() - 2; i++)
	{
		addinfo << add[i].get_ID() << "\t" << add[i].get_borrowed_num() << "\t";

		for (j = 0; j <= add[i].get_borrowed_num() - 1; j++)
			addinfo << add[i].get_borrow_time()[j].get_year() << "\t" << add[i].get_borrow_time()[j].get_month() << "\t" << add[i].get_borrow_time()[j].get_day() << "\t";

		for (j = 0; j <= add[i].get_borrowed_num() - 1; j++)
			addinfo << add[i].get_borrowed_ISBN()[j] << "\t";

		addinfo << add[i].get_wanted_num();
		if (add[i].get_wanted_num() != 0)
			addinfo << "\t";

		for (j = 0; j <= add[i].get_wanted_num() - 2; j++)
			addinfo << add[i].get_wanted_ISBN()[j] << "\t";

		if (add[i].get_wanted_num() != 0)
			addinfo << add[i].get_wanted_ISBN()[add[i].get_wanted_num() - 1] << endl;
		else
			addinfo << "\n";
	}

	/*������һ����Ϣ*/
	addinfo << add[i].get_ID() << "\t" << add[i].get_borrowed_num() << "\t";

	for (j = 0; j <= add[i].get_borrowed_num() - 1; j++)
		addinfo << add[i].get_borrow_time()[j].get_year() << "\t" << add[i].get_borrow_time()[j].get_month() << "\t" << add[i].get_borrow_time()[j].get_day() << "\t";

	for (j = 0; j <= add[i].get_borrowed_num() - 1; j++)
		addinfo << add[i].get_borrowed_ISBN()[j] << "\t";

	addinfo << add[i].get_wanted_num();
	if (add[i].get_wanted_num() != 0)
		addinfo << "\t";

	for (j = 0; j <= add[i].get_wanted_num() - 2; j++)
		addinfo << add[i].get_wanted_ISBN()[j] << "\t";
	if (add[i].get_wanted_num() != 0)
		addinfo << add[i].get_wanted_ISBN()[add[i].get_wanted_num() - 1];
}

void gotoxy(int x, int y)
{//��λ��꣬xΪ������,yΪ������
	COORD pos = { x,y };								//������  λ�ã��� 
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);  //�õ���׼������׼��������� 
	SetConsoleCursorPosition(hOut, pos);			//���ÿ���̨���λ�ã� 
}

int login(vector<User> user)
{
	int root = 2, i = 0, number = -2,j;
	string password, IDnumber;
	cout << "�����˳�ϵͳ���Ǽ�����¼�����˳�������1������������0��";
	cin >> j;
	while ((j != 1) && (j != 0))
	{
		cout << "������Ч�����������룺";
		cin >> j;
	}
	if (j == 1)
		return -2;//�˳�
	else
	{
		cout << "���Ƿ��ǹ���Ա������������1������������0��:";
		cin >> root;
		while ((root != 1) && (root != 0))
		{
			cout << "������Ч�����������룺";
			cin >> root;
		}

		if (root == 1)
		{
			cout << "����������:";
			cin >> password;
			while (password != "11111111")
			{
				cout << "��¼ʧ�ܣ����������룺";
				cin >> password;
			}
			number = -1;//root
			cout << "��¼�ɹ�\n";

		}

		else
		{
			cout << "����������ѧ�ţ�";
			cin >> IDnumber;
			for (i = 0; i <= user.size() - 1; i++)
			{
				if (IDnumber == user[i].get_ID())
				{
					number = i;
					cout << "��½�ɹ�\n";
				}
			}
			while (number == -2)
			{
				cout << "����ѧ�������������������룺";
				cin >> IDnumber;
				for (i = 0; i <= user.size() - 1; i++)
				{
					if (IDnumber == user[i].get_ID())
					{
						number = i;
						cout << "��½�ɹ�\n";
					}
				}
			}
		}
		Sleep(1500);
		return number;
	}
}

void ShowMenu1(int n)
{
	if (n == -1)//���ǹ���Ա
		cout << "���ܽ��ܣ�\n1-�����Ŀ\n2-�޸������Ŀ\n3-��ѯ��Ŀ\n4-��ѯ�û����ż�¼\n5-�˳�\n";
	else
		cout << "���ܽ��ܣ�\n1-����\n2-����\n3-ԤԼ\n4-��ѯ\n5-ȡ��ԤԼ\n6-�˳�\n";
	cout << "��\"`\"�˳�\n";
}

void ShowInfo(int n, vector<Book> book, vector<User> user)
{
	cout << "���ã�����Ա��\n";
	cout << "����ͼ�����ࣺ" << book.size() << endl;
	cout << "�����û�������" << user.size() << endl<<endl;
}

void ShowInfo(User user, vector<Book> book, additional addinfo)
{
	cout << "���ã�" << user.get_name() << endl;
	cout << "����ѧԺ��" << user.get_academy() << endl;
	cout << "������ݣ�";
	if (user.get_authority() == 0)
		cout << "ѧ��\n";
	else
		cout << "��ʦ\n";
	cout << "��Ƿ��" << user.get_money_delay() << endl;

	cout << "�ѽ��飺" << addinfo.get_borrowed_num() << "��" << endl;
	if (addinfo.get_borrowed_num() != 0)
	{
		int i,j;
		for (i = 0; i <= addinfo.get_borrowed_num() - 1; i++)
		{
			j = Search_ISBN(addinfo.get_borrowed_ISBN()[i], book);
			cout << book[j].get_name() << "\t" << book[j].get_author() << "\t����ʱ�䣺";
			addinfo.get_borrow_time()[i].show();
			cout << "\n";
		}
	}

	cout << "��ԤԼ�飺" << addinfo.get_wanted_num() << "��" << endl;
	if (addinfo.get_wanted_num() != 0)
	{
		int i, j;
		for (i = 0; i <= addinfo.get_wanted_num() - 1; i++)
		{
			j = Search_ISBN(addinfo.get_wanted_ISBN()[i], book);
			cout << book[j].get_name() << "\t" << book[j].get_author() << "\tISBN:" << book[j].get_ISBN() << "\t״̬��";
			if (book[j].get_remain_num() != 0)
				cout << "�ɽ�\n";
			else
				cout << "���ɽ�\n";
			cout << "\n";
		}
	}
}

bool All_Patch(string a, vector<string> b)
{
	int i;
	for (i = 0; i <= b.size() - 1; i++)
	{
		if (a.find(b[i]) == string::npos)
			return false;
	}
	return true;
}

void getNext(string substr, vector<int> &next)
{
	next.clear();
	next.resize(substr.length());
	int j = -1;
	next[0] = -1;
	for (int i = 1; i < substr.size(); ++i)
	{
		while (j > -1 && substr[j + 1] != substr[i])
			j = next[j];
		if (substr[j + 1] == substr[i])
			++j;
		next[i] = j;
	}
}

int kmp(string str, string substr, vector<int> &next)
{
	int cnt = 0;
	getNext(substr, next);
	int j = -1;
	for (int i = 0; i < str.size(); ++i)
	{
		while (j > -1 && substr[j + 1] != str[i])
			j = next[j];
		if (substr[j + 1] == str[i])
			++j;
		if (j == substr.size() - 1)
		{
			++cnt;
			j = next[j];
		}
	}
	if (cnt == 0)
		return 0;
	else
		return 1;
}

int Search_ISBN(string isbn, vector<Book> book)
{
	int i=-1;
	for (i = 0; i <= book.size() - 1; i++) 
	{
		if (isbn == book[i].get_ISBN())
			return i;
	}
	return -1  ;
}

int Search_name(string name, vector<Book> book)
{
	int i=-1;
	for (i = 0; i <= book.size() - 1; i++)
	{
		if (name == book[i].get_name())
			break;
	}
	return i;
}

vector<int> Search_author(string author, vector<Book> book)
{
	vector<int> b;
	int i;
	for (i = 0; i <= book.size() - 1; i++)
	{
		if (author == book[i].get_author())
			b.push_back(i);
	}
	return b;
}

vector<int> Search_publisher(string publisher, vector<Book> book)
{
	vector<int> b;
	int i;
	for (i = 0; i <= book.size() - 1; i++)
	{
	if (publisher == book[i].get_publisher())
		b.push_back(i);
	}
	return b;
}

vector<int> Search_name_vague(vector<string> name, vector<Book> book)
{
	vector<int> b;
	int i;
	for (i = 0; i <= book.size() - 1; i++)
	{
		if (All_Patch(book[i].get_name(),name))
			b.push_back(i);
	}
	return b;
}

vector<int> Search_name_KMP(string name, vector<Book> book)
{
	vector<int> a;//For KMP
	vector<int> b;//������Ҫ�ҵ����ӳ��
	int i;
	for (i = 0; i <= book.size() - 1; i++)
	{
		if (kmp(book[i].get_name(),name,a))
			b.push_back(i);
	}
	return b;
}

vector<int> Search_author_vague(string author, vector<Book> book)
{
	vector<int> b;
	int i;
	for (i = 0; i <= book.size() - 1; i++)
	{
		if (book[i].get_author().find(author) != string::npos)
			b.push_back(i);
	}
	return b;
}

vector<int> Search_publisher_vague(string publisher, vector<Book> book)
{
	vector<int> b;
	int i;
	for (i = 0; i <= book.size() - 1; i++)
	{
		if (book[i].get_publisher().find(publisher) != string::npos)
			b.push_back(i);
	}
	return b;
}

int Search_ID(string ID, vector<User> user)
{
	int i;
	for (i = 0; i <= user.size() - 1; i++)
	{
		if (ID == user[i].get_ID())
			break;
	}
	return i;
}

void AddBook(vector<Book> &book, ofstream &journal, Time now)
{
	int ID;               //ͼ�����
	string ISBN;          //ISBN
	string name;          //����
	string author;        //����
	string publisher;     //������
	string introduction;  //���
	string bought_time;   //����ʱ��
	int remain_num;       //����
	ID = book.size();

	stringstream a;
	a << ID;
	string ID1 = a.str();


	cout << "������������Ϣ��\nISBN��";
	cin >> ISBN;
	cout << "����:";
	cin >> name;
	cout << "����:";
	cin >> author;
	cout << "������:";
	cin >> publisher;
	cout << "���:";
	cin >> introduction;
	cout << "����ʱ��:";
	cin >> bought_time;
	cout << "����:";
	cin >> remain_num;
	Book temp(ID1, ISBN, name, author, publisher, introduction, bought_time, remain_num, remain_num);
	book.push_back(temp);
	journal << now.get_year() << "��" << now.get_month() << "��" << now.get_day() << "��  ";
	journal << "����Ա����� "<<remain_num<<" ����"<<name<<"��\n";
}

void ChangeNum(vector<Book> &book, ofstream &journal, Time now)
{
	cout << "�������޸���Ŀ��ISBN���룺";
	string isbn;
	cin >> isbn;
	int i = Search_ISBN(isbn, book);
	if (i == -1)
		cout << "û���ҵ�����\n";
	else
	{
		cout << "������Ŀ�걾����";
		int tar;
		cin >> tar;
		book[i].set_remain_num(tar);
		journal << now.get_year() << "��" << now.get_month() << "��" << now.get_day() << "��  ";
		journal << "����Ա��ISBN����Ϊ " << isbn << " �������Ŀ��Ϊ " << tar << endl;
	}
}

bool IsHonest(vector<User> user)
{
	string ID;
	cout << "�����������ѯ��ID:";
	cin >> ID;
	int i = Search_ID(ID, user);
	if (user[i].get_money_delay() > MAX_OWE_MONEY)
		return false;
	else
		return true;
}

vector<int> Search(vector<Book> book)
{//-1û�ҵ�
	cout << "����ͨ�����ַ�ʽ��ѯ��\n";

	int method, temp(-1);
	vector<int> res;
	int i;//����

	cout << "1-ͨ������\n2-ͨ��ISBN\n3-ͨ������\n4-ͨ��������\n";
	cout << "�����룺";
	cin >> method;
	while (method <= 0 || method > 4)
	{
		cout << "�����������������:";
		cin >> method;
	}

	if (method == 1)
	{//ͨ����������
		string name;
		vector<string> wanted1;
		int method1;
		cout << "��ϣ����ȷ���һ���ģ�����ң�0-��ȷ���ң�1-���ڿ⺯����ģ������(�ɶ�ʣ����硰���� �ʵ� ��ѧ��)��2-����KMP��ģ�����ң���";
		cin >> method1;
		while (method1 != 0 && method1 != 1 && method1 != 2)
		{
			cout << "����������������룺";
			cin >> method1;
		}
		
		//��ȡ��Ϣ
		cout << "������������֣�";
		if (method1 == 0 || method1 == 2)
			cin >> name;
		else
		{
			string s = "";
			char c;
			getchar();
			while ((c = cin.get()) != '\n')
				s += c;

			int iter1;
			string temp = "";

			for (iter1 = 0; iter1 <= s.length() - 1; iter1++)
			{
				while (s[iter1] != ' ' && iter1 <= s.length() - 1)
				{
					temp += s[iter1];
					iter1++;
				}
				wanted1.push_back(temp);
				temp = "";
			}
		}

		if (method1 == 0)
		{
			for (i = 0; i <= book.size() - 1; i++)
			{
				if (name == book[i].get_name())
				{
					temp = i;
					res.push_back(i);
				}
			}
			return res;
		}
		else if (method1 == 1)
			return Search_name_vague(wanted1, book);
		else if (method1 == 2){}
			return Search_name_KMP(name, book);
	}

	else if (method == 2)
	{
		string ISBN;
		cout << "������ISBN����֧�־�ȷ���ң���";
		cin >> ISBN;
		for (i = 0; i <= book.size() - 1; i++)
		{
			if (ISBN == book[i].get_name())
			{
				temp = i;
				res.push_back(i);
			}
		}
		return res;
	}

	else if (method == 3)
	{
		string author;
		int method3;
		cout << "��ϣ����ȷ���һ���ģ�����ң�0-��ȷ���ң�1-ģ�����ң���";
		cin >> method3;
		while (method3 != 0 && method3 != 1)
		{
			cout << "����������������룺";
			cin >> method3;
		}
		cout << "���������ߵ����֣�";
		cin >> author;
		if(method3==0)
			return Search_author(author, book);
		else
			return Search_author_vague(author, book);
	}

	else if (method == 4)
	{
		string publisher;
		int method4;
		cout << "��ϣ����ȷ���һ���ģ�����ң�0-��ȷ���ң�1-ģ�����ң���";
		cin >> method4;
		while (method4 != 0 && method4 != 1)
		{
			cout << "����������������룺";
			cin >> method4;
		}
		cout << "���������������֣�";
		cin >> publisher;
		if (method4 == 0)
			return Search_publisher(publisher, book);
		else
			return Search_publisher_vague(publisher, book);
	}
}

void Borrow(Book &book, 
	        User &user, 
	        additional &addinfo,
	        Time now, 
	        ofstream &journal)
{
	if (user.get_authority() == 1)
	{//����ʦ
		if (book.get_remain_num() > 0)
		{
			int now_remain = book.get_remain_num() - 1;
			int now_borrowed = addinfo.get_borrowed_num() + 1;
			vector<Time> time_to = addinfo.get_borrow_time();
			vector<string> ISBN_to = addinfo.get_borrowed_ISBN();

			book.set_remain_num(now_remain);
			addinfo.set_borrowed_num(now_borrowed);
			user.set_lent_number(now_borrowed);
			time_to.push_back(now);
			ISBN_to.push_back(book.get_ISBN());
			addinfo.set_borrowed_ISBN(ISBN_to);
			addinfo.set_borrow_time(time_to);
			cout << "����ɹ�������7���ڻ��飬����ÿ����һ���һԪǮ!\n";
			journal << now.get_year() << "��" << now.get_month() << "��" << now.get_day() << "��  ";
			journal << user.get_name() << "����һ����" << book.get_name() << "��\n";
		}
		else
		{
			cout << "�����Ѿ�������ˣ�\n�Ƿ�ԤԼ����0-��ԤԼ��1-ԤԼ����";
			int is_to1;
			cin >> is_to1;
			while (is_to1 != 0 && is_to1 != 1)
			{
				cout << "������������ԣ�";
				cin >> is_to1;
			}
			if (is_to1 == 1)
				order(addinfo, book);
		}
			
	}
	else
	{//��ѧ��
		if (book.get_remain_num() > 0)
		{
			if (user.get_lent_number() == MAX_STU_LENT_NUM)
				cout << "ѧ��ֻ�ܽ�������\n";
			else
			{
				if (book.isForeign())
					cout << "ѧ�����ܽ��������д���鼮��\n";
				else
				{
					int now_remain = book.get_remain_num() - 1;
					int now_borrowed = addinfo.get_borrowed_num() + 1;
					vector<Time> time_to = addinfo.get_borrow_time();
					vector<string> ISBN_to = addinfo.get_borrowed_ISBN();

					book.set_remain_num(now_remain);
					addinfo.set_borrowed_num(now_borrowed);
					user.set_lent_number(now_borrowed);
					time_to.push_back(now);
					ISBN_to.push_back(book.get_ISBN());
					addinfo.set_borrowed_ISBN(ISBN_to);
					addinfo.set_borrow_time(time_to);
					cout << "����ɹ�������7���ڻ��飬����ÿ����һ���һԪǮ!\n";
					journal << now.get_year() << "��" << now.get_month() << "��" << now.get_day() << "��  ";
					journal << user.get_name() << "����һ����" << book.get_name() << "��\n";
				}
			}
		}
		else
		{
			cout << "�����Ѿ�������ˣ�\n�Ƿ�ԤԼ����0-��ԤԼ��1-ԤԼ����";
			int is_to2;
			cin >> is_to2;
			while (is_to2 != 0 && is_to2 != 1)
			{
				cout << "������������ԣ�";
				cin >> is_to2;
			}
			if (is_to2 == 1)
				order(addinfo, book);
		}
	}
}

void order(additional &addinfo, Book book)
{
	int now_order = addinfo.get_wanted_num() + 1;
	vector<string> now_want_ISBN = addinfo.get_wanted_ISBN();
	now_want_ISBN.push_back(book.get_ISBN());

	addinfo.set_wanted_num(now_order);
	addinfo.set_wanted_ISBN(now_want_ISBN);
	cout << "ԤԼ�ɹ���\n";
}

void cancel_order(additional &addinfo, int n)
{
	int want_now = addinfo.get_wanted_num() - 1;
	vector<string>new_ISBN = addinfo.get_wanted_ISBN();
	new_ISBN.erase(new_ISBN.begin()+n);
	addinfo.set_wanted_num(want_now);
	addinfo.set_borrowed_ISBN(new_ISBN);
	cout << "ȡ��Ԥ���ɹ�\n";
}

void returnbook(Book &book, 
	            User &user, 
	            additional &addinfo, 
	            Time now, 
	            ofstream &journal)
{ 
	cout << "�����黹��"<<book.get_name()<<"��\n";
	int remain_now = book.get_remain_num() + 1;
	int borrow_now = user.get_lent_number() - 1;//user and addinfo

	int i;//find the one to erase
	for (i = 0; i <= addinfo.get_borrowed_num(); i++)
	{
		if (book.get_ISBN() == addinfo.get_borrowed_ISBN()[i])
			break;
	}//finally find you

	int delay_money = user.get_money_delay();
	int minusdays = now.get_minus(addinfo.get_borrow_time()[i], now);
	if (minusdays > 7)
	{
		delay_money += minusdays - 7;
	}

	vector<Time> new_time = addinfo.get_borrow_time();
	vector<string>new_ISBN = addinfo.get_borrowed_ISBN();

	new_time.erase(new_time.begin() + i);
	new_ISBN.erase(new_ISBN.begin() + i);

	book.set_remain_num(remain_now);
	user.set_lent_number(borrow_now);
	user.set_money_delay(delay_money);
	addinfo.set_borrowed_num(borrow_now);
	addinfo.set_borrowed_ISBN(new_ISBN);
	addinfo.set_borrow_time(new_time);
	cout << "����ɹ����˴ν��鷣��";
	if (minusdays - 7 <= 0)
		cout << "0";
	else
		cout << minusdays - 7;
	cout << "Ԫ\n";
	journal << now.get_year() << "��" << now.get_month() << "��" << now.get_day() << "��  ";
	journal << user.get_name() << "����һ����" << book.get_name() << "��\n";
}
