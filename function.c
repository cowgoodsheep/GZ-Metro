#include"all.h"

int station_num;//ͳ����վ��

//��ȡϵͳʱ��
void times()
{
	time_t rawtime;
	struct tm *timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	printf("���ڵ�ʱ����: %s", asctime(timeinfo));
}

//�û��ļ�����
void Creat_userstxt()
{
	FILE *fp;
	if ((fp = fopen("users.txt", "rb+")) == NULL)//����ļ�������
	{
		if ((fp = fopen("users.txt", "wb+")) == NULL)//�����ļ�
		{
			printf("�޷������û��ļ���\n");
			exit(-1);
		}
	}
}

//��·�ļ�����
void Creat_linestxt()
{
	FILE *fp;
	if ((fp = fopen("lines.txt", "rb+")) == NULL)//����ļ�������
	{
		if ((fp = fopen("lines.txt", "wb+")) == NULL)//�����ļ�
		{
			printf("�޷�������·�ļ���\n");
			exit(-1);
		}
	}
}

//վ���ļ�����
void Creat_stationstxt()
{
	FILE *fp;
	if ((fp = fopen("stations.txt", "rb+")) == NULL)//����ļ�������
	{
		if ((fp = fopen("stations.txt", "wb+")) == NULL)//�����ļ�
		{
			printf("�޷�����վ���ļ���\n");
			exit(-1);
		}
	}
}

//��Ϣ�ļ�����
void Creat_informationtxt()
{
	FILE *fp;
	if ((fp = fopen("information.txt", "rb+")) == NULL)//����ļ�������
	{
		if ((fp = fopen("information.txt", "wb+")) == NULL)//�����ļ�
		{
			printf("�޷�������Ϣ�ļ���\n");
			exit(-1);
		}
	}
}

