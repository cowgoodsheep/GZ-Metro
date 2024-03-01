#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
//结构体 
typedef struct The_users
{
	char phone[20];
	char id[20];
	char name[16];
	char password[16];
	double money;
} users;
typedef struct line
{
	int line_number;
	char line_name[50];
	char line_EnglishName[50];
	int firststation_number;
	int laststation_number;
	char startdate[50];
} Line;
typedef struct station
{
	struct station *next;
	int belongLine_number;
	int station_number;
	char station_name[50];
	char station_Englishname[50];
	char station_information[50];
} Station;
typedef struct Information
{
	char str_time[50];
	int nowticket;
	int nowmoney;
	int line_money[50];
	int line_ticket[50]; 
}information;
//界面函数 
void head_menu();
void manager_menu();
void user_menu();
void after_login_menu(users t);
void inquire_money_menu(users t);
void manager_input_menu();
void manager_inquire_menu();
void line_inquire_menu();
void manager_change_menu();
void manager_subway_information_change_menu();
void manager_user_change_menu1();
void manager_user_change_menu2(users t);
void user_change_menu(users t);
//系统函数 
void times();
void Creat_userstxt();
void registers();
void login();
void changepassport(users t);
void changephone(users t);
void Recharge(users t);
void Creat_linestxt();
void Creat_informationtxt();
void linesInput();
void line_delete();
void station_delete();
void Creat_stationstxt();
void line_change();
void stationsInput();
void account_delect(users t);
void changename(users t);
void line_information_sort(); 
void station_information_sort();
void lineprint(int n);
void station_change();
void buy(users t);
void Shortest_path(int first_line, int first_station, int end_line, int end_station, int path, int judgment, int sp);
void Record_CustomAndMoney(int tline);
void information_printf();
void all_lineprint();
void users_printf(); 
