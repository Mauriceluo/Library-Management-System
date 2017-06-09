#include"function.h"

void operation(vector<Book> &book,
	           vector<User> &user,
	           vector<additional> &addinfo, 
	           Time &now, 
	           ofstream &journal)
{
	int sec = 0, flag1=-1, flag2=-1, flag3=-1;
	int i;//������
	char c;

	vector<int> tar;
	int target;

	while (flag1 == -1)
	{
		system("cls");
		int ID = login(user);//-1�ǹ���Ա
		system("cls");
		flag2 = -1;//����
		if (ID == -2)
			flag1 = 0;
		else
		{
			while (flag2 == -1)
			{
				if (!kbhit())
				{
					system("cls");

					if (ID == -1)//root
						ShowInfo(1, book, user);
					else
						ShowInfo(user[ID], book, addinfo[ID]);
					ShowMenu1(ID);
					cout << "\n�밴�������ͣ��ʱ...";

					gotoxy(100, 24);
					cout << "��ʱ��" << sec;
					gotoxy(100, 25);
					now.show();
					if (sec == 9)
					{
						sec = 0;
						now.tomorrow();
					}
					else
						sec++;
					Sleep(1000);
				}
				else
				{
					c = getch();
					if (c == '`')
					{
						flag2 = 0;
						//restart
					}
						
					else
					{
						system("cls");
						int act = -1;
						while (((act != 5) && (ID == -1)) || 
							   ((act != 6) && (ID != -1)))
						{
							if (ID == -1)//root
								ShowInfo(1, book, user);
							else
								ShowInfo(user[ID], book, addinfo[ID]);

							ShowMenu1(ID);
							gotoxy(100, 24);
							cout << "��ʱ��" << sec;
							gotoxy(100, 25);
							now.show();
							cout << "\n�����빦�ܺ���:";

							cin >> act;
							while (((act <= 0 || act > 5)&&
								    (ID==-1))||((act <= 0 || act > 6) && 
								    (ID != -1)))
							{
								cout << "������������ԣ�";
								cin >> act;
							}
							system("cls");
							if (ID == -1)
							{//����Ա����
								cout << "�Թ���Ա�������\n";

								if (act == 1)
								{//�����Ŀ
									cout << "�����Ŀ";
									AddBook(book, journal, now);
									Sleep(1000);
								}

								else if (act == 2)
								{//�޸������Ŀ
									cout << "�޸������Ŀ";
									ChangeNum(book, journal, now);
									Sleep(1000);
								}

								else if (act == 3)
								{//��ѯ
									cout << "��ѯ";
									tar.swap(vector<int>());
									tar = Search(book);
									if (tar.size() == 0)
										cout << "δ�ҵ���\n";
									else
									{
										cout << "�Ѿ��ҵ�" << tar.size() << "��\n";
										for (i = 0; i <= tar.size() - 1; i++)
										{
											cout << i+1 << ". ";
											book[tar[i]].ShowAllInfo();
										}
									}
									system("pause");
									Sleep(2000);
								}

								else if (act == 4)
								{//��ѯ�û����ż�¼
									cout << "��ѯ�û����ż�¼";
									bool isHon=IsHonest(user);
									if (isHon)
										cout << "���ż�¼����\n";
									else
										cout << "���ż�¼���ӣ�����Ƿ���20Ԫ����\n";

									Sleep(1000);
								}
								
								else if (act == 5)
									cout << "�����˳�";
							}
							else
							{//�ǹ���Ա
								if (user[ID].get_authority() == 0)
									cout << "��ѧ���������\n";
								else
									cout << "�Խ�ʦ�������\n";

								if (act == 1)
								{//����Ŀ
									cout << "����Ŀ";
									cout << "��֧��ISBN����������Ҫ�˽������Ϣ��������ѯ���Ƿ��������0-�˳���1-����ISBN���飩��";
									int action1;
									cin >> action1;
									while (action1 != 0 && action1 != 1)
									{
										cout << "������������ԣ�";
										cin >> action1;
									}
									if (action1 == 1)
									{
										string ISBN_to;
										cout << "������ISBN���룺";
										cin >> ISBN_to;
										target = Search_ISBN(ISBN_to,book);
										//cout << "target=" << target << endl;
										if (target == -1)
											cout << "��û���Ȿ��\n";
										else
											Borrow(book[target], user[ID], addinfo[ID], now, journal);
									}
									system("pause");
								}

								else if (act == 2)
								{//����Ŀ
									cout << "����Ŀ";
									if (user[ID].get_lent_number() <= 0)
										cout << "����ɻ�!\n";
									else
									{
										cout << "���ѽ��飺\n";
										int j;
										for (i = 0; i <= addinfo[ID].get_borrowed_num() - 1; i++)
										{
											j = Search_ISBN(addinfo[ID].get_borrowed_ISBN()[i], book);
											cout<<i+1<<". "<< book[j].get_name() << "\t" << book[j].get_author() << "\t����ʱ�䣺";
											addinfo[ID].get_borrow_time()[i].show();
											cout << "\n";
										}
										cout << "���������뻹�������ţ�";
										int to_return;
										cin >> to_return;
										while (to_return <= 0 || to_return > addinfo[ID].get_borrowed_num())
										{
											cout << "������������ԣ�";
											cin >> to_return;
										}
										int final_to_return = Search_ISBN(addinfo[ID].get_borrowed_ISBN()[to_return-1], book);
										returnbook(book[final_to_return], user[ID], addinfo[ID], now, journal);
									}
									system("pause");
								}

								else if (act == 3)
								{//ԤԼ
									cout << "ԤԼ";
									cout << "��֧��ISBN����������Ҫ�˽������Ϣ��������ѯ���Ƿ��������0-�˳���1-����ISBNԤԼ����";
									int action3;
									cin >> action3;
									while (action3 != 0 && action3 != 1)
									{
										cout << "������������ԣ�";
										cin >> action3;
									}
									if (action3 == 1)
									{
										int want;
										string ISBN_to;
										cout << "������ISBN���룺";
										cin >> ISBN_to;
										want = Search_ISBN(ISBN_to, book);
										order(addinfo[ID], book[want]);
									}
									system("pause");
								}

								else if (act == 4)
								{//��ѯ
									cout << "��ѯ";
									tar.swap(vector<int>());
									tar = Search(book);
									if (tar.size() == 0)
										cout << "δ�ҵ���\n";
									else
									{
										cout << "�Ѿ��ҵ�" << tar.size() << "��\n";
										for (i = 0; i <= tar.size() - 1; i++)
										{
											cout << i+1 << ". ";
											book[tar[i]].ShowAllInfo();
										}
										cout << "��������ֱ�ӽ��黹���˳��˲���(0-������1-�˳�):";
										int action4;
										cin >> action4;
										while (action4 != 0 && action4 != 1)
										{
											cout << "�������\n��������ֱ�ӽ��黹���˳��˲���(0-������1-�˳�):";
											cin>>action4;
										}
										if (action4 == 0)
										{
											int temp;
											cout << "��������ǰ�ĺ��룺";
											cin >> temp;
											while (temp <= 0 || temp > tar.size())
											{
												cout << "�������������\n��������ǰ�ĺ��룺";
												cin >> temp;
											}
											target = tar[temp-1];
											Borrow(book[target], user[ID], addinfo[ID], now, journal);
										}
									}
									Sleep(1000);
								}

								else if (act == 5)
								{
									cout << "ȡ��ԤԼ\n";

									if (addinfo[ID].get_wanted_num() <= 0)
										cout << "����û��ԤԼ!\n";
									else
									{
										cout << "����ԤԼ��\n";
										int j;
										for (i = 0; i <= addinfo[ID].get_wanted_num() - 1; i++)
										{
											j = Search_ISBN(addinfo[ID].get_wanted_ISBN()[i], book);
											cout << i + 1 << ". " << book[j].get_name() << "\t" << book[j].get_author();
											cout << "\n";
										}
										cout << "����������ȡ������ţ�";
										int to_cancel;
										cin >> to_cancel;
										while (to_cancel <= 0 || to_cancel > addinfo[ID].get_wanted_num())
										{
											cout << "������������ԣ�";
											cin >> to_cancel;
										}
										cancel_order(addinfo[ID],to_cancel-1);
									}
									system("pause");
								}

								else if (act == 6)
									cout << "�����˳�";
							}
							system("cls");
						}
					}
				}
			}
		}	
	}
	cout << "�����˳�ϵͳ\n";
	Sleep(2000);
}