//ע���˺�
void registers()
{
	users a, b, c;//aΪ��ǰ����������û����ϣ�bΪ�Ѵ����ĵ����û����ϣ�cΪ�ݴ�
	FILE *fp;
	system("cls");//����
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("|       ���û�ע����� ��      |\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	times();//�������ʱ��
	fp = fopen("users.txt", "rb+");//ָ���û������ļ���ָ��
	fread(&b, sizeof(struct The_users), 1, fp);//����һ���ṹ���ַ�����b
	while (1)//�ж��ֻ����Ƿ�Ϊ11λ
	{
		printf("�������ֻ��� >> ");
		scanf("%s", c.phone);
		getchar();
		if (strlen(c.phone) == 11)
		{
			strcpy(a.phone, c.phone);
			break;
		}
		else
		{
			printf("��ȷ����������ֻ���λ���Ƿ�Ϊ 11 λ\n");
		}
	}
	while (1)
	{
		if (!feof(fp))//���δ���ļ�β
		{
			if (!strcmp(a.phone, b.phone))//����������
			{
				system("cls");//����
				printf("--------------------------------\n");
				printf("|                              |\n");
				printf("|          ���û��Ѵ���        |\n");
				printf("|                              |\n");
				printf("--------------------------------\n");
				times();//�������ʱ��
				system("pause");
				fclose(fp);
				return;
			}
			fread(&b, sizeof(struct The_users), 1, fp);//��ȡ��һ�У������жϡ�
		}
		else
		{
			break;
		}
	}
	printf("���������� >> ");
	scanf("%s", a.name);
	getchar();
	while (1)//�ж����֤���Ƿ�Ϊ18λ
	{
		printf("���������֤�� >> ");
		scanf("%s", c.id);
		getchar();
		if (strlen(c.id) == 18)
		{
			strcpy(a.id, c.id);
			break;
		}
		else
		{
			printf("��ȷ����������ֻ���λ���Ƿ�Ϊ 18 λ\n");
		}
	}
	printf("����������(16λ����) >> ");
	scanf("%s", a.password);
	getchar();
	while (1)//�ж����������Ƿ�һ��
	{
		printf("��ȷ������ >> ");
		scanf("%s", c.password);
		getchar();
		if (!strcmp(a.password, c.password))
		{
			a.money = 0;
			fwrite(&a, sizeof(users), 1, fp);
			system("cls");//����
			printf("--------------------------------\n");
			printf("|                              |\n");
			printf("|            ע��ɹ�          |\n");
			printf("|                              |\n");
			printf("|           �뷵�ص�¼         |\n");
			printf("|                              |\n");
			printf("--------------------------------\n");
			times();//�������ʱ��
			system("pause");
			fclose(fp);
			return;
		}
		else
		{
			printf("�������벻ƥ�䣬���������룡\n");
		}
	}
}

//��¼ϵͳ
void login()
{
	users a, b;//��b�����μ�¼�ļ��е�ÿһ���û����ϣ����뵱ǰ������û�����a���ȶԣ��Դ˼���û��Ƿ���ע��
	FILE *fp;
	system("cls");//����
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("|       ���û���½���� ��      |\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	times();//�������ʱ��
	fp = fopen("users.txt", "r");
	fread(&b, sizeof(struct The_users), 1, fp);//����һ���ṹ�� д��b
	printf("�����������ֻ��� >> ");
	scanf("%s", a.phone);
	while (1)
	{
		if (strcmp(a.phone, b.phone) == 0)//����д��û���
		{
			break;
		}
		else
		{
			if (!feof(fp))//����ļ�û�ж���
			{
				fread(&b, sizeof(struct The_users), 1, fp);
			}
			else
			{
				system("cls");//����
				printf("--------------------------------\n");
				printf("|                              |\n");
				printf("|        ���û���������        |\n");
				printf("|                              |\n");
				printf("|          �����µ�½          |\n");
				printf("|                              |\n");
				printf("--------------------------------\n");
				times();//�������ʱ��
				system("pause");
				fclose(fp);
				return;
			}
		}
	}
	printf("���������� >> ");
	scanf("%s", a.password);
	if (strcmp(a.password, b.password) == 0)//�������ƥ��
	{
		fclose(fp);
		system("cls");//����
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|           ��½�ɹ�           |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//�������ʱ��
		system("pause");
		after_login_menu(b);
		return;
	}
	else
	{
		system("cls");//����
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|           �������           |\n");
		printf("|                              |\n");
		printf("|          �����µ�½          |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//�������ʱ��
		system("pause");
	}
}

//�޸�����ϵͳ
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
		printf("|         �������޸� ��        |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//�������ʱ��
		printf("������������ >> ");
		scanf("%s", newpassword1);
		getchar();
		printf("��ȷ������������ >> ");
		scanf("%s", newpassword2);
		getchar();
		if (!strcmp(newpassword1, newpassword2))
		{
			break;
		}
		else
		{
			printf("�������벻ƥ�䣡���������룡\n");
			system("pause");
		}
	}
	fp = fopen("users.txt", "r+");
	while (fread(&temp, sizeof(users), 1, fp))
	{
		if (!strcmp(temp.id, t.id))
		{
			strcpy(temp.password, newpassword1);
			fseek(fp, -sizeof(users), SEEK_CUR);//ָ�������޸�Ŀ��ǰ
			fwrite(&temp, sizeof(users), 1, fp);
			fclose(fp);
			system("cls");
			printf("--------------------------------\n");
			printf("|                              |\n");
			printf("|         �����޸ĳɹ���       |\n");
			printf("|                              |\n");
			printf("|          �����µ�½          |\n");
			printf("|                              |\n");
			printf("--------------------------------\n");
			times();//�������ʱ��
			system("pause");
			return;
		}
	}
}

//�޸��ֻ���ϵͳ
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
		printf("|        ���ֻ����޸� ��       |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//�������ʱ��
		while (1)//�ж��ֻ����Ƿ�Ϊ11λ
		{
			printf("���������ֻ��� >> ");
			scanf("%s", newphone1);
			getchar();
			if (strlen(newphone1) == 11)
			{
				break;
			}
			else
			{
				printf("��ȷ����������ֻ���λ���Ƿ�Ϊ 11 λ\n");
			}
		}
		printf("��ȷ���������ֻ��� >> ");
		scanf("%s", newphone2);
		getchar();
		if (!strcmp(newphone1, newphone2))
		{
			break;
		}
		else
		{
			printf("�����ֻ��Ų�ƥ�䣡���������룡\n");
			system("pause");
		}
	}
	fp = fopen("users.txt", "r+");
	while (fread(&temp, sizeof(users), 1, fp))
	{
		if (!strcmp(temp.id, t.id))
		{
			strcpy(temp.phone, newphone1);
			fseek(fp, -sizeof(users), SEEK_CUR);//ָ�������޸�Ŀ��ǰ
			fwrite(&temp, sizeof(users), 1, fp);
			fclose(fp);
			system("cls");
			printf("--------------------------------\n");
			printf("|                              |\n");
			printf("|        �ֻ����޸ĳɹ���      |\n");
			printf("|                              |\n");
			printf("|          �����µ�½          |\n");
			printf("|                              |\n");
			printf("--------------------------------\n");
			times();//�������ʱ��
			system("pause");
			return;
		}
	}
}

//�޸�����ϵͳ
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
		printf("|         �������޸� ��        |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//�������ʱ��
		printf("������������ >> ");
		scanf("%s", newname1);
		getchar();
		printf("��ȷ������������ >> ");
		scanf("%s", newname2);
		getchar();
		if (!strcmp(newname1, newname2))
		{
			break;
		}
		else
		{
			printf("����������ƥ�䣡���������룡\n");
			system("pause");
		}
	}
	fp = fopen("users.txt", "r+");
	while (fread(&temp, sizeof(users), 1, fp))
	{
		if (!strcmp(temp.id, t.id))
		{
			strcpy(temp.name, newname1);
			fseek(fp, -sizeof(users), SEEK_CUR);//ָ�������޸�Ŀ��ǰ
			fwrite(&temp, sizeof(users), 1, fp);
			fclose(fp);
			system("cls");
			printf("--------------------------------\n");
			printf("|                              |\n");
			printf("|         �����޸ĳɹ���       |\n");
			printf("|                              |\n");
			printf("|          �����µ�½          |\n");
			printf("|                              |\n");
			printf("--------------------------------\n");
			times();//�������ʱ��
			system("pause");
			return;
		}
	}
}

