#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include "common.h"
#include "ware.h"

char printMainMenu(); //打印主菜单
char printSubMain();//打印子菜单 

 
int main()
{
	char menuID;
	init();
	while(1){
		menuID = printMainMenu();
		switch(menuID){
			case '1':
				while(1){
					menuID = printSubMain();
					switch(menuID){
						case'1':
							findWareByID();
							break;
						case'2':
							findWareByName();
							break;
					}
					if(menuID == '3'){
						break;
					}
				}
				break;
		    case '2':
		    	displayAllware();
		    	break;
		    case '3':
		    	addware();
		    	break;
		    case '4':
		    	deleteware();
		    	break;
		    case '5':
		    	exit(0);
		} 
	}
	printMainMenu();
	return 0;
} 

char printMainMenu()
{
	char menuID;
	system("cls");
	printf("\n\n\n\n\n");
	printf("\t\t|-------------------菜单------------|\n");
	printf("\t\t|\t 1. 查询货物信息            |\n");
	printf("\t\t|\t 2. 显示存货列表            |\n");
	printf("\t\t|\t 3. 入库                    |\n");
	printf("\t\t|\t 4. 出库                    |\n");
	printf("\t\t|\t 5. 退出程序                |\n"); 
	printf("\t\t|-----------------------------------|\n");
	printf("\t\t\t选择(1-5):");
	fflush(stdin);
	menuID = getch();
	return menuID;
}

char printSubMain(){
	char menuID;
	system("cls");
	printf("\n\n\n\n\n");
	printf("\t\t|------------查询货物信息-----------|\n");
	printf("\t\t|\t 1.根据货物型号查询         |\n");
	printf("\t\t|\t 2.根据货物名字查询         |\n");
	printf("\t\t|\t 3.返回主菜单               |\n");
	printf("\t\t|-----------------------------------|\n");
	fflush(stdin);
	menuID = getch();
	return menuID;
}
