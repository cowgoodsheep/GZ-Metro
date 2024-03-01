#include"all.h"

int station_num;//统计总站数

//获取系统时间
void times()
{
	time_t rawtime;
	struct tm *timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	printf("现在的时间是: %s", asctime(timeinfo));
}

//用户文件创建
void Creat_userstxt()
{
	FILE *fp;
	if ((fp = fopen("users.txt", "rb+")) == NULL)//如果文件不存在
	{
		if ((fp = fopen("users.txt", "wb+")) == NULL)//创建文件
		{
			printf("无法创建用户文件！\n");
			exit(-1);
		}
	}
}

//线路文件创建
void Creat_linestxt()
{
	FILE *fp;
	if ((fp = fopen("lines.txt", "rb+")) == NULL)//如果文件不存在
	{
		if ((fp = fopen("lines.txt", "wb+")) == NULL)//创建文件
		{
			printf("无法建立线路文件！\n");
			exit(-1);
		}
	}
}

//站点文件创建
void Creat_stationstxt()
{
	FILE *fp;
	if ((fp = fopen("stations.txt", "rb+")) == NULL)//如果文件不存在
	{
		if ((fp = fopen("stations.txt", "wb+")) == NULL)//创建文件
		{
			printf("无法建立站点文件！\n");
			exit(-1);
		}
	}
}

//信息文件创建
void Creat_informationtxt()
{
	FILE *fp;
	if ((fp = fopen("information.txt", "rb+")) == NULL)//如果文件不存在
	{
		if ((fp = fopen("information.txt", "wb+")) == NULL)//创建文件
		{
			printf("无法建立信息文件！\n");
			exit(-1);
		}
	}
}

