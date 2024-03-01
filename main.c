#include"all.h"
int main()
{
	Creat_userstxt();
	Creat_linestxt();
	Creat_stationstxt();
	Creat_informationtxt();
	system("color 70");//界面颜色设置为灰色
	head_menu();//输出首界面
	return 0;
}
