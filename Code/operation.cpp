#include"function.h"

void operation(vector<Book> &book,
	           vector<User> &user,
	           vector<additional> &addinfo, 
	           Time &now, 
	           ofstream &journal)
{
	int sec = 0, flag1=-1, flag2=-1, flag3=-1;
	int i;//计数菌
	char c;

	vector<int> tar;
	int target;

	while (flag1 == -1)
	{
		system("cls");
		int ID = login(user);//-1是管理员
		system("cls");
		flag2 = -1;//更新
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
					cout << "\n请按任意键暂停计时...";

					gotoxy(100, 24);
					cout << "计时：" << sec;
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
							cout << "计时：" << sec;
							gotoxy(100, 25);
							now.show();
							cout << "\n请输入功能号码:";

							cin >> act;
							while (((act <= 0 || act > 5)&&
								    (ID==-1))||((act <= 0 || act > 6) && 
								    (ID != -1)))
							{
								cout << "输入错误，请重试：";
								cin >> act;
							}
							system("cls");
							if (ID == -1)
							{//管理员工作
								cout << "以管理员身份运行\n";

								if (act == 1)
								{//添加书目
									cout << "添加书目";
									AddBook(book, journal, now);
									Sleep(1000);
								}

								else if (act == 2)
								{//修改书的书目
									cout << "修改书的书目";
									ChangeNum(book, journal, now);
									Sleep(1000);
								}

								else if (act == 3)
								{//查询
									cout << "查询";
									tar.swap(vector<int>());
									tar = Search(book);
									if (tar.size() == 0)
										cout << "未找到！\n";
									else
									{
										cout << "已经找到" << tar.size() << "本\n";
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
								{//查询用户诚信记录
									cout << "查询用户诚信记录";
									bool isHon=IsHonest(user);
									if (isHon)
										cout << "诚信记录良好\n";
									else
										cout << "诚信记录恶劣，已拖欠书款20元以上\n";

									Sleep(1000);
								}
								
								else if (act == 5)
									cout << "即将退出";
							}
							else
							{//非管理员
								if (user[ID].get_authority() == 0)
									cout << "以学生身份运行\n";
								else
									cout << "以教师身份运行\n";

								if (act == 1)
								{//借书目
									cout << "借书目";
									cout << "仅支持ISBN搜索，如想要了解更多信息，请进入查询。是否继续？（0-退出，1-输入ISBN借书）：";
									int action1;
									cin >> action1;
									while (action1 != 0 && action1 != 1)
									{
										cout << "输入错误，请重试：";
										cin >> action1;
									}
									if (action1 == 1)
									{
										string ISBN_to;
										cout << "请输入ISBN号码：";
										cin >> ISBN_to;
										target = Search_ISBN(ISBN_to,book);
										//cout << "target=" << target << endl;
										if (target == -1)
											cout << "并没有这本书\n";
										else
											Borrow(book[target], user[ID], addinfo[ID], now, journal);
									}
									system("pause");
								}

								else if (act == 2)
								{//还书目
									cout << "还书目";
									if (user[ID].get_lent_number() <= 0)
										cout << "无书可还!\n";
									else
									{
										cout << "您已借书：\n";
										int j;
										for (i = 0; i <= addinfo[ID].get_borrowed_num() - 1; i++)
										{
											j = Search_ISBN(addinfo[ID].get_borrowed_ISBN()[i], book);
											cout<<i+1<<". "<< book[j].get_name() << "\t" << book[j].get_author() << "\t借阅时间：";
											addinfo[ID].get_borrow_time()[i].show();
											cout << "\n";
										}
										cout << "请输入你想还的书的序号：";
										int to_return;
										cin >> to_return;
										while (to_return <= 0 || to_return > addinfo[ID].get_borrowed_num())
										{
											cout << "输入错误，请重试：";
											cin >> to_return;
										}
										int final_to_return = Search_ISBN(addinfo[ID].get_borrowed_ISBN()[to_return-1], book);
										returnbook(book[final_to_return], user[ID], addinfo[ID], now, journal);
									}
									system("pause");
								}

								else if (act == 3)
								{//预约
									cout << "预约";
									cout << "仅支持ISBN搜索，如想要了解更多信息，请进入查询。是否继续？（0-退出，1-输入ISBN预约）：";
									int action3;
									cin >> action3;
									while (action3 != 0 && action3 != 1)
									{
										cout << "输入错误，请重试：";
										cin >> action3;
									}
									if (action3 == 1)
									{
										int want;
										string ISBN_to;
										cout << "请输入ISBN号码：";
										cin >> ISBN_to;
										want = Search_ISBN(ISBN_to, book);
										order(addinfo[ID], book[want]);
									}
									system("pause");
								}

								else if (act == 4)
								{//查询
									cout << "查询";
									tar.swap(vector<int>());
									tar = Search(book);
									if (tar.size() == 0)
										cout << "未找到！\n";
									else
									{
										cout << "已经找到" << tar.size() << "本\n";
										for (i = 0; i <= tar.size() - 1; i++)
										{
											cout << i+1 << ". ";
											book[tar[i]].ShowAllInfo();
										}
										cout << "请问您想直接借书还是退出此操作(0-继续，1-退出):";
										int action4;
										cin >> action4;
										while (action4 != 0 && action4 != 1)
										{
											cout << "输入错误！\n请问您想直接借书还是退出此操作(0-继续，1-退出):";
											cin>>action4;
										}
										if (action4 == 0)
										{
											int temp;
											cout << "请输入书前的号码：";
											cin >> temp;
											while (temp <= 0 || temp > tar.size())
											{
												cout << "输入错误，请重试\n请输入书前的号码：";
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
									cout << "取消预约\n";

									if (addinfo[ID].get_wanted_num() <= 0)
										cout << "您并没有预约!\n";
									else
									{
										cout << "您已预约：\n";
										int j;
										for (i = 0; i <= addinfo[ID].get_wanted_num() - 1; i++)
										{
											j = Search_ISBN(addinfo[ID].get_wanted_ISBN()[i], book);
											cout << i + 1 << ". " << book[j].get_name() << "\t" << book[j].get_author();
											cout << "\n";
										}
										cout << "请输入你想取消的序号：";
										int to_cancel;
										cin >> to_cancel;
										while (to_cancel <= 0 || to_cancel > addinfo[ID].get_wanted_num())
										{
											cout << "输入错误，请重试：";
											cin >> to_cancel;
										}
										cancel_order(addinfo[ID],to_cancel-1);
									}
									system("pause");
								}

								else if (act == 6)
									cout << "即将退出";
							}
							system("cls");
						}
					}
				}
			}
		}	
	}
	cout << "即将退出系统\n";
	Sleep(2000);
}