//�˺�ע��ϵͳ
void account_delect(users t)
{
	int i, num = 0;
	char s[20];
	FILE *fp;
	users a[10000], temp; //a���ڽ��û���Ϣȫ������
	system("cls");
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("| �����ٴ�ȷ����Ҫע�����˺� ��|\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	times();
	printf("������Ҫע���˻������֤�� >> ");
	scanf("%s", s);
	getchar();
	if (strcmp(s, t.id))
	{
		system("cls");//����
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|         ���ȷ��ʧ��         |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//�������ʱ��
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
	fp = fopen("users.txt", "wb+"); //�����û���Ϣ�ļ�
	for (i = 0; i < num; ++i)
	{
		fwrite(&a[i], sizeof(users), 1, fp);
	}
	fclose(fp);
	system("cls");
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("|         �û�ע���ɹ�         |\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	times();
	system("pause");
	return;
}

//��ֵϵͳ
void Recharge(users t)
{
	FILE *fp;
	double moneyadd;//��ֵ���
	users temp;
	system("cls");
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("|           ��ֵ���           |\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	times();//�������ʱ��
	printf("����������Ҫ��ֵ�Ľ�� >> ");
	scanf("%lf", &moneyadd);
	if (moneyadd <= 0)
	{
		system("cls");
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|      ������һ������0����     |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//�������ʱ��
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
			fseek(fp, -sizeof(users), SEEK_CUR);//ָ�������޸�Ŀ��ǰ
			fwrite(&temp, sizeof(users), 1, fp);
			system("cls");
			printf("----------------------------------------------\n");
			printf("|                                            |\n");
			printf("|                  ��ֵ�ɹ���                |\n");
			printf("|                                            |\n");
			printf("|      ����ǰ�����Ϊ����%-20.2lf|\n", temp.money);
			printf("|                                            |\n");
			printf("----------------------------------------------\n");
			times();//�������ʱ��
			fclose(fp);
			system("pause");
			return;
		}
	}
	return;
}

//��·����ϵͳ
void linesInput()
{
	FILE *fp;
	Line a, b;
	fp = fopen("lines.txt", "rb+");
	system("cls");
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("|         ����·���� ��        |\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	times();//�������ʱ��
	printf("���������·��� >> ");
	scanf("%d", &a.line_number);
	getchar();
	if (a.line_number == 0)//������0����
	{
		system("cls");
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|          ������0����         |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//�������ʱ��
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
				printf("|          ����·�Ѵ���        |\n");
				printf("|                              |\n");
				printf("--------------------------------\n");
				times();//�������ʱ��
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
	printf("������·�������� >> ");
	gets(a.line_name);
	printf("������·��Ӣ���� >> ");
	gets(a.line_EnglishName);
	printf("�������·�ߵ���վ���� >> ");
	scanf("%d", &a.firststation_number);
	if (a.firststation_number == 0)//������0��վ��
	{
		system("cls");
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|         ������0��վ��        |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//�������ʱ��
		fclose(fp);
		system("pause");
		return;
	}
	printf("�������·�ߵ�βվ���� >> ");
	scanf("%d", &a.laststation_number);
	getchar();
	if (a.laststation_number < a.firststation_number)//���һ��վ�㲻�ܱȵ�һ��վ��С
	{
		system("cls");
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|     βվ�㲻��С����վ��     |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//�������ʱ��
		fclose(fp);
		system("pause");
		return;
	}
	printf("�������·�ߵĳ������� >> ");
	scanf("%s", a.startdate);
	getchar();
	fseek(fp, 0, SEEK_END);
	fwrite(&a, sizeof(Line), 1, fp);
	system("cls");
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("|         ��·����ɹ�         |\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	times();//�������ʱ��
	system("pause");
	fclose(fp);
	return;
}

//վ������ϵͳ
void stationsInput()
{
	FILE *fp, *tfp;
	Station a, b;
	Line t;
	if ((fp = fopen("stations.txt", "rb+")) == NULL)
	{
		printf("���ļ�ʧ�ܣ�\n");
		return;
	}
	if ((tfp = fopen("lines.txt", "rb+")) == NULL)
	{
		printf("���ļ�ʧ�ܣ�\n");
		return;
	}
	system("cls");
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("|         ��վ������ ��        |\n");
	printf("|                              |\n");
	printf("|           ��ע�⣡           |\n");
	printf("|      �����Ҫ���뽻��վ      |\n");
	printf("|     ���ڸ���·��Ϣ������     |\n");
	printf("|        xxx/xxx����վ         |\n");
	printf("|      ����102/202����վ       |\n");
	printf("|            ��л��            |\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	times();//�������ʱ��
	printf("�������վ��������·��� >> ");
	scanf("%d", &a.belongLine_number);
	if (a.belongLine_number == 0)//������0����
	{
		system("cls");
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|          ����·������        |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//�������ʱ��
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
			if (!feof(tfp))//���δ���ļ�β
			{
				fread(&t, sizeof(Line), 1, tfp);//��һ��
			}
			else
			{
				system("cls");
				printf("--------------------------------\n");
				printf("|                              |\n");
				printf("|          ����·������        |\n");
				printf("|                              |\n");
				printf("--------------------------------\n");
				times();//�������ʱ��
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
	printf("������Ҫ�����վ���� >> ");
	scanf("%d", &a.station_number);
	getchar();
	if (a.station_number == 0)//������0��վ��
	{
		system("cls");
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|         ������0��վ��        |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//�������ʱ��
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
			printf("|          ��վ���Ѵ���        |\n");
			printf("|                              |\n");
			printf("--------------------------------\n");
			times();//�������ʱ��
			fclose(fp);
			fclose(tfp);
			system("pause");
			return;
		}
		else
		{
			if (!feof(fp))//���δ���ļ�β
			{
				fread(&b, sizeof(Station), 1, fp);//��ȡ��һ�У������ж�
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
		printf("|     ��վ�㳬������·��Χ     |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//�������ʱ��
		fclose(fp);
		fclose(tfp);
		system("pause");
		return;
	}
	printf("�������վ��������� >> ");
	gets(a.station_name);
	printf("�������վ��Ӣ���� >> ");
	gets(a.station_Englishname);
	printf("�������վ�����Ϣ >> ");
	gets(a.station_information);
	fseek(fp, 0, SEEK_END);
	fwrite(&a, sizeof(Station), 1, fp);
	system("cls");
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("|         վ������ɹ�         |\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	times();//�������ʱ��
	system("pause");
	fclose(fp);
	fclose(tfp);
	return;
}

//��·��Ϣ����ϵͳ
void line_information_sort()
{
	Line t[10000], temp;//��������·��Ϣ����ṹ������t��,tempΪ��ʱ�ṹ��,��������
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
	--cnt;//���cnt���1����������
	for (i = 0; i < cnt; ++i)//������·�Ŵ�С��������
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

//վ����Ϣ����ϵͳ
void station_information_sort()
{
	Station t[10000], temp;//������վ����Ϣ����ṹ������t��,tempΪ��ʱ�ṹ��,��������
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
	--cnt;//���cnt���1����������
	for (i = 0; i < cnt; ++i)//����������·�ź�վ��Ŵ�С��������
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

//��·��ӡϵͳ���������˶�̬����
void lineprint(int n)
{
	Line a;
	Station b[10000];
	FILE *fp, *fp1;//fp����· fp1��վ��
	Station *head, *p, *t;//����ָ��
	int i = 0, cnt = 0;//cntΪʵ��վ��
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
			printf("|         �Ҳ�������·         |\n");
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
				while (p->next != NULL)//ʹ��β�巨�����ѯ
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
	if (cnt != a.laststation_number - a.firststation_number + 1)//�жϸ���·�Ƿ�����
	{
		system("cls");
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|     ����·վ����Ϣ������     |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();
		fclose(fp1);
		return;
	}
	system("cls");
	printf("                                             ���� · �� Ϣ��                                             \n");
	printf("---------------------------------------------------------------------------------------------------------\n");
	printf("| %-2d���� | ��������%-16s | Ӣ������%-24s | �������ڣ�%-20s |\n", n, a.line_name, a.line_EnglishName, a.startdate);
	printf("---------------------------------------------------------------------------------------------------------\n");
	printf("                                             ��վ �� �� Ϣ��                                             \n");
	printf("---------------------------------------------------------------------------------------------------------\n");
	for (t = head->next; t != NULL; t = t->next)
	{
		printf("| %-2d��վ | ��������%-16s | Ӣ������%-24s | վ����Ϣ��%-20s |\n", t->station_number, t->station_name, t->station_Englishname, t->station_information);
	}
	printf("---------------------------------------------------------------------------------------------------------\n");
	times();
	fclose(fp1);
	return;
}

//��ӡȫ����·ϵͳ
void all_lineprint()
{
	Line a;
	Station b[10000];
	FILE *fp, *fp1;//fp����· fp1��վ��
	Station *head, *p, *t;//����ָ��
	int i, cnt = 0;//cntΪʵ��վ��
	fp = fopen("lines.txt", "rb+");
	system("cls");
	while (1)
	{
		fread(&a, sizeof(Line), 1, fp);
		if (feof(fp))
		{
			printf("����Ϣ\n");
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
						while (p->next != NULL)//ʹ��β�巨�����ѯ
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
			printf("                                             ���� · �� Ϣ��                                             \n");
			printf("---------------------------------------------------------------------------------------------------------\n");
			printf("| %-2d���� | ��������%-16s | Ӣ������%-24s | �������ڣ�%-20s |\n", a.line_number, a.line_name, a.line_EnglishName, a.startdate);
			printf("---------------------------------------------------------------------------------------------------------\n");
			printf("                                             ��վ �� �� Ϣ��                                             \n");
			printf("---------------------------------------------------------------------------------------------------------\n");
			for (t = head->next; t != NULL; t = t->next)
			{
				printf("| %-2d��վ | ��������%-16s | Ӣ������%-24s | վ����Ϣ��%-20s |\n", t->station_number, t->station_name, t->station_Englishname, t->station_information);
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

//��·�޸�ϵͳ
void line_change()
{
	int n;//��·��
	FILE *fp;
	Line a;
	system("cls");
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("|         ��·��Ϣ�޸�         |\n");
	printf("|                              |\n");
	printf("|           ��ע�⣡           |\n");
	printf("|          �޸���·��          |\n");
	printf("|      ��ǰ��վ���޸Ľ���      |\n");
	printf("|     �޸ĸ���·��վ����Ϣ     |\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	times();
	printf("������Ҫ�޸ĵ���·���� >> ");
	scanf("%d", &n);
	getchar();
	if ((fp = fopen("lines.txt", "rb+")) == NULL)
	{
		printf("�޷���������·�ļ���\n");
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
				printf("|         �����ڸ���·         |\n");
				printf("|                              |\n");
				printf("--------------------------------\n");
				times();
				fclose(fp);
				system("pause");
				return;
			}
		}
	}
	printf("�������޸ĺ����·�������� >> ");
	gets(a.line_name);
	printf("�������޸ĺ��վ��Ӣ���� >> ");
	gets(a.line_EnglishName);
	printf("�������޸ĺ��վ�����վ�� >> ");
	scanf("%d", &a.firststation_number);
	if (a.firststation_number == 0)//������0��վ��
	{
		system("cls");
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|         ������0��վ��        |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//�������ʱ��
		fclose(fp);
		system("pause");
		return;
	}
	printf("�������޸ĺ��վ���βվ�� >> ");
	scanf("%d", &a.laststation_number);
	getchar();
	if (a.laststation_number < a.firststation_number)//���һ��վ�㲻�ܱȵ�һ��վ��С
	{
		system("cls");
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|     βվ�㲻��С����վ��     |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//�������ʱ��
		fclose(fp);
		system("pause");
		return;
	}
	printf("�������޸ĺ��վ��ĳ������� >> ");
	gets(a.startdate);
	fseek(fp, -sizeof(Line), SEEK_CUR);
	fwrite(&a, sizeof(Line), 1, fp);
	fclose(fp);
	system("cls");
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("|         ��·�޸ĳɹ�         |\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	times();//�������ʱ��
	system("pause");
	fclose(fp);
	return;
}

//վ���޸�ϵͳ
void station_change()
{
	int n, m;//n���޸ĵ���·�ţ�m�Ǹ���·��Ҫ�޸ĵ�վ���
	FILE *fp, *fp1;
	Line a;
	Station b;
	system("cls");
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("|         վ����Ϣ�޸�         |\n");
	printf("|                              |\n");
	printf("|           ��ע�⣡           |\n");
	printf("|      �����Ҫ���뽻��վ      |\n");
	printf("|     ���ڸ���·��Ϣ������     |\n");
	printf("|       xxx/xxx�Ľ���վ        |\n");
	printf("|     ����102/202�Ľ���վ      |\n");
	printf("|            ��л��            |\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	times();
	printf("������Ҫ�޸ĵ�վ����������·�� >> ");
	scanf("%d", &n);
	if ((fp = fopen("lines.txt", "rb+")) == NULL)
	{
		printf("�޷���������·�ļ���\n");
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
				printf("|         �����ڸ���·         |\n");
				printf("|                              |\n");
				printf("--------------------------------\n");
				times();
				system("pause");
				return;
			}
		}
	}
	printf("������Ҫ�޸ĵ�վ����� >> ");
	scanf("%d", &m);
	getchar();
	if ((fp1 = fopen("stations.txt", "rb+")) == NULL)
	{
		printf("�޷�������վ���ļ���\n");
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
				printf("|         �����ڸ�վ��         |\n");
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
	printf("�������޸ĺ��վ��������� >> ");
	gets(b.station_name);
	printf("�������޸ĺ��վ��Ӣ���� >> ");
	gets(b.station_Englishname);
	printf("�������޸ĺ��վ�����Ϣ >> ");
	gets(b.station_information);
	fseek(fp1, -sizeof(Station), SEEK_CUR);
	fwrite(&b, sizeof(Station), 1, fp1);
	system("cls");
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("|         վ���޸ĳɹ�         |\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	times();//�������ʱ��
	system("pause");
	fclose(fp);
	fclose(fp1);
	return;
}

//��·ɾ��ϵͳ
void line_delete()
{
	int n, i, num1 = 0, num2 = 0; //num1Ϊ����ɾ����·������·����,num2Ϊ����ɾ��վ�����վ������
	FILE *fp, *fp1;
	Line a[1000], t1; //a���ڽ���·��Ϣȫ������
	Station b[10000], t2;//b���ڽ�վ����Ϣȫ������
	system("cls");
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("|         ��·��Ϣɾ��         |\n");
	printf("|                              |\n");
	printf("|           ��ע�⣡           |\n");
	printf("|      ɾ����·ʱ��ͬʱ��      |\n");
	printf("|     ����·������վ��ɾ��     |\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	times();
	printf("������Ҫɾ������·�� >> ");
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
			printf("|         �����ڸ���·         |\n");
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
	while (1)//����Ϣʱ����Ҫɾ������·�͵���ɾ����
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
	fp = fopen("lines.txt", "wb+");//������·��Ϣ�ļ�
	for (i = 0; i < num1; ++i)
	{
		fwrite(&a[i], sizeof(Line), 1, fp);
	}
	fclose(fp);
	//����Ϊɾ��վ��
	fp1 = fopen("stations.txt", "rb+");
	fread(&t2, sizeof(Station), 1, fp1);
	while (1)//����Ϣʱ����Ҫɾ����վ��͵���ɾ����
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
	fp1 = fopen("stations.txt", "wb+");//����վ����Ϣ�ļ�
	for (i = 0; i < num2; ++i)
	{
		fwrite(&b[i], sizeof(Station), 1, fp1);
	}
	fclose(fp1);
	system("cls");
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("|         ��·ɾ���ɹ�         |\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	times();
	system("pause");
	return;
}

//վ��ɾ��ϵͳ
void station_delete()
{
	int n, m, num = 0, i;//numΪ����ɾ��վ�����վ������
	FILE *fp, *fp1;
	Line a;
	Station b[10000], t;//b���ڽ�վ����Ϣȫ������
	system("cls");
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("|         վ����Ϣɾ��         |\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	times();
	printf("������Ҫɾ����վ����������·�� >> ");
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
			printf("|         �����ڸ���·         |\n");
			printf("|                              |\n");
			printf("--------------------------------\n");
			times();
			system("pause");
			fclose(fp);
			return;
		}
	}
	fclose(fp);
	printf("������Ҫɾ����վ��� >> ");
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
			printf("|         �����ڸ�վ��         |\n");
			printf("|                              |\n");
			printf("--------------------------------\n");
			times();
			system("pause");
			fclose(fp1);
			return;
		}
	}
	fseek(fp1, 0, SEEK_SET); //ָ��ص���ͷ
	fread(&t, sizeof(Station), 1, fp1);
	while (1)//����Ϣʱ����Ҫɾ����վ��͵���ɾ����
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
	fp1 = fopen("stations.txt", "wb+");//����վ����Ϣ�ļ�
	for (i = 0; i < num; ++i)
	{
		fwrite(&b[i], sizeof(Station), 1, fp1);
	}
	fclose(fp1);
	system("cls");
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("|         վ��ɾ���ɹ�         |\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	times();
	system("pause");
	return;
}

//��Ʊ����ϵͳ
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
		printf("�޷���������·�ļ���\n");
		system("pause");
		return;
	}
	if ((fp1 = fopen("stations.txt", "rb+")) == NULL)
	{
		printf("�޷�������վ���ļ���\n");
		system("pause");
		return;
	}
	if ((fp2 = fopen("users.txt", "rb+")) == NULL)
	{
		printf("�޷��������û��ļ���\n");
		system("pause");
		return;
	}
	system("cls");
	all_lineprint();
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("|         ����Ʊ ��        |\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	times();//�������ʱ��
	printf("����������λ�ڵ���·��� >> ");
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
			printf("|          �Ҳ�������·        |\n");
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
	printf("����������λ�ڵ�վ���� >> ");
	scanf("%d", &first_station);
	while (1)
	{
		if (!feof(fp1))
		{
			fread(&a, sizeof(Station), 1, fp1);
			if (first_station == a.station_number && first_line == a.belongLine_number)   //�����վ��Ϊ����վ���˴�Ϊ���е�Ԥ����
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
			printf("|          �Ҳ�����վ��        |\n");
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
	printf("������Ԥ�Ƶ������·��� >> ");
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
			printf("|          �Ҳ�������·        |\n");
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
	printf("������Ԥ�Ƶ����վ���� >> ");
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
			printf("|          �Ҳ�����վ��        |\n");
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
	//�����վ��Ϊ0��������Ʊ
	if (station_num == 0)
	{
		system("cls");
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|      ��ʼվ���յ�վ��ͬ      |\n");
		printf("|        ���޷������վ        |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();
		fclose(fp);
		fclose(fp1);
		fclose(fp2);
		system("pause");
		return;
	}
	printf("\n�����Ҫ���� %d վ\n\n", station_num);
	printf("��ע���¼������Ϣ\n");
	times();
	system("pause");
	while (1)
	{
		system("cls");
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|     ��Ʊ��%-2dԪ���Ƿ���   |\n", moneycut);
		printf("|                              |\n");
		printf("|          1.ȷ�Ϲ���          |\n");
		printf("|                              |\n");
		printf("|          0.���ز˵�          |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();
		printf("��ѡ�� >> ");
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
							printf("|       ���㣬���ֵ��     |\n");
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
						printf("|           ��Ʊ�ɹ���         |\n");
						printf("|                              |\n");
						printf("--------------------------------\n");
						Record_CustomAndMoney(first_line);//ʵʱ������Ϣ����
						times();
						fclose(fp);
						fclose(fp1);
						fclose(fp2);
						system("pause");
						system("cls");
						printf("--------------------------------\n");
						printf("|       ������е�����Ʊ ��    |\n");
						printf("|                              |\n");
						printf("|  ����վ��%-20s|\n", a.station_name);
						printf("|                              |\n");
						printf("|  �յ�վ��%-20s|\n", b.station_name);
						printf("|                              |\n");
						printf("|         Ʊ�ۣ�%-2dԪ           |\n", moneycut);
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
				printf("������һ����Ч����\n");
				system("pause");
				break;
		}
	}
}

//Ѱ�����·��ϵͳ
void Shortest_path(int first_line, int first_station, int end_line, int end_station, int path, int judgment, int sp)
{
	//(վ����Ϣ��ʽ����Ϊ xxx/xxx����վ)
	extern int station_num;
	if (judgment == 1)//�����һ���ݹ����ҵ����յ㣬ʣ�µľͲ������ˣ���Ϊ��һ���ҵ��Ŀ϶�����̵�
	{
		printf("��վ��Ϊ��%d\n", path);
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
		printf("�޷���������·�ļ���\n");
		system("pasue");
		return;
	}
	if ((fp1 = fopen("stations.txt", "rb+")) == NULL)
	{
		printf("�޷�������վ���ļ���\n");
		system("pasue");
		return;
	}
	fseek(fp1, 0, SEEK_SET);
	fread(&a, sizeof(Line), 1, fp);
	while (!feof(fp))//ÿ����·
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
	if (sp && t_line != end_line)//�����վ��Ϊ����վ������
	{
		sp = 0;
		if (t_line == tl[t_line].station_information[first_station][0] - '0')
		{
			printf("���%c���ߵ�%c%c%cվ������%c����\n", tl[t_line].station_information[tp_station][0], tl[t_line].station_information[tp_station][0], tl[t_line].station_information[tp_station][1], tl[t_line].station_information[tp_station][2], tl[t_line].station_information[tp_station][4]);
			Shortest_path(tl[t_line].station_information[first_station][4] - '0', (tl[t_line].station_information[first_station][5] - '0') * 10 + (tl[t_line].station_information[first_station][6] - '0'), end_line, end_station, cnt, judgment, sp);
		}
		else if (t_line == tl[t_line].station_information[first_station][4] - '0')
		{
			printf("���%c���ߵ�%c%c%cվ������%c����\n", tl[t_line].station_information[tp_station][4], tl[t_line].station_information[tp_station][4], tl[t_line].station_information[tp_station][5], tl[t_line].station_information[tp_station][6], tl[t_line].station_information[tp_station][0]);
			Shortest_path(tl[t_line].station_information[first_station][4] - '0', (tl[t_line].station_information[first_station][5] - '0') * 10 + (tl[t_line].station_information[first_station][6] - '0'), end_line, end_station, cnt, judgment, sp);
		}
	}
	else
	{
		while (1)//վ������ж�
		{
			//�����վ�˷��ز�������judgment���1
			if (t_line == end_line && tp_station == end_station)
			{
				judgment = 1;
				station_num = cnt + cnt1;
				return;
			}
			++tp_station, ++cnt1;
			//���վ�㵽�˴��ߵ���վ��βվ������������ߵ�Ѱ��
			if (tp_station < tl[t_line].firststation_number || tp_station > tl[t_line].laststation_number)
			{
				break;
			}
			//����ҵ��˽��㣬��һ���ߵݹ�Ѱ��
			if (t_line != end_line)
			{
				//����ifΪ�жϸ�վ��Ϣ�Ƿ����㽻��
				if ((tl[t_line].station_information[tp_station][0] >= '0' && tl[t_line].station_information[tp_station][0] <= '9') && (tl[t_line].station_information[tp_station][4] >= '0' && tl[t_line].station_information[tp_station][4] <= '9'))
				{
					if (t_line == tl[t_line].station_information[tp_station][0] - '0')
					{
						if (t_line != end_line)//�����ʼվ���յ�վ��ͬ�������軻��
						{
							printf("���%c���ߵ�%c%c%cվ������%c����\n", tl[t_line].station_information[tp_station][0], tl[t_line].station_information[tp_station][0], tl[t_line].station_information[tp_station][1], tl[t_line].station_information[tp_station][2], tl[t_line].station_information[tp_station][4]);
						}
						Shortest_path(tl[t_line].station_information[tp_station][4] - '0', (tl[t_line].station_information[tp_station][5] - '0') * 10 + (tl[t_line].station_information[tp_station][6] - '0'), end_line, end_station, cnt + cnt1, judgment, sp);
					}
					else if (t_line == tl[t_line].station_information[tp_station][4] - '0')
					{
						if (t_line != end_line)
						{
							printf("���%c���ߵ�%c%c%cվ������%c����\n", tl[t_line].station_information[tp_station][4], tl[t_line].station_information[tp_station][4], tl[t_line].station_information[tp_station][5], tl[t_line].station_information[tp_station][6], tl[t_line].station_information[tp_station][0]);
						}
						Shortest_path(tl[t_line].station_information[tp_station][0] - '0', (tl[t_line].station_information[tp_station][1] - '0') * 10 + (tl[t_line].station_information[tp_station][2] - '0'), end_line, end_station, cnt + cnt1, judgment, sp);
					}
				}
			}
		}
		int cnt2 = 0;
		while (1)//վ��ݼ��ж�
		{
			//�����վ�˷��ز�������judgment���1
			if (t_line == end_line && td_station == end_station)
			{
				judgment = 1;
				station_num = cnt + cnt2;
				return;
			}
			--td_station, ++cnt2;
			//���վ�㵽�˴��ߵ���վ��βվ��������ݼ��ߵ�Ѱ��
			if (td_station < tl[t_line].firststation_number || td_station > tl[t_line].laststation_number)
			{
				break;
			}
			//����ҵ��˽��㣬��һ���ߵݹ�Ѱ��
			if (t_line != end_line)
			{
				if ((tl[t_line].station_information[td_station][0] >= '0' && tl[t_line].station_information[td_station][0] <= '9') && (tl[t_line].station_information[td_station][4] >= '0' && tl[t_line].station_information[td_station][4] <= '9'))
				{
					if (t_line == tl[t_line].station_information[td_station][0] - '0')
					{
						if (t_line != end_line)
						{
							printf("���%c���ߵ�%c%c%cվ������%c����\n", tl[t_line].station_information[td_station][0], tl[t_line].station_information[td_station][0], tl[t_line].station_information[td_station][1], tl[t_line].station_information[td_station][2], tl[t_line].station_information[td_station][4]);
						}
						Shortest_path(tl[t_line].station_information[td_station][4] - '0', (tl[t_line].station_information[td_station][5] - '0') * 10 + (tl[t_line].station_information[td_station][6] - '0'), end_line, end_station, cnt + cnt2, judgment, sp);
					}
					else if (t_line == tl[t_line].station_information[td_station][4] - '0')
					{
						if (t_line != end_line)
						{
							printf("���%c���ߵ�%c%c%cվ������%c����\n", tl[t_line].station_information[td_station][4], tl[t_line].station_information[td_station][4], tl[t_line].station_information[td_station][5], tl[t_line].station_information[td_station][6], tl[t_line].station_information[td_station][0]);
						}
						Shortest_path(tl[t_line].station_information[td_station][0] - '0', (tl[t_line].station_information[td_station][1] - '0') * 10 + (tl[t_line].station_information[td_station][2] - '0'), end_line, end_station, cnt + cnt2, judgment, sp);
					}
				}
			}
		}
	}
}

//�������������Ʊ����Ϣϵͳ
void Record_CustomAndMoney(int tline)
{
	extern int station_num;
	time_t curtime;
	time(&curtime);
	information a, b;
	int i;
	strcpy(a.str_time, ctime(&curtime));
	for (i = 1; i <= 50; ++i) //��������
	{
		a.line_money[i] = 0;
		a.line_ticket[i] = 0;
	}
	a.nowticket = 1;//������Ʊ����һ
	a.nowmoney = station_num;//����������
	a.line_money[tline] = station_num;//��������·��������
	a.line_ticket[tline] = 1;//����·��Ʊ����һ
	FILE *fp;
	if ((fp = fopen("information.txt", "rb+")) == NULL)
	{
		printf("�޷�����Ϣ�ļ�\n");
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
			//����е���ļ�¼�����ۼӲ���¼
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
		//���û�е���ļ�¼����ֱ�Ӽ�¼
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

//��ӡ�˿���������·������ϵͳ
void information_printf()
{
	FILE *fp;
	information a;
	int i;
	if ((fp = fopen("information.txt", "rb+")) == NULL)
	{
		printf("�޷�����Ϣ�ļ�\n");
		system("pause");
		return;
	}
	fread(&a, sizeof(information), 1, fp);
	if (feof(fp))
	{
		printf("����Ϣ\n");
		fclose(fp);
		return;
	}
	while (1)
	{
		if (!feof(fp))
		{
			printf("���ڣ�%c%c%c%c %c%c%c %c%c %c%c%c\n", a.str_time[20], a.str_time[21], a.str_time[22], a.str_time[23], a.str_time[4], a.str_time[5], a.str_time[6], a.str_time[8], a.str_time[9], a.str_time[0], a.str_time[1], a.str_time[2]);
			printf("------------------------------------\n");
			printf("|  ��·  |   ������   | ������(Ԫ) |\n");
			printf("------------------------------------\n");
			for (i = 1; i <= 50; ++i)
			{
				if (a.line_money[i])
				{
					printf("| %-2d���� | %-10d | %-10d |\n", i, a.line_ticket[i], a.line_money[i]);
				}
			}
			printf("------------------------------------\n");
			printf("|  �ܼ�  | %-10d | %-10d |\n", a.nowticket, a.nowmoney);
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

//�û���Ϣ��ӡ
void users_printf()
{
	users a, b;
	FILE *fp;
	system("cls");
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("|     ���û���Ϣ��ѯ���� ��    |\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	times();
	printf("����������Ҫ��ѯ���û������֤�� >> ");
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
			printf("|          ���û�������        |\n");
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
	printf("|           �û���Ϣ           |\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	printf("���֤�� >> %s\n", b.id);
	printf("���� >> %s\n", b.name);
	printf("�ֻ��� >> %s\n", b.phone);
	printf("���� >> %s\n", b.password);
	printf("��� >> %.2lf\n", b.money);
	fclose(fp);
	return;
}
