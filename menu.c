#include"all.h"

//�׽���
void head_menu()
{
	int select;//ѡ�����
	while (1)
	{
		system("cls");//����
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("| ��ӭʹ�ù����г˵�����Ʊ���� |\n");
		printf("|                              |\n");
		printf("|          1.�������          |\n");
		printf("|                              |\n");
		printf("|          2.�û�����          |\n");
		printf("|                              |\n");
		printf("|            0.�˳�            |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//�������ʱ��
		printf("��ѡ�� >> ");
		scanf("%d", &select);//����ѡ�����
		getchar();//���������ַ��������ѭ��
		switch (select)
		{
			case 1:
				manager_menu();
				break;
			case 2:
				user_menu();
				break;
			case 0:
				printf("��л����ʹ�ã�\n");
				Sleep(1000);
				return;
			default:
				printf("������һ����Ч����\n");
				system("pause");
				break;
		}
	}
}

//�������
void manager_menu()
{
	system("cls");//����
	char t[5];
	int select;
	printf("���������Ա���� >> ");
	scanf("%s", t);
	getchar();
	if (!strcmp(t, "admin"))
	{
		printf("������ȷ\n");
	}
	else
	{
		printf("�������\n");
		system("pause");
		return;
	}
	while (1)
	{
		system("cls");
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|         �������� ��        |\n");
		printf("|                              |\n");
		printf("|          1.���빦��          |\n");
		printf("|                              |\n");
		printf("|          2.��ѯ����          |\n");
		printf("|                              |\n");
		printf("|          3.�޸Ĺ���          |\n");
		printf("|                              |\n");
		printf("|         0.������һ��         |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//�������ʱ��
		printf("��ѡ�� >> ");
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
				printf("������һ����Ч����\n");
				system("pause");
				break;
		}
	}
}

//�����������
void manager_input_menu()
{
	int select;
	while (1)
	{
		system("cls");
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|         ��������� ��        |\n");
		printf("|                              |\n");
		printf("|          1.��·����          |\n");
		printf("|                              |\n");
		printf("|          2.վ������          |\n");
		printf("|                              |\n");
		printf("|         0.������һ��         |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//�������ʱ��
		printf("��ѡ�� >> ");
		scanf("%d", &select);
		getchar();
		switch (select)
		{
			case 1:
				linesInput();
				line_information_sort();//����������򣬷����Ժ����
				break;
			case 2:
				stationsInput();
				station_information_sort();//����������򣬷����Ժ����
				break;
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

//�����ѯ����
void manager_inquire_menu()
{
	int select;
	while (1)
	{
		system("cls");
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|         ���ѯ���� ��        |\n");
		printf("|                              |\n");
		printf("|        1.��·��Ϣ��ѯ        |\n");
		printf("|                              |\n");
		printf("|        2.ͳ����Ϣ��ѯ        |\n");
		printf("|                              |\n");
		printf("|        3.ȫ����·��ѯ        |\n");
		printf("|                              |\n");
		printf("|        4.�û���Ϣ��ѯ        |\n");
		printf("|                              |\n");
		printf("|         0.������һ��         |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//�������ʱ��
		printf("��ѡ�� >> ");
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
				printf("������һ����Ч����\n");
				system("pause");
				break;
		}
	}
}

//��·��ѯ����
void line_inquire_menu()
{
	int n;
	system("cls");
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("|       ����·��ѯ���� ��      |\n");
	printf("|                              |\n");
	printf("|      0.�鿴������·��ͼ      |\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	times();//�������ʱ��
	printf("��ѡ������Ҫ��ѯ����· >> ");
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

//�����޸Ľ���
void manager_change_menu()
{
	int select;
	while (1)
	{
		system("cls");
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|         ���޸Ľ��� ��        |\n");
		printf("|                              |\n");
		printf("|        1.�û���Ϣ�޸�        |\n");
		printf("|                              |\n");
		printf("|        2.������Ϣ�޸�        |\n");
		printf("|                              |\n");
		printf("|         0.������һ��         |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//�������ʱ��
		printf("��ѡ�� >> ");
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
				printf("������һ����Ч����\n");
				system("pause");
				break;
		}
	}
}

//���������Ϣ�޸Ľ���
void manager_subway_information_change_menu()
{
	int select;
	while (1)
	{
		system("cls");
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|     �������Ϣ�޸Ľ��� ��    |\n");
		printf("|                              |\n");
		printf("|        1.��·��Ϣ�޸�        |\n");
		printf("|                              |\n");
		printf("|        2.վ����Ϣ�޸�        |\n");
		printf("|                              |\n");
		printf("|        3.��·��Ϣɾ��        |\n");
		printf("|                              |\n");
		printf("|        4.վ����Ϣɾ��        |\n");
		printf("|                              |\n");
		printf("|         0.������һ��         |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//�������ʱ��
		printf("��ѡ�� >> ");
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
				printf("������һ����Ч����\n");
				system("pause");
				break;
		}
	}
}

//�����û���Ϣ�޸Ľ���1
void manager_user_change_menu1()
{
	FILE *fp;
	users t;
	char temp[20];
	fp = fopen("users.txt", "r+");
	system("cls");
	printf("--------------------------------\n");
	printf("|                              |\n");
	printf("|     ���û���Ϣ�޸Ľ��� ��    |\n");
	printf("|                              |\n");
	printf("--------------------------------\n");
	times();
	printf("����������Ҫ�޸ĵ��û������֤�� >> ");
	scanf("%s", temp);
	getchar();
	while (1)
	{
		if (!strcmp(temp, t.id))//����д��û���
		{
			break;
		}
		else
		{
			if (!feof(fp))//����ļ�û�ж���
			{
				fread(&t, sizeof(users), 1, fp);
			}
			else
			{
				system("cls");//����
				printf("--------------------------------\n");
				printf("|                              |\n");
				printf("|         ���û�������         |\n");
				printf("|                              |\n");
				printf("--------------------------------\n");
				times();//�������ʱ��
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

//�����û���Ϣ�޸Ľ���2
void manager_user_change_menu2(users t)
{
	int select;
	while (1)
	{
		system("cls");
		printf("----------------------------------------\n");
		printf("|                                      |\n");
		printf("|    ���֤�� >> %-18s    |\n", t.id);
		printf("|                                      |\n");
		printf("|         ���û���Ϣ�޸Ľ��� ��        |\n");
		printf("|                                      |\n");
		printf("|             1.�ֻ����޸�             |\n");
		printf("|                                      |\n");
		printf("|              2.�����޸�              |\n");
		printf("|                                      |\n");
		printf("|              3.�����޸�              |\n");
		printf("|                                      |\n");
		printf("|              4.ע���˻�              |\n");
		printf("|                                      |\n");
		printf("|             0.������һ��             |\n");
		printf("|                                      |\n");
		printf("----------------------------------------\n");
		times();//�������ʱ��
		printf("��ѡ�� >> ");
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
				printf("������һ����Ч����\n");
				system("pause");
				break;
		}
	}
}

//�û�����
void user_menu()
{
	int select;
	while (1)
	{
		system("cls");//����
		printf("--------------------------------\n");
		printf("|                              |\n");
		printf("|         ���û����� ��        |\n");
		printf("|                              |\n");
		printf("|            1.��½            |\n");
		printf("|                              |\n");
		printf("|            2.ע��            |\n");
		printf("|                              |\n");
		printf("|         0.������һ��         |\n");
		printf("|                              |\n");
		printf("--------------------------------\n");
		times();//�������ʱ��
		printf("��ѡ�� >> ");
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
				printf("������һ����Ч����\n");
				system("pause");
				break;
		}
	}
}

//��½�����
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
		system("cls");//����
		printf("------------------------------------------\n");
		printf("|                                        |\n");
		printf("|     �𾴵� %-10s �û�����ӭ��     |\n", t.name);
		printf("|                                        |\n");
		printf("|               1.����Ʊ               |\n");
		printf("|                                        |\n");
		printf("|               2.�޸���Ϣ               |\n");
		printf("|                                        |\n");
		printf("|               3.��ֵ���               |\n");
		printf("|                                        |\n");
		printf("|               4.��ѯ���               |\n");
		printf("|                                        |\n");
		printf("|               5.��ѯ��·               |\n");
		printf("|                                        |\n");
		printf("|             6.��ѯȫ����·             |\n");
		printf("|                                        |\n");
		printf("|               0.�˳���¼               |\n");
		printf("|                                        |\n");
		printf("------------------------------------------\n");
		times();//�������ʱ��
		printf("��ѡ�� >> ");
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
				printf("������һ����Ч����\n");
				system("pause");
				break;
		}
	}
	return;
}

//�û��޸Ľ���
void user_change_menu(users t)
{
	int select;
	while (1)
	{
		system("cls");
		printf("----------------------------------------\n");
		printf("|                                      |\n");
		printf("|    ���֤�� >> %-18s    |\n", t.id);
		printf("|                                      |\n");
		printf("|         ���û���Ϣ�޸Ľ��� ��        |\n");
		printf("|                                      |\n");
		printf("|             1.�ֻ����޸�             |\n");
		printf("|                                      |\n");
		printf("|              2.�����޸�              |\n");
		printf("|                                      |\n");
		printf("|              3.�����޸�              |\n");
		printf("|                                      |\n");
		printf("|              4.ע���˻�              |\n");
		printf("|                                      |\n");
		printf("|             0.������һ��             |\n");
		printf("|                                      |\n");
		printf("----------------------------------------\n");
		times();//�������ʱ��
		printf("��ѡ�� >> ");
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
				printf("������һ����Ч����\n");
				system("pause");
				break;
		}
	}
}

//����ѯ����
void inquire_money_menu(users t)
{
	system("cls");//����
	printf("----------------------------------------------\n");
	printf("|                                            |\n");
	printf("|      ����ǰ�����Ϊ����%-20.2lf|\n", t.money);
	printf("|                                            |\n");
	printf("----------------------------------------------\n");
	times();//�������ʱ��
	system("pause");
	return;
}