//注册账号
void registers()
{
	users a, b, c;//a为当前即将输入的用户资料，b为已存入文档的用户资料，c为暂存
	FILE *fp;
	system("cls");//清屏
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("|       ◎用户注册界面 ◎      |\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	times();//输出现在时间
	fp = fopen("users.txt", "rb+");//指向用户资料文件的指针
	fread(&b, sizeof(struct The_users), 1, fp);//读入一个结构体字符串到b
	while (1)//判断手机号是否为11位
	{
		printf("请输入手机号 >> ");
		scanf("%s", c.phone);
		getchar();
		if (strlen(c.phone) == 11)
		{
			strcpy(a.phone, c.phone);
			break;
		}
		else
		{
			printf("请确认您输入的手机号位数是否为 11 位\n");
		}
	}
	while (1)
	{
		if (!feof(fp))//如果未到文件尾
		{
			if (!strcmp(a.phone, b.phone))//如果两串相等
			{
				system("cls");//清屏
				printf("--------------------------------\n");
				printf("|                              |\n");
				printf("|          此用户已存在        |\n");
				printf("|                              |\n");
				printf("--------------------------------\n");
				times();//输出现在时间
				system("pause");
				fclose(fp);
				return;
			}
			fread(&b, sizeof(struct The_users), 1, fp);//读取下一行，依次判断。
		}
		else
		{
			break;
		}
	}
	printf("请输入姓名 >> ");
	scanf("%s", a.name);
	getchar();
	while (1)//判断身份证号是否为18位
	{
		printf("请输入身份证号 >> ");
		scanf("%s", c.id);
		getchar();
		if (strlen(c.id) == 18)
		{
			strcpy(a.id, c.id);
			break;
		}
		else
		{
			printf("请确认您输入的手机号位数是否为 18 位\n");
		}
	}
	printf("请输入密码(16位以下) >> ");
	scanf("%s", a.password);
	getchar();
	while (1)//判断两次密码是否一致
	{
		printf("请确认密码 >> ");
		scanf("%s", c.password);
		getchar();
		if (!strcmp(a.password, c.password))
		{
			a.money = 0;
			fwrite(&a, sizeof(users), 1, fp);
			system("cls");//清屏
			printf("--------------------------------\n");
			printf("|                              |\n");
			printf("|            注册成功          |\n");
			printf("|                              |\n");
			printf("|           请返回登录         |\n");
			printf("|                              |\n");
			printf("--------------------------------\n");
			times();//输出现在时间
			system("pause");
			fclose(fp);
			return;
		}
		else
		{
			printf("两次密码不匹配，请重新输入！\n");
		}
	}
}

//登录系统
void login()
{
	users a, b;//用b来依次记录文件中的每一个用户资料，并与当前输入的用户资料a作比对，以此检查用户是否已注册
	FILE *fp;
	system("cls");//清屏
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("|       ◎用户登陆界面 ◎      |\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	times();//输出现在时间
	fp = fopen("users.txt", "r");
	fread(&b, sizeof(struct The_users), 1, fp);//读入一个结构体 写入b
	printf("请输入您的手机号 >> ");
	scanf("%s", a.phone);
	while (1)
	{
		if (strcmp(a.phone, b.phone) == 0)//如果有此用户名
		{
			break;
		}
		else
		{
			if (!feof(fp))//如果文件没有读完
			{
				fread(&b, sizeof(struct The_users), 1, fp);
			}
			else
			{
				system("cls");//清屏
				printf("--------------------------------\n");
				printf("|                              |\n");
				printf("|        此用户名不存在        |\n");
				printf("|                              |\n");
				printf("|          请重新登陆          |\n");
				printf("|                              |\n");
				printf("--------------------------------\n");
				times();//输出现在时间
				system("pause");
				fclose(fp);
				return;
			}
		}
	}
	printf("请输入密码 >> ");
	scanf("%s", a.password);
	if (strcmp(a.password, b.password) == 0)//如果密码匹配
	{
		fclose(fp);
		system("cls");//清屏
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|           登陆成功           |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//输出现在时间
		system("pause");
		after_login_menu(b);
		return;
	}
	else
	{
		system("cls");//清屏
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|           密码错误           |\n");
		printf("|                              |\n");
		printf("|          请重新登陆          |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//输出现在时间
		system("pause");
	}
}

//修改密码系统
void changepassport(users t)
{
	FILE *fp;
	users temp;
	char newpassword1[16], newpassword2[16];
	while (1)
	{
		system("cls");
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|         ◎密码修改 ◎        |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//输出现在时间
		printf("请输入新密码 >> ");
		scanf("%s", newpassword1);
		getchar();
		printf("请确认您的新密码 >> ");
		scanf("%s", newpassword2);
		getchar();
		if (!strcmp(newpassword1, newpassword2))
		{
			break;
		}
		else
		{
			printf("两次密码不匹配！请重新输入！\n");
			system("pause");
		}
	}
	fp = fopen("users.txt", "r+");
	while (fread(&temp, sizeof(users), 1, fp))
	{
		if (!strcmp(temp.id, t.id))
		{
			strcpy(temp.password, newpassword1);
			fseek(fp, -sizeof(users), SEEK_CUR);//指针移至修改目标前
			fwrite(&temp, sizeof(users), 1, fp);
			fclose(fp);
			system("cls");
			printf("--------------------------------\n");
			printf("|                              |\n");
			printf("|         密码修改成功！       |\n");
			printf("|                              |\n");
			printf("|          请重新登陆          |\n");
			printf("|                              |\n");
			printf("--------------------------------\n");
			times();//输出现在时间
			system("pause");
			return;
		}
	}
}

//修改手机号系统
void changephone(users t)
{
	FILE *fp;
	users temp;
	char newphone1[16], newphone2[16];
	while (1)
	{
		system("cls");
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|        ◎手机号修改 ◎       |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//输出现在时间
		while (1)//判断手机号是否为11位
		{
			printf("请输入新手机号 >> ");
			scanf("%s", newphone1);
			getchar();
			if (strlen(newphone1) == 11)
			{
				break;
			}
			else
			{
				printf("请确认您输入的手机号位数是否为 11 位\n");
			}
		}
		printf("请确认您的新手机号 >> ");
		scanf("%s", newphone2);
		getchar();
		if (!strcmp(newphone1, newphone2))
		{
			break;
		}
		else
		{
			printf("两次手机号不匹配！请重新输入！\n");
			system("pause");
		}
	}
	fp = fopen("users.txt", "r+");
	while (fread(&temp, sizeof(users), 1, fp))
	{
		if (!strcmp(temp.id, t.id))
		{
			strcpy(temp.phone, newphone1);
			fseek(fp, -sizeof(users), SEEK_CUR);//指针移至修改目标前
			fwrite(&temp, sizeof(users), 1, fp);
			fclose(fp);
			system("cls");
			printf("--------------------------------\n");
			printf("|                              |\n");
			printf("|        手机号修改成功！      |\n");
			printf("|                              |\n");
			printf("|          请重新登陆          |\n");
			printf("|                              |\n");
			printf("--------------------------------\n");
			times();//输出现在时间
			system("pause");
			return;
		}
	}
}

//修改姓名系统
void changename(users t)
{
	FILE *fp;
	users temp;
	char newname1[16], newname2[16];
	while (1)
	{
		system("cls");
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|         ◎姓名修改 ◎        |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//输出现在时间
		printf("请输入新姓名 >> ");
		scanf("%s", newname1);
		getchar();
		printf("请确认您的新姓名 >> ");
		scanf("%s", newname2);
		getchar();
		if (!strcmp(newname1, newname2))
		{
			break;
		}
		else
		{
			printf("两次姓名不匹配！请重新输入！\n");
			system("pause");
		}
	}
	fp = fopen("users.txt", "r+");
	while (fread(&temp, sizeof(users), 1, fp))
	{
		if (!strcmp(temp.id, t.id))
		{
			strcpy(temp.name, newname1);
			fseek(fp, -sizeof(users), SEEK_CUR);//指针移至修改目标前
			fwrite(&temp, sizeof(users), 1, fp);
			fclose(fp);
			system("cls");
			printf("--------------------------------\n");
			printf("|                              |\n");
			printf("|         姓名修改成功！       |\n");
			printf("|                              |\n");
			printf("|          请重新登陆          |\n");
			printf("|                              |\n");
			printf("--------------------------------\n");
			times();//输出现在时间
			system("pause");
			return;
		}
	}
}

//账号注销系统
void account_delect(users t)
{
	int i, num = 0;
	char s[20];
	FILE *fp;
	users a[10000], temp; //a用于将用户信息全部读出
	system("cls");
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("| △请再次确认需要注销的账号 △|\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	times();
	printf("请输入要注销账户的身份证号 >> ");
	scanf("%s", s);
	getchar();
	if (strcmp(s, t.id))
	{
		system("cls");//清屏
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|         身份确认失败         |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//输出现在时间
		system("pause");
		return;
	}
	fp = fopen("users.txt", "rb+");
	fread(&temp, sizeof(users), 1, fp);
	while (1)
	{
		if (!feof(fp))
		{
			if (strcmp(temp.id, t.id))
			{
				a[num++] = temp;
			}
			fread(&temp, sizeof(users), 1, fp);
		}
		else
		{
			break;
		}
	}
	fclose(fp);
	fp = fopen("users.txt", "wb+"); //重置用户信息文件
	for (i = 0; i < num; ++i)
	{
		fwrite(&a[i], sizeof(users), 1, fp);
	}
	fclose(fp);
	system("cls");
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("|         用户注销成功         |\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	times();
	system("pause");
	return;
}

//充值系统
void Recharge(users t)
{
	FILE *fp;
	double moneyadd;//充值金额
	users temp;
	system("cls");
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("|           充值余额           |\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	times();//输出现在时间
	printf("请输入您需要充值的金额 >> ");
	scanf("%lf", &moneyadd);
	if (moneyadd <= 0)
	{
		system("cls");
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|      请输入一个大于0的数     |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//输出现在时间
		system("pause");
		return;
	}
	system("ZF.jpg");
	fp = fopen("users.txt", "rb+") ;
	while (fread(&temp, sizeof(users), 1, fp))
	{
		if (!strcmp(temp.phone, t.phone))
		{
			temp.money += moneyadd;
			fseek(fp, -sizeof(users), SEEK_CUR);//指针移至修改目标前
			fwrite(&temp, sizeof(users), 1, fp);
			system("cls");
			printf("----------------------------------------------\n");
			printf("|                                            |\n");
			printf("|                  充值成功！                |\n");
			printf("|                                            |\n");
			printf("|      您当前的余额为：￥%-20.2lf|\n", temp.money);
			printf("|                                            |\n");
			printf("----------------------------------------------\n");
			times();//输出现在时间
			fclose(fp);
			system("pause");
			return;
		}
	}
	return;
}

//线路输入系统
void linesInput()
{
	FILE *fp;
	Line a, b;
	fp = fopen("lines.txt", "rb+");
	system("cls");
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("|         ◎线路输入 ◎        |\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	times();//输出现在时间
	printf("请输入的线路编号 >> ");
	scanf("%d", &a.line_number);
	getchar();
	if (a.line_number == 0)//不存在0号线
	{
		system("cls");
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|          不存在0号线         |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//输出现在时间
		fclose(fp);
		system("pause");
		return;
	}
	fseek(fp, 0, SEEK_SET);
	fread(&b, sizeof(Line), 1, fp);
	while (1)
	{
		if (!feof(fp))
		{
			if (a.line_number == b.line_number)
			{
				system("cls");
				printf("--------------------------------\n");
				printf("|                              |\n");
				printf("|          该线路已存在        |\n");
				printf("|                              |\n");
				printf("--------------------------------\n");
				times();//输出现在时间
				fclose(fp);
				system("pause");
				return;
			}
			fread(&b, sizeof(Line), 1, fp);
		}
		else
		{
			break;
		}
	}
	printf("请输入路线中文名 >> ");
	gets(a.line_name);
	printf("请输入路线英文名 >> ");
	gets(a.line_EnglishName);
	printf("请输入该路线的首站点编号 >> ");
	scanf("%d", &a.firststation_number);
	if (a.firststation_number == 0)//不存在0号站点
	{
		system("cls");
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|         不存在0号站点        |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//输出现在时间
		fclose(fp);
		system("pause");
		return;
	}
	printf("请输入该路线的尾站点编号 >> ");
	scanf("%d", &a.laststation_number);
	getchar();
	if (a.laststation_number < a.firststation_number)//最后一个站点不能比第一个站点小
	{
		system("cls");
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|     尾站点不能小于首站点     |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//输出现在时间
		fclose(fp);
		system("pause");
		return;
	}
	printf("请输入该路线的初建日期 >> ");
	scanf("%s", a.startdate);
	getchar();
	fseek(fp, 0, SEEK_END);
	fwrite(&a, sizeof(Line), 1, fp);
	system("cls");
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("|         线路输入成功         |\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	times();//输出现在时间
	system("pause");
	fclose(fp);
	return;
}

//站点输入系统
void stationsInput()
{
	FILE *fp, *tfp;
	Station a, b;
	Line t;
	if ((fp = fopen("stations.txt", "rb+")) == NULL)
	{
		printf("打开文件失败！\n");
		return;
	}
	if ((tfp = fopen("lines.txt", "rb+")) == NULL)
	{
		printf("打开文件失败！\n");
		return;
	}
	system("cls");
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("|         ◎站点输入 ◎        |\n");
	printf("|                              |\n");
	printf("|           △注意！           |\n");
	printf("|      如果想要输入交点站      |\n");
	printf("|     请在该线路信息处输入     |\n");
	printf("|        xxx/xxx交点站         |\n");
	printf("|      例：102/202交点站       |\n");
	printf("|            感谢！            |\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	times();//输出现在时间
	printf("请输入该站点所属线路编号 >> ");
	scanf("%d", &a.belongLine_number);
	if (a.belongLine_number == 0)//不存在0号线
	{
		system("cls");
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|          此线路不存在        |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//输出现在时间
		fclose(fp);
		fclose(tfp);
		system("pause");
		return;
	}
	fseek(tfp, 0, SEEK_SET);
	fread(&t, sizeof(Line), 1, tfp);
	while (1)
	{
		if (a.belongLine_number != t.line_number)
		{
			if (!feof(tfp))//如果未到文件尾
			{
				fread(&t, sizeof(Line), 1, tfp);//下一个
			}
			else
			{
				system("cls");
				printf("--------------------------------\n");
				printf("|                              |\n");
				printf("|          此线路不存在        |\n");
				printf("|                              |\n");
				printf("--------------------------------\n");
				times();//输出现在时间
				fclose(fp);
				fclose(tfp);
				system("pause");
				return;
			}
		}
		else
		{
			break;
		}
	}
	printf("请输入要输入的站点编号 >> ");
	scanf("%d", &a.station_number);
	getchar();
	if (a.station_number == 0)//不存在0号站点
	{
		system("cls");
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|         不存在0号站点        |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//输出现在时间
		fclose(fp);
		fclose(tfp);
		system("pause");
		return;
	}
	fread(&b, sizeof(Station), 1, fp);
	while (1)
	{
		if ((a.belongLine_number == b.belongLine_number) && (a.station_number == b.station_number))
		{
			system("cls");
			printf("--------------------------------\n");
			printf("|                              |\n");
			printf("|          该站点已存在        |\n");
			printf("|                              |\n");
			printf("--------------------------------\n");
			times();//输出现在时间
			fclose(fp);
			fclose(tfp);
			system("pause");
			return;
		}
		else
		{
			if (!feof(fp))//如果未到文件尾
			{
				fread(&b, sizeof(Station), 1, fp);//读取下一行，依次判断
			}
			else
			{
				break;
			}
		}
	}
	if (a.station_number > t.laststation_number || a.station_number < t.firststation_number)
	{
		system("cls");
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|     该站点超出此线路范围     |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//输出现在时间
		fclose(fp);
		fclose(tfp);
		system("pause");
		return;
	}
	printf("请输入该站点的中文名 >> ");
	gets(a.station_name);
	printf("请输入该站点英文名 >> ");
	gets(a.station_Englishname);
	printf("请输入该站点的信息 >> ");
	gets(a.station_information);
	fseek(fp, 0, SEEK_END);
	fwrite(&a, sizeof(Station), 1, fp);
	system("cls");
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("|         站点输入成功         |\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	times();//输出现在时间
	system("pause");
	fclose(fp);
	fclose(tfp);
	return;
}

//线路信息排序系统
void line_information_sort()
{
	Line t[10000], temp;//将所有线路信息存入结构体数组t中,temp为临时结构体,做交换用
	FILE *fp;
	int cnt = 0, i, j;
	fp = fopen("lines.txt", "rb+");
	fread(&t[cnt++], sizeof(Line), 1, fp);
	while (1)
	{
		if (!feof(fp))
		{
			fread(&t[cnt++], sizeof(Line), 1, fp);
		}
		else
		{
			break;
		}
	}
	--cnt;//最后cnt会多1，减掉即可
	for (i = 0; i < cnt; ++i)//按照线路号从小到大排序
	{
		for (j = 0; j < cnt - i - 1; ++j)
		{
			if (t[j].line_number > t[j + 1].line_number)
			{
				temp = t[j];
				t[j] = t[j + 1];
				t[j + 1] = temp;
			}
		}
	}
	fseek(fp, 0, SEEK_SET);
	for (i = 0; i < cnt; ++i)
	{
		fwrite(&t[i], sizeof(Line), 1, fp);
	}
	fclose(fp);
	return;
}

//站点信息排序系统
void station_information_sort()
{
	Station t[10000], temp;//将所有站点信息存入结构体数组t中,temp为临时结构体,做交换用
	FILE *fp;
	int cnt = 0, i, j;
	fp = fopen("stations.txt", "rb+");
	fread(&t[cnt++], sizeof(Station), 1, fp);
	while (1)
	{
		if (!feof(fp))
		{
			fread(&t[cnt++], sizeof(Station), 1, fp);
		}
		else
		{
			break;
		}
	}
	--cnt;//最后cnt会多1，减掉即可
	for (i = 0; i < cnt; ++i)//按照所属线路号和站点号从小到大排序
	{
		for (j = 0; j < cnt - i - 1; ++j)
		{
			if (t[j].belongLine_number > t[j + 1].belongLine_number)
			{
				temp = t[j];
				t[j] = t[j + 1];
				t[j + 1] = temp;
			}
			else if (t[j].belongLine_number == t[j + 1].belongLine_number)
			{
				if (t[j].station_number > t[j + 1].station_number)
				{
					temp = t[j];
					t[j] = t[j + 1];
					t[j + 1] = temp;
				}
			}
		}
	}
	fseek(fp, 0, SEEK_SET);
	for (i = 0; i < cnt; ++i)
	{
		fwrite(&t[i], sizeof(Station), 1, fp);
	}
	fclose(fp);
	return;
}

//线路打印系统（这里用了动态链表）
void lineprint(int n)
{
	Line a;
	Station b[10000];
	FILE *fp, *fp1;//fp找线路 fp1找站点
	Station *head, *p, *t;//链表指针
	int i = 0, cnt = 0;//cnt为实际站数
	head = p = t = (Station*)malloc(sizeof(Station));
	t->next = NULL;
	head = t;
	fp = fopen("lines.txt", "rb+");
	while (1)
	{
		if (!feof(fp))
		{
			fread(&a, sizeof(Line), 1, fp);
			if (a.line_number == n)
			{
				break;
			}
		}
		else
		{
			system("cls");
			printf("--------------------------------\n");
			printf("|                              |\n");
			printf("|         找不到该线路         |\n");
			printf("|                              |\n");
			printf("--------------------------------\n");
			times();
			fclose(fp);
			return;
		}
	}
	fclose(fp);
	fp1 = fopen("stations.txt", "rb+");
	fread(&b[i++], sizeof(Station), 1, fp1);
	while (1)
	{
		if (!feof(fp1))
		{
			if (b[i - 1].belongLine_number == n)
			{
				p = head;
				while (p->next != NULL)//使用尾插法方便查询
				{
					p = p->next;
				}
				t = &b[i - 1];
				p->next = t;
				++cnt;
			}
			fread(&b[i++], sizeof(Station), 1, fp1);
		}
		else
		{
			break;
		}
	}
	if (cnt != a.laststation_number - a.firststation_number + 1)//判断该线路是否完整
	{
		system("cls");
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|     该线路站点信息不完整     |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();
		fclose(fp1);
		return;
	}
	system("cls");
	printf("                                             ◎线 路 信 息◎                                             \n");
	printf("---------------------------------------------------------------------------------------------------------\n");
	printf("| %-2d号线 | 中文名：%-16s | 英文名：%-24s | 创建日期：%-20s |\n", n, a.line_name, a.line_EnglishName, a.startdate);
	printf("---------------------------------------------------------------------------------------------------------\n");
	printf("                                             ◎站 点 信 息◎                                             \n");
	printf("---------------------------------------------------------------------------------------------------------\n");
	for (t = head->next; t != NULL; t = t->next)
	{
		printf("| %-2d号站 | 中文名：%-16s | 英文名：%-24s | 站点信息：%-20s |\n", t->station_number, t->station_name, t->station_Englishname, t->station_information);
	}
	printf("---------------------------------------------------------------------------------------------------------\n");
	times();
	fclose(fp1);
	return;
}

//打印全部线路系统
void all_lineprint()
{
	Line a;
	Station b[10000];
	FILE *fp, *fp1;//fp找线路 fp1找站点
	Station *head, *p, *t;//链表指针
	int i, cnt = 0;//cnt为实际站数
	fp = fopen("lines.txt", "rb+");
	system("cls");
	while (1)
	{
		fread(&a, sizeof(Line), 1, fp);
		if (feof(fp))
		{
			printf("无信息\n");
			fclose(fp);
			return;
		}
		if (!feof(fp))
		{
			i = 0, cnt = 0;
			head = p = t = (Station*)malloc(sizeof(Station));
			t->next = NULL;
			head = t;
			fp1 = fopen("stations.txt", "rb+");
			fread(&b[i++], sizeof(Station), 1, fp1);
			while (1)
			{
				if (!feof(fp1))
				{
					if (b[i - 1].belongLine_number == a.line_number)
					{
						p = head;
						while (p->next != NULL)//使用尾插法方便查询
						{
							p = p->next;
						}
						t = &b[i - 1];
						p->next = t;
						++cnt;
					}
					fread(&b[i++], sizeof(Station), 1, fp1);
				}
				else
				{
					break;
				}
			}
			printf("                                             ◎线 路 信 息◎                                             \n");
			printf("---------------------------------------------------------------------------------------------------------\n");
			printf("| %-2d号线 | 中文名：%-16s | 英文名：%-24s | 创建日期：%-20s |\n", a.line_number, a.line_name, a.line_EnglishName, a.startdate);
			printf("---------------------------------------------------------------------------------------------------------\n");
			printf("                                             ◎站 点 信 息◎                                             \n");
			printf("---------------------------------------------------------------------------------------------------------\n");
			for (t = head->next; t != NULL; t = t->next)
			{
				printf("| %-2d号站 | 中文名：%-16s | 英文名：%-24s | 站点信息：%-20s |\n", t->station_number, t->station_name, t->station_Englishname, t->station_information);
			}
			printf("---------------------------------------------------------------------------------------------------------\n\n");
			fclose(fp1);
		}
		else
		{
			times();
			fclose(fp);
			return;
		}
	}
}

//线路修改系统
void line_change()
{
	int n;//线路号
	FILE *fp;
	Line a;
	system("cls");
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("|         线路信息修改         |\n");
	printf("|                              |\n");
	printf("|           △注意！           |\n");
	printf("|          修改线路后          |\n");
	printf("|      请前往站点修改界面      |\n");
	printf("|     修改该线路的站点信息     |\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	times();
	printf("请输入要修改的线路号码 >> ");
	scanf("%d", &n);
	getchar();
	if ((fp = fopen("lines.txt", "rb+")) == NULL)
	{
		printf("无法正常打开线路文件！\n");
		system("pause");
		return;
	}
	fread(&a, sizeof(Line), 1, fp);
	while (1)
	{
		if (n == a.line_number)
		{
			break;
		}
		else
		{
			if (!feof(fp))
			{
				fread(&a, sizeof(Line), 1, fp);
			}
			else
			{
				system("cls");
				printf("--------------------------------\n");
				printf("|                              |\n");
				printf("|         不存在该线路         |\n");
				printf("|                              |\n");
				printf("--------------------------------\n");
				times();
				fclose(fp);
				system("pause");
				return;
			}
		}
	}
	printf("请输入修改后该线路的中文名 >> ");
	gets(a.line_name);
	printf("请输入修改后该站点英文名 >> ");
	gets(a.line_EnglishName);
	printf("请输入修改后该站点的首站点 >> ");
	scanf("%d", &a.firststation_number);
	if (a.firststation_number == 0)//不存在0号站点
	{
		system("cls");
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|         不存在0号站点        |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//输出现在时间
		fclose(fp);
		system("pause");
		return;
	}
	printf("请输入修改后该站点的尾站点 >> ");
	scanf("%d", &a.laststation_number);
	getchar();
	if (a.laststation_number < a.firststation_number)//最后一个站点不能比第一个站点小
	{
		system("cls");
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|     尾站点不能小于首站点     |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//输出现在时间
		fclose(fp);
		system("pause");
		return;
	}
	printf("请输入修改后该站点的初建日期 >> ");
	gets(a.startdate);
	fseek(fp, -sizeof(Line), SEEK_CUR);
	fwrite(&a, sizeof(Line), 1, fp);
	fclose(fp);
	system("cls");
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("|         线路修改成功         |\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	times();//输出现在时间
	system("pause");
	fclose(fp);
	return;
}

//站点修改系统
void station_change()
{
	int n, m;//n是修改的线路号，m是该线路中要修改的站点号
	FILE *fp, *fp1;
	Line a;
	Station b;
	system("cls");
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("|         站点信息修改         |\n");
	printf("|                              |\n");
	printf("|           △注意！           |\n");
	printf("|      如果想要输入交点站      |\n");
	printf("|     请在该线路信息处输入     |\n");
	printf("|       xxx/xxx的交点站        |\n");
	printf("|     例：102/202的交点站      |\n");
	printf("|            感谢！            |\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	times();
	printf("请输入要修改的站点所属的线路号 >> ");
	scanf("%d", &n);
	if ((fp = fopen("lines.txt", "rb+")) == NULL)
	{
		printf("无法正常打开线路文件！\n");
		system("pause");
		return;
	}
	fread(&a, sizeof(Line), 1, fp);
	while (1)
	{
		if (n == a.line_number)
		{
			break;
		}
		else
		{
			if (!feof(fp))
			{
				fread(&a, sizeof(Line), 1, fp);
			}
			else
			{
				system("cls");
				printf("--------------------------------\n");
				printf("|                              |\n");
				printf("|         不存在该线路         |\n");
				printf("|                              |\n");
				printf("--------------------------------\n");
				times();
				system("pause");
				return;
			}
		}
	}
	printf("请输入要修改的站点号码 >> ");
	scanf("%d", &m);
	getchar();
	if ((fp1 = fopen("stations.txt", "rb+")) == NULL)
	{
		printf("无法正常打开站点文件！\n");
		system("pause");
		fclose(fp);
		fclose(fp1);
		return;
	}
	fread(&b, sizeof(Station), 1, fp1);
	while (1)
	{
		if (m == b.station_number && b.belongLine_number == a.line_number)
		{
			break;
		}
		else
		{
			if (!feof(fp1))
			{
				fread(&b, sizeof(Station), 1, fp1);
			}
			else
			{
				system("cls");
				printf("--------------------------------\n");
				printf("|                              |\n");
				printf("|         不存在该站点         |\n");
				printf("|                              |\n");
				printf("--------------------------------\n");
				times();
				fclose(fp);
				fclose(fp1);
				system("pause");
				return;
			}
		}
	}
	printf("请输入修改后该站点的中文名 >> ");
	gets(b.station_name);
	printf("请输入修改后该站点英文名 >> ");
	gets(b.station_Englishname);
	printf("请输入修改后该站点的信息 >> ");
	gets(b.station_information);
	fseek(fp1, -sizeof(Station), SEEK_CUR);
	fwrite(&b, sizeof(Station), 1, fp1);
	system("cls");
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("|         站点修改成功         |\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	times();//输出现在时间
	system("pause");
	fclose(fp);
	fclose(fp1);
	return;
}

//线路删除系统
void line_delete()
{
	int n, i, num1 = 0, num2 = 0; //num1为除了删除线路的总线路数量,num2为除了删除站点的总站点数量
	FILE *fp, *fp1;
	Line a[1000], t1; //a用于将线路信息全部读出
	Station b[10000], t2;//b用于将站点信息全部读出
	system("cls");
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("|         线路信息删除         |\n");
	printf("|                              |\n");
	printf("|           △注意！           |\n");
	printf("|      删除线路时会同时将      |\n");
	printf("|     该线路的所有站点删除     |\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	times();
	printf("请输入要删除的线路号 >> ");
	scanf("%d", &n);
	getchar();
	fp = fopen("lines.txt", "rb+");
	fread(&t1, sizeof(Line), 1, fp);
	while (1)
	{
		if (!feof(fp))
		{
			if (t1.line_number == n)
			{
				break;
			}
			else
			{
				fread(&t1, sizeof(Line), 1, fp);
			}
		}
		else
		{
			system("cls");
			printf("--------------------------------\n");
			printf("|                              |\n");
			printf("|         不存在该线路         |\n");
			printf("|                              |\n");
			printf("--------------------------------\n");
			times();
			system("pause");
			fclose(fp);
			return;
		}
	}
	fseek(fp, 0, SEEK_SET);
	fread(&t1, sizeof(Line), 1, fp);
	while (1)//存信息时不存要删除的线路就等于删除了
	{
		if (!feof(fp))
		{
			if (t1.line_number != n)
			{
				a[num1++] = t1;
			}
			fread(&t1, sizeof(Line), 1, fp);
		}
		else
		{
			break;
		}
	}
	fclose(fp);
	fp = fopen("lines.txt", "wb+");//重置线路信息文件
	for (i = 0; i < num1; ++i)
	{
		fwrite(&a[i], sizeof(Line), 1, fp);
	}
	fclose(fp);
	//下面为删除站点
	fp1 = fopen("stations.txt", "rb+");
	fread(&t2, sizeof(Station), 1, fp1);
	while (1)//存信息时不存要删除的站点就等于删除了
	{
		if (!feof(fp))
		{
			if (t2.belongLine_number != n)
			{
				b[num2++] = t2;
			}
			fread(&t2, sizeof(Station), 1, fp1);
		}
		else
		{
			break;
		}
	}
	fclose(fp1);
	fp1 = fopen("stations.txt", "wb+");//重置站点信息文件
	for (i = 0; i < num2; ++i)
	{
		fwrite(&b[i], sizeof(Station), 1, fp1);
	}
	fclose(fp1);
	system("cls");
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("|         线路删除成功         |\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	times();
	system("pause");
	return;
}

//站点删除系统
void station_delete()
{
	int n, m, num = 0, i;//num为除了删除站点的总站点数量
	FILE *fp, *fp1;
	Line a;
	Station b[10000], t;//b用于将站点信息全部读出
	system("cls");
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("|         站点信息删除         |\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	times();
	printf("请输入要删除的站点所属的线路号 >> ");
	scanf("%d", &n);
	getchar();
	fp = fopen("lines.txt", "rb+");
	fread(&a, sizeof(Line), 1, fp);
	while (1)
	{
		if (!feof(fp))
		{
			if (a.line_number == n)
			{
				break;
			}
			else
			{
				fread(&a, sizeof(Line), 1, fp);
			}
		}
		else
		{
			system("cls");
			printf("--------------------------------\n");
			printf("|                              |\n");
			printf("|         不存在该线路         |\n");
			printf("|                              |\n");
			printf("--------------------------------\n");
			times();
			system("pause");
			fclose(fp);
			return;
		}
	}
	fclose(fp);
	printf("请输入要删除的站点号 >> ");
	scanf("%d", &m);
	getchar();
	fp1 = fopen("stations.txt", "rb+");
	fread(&t, sizeof(Station), 1, fp1);
	while (1)
	{
		if (!feof(fp1))
		{
			if (t.belongLine_number == n && t.station_number == m)
			{
				break;
			}
			else
			{
				fread(&t, sizeof(Station), 1, fp1);
			}
		}
		else
		{
			system("cls");
			printf("--------------------------------\n");
			printf("|                              |\n");
			printf("|         不存在该站点         |\n");
			printf("|                              |\n");
			printf("--------------------------------\n");
			times();
			system("pause");
			fclose(fp1);
			return;
		}
	}
	fseek(fp1, 0, SEEK_SET); //指针回到开头
	fread(&t, sizeof(Station), 1, fp1);
	while (1)//存信息时不存要删除的站点就等于删除了
	{
		if (!feof(fp))
		{
			if (!(t.belongLine_number == n && t.station_number == m))
			{
				b[num++] = t;
			}
			fread(&t, sizeof(Station), 1, fp1);
		}
		else
		{
			break;
		}
	}
	fclose(fp1);
	fp1 = fopen("stations.txt", "wb+");//重置站点信息文件
	for (i = 0; i < num; ++i)
	{
		fwrite(&b[i], sizeof(Station), 1, fp1);
	}
	fclose(fp1);
	system("cls");
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("|         站点删除成功         |\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	times();
	system("pause");
	return;
}

//车票购买系统
void buy(users t)
{
	extern int station_num;
	users temp;
	Line lll;
	Station a, b;
	FILE *fp, *fp1, *fp2;
	int first_line, first_station, end_line, end_station, sp = 0, moneycut, select;
	if ((fp = fopen("lines.txt", "rb+")) == NULL)
	{
		printf("无法正常打开线路文件！\n");
		system("pause");
		return;
	}
	if ((fp1 = fopen("stations.txt", "rb+")) == NULL)
	{
		printf("无法正常打开站点文件！\n");
		system("pause");
		return;
	}
	if ((fp2 = fopen("users.txt", "rb+")) == NULL)
	{
		printf("无法正常打开用户文件！\n");
		system("pause");
		return;
	}
	system("cls");
	all_lineprint();
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("|         ◎购买车票 ◎        |\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	times();//输出现在时间
	printf("请输入现在位于的线路编号 >> ");
	scanf("%d", &first_line);
	while (1)
	{
		if (!feof(fp))
		{
			fread(&lll, sizeof(Line), 1, fp);
			if (lll.line_number == first_line)
			{
				break;
			}
		}
		else
		{
			system("cls");
			printf("--------------------------------\n");
			printf("|                              |\n");
			printf("|          找不到该线路        |\n");
			printf("|                              |\n");
			printf("--------------------------------\n");
			times();
			fclose(fp);
			fclose(fp1);
			fclose(fp2);
			system("pause");
			return;
		}
	}
	printf("请输入现在位于的站点编号 >> ");
	scanf("%d", &first_station);
	while (1)
	{
		if (!feof(fp1))
		{
			fread(&a, sizeof(Station), 1, fp1);
			if (first_station == a.station_number && first_line == a.belongLine_number)   //如果首站点为交点站，此处为特判的预处理
			{
				if ((a.station_information[0] >= '0' && a.station_information[0] <= '9') && (a.station_information[4] >= '0' && a.station_information[4] <= '9'))
				{
					sp = 1;
				}
				break;
			}
		}
		else
		{
			system("cls");
			printf("--------------------------------\n");
			printf("|                              |\n");
			printf("|          找不到该站点        |\n");
			printf("|                              |\n");
			printf("--------------------------------\n");
			times();
			fclose(fp);
			fclose(fp1);
			fclose(fp2);
			system("pause");
			return;
		}
	}
	fseek(fp, 0, SEEK_SET);
	fseek(fp1, 0, SEEK_SET);
	printf("请输入预计到达的线路编号 >> ");
	scanf("%d", &end_line);
	while (1)
	{
		if (!feof(fp))
		{
			fread(&lll, sizeof(Line), 1, fp);
			if (lll.line_number == end_line)
			{
				break;
			}
		}
		else
		{
			system("cls");
			printf("--------------------------------\n");
			printf("|                              |\n");
			printf("|          找不到该线路        |\n");
			printf("|                              |\n");
			printf("--------------------------------\n");
			times();
			fclose(fp);
			fclose(fp1);
			fclose(fp2);
			system("pause");
			return;
		}
	}
	printf("请输入预计到达的站点编号 >> ");
	scanf("%d", &end_station);
	fseek(fp1, 0, SEEK_SET);
	while (1)
	{
		if (!feof(fp1))
		{
			fread(&b, sizeof(Station), 1, fp1);
			if (end_station == b.station_number && end_line == b.belongLine_number)
			{
				break;
			}
		}
		else
		{
			system("cls");
			printf("--------------------------------\n");
			printf("|                              |\n");
			printf("|          找不到该站点        |\n");
			printf("|                              |\n");
			printf("--------------------------------\n");
			times();
			fclose(fp);
			fclose(fp1);
			fclose(fp2);
			system("pause");
			return;
		}
	}
	system("cls");
	int judgment = 0;
	Shortest_path(first_line, first_station, end_line, end_station, 0, judgment, sp);
	moneycut = station_num;
	//如果总站数为0，不给买票
	if (station_num == 0)
	{
		system("cls");
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|      初始站与终点站相同      |\n");
		printf("|        或无法到达此站        |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();
		fclose(fp);
		fclose(fp1);
		fclose(fp2);
		system("pause");
		return;
	}
	printf("\n最短需要经过 %d 站\n\n", station_num);
	printf("请注意记录以上信息\n");
	times();
	system("pause");
	while (1)
	{
		system("cls");
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|     车票须%-2d元，是否购买？   |\n", moneycut);
		printf("|                              |\n");
		printf("|          1.确认购买          |\n");
		printf("|                              |\n");
		printf("|          0.返回菜单          |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();
		printf("请选择 >> ");
		scanf("%d", &select);
		getchar();
		switch (select)
		{
			case 1:
				while (fread(&temp, sizeof(users), 1, fp2))
				{
					if (!strcmp(temp.phone, t.phone))
					{
						if (t.money < moneycut)
						{
							system("cls");
							printf("--------------------------------\n");
							printf("|                              |\n");
							printf("|       余额不足，请充值！     |\n");
							printf("|                              |\n");
							printf("--------------------------------\n");
							times();
							fclose(fp);
							fclose(fp1);
							fclose(fp2);
							system("pause");
							return;
						}
						t.money -= moneycut;
						fseek(fp2, -sizeof(users), SEEK_CUR);
						fwrite(&t, sizeof(users), 1, fp2);
						system("cls");
						printf("--------------------------------\n");
						printf("|                              |\n");
						printf("|           出票成功！         |\n");
						printf("|                              |\n");
						printf("--------------------------------\n");
						Record_CustomAndMoney(first_line);//实时更新信息数据
						times();
						fclose(fp);
						fclose(fp1);
						fclose(fp2);
						system("pause");
						system("cls");
						printf("--------------------------------\n");
						printf("|       ◎广州市地铁车票 ◎    |\n");
						printf("|                              |\n");
						printf("|  出发站：%-20s|\n", a.station_name);
						printf("|                              |\n");
						printf("|  终点站：%-20s|\n", b.station_name);
						printf("|                              |\n");
						printf("|         票价：%-2d元           |\n", moneycut);
						printf("|                              |\n");
						printf("--------------------------------\n");
						times();
						system("pause");
						return;
					}
				}
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

//寻找最短路径系统
void Shortest_path(int first_line, int first_station, int end_line, int end_station, int path, int judgment, int sp)
{
	//(站点信息格式必须为 xxx/xxx交点站)
	extern int station_num;
	if (judgment == 1)//如果有一个递归线找到了终点，剩下的就不用找了，因为第一个找到的肯定是最短的
	{
		printf("总站数为：%d\n", path);
		return;
	}
	struct tline
	{
		int firststation_number;
		int laststation_number;
		char station_information[50][50];
	};
	struct tline tl[50];
	FILE *fp, *fp1;
	Line a;
	Station b;
	if ((fp = fopen("lines.txt", "rb+")) == NULL)
	{
		printf("无法正常打开线路文件！\n");
		system("pasue");
		return;
	}
	if ((fp1 = fopen("stations.txt", "rb+")) == NULL)
	{
		printf("无法正常打开站点文件！\n");
		system("pasue");
		return;
	}
	fseek(fp1, 0, SEEK_SET);
	fread(&a, sizeof(Line), 1, fp);
	while (!feof(fp))//每条线路
	{
		tl[a.line_number].firststation_number = a.firststation_number;
		tl[a.line_number].laststation_number = a.laststation_number;
		fseek(fp1, 0, SEEK_SET);
		fread(&b, sizeof(Station), 1, fp1);
		while (1)
		{
			if (!feof(fp1))
			{
				if (b.belongLine_number == a.line_number)
				{
					strcpy(tl[a.line_number].station_information[b.station_number], b.station_information);
					fread(&b, sizeof(Station), 1, fp1);
				}
				else
				{
					fread(&b, sizeof(Station), 1, fp1);
				}
			}
			else
			{
				break;
			}
		}
		fread(&a, sizeof(Line), 1, fp);
	}
	fclose(fp);
	fclose(fp1);
	int cnt = path, t_line = first_line, tp_station = first_station, td_station = first_station;
	int cnt1 = 0;
	if (sp && t_line != end_line)//如果首站点为交点站，特判
	{
		sp = 0;
		if (t_line == tl[t_line].station_information[first_station][0] - '0')
		{
			printf("请从%c号线的%c%c%c站换乘至%c号线\n", tl[t_line].station_information[tp_station][0], tl[t_line].station_information[tp_station][0], tl[t_line].station_information[tp_station][1], tl[t_line].station_information[tp_station][2], tl[t_line].station_information[tp_station][4]);
			Shortest_path(tl[t_line].station_information[first_station][4] - '0', (tl[t_line].station_information[first_station][5] - '0') * 10 + (tl[t_line].station_information[first_station][6] - '0'), end_line, end_station, cnt, judgment, sp);
		}
		else if (t_line == tl[t_line].station_information[first_station][4] - '0')
		{
			printf("请从%c号线的%c%c%c站换乘至%c号线\n", tl[t_line].station_information[tp_station][4], tl[t_line].station_information[tp_station][4], tl[t_line].station_information[tp_station][5], tl[t_line].station_information[tp_station][6], tl[t_line].station_information[tp_station][0]);
			Shortest_path(tl[t_line].station_information[first_station][4] - '0', (tl[t_line].station_information[first_station][5] - '0') * 10 + (tl[t_line].station_information[first_station][6] - '0'), end_line, end_station, cnt, judgment, sp);
		}
	}
	else
	{
		while (1)//站点递增判断
		{
			//如果到站了返回步数并让judgment变成1
			if (t_line == end_line && tp_station == end_station)
			{
				judgment = 1;
				station_num = cnt + cnt1;
				return;
			}
			++tp_station, ++cnt1;
			//如果站点到了此线的首站或尾站，则结束递增边的寻找
			if (tp_station < tl[t_line].firststation_number || tp_station > tl[t_line].laststation_number)
			{
				break;
			}
			//如果找到了交点，另一条线递归寻找
			if (t_line != end_line)
			{
				//以下if为判断该站信息是否满足交点
				if ((tl[t_line].station_information[tp_station][0] >= '0' && tl[t_line].station_information[tp_station][0] <= '9') && (tl[t_line].station_information[tp_station][4] >= '0' && tl[t_line].station_information[tp_station][4] <= '9'))
				{
					if (t_line == tl[t_line].station_information[tp_station][0] - '0')
					{
						if (t_line != end_line)//如果初始站与终点站相同，则无需换线
						{
							printf("请从%c号线的%c%c%c站换乘至%c号线\n", tl[t_line].station_information[tp_station][0], tl[t_line].station_information[tp_station][0], tl[t_line].station_information[tp_station][1], tl[t_line].station_information[tp_station][2], tl[t_line].station_information[tp_station][4]);
						}
						Shortest_path(tl[t_line].station_information[tp_station][4] - '0', (tl[t_line].station_information[tp_station][5] - '0') * 10 + (tl[t_line].station_information[tp_station][6] - '0'), end_line, end_station, cnt + cnt1, judgment, sp);
					}
					else if (t_line == tl[t_line].station_information[tp_station][4] - '0')
					{
						if (t_line != end_line)
						{
							printf("请从%c号线的%c%c%c站换乘至%c号线\n", tl[t_line].station_information[tp_station][4], tl[t_line].station_information[tp_station][4], tl[t_line].station_information[tp_station][5], tl[t_line].station_information[tp_station][6], tl[t_line].station_information[tp_station][0]);
						}
						Shortest_path(tl[t_line].station_information[tp_station][0] - '0', (tl[t_line].station_information[tp_station][1] - '0') * 10 + (tl[t_line].station_information[tp_station][2] - '0'), end_line, end_station, cnt + cnt1, judgment, sp);
					}
				}
			}
		}
		int cnt2 = 0;
		while (1)//站点递减判断
		{
			//如果到站了返回步数并让judgment变成1
			if (t_line == end_line && td_station == end_station)
			{
				judgment = 1;
				station_num = cnt + cnt2;
				return;
			}
			--td_station, ++cnt2;
			//如果站点到了此线的首站或尾站，则结束递减边的寻找
			if (td_station < tl[t_line].firststation_number || td_station > tl[t_line].laststation_number)
			{
				break;
			}
			//如果找到了交点，另一条线递归寻找
			if (t_line != end_line)
			{
				if ((tl[t_line].station_information[td_station][0] >= '0' && tl[t_line].station_information[td_station][0] <= '9') && (tl[t_line].station_information[td_station][4] >= '0' && tl[t_line].station_information[td_station][4] <= '9'))
				{
					if (t_line == tl[t_line].station_information[td_station][0] - '0')
					{
						if (t_line != end_line)
						{
							printf("请从%c号线的%c%c%c站换乘至%c号线\n", tl[t_line].station_information[td_station][0], tl[t_line].station_information[td_station][0], tl[t_line].station_information[td_station][1], tl[t_line].station_information[td_station][2], tl[t_line].station_information[td_station][4]);
						}
						Shortest_path(tl[t_line].station_information[td_station][4] - '0', (tl[t_line].station_information[td_station][5] - '0') * 10 + (tl[t_line].station_information[td_station][6] - '0'), end_line, end_station, cnt + cnt2, judgment, sp);
					}
					else if (t_line == tl[t_line].station_information[td_station][4] - '0')
					{
						if (t_line != end_line)
						{
							printf("请从%c号线的%c%c%c站换乘至%c号线\n", tl[t_line].station_information[td_station][4], tl[t_line].station_information[td_station][4], tl[t_line].station_information[td_station][5], tl[t_line].station_information[td_station][6], tl[t_line].station_information[td_station][0]);
						}
						Shortest_path(tl[t_line].station_information[td_station][0] - '0', (tl[t_line].station_information[td_station][1] - '0') * 10 + (tl[t_line].station_information[td_station][2] - '0'), end_line, end_station, cnt + cnt2, judgment, sp);
					}
				}
			}
		}
	}
}

//更新总收入和总票数信息系统
void Record_CustomAndMoney(int tline)
{
	extern int station_num;
	time_t curtime;
	time(&curtime);
	information a, b;
	int i;
	strcpy(a.str_time, ctime(&curtime));
	for (i = 1; i <= 50; ++i) //重置数组
	{
		a.line_money[i] = 0;
		a.line_ticket[i] = 0;
	}
	a.nowticket = 1;//当天总票数加一
	a.nowmoney = station_num;//当天总收入
	a.line_money[tline] = station_num;//单独算线路的总收入
	a.line_ticket[tline] = 1;//该线路总票数加一
	FILE *fp;
	if ((fp = fopen("information.txt", "rb+")) == NULL)
	{
		printf("无法打开信息文件\n");
		system("pause");
		return;
	}
	fread(&b, sizeof(information), 1, fp);
	if (feof(fp))
	{
		fwrite(&a, sizeof(information), 1, fp);
		fclose(fp);
		return;
	}
	while (1)
	{
		if (!feof(fp))
		{
			//如果有当天的记录，则累加并记录
			if (a.str_time[0] == b.str_time[0] && a.str_time[1] == b.str_time[1] && a.str_time[2] == b.str_time[2] && a.str_time[4] == b.str_time[4] && a.str_time[5] == b.str_time[5] && a.str_time[6] == b.str_time[6] && a.str_time[8] == b.str_time[8] && a.str_time[9] == b.str_time[9])
			{
				b.nowticket += a.nowticket;
				b.nowmoney += a.nowmoney;
				b.line_money[tline] += a.line_money[tline];
				b.line_ticket[tline] += a.line_ticket[tline];
				fseek(fp, -sizeof(information), SEEK_CUR);
				fwrite(&b, sizeof(information), 1, fp);
				fclose(fp);
				return;
			}
			else
			{
				fread(&b, sizeof(information), 1, fp);
			}
		}
		//如果没有当天的记录，则直接记录
		else
		{
			fseek(fp, 0, SEEK_END);
			fwrite(&a, sizeof(information), 1, fp);
			fclose(fp);
			return;
		}
	}
	fclose(fp);
	return;
}

//打印乘客数量和线路总收入系统
void information_printf()
{
	FILE *fp;
	information a;
	int i;
	if ((fp = fopen("information.txt", "rb+")) == NULL)
	{
		printf("无法打开信息文件\n");
		system("pause");
		return;
	}
	fread(&a, sizeof(information), 1, fp);
	if (feof(fp))
	{
		printf("无信息\n");
		fclose(fp);
		return;
	}
	while (1)
	{
		if (!feof(fp))
		{
			printf("日期：%c%c%c%c %c%c%c %c%c %c%c%c\n", a.str_time[20], a.str_time[21], a.str_time[22], a.str_time[23], a.str_time[4], a.str_time[5], a.str_time[6], a.str_time[8], a.str_time[9], a.str_time[0], a.str_time[1], a.str_time[2]);
			printf("------------------------------------\n");
			printf("|  线路  |   人流量   | 线收入(元) |\n");
			printf("------------------------------------\n");
			for (i = 1; i <= 50; ++i)
			{
				if (a.line_money[i])
				{
					printf("| %-2d号线 | %-10d | %-10d |\n", i, a.line_ticket[i], a.line_money[i]);
				}
			}
			printf("------------------------------------\n");
			printf("|  总计  | %-10d | %-10d |\n", a.nowticket, a.nowmoney);
			printf("------------------------------------\n\n");
			fread(&a, sizeof(information), 1, fp);
		}
		else
		{
			fclose(fp);
			return;
		}
	}
}

//用户信息打印
void users_printf()
{
	users a, b;
	FILE *fp;
	system("cls");
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("|     ◎用户信息查询界面 ◎    |\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	times();
	printf("请输入您需要查询的用户的身份证号 >> ");
	scanf("%s", a.id);
	getchar();
	fp = fopen("users.txt", "rb+");
	fread(&b, sizeof(struct The_users), 1, fp);
	while (1)
	{
		if (!feof(fp))
		{
			if (!strcmp(a.id, b.id))
			{
				break;
			}
			fread(&b, sizeof(struct The_users), 1, fp);
		}
		else
		{
			system("cls");
			printf("--------------------------------\n");
			printf("|                              |\n");
			printf("|          此用户不存在        |\n");
			printf("|                              |\n");
			printf("--------------------------------\n");
			times();
			fclose(fp);
			return;
		}
	}
	system("cls");
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("|           用户信息           |\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	printf("身份证号 >> %s\n", b.id);
	printf("姓名 >> %s\n", b.name);
	printf("手机号 >> %s\n", b.phone);
	printf("密码 >> %s\n", b.password);
	printf("余额 >> %.2lf\n", b.money);
	fclose(fp);
	return;
}
