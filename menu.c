#include"all.h"

//首界面
void head_menu()
{
	int select;//选择变量
	while (1)
	{
		system("cls");//清屏
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("| 欢迎使用广州市乘地铁售票程序 |\n");
		printf("|                              |\n");
		printf("|          1.管理界面          |\n");
		printf("|                              |\n");
		printf("|          2.用户界面          |\n");
		printf("|                              |\n");
		printf("|            0.退出            |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//输出现在时间
		printf("请选择 >> ");
		scanf("%d", &select);//输入选择变量
		getchar();//避免输入字符后进入死循环
		switch (select)
		{
			case 1:
				manager_menu();
				break;
			case 2:
				user_menu();
				break;
			case 0:
				printf("感谢您的使用！\n");
				Sleep(1000);
				return;
			default:
				printf("请输入一个有效数字\n");
				system("pause");
				break;
		}
	}
}

//管理界面
void manager_menu()
{
	system("cls");//清屏
	char t[5];
	int select;
	printf("请输入管理员密码 >> ");
	scanf("%s", t);
	getchar();
	if (!strcmp(t, "admin"))
	{
		printf("密码正确\n");
	}
	else
	{
		printf("密码错误\n");
		system("pause");
		return;
	}
	while (1)
	{
		system("cls");
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|         ◎管理界面 ◎        |\n");
		printf("|                              |\n");
		printf("|          1.输入功能          |\n");
		printf("|                              |\n");
		printf("|          2.查询功能          |\n");
		printf("|                              |\n");
		printf("|          3.修改功能          |\n");
		printf("|                              |\n");
		printf("|         0.返回上一级         |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//输出现在时间
		printf("请选择 >> ");
		scanf("%d", &select);
		getchar();
		switch (select)
		{
			case 1:
				manager_input_menu();
				break;
			case 2:
				manager_inquire_menu();
				break;
			case 3:
				manager_change_menu();
				break;
			case 0:
				system("pause");
				return;
			default:
				printf("请输入一个有效数字\n");
				system("pause");
				break;
		}
	}
}

//管理输入界面
void manager_input_menu()
{
	int select;
	while (1)
	{
		system("cls");
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|         ◎输入界面 ◎        |\n");
		printf("|                              |\n");
		printf("|          1.线路输入          |\n");
		printf("|                              |\n");
		printf("|          2.站点输入          |\n");
		printf("|                              |\n");
		printf("|         0.返回上一级         |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//输出现在时间
		printf("请选择 >> ");
		scanf("%d", &select);
		getchar();
		switch (select)
		{
			case 1:
				linesInput();
				line_information_sort();//输入完就排序，方便以后操作
				break;
			case 2:
				stationsInput();
				station_information_sort();//输入完就排序，方便以后操作
				break;
			case 0:
				system("pause");
				return;
			default:
				printf("请输入一个有效数字\n");
				system("pause");
				break;
		}
	}
}

//管理查询界面
void manager_inquire_menu()
{
	int select;
	while (1)
	{
		system("cls");
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|         ◎查询界面 ◎        |\n");
		printf("|                              |\n");
		printf("|        1.线路信息查询        |\n");
		printf("|                              |\n");
		printf("|        2.统计信息查询        |\n");
		printf("|                              |\n");
		printf("|        3.全部线路查询        |\n");
		printf("|                              |\n");
		printf("|        4.用户信息查询        |\n");
		printf("|                              |\n");
		printf("|         0.返回上一级         |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//输出现在时间
		printf("请选择 >> ");
		scanf("%d", &select);
		getchar();
		switch (select)
		{
			case 1:
				line_inquire_menu();
				break;
			case 2:
				system("cls");
				information_printf();
				system("pause");
				break;
			case 3:
				system("cls");
				all_lineprint();
				system("pause");
				break;
			case 4:
				system("cls");
				users_printf();
				system("pause");
				break;
			case 0:
				system("pause");
				return;
			default:
				printf("请输入一个有效数字\n");
				system("pause");
				break;
		}
	}
}

//线路查询界面
void line_inquire_menu()
{
	int n;
	system("cls");
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("|       ◎线路查询界面 ◎      |\n");
	printf("|                              |\n");
	printf("|      0.查看高清线路大图      |\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	times();//输出现在时间
	printf("请选择您需要查询的线路 >> ");
	scanf("%d", &n);
	getchar();
	if (n == 0)
	{
		system("picture.jpg");
		system("pause");
		return;
	}
	lineprint(n);
	system("pause");
	return;
}

//管理修改界面
void manager_change_menu()
{
	int select;
	while (1)
	{
		system("cls");
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|         ◎修改界面 ◎        |\n");
		printf("|                              |\n");
		printf("|        1.用户信息修改        |\n");
		printf("|                              |\n");
		printf("|        2.地铁信息修改        |\n");
		printf("|                              |\n");
		printf("|         0.返回上一级         |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//输出现在时间
		printf("请选择 >> ");
		scanf("%d", &select);
		getchar();
		switch (select)
		{
			case 1:
				manager_user_change_menu1();
				break;
			case 2:
				manager_subway_information_change_menu();
				break;
			case 0:
				system("pause");
				return;
			default:
				printf("请输入一个有效数字\n");
				system("pause");
				break;
		}
	}
}

//管理地铁信息修改界面
void manager_subway_information_change_menu()
{
	int select;
	while (1)
	{
		system("cls");
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|     ◎地铁信息修改界面 ◎    |\n");
		printf("|                              |\n");
		printf("|        1.线路信息修改        |\n");
		printf("|                              |\n");
		printf("|        2.站点信息修改        |\n");
		printf("|                              |\n");
		printf("|        3.线路信息删除        |\n");
		printf("|                              |\n");
		printf("|        4.站点信息删除        |\n");
		printf("|                              |\n");
		printf("|         0.返回上一级         |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//输出现在时间
		printf("请选择 >> ");
		scanf("%d", &select);
		getchar();
		switch (select)
		{
			case 1:
				line_change();
				break;
			case 2:
				station_change();
				break;
			case 3:
				line_delete();
				break;
			case 4:
				station_delete();
				break;
			case 0:
				system("pause");
				return;
			default:
				printf("请输入一个有效数字\n");
				system("pause");
				break;
		}
	}
}

//管理用户信息修改界面1
void manager_user_change_menu1()
{
	FILE *fp;
	users t;
	char temp[20];
	fp = fopen("users.txt", "r+");
	system("cls");
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("|     ◎用户信息修改界面 ◎    |\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	times();
	printf("请输入您需要修改的用户的身份证号 >> ");
	scanf("%s", temp);
	getchar();
	while (1)
	{
		if (!strcmp(temp, t.id))//如果有此用户名
		{
			break;
		}
		else
		{
			if (!feof(fp))//如果文件没有读完
			{
				fread(&t, sizeof(users), 1, fp);
			}
			else
			{
				system("cls");//清屏
				printf("--------------------------------\n");
				printf("|                              |\n");
				printf("|         此用户不存在         |\n");
				printf("|                              |\n");
				printf("--------------------------------\n");
				times();//输出现在时间
				system("pause");
				fclose(fp);
				return;
			}
		}
	}
	fclose(fp);
	manager_user_change_menu2(t);
	return;
}

//管理用户信息修改界面2
void manager_user_change_menu2(users t)
{
	int select;
	while (1)
	{
		system("cls");
		printf("----------------------------------------\n");
		printf("|                                      |\n");
		printf("|    身份证号 >> %-18s    |\n", t.id);
		printf("|                                      |\n");
		printf("|         ◎用户信息修改界面 ◎        |\n");
		printf("|                                      |\n");
		printf("|             1.手机号修改             |\n");
		printf("|                                      |\n");
		printf("|              2.姓名修改              |\n");
		printf("|                                      |\n");
		printf("|              3.密码修改              |\n");
		printf("|                                      |\n");
		printf("|              4.注销账户              |\n");
		printf("|                                      |\n");
		printf("|             0.返回上一级             |\n");
		printf("|                                      |\n");
		printf("----------------------------------------\n");
		times();//输出现在时间
		printf("请选择 >> ");
		scanf("%d", &select);
		getchar();
		switch (select)
		{
			case 1:
				changephone(t);
				break;
			case 2:
				changename(t);
				break;
			case 3:
				changepassport(t);
				break;
			case 4:
				account_delect(t);
				return;
			case 0:
				system("pause");
				return;
			default:
				printf("请输入一个有效数字\n");
				system("pause");
				break;
		}
	}
}

//用户界面
void user_menu()
{
	int select;
	while (1)
	{
		system("cls");//清屏
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|         ◎用户界面 ◎        |\n");
		printf("|                              |\n");
		printf("|            1.登陆            |\n");
		printf("|                              |\n");
		printf("|            2.注册            |\n");
		printf("|                              |\n");
		printf("|         0.返回上一级         |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//输出现在时间
		printf("请选择 >> ");
		scanf("%d", &select);
		getchar();
		switch (select)
		{
			case 1:
				login();
				break;
			case 2:
				registers();
				break;
			case 0:
				system("pause");
				return;
			default:
				printf("请输入一个有效数字\n");
				system("pause");
				break;
		}
	}
}

//登陆后界面
void after_login_menu(users t)
{
	FILE *fp;
	users temp;
	int select;
	while (1)
	{
		fp = fopen("users.txt", "r");
		while (1)
		{
			fread(&temp, sizeof(users), 1, fp);
			if (!strcmp(temp.id, t.id))
			{
				fclose(fp);
				break;
			}
		}
		system("cls");//清屏
		printf("------------------------------------------\n");
		printf("|                                        |\n");
		printf("|     尊敬的 %-10s 用户，欢迎您     |\n", t.name);
		printf("|                                        |\n");
		printf("|               1.购买车票               |\n");
		printf("|                                        |\n");
		printf("|               2.修改信息               |\n");
		printf("|                                        |\n");
		printf("|               3.充值余额               |\n");
		printf("|                                        |\n");
		printf("|               4.查询余额               |\n");
		printf("|                                        |\n");
		printf("|               5.查询线路               |\n");
		printf("|                                        |\n");
		printf("|             6.查询全部线路             |\n");
		printf("|                                        |\n");
		printf("|               0.退出登录               |\n");
		printf("|                                        |\n");
		printf("------------------------------------------\n");
		times();//输出现在时间
		printf("请选择 >> ");
		scanf("%d", &select);
		getchar();
		switch (select)
		{
			case 1:
				buy(temp);
				break;
			case 2:
				user_change_menu(temp);
				return;
			case 3:
				Recharge(temp);
				break;
			case 4:
				inquire_money_menu(temp);
				break;
			case 5:
				line_inquire_menu();
				break;
			case 6:
				system("cls");
				all_lineprint();
				system("pause");
				break;
			case 0:
				system("pause");
				return;
			default:
				printf("请输入一个有效数字\n");
				system("pause");
				break;
		}
	}
	return;
}

//用户修改界面
void user_change_menu(users t)
{
	int select;
	while (1)
	{
		system("cls");
		printf("----------------------------------------\n");
		printf("|                                      |\n");
		printf("|    身份证号 >> %-18s    |\n", t.id);
		printf("|                                      |\n");
		printf("|         ◎用户信息修改界面 ◎        |\n");
		printf("|                                      |\n");
		printf("|             1.手机号修改             |\n");
		printf("|                                      |\n");
		printf("|              2.姓名修改              |\n");
		printf("|                                      |\n");
		printf("|              3.密码修改              |\n");
		printf("|                                      |\n");
		printf("|              4.注销账户              |\n");
		printf("|                                      |\n");
		printf("|             0.返回上一级             |\n");
		printf("|                                      |\n");
		printf("----------------------------------------\n");
		times();//输出现在时间
		printf("请选择 >> ");
		scanf("%d", &select);
		getchar();
		switch (select)
		{
			case 1:
				changephone(t);
				return;
			case 2:
				changename(t);
				return;
			case 3:
				changepassport(t);
				return;
			case 4:
				account_delect(t);
				return;
			case 0:
				system("pause");
				return;
			default:
				printf("请输入一个有效数字\n");
				system("pause");
				break;
		}
	}
}

//余额查询界面
void inquire_money_menu(users t)
{
	system("cls");//清屏
	printf("----------------------------------------------\n");
	printf("|                                            |\n");
	printf("|      您当前的余额为：￥%-20.2lf|\n", t.money);
	printf("|                                            |\n");
	printf("----------------------------------------------\n");
	times();//输出现在时间
	system("pause");
	return;
}
