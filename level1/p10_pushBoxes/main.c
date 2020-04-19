#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<string.h>
#include<conio.h>
int x = 0, y = 0;
int map[10][10]={0};//存储当前地图
extern int map_1[10][10] ;
extern int map_2[10][10] ;
extern int map_3[10][10] ;
int finish();//判断游戏是否成功
void move(int x1, int y1, int x2, int y2);//控制移动
int render();//根据二维数组渲染地图
void find();//查找目前小人所在位置
void setmap(int n);//根据用户输入，确定用户选哪张地图
void color(int m);//
int main()
{
    int n;
    int grade = 0;
    char dir;
    char c;
    printf("**************推箱子游戏欢迎您***************\n"
		"*                                           *\n"
		"*         -----------------------           *\n"
		"*   |    Powered By c.biancheng.net    |    *\n"
		"*         -----------------------           *\n"
		"*                                           *\n"
		"*             ♀:自己的位置                 *\n"
		"*             ☆:箱子要到的的位置           *\n"
		"*             ■:箱子的位置                 *\n"
		"*                                           *\n"
		"*         |       游戏规则       |          *\n"
		"*                                           *\n"
		"*          控制♀将■推到☆的位置           *\n"
		"*          按 wasd 控制♀的移动             *\n"
		"*          按   r  重新开始游戏             *\n"
		"*          按   q      退出游戏             *\n"
		"*********************************************\n");
	color(0xA);
	printf("请选择关卡：（1/2/3）(0:退出游戏):");

	while (scanf("%d", &n)) {
		getchar();
		//n==0，游戏退出
		if (n == 0) {
			printf("game over\n");
			break;
		}
		system("cls");//清空命令行窗口中显示的所有信息
		if (n == 1 || n == 2||n == 3) {
			setmap(n);//根据 n 的值，设置当前地图
			render();//根据所选地图，在命令行窗口中将其渲染出来
					 //游戏开始，用户输入字符w/a/s/d，控制小人移动
			while ((dir = getch()) != EOF) {
				system("cls");//移动之前，删除原有命令行中的地图
				find();//移动之前，需找到当前小人所在的位置
					   //根据 dir 字符的值，控制小人的移动，以及设置重新开始和退出选项的操作
				switch (dir) {
				case 'w':move(x - 1, y, x - 2, y); break;
				case 's':move(x + 1, y, x + 2, y); break;
				case 'a':move(x, y - 1, x, y - 2); break;
				case 'd':move(x, y + 1, x, y + 2); break;
				case 'r':setmap(n); break;
				case 'q':return 0;
				}
				grade++;
				//重新渲染人移动后的场景
				render();
				//每次移动，判断是否挑战成功
				if (finish()) {
                    printf("你的得分是:%d\n", grade);
					printf("游戏胜利,请重新选择关卡(1/2/3)(0:退出游戏):");
					break;
				}
			}
		}
		else {
			printf("输入有误，请重新输入\n");
			printf("请选择关卡：（1/2/3）(0:退出游戏):");
		}
	}
    system("pause");
	return 0;
}
void move(int x1, int y1, int x2, int y2) {
	if (map[x][y] == 3) //找到自己的位置
	{
		//人前边是箱子，箱子在空格上
		if (map[x1][y1] == 2) {
			//箱子前边是空格
			if (map[x2][y2] == 0) {
				map[x][y] = 0;
				map[x1][y1] = 3;
				map[x2][y2] = 2;
			}
			//箱子前边是位置
			if (map[x2][y2] == 4) {
				map[x][y] = 0;
				map[x1][y1] = 3;
				map[x2][y2] = 5;
			}
		}
		//人前是箱子，箱子在位置上
		if (map[x1][y1] == 5) {
			//箱子前边是空格
			if (map[x2][y2] == 0) {
				map[x][y] = 0;
				map[x1][y1] = 6;
				map[x2][y2] = 2;
			}
			//箱子前边是位置
			if (map[x2][y2] == 4) {
				map[x][y] = 0;
				map[x1][y1] = 6;
				map[x2][y2] = 5;
			}
		}
		//人前为空格
		if (map[x1][y1] == 0) {
			map[x1][y1] = 3;
			map[x][y] = 0;
		}
		if (map[x1][y1] == 4) {
			map[x][y] = 0;
			map[x1][y1] = 6;
		}
	}
	if (map[x][y] == 6) //人在位置上
	{
		//位置前是箱子，箱子在空格上
		if (map[x1][y1] == 2) {
			//箱子前是空格
			if (map[x2][y2] == 0) {
				map[x][y] = 4;
				map[x1][y1] = 3;
				map[x2][y2] = 2;
			}
			//箱子前是位置
			if (map[x2][y2] == 4) {
				map[x][y] = 4;
				map[x1][y1] = 3;
				map[x2][y2] = 5;
			}
		}
		//位置前是箱子，箱子在位置上
		if (map[x1][y1] == 5) {
			//箱子前是空格
			if (map[x2][y2] == 0) {
				map[x][y] = 4;
				map[x1][y1] = 6;
				map[x2][y2] = 2;
			}
			//箱子前是位置
			if (map[x2][y2] == 4) {
				map[x][y] = 4;
				map[x1][y1] = 6;
				map[x2][y2] = 5;
			}
		}
		//人前面是位置
		if (map[x1][y1] == 4) {
			map[x][y] = 4;
			map[x1][y1] = 6;
		}
		//人前面是空格
		if (map[x1][y1] == 0) {
			map[x][y] = 4;
			map[x1][y1] = 3;
		}
	}
}

void find() {
	for (x = 0; x < 10; x++) {
		for (y = 0; y < 10; y++) {
			if (map[x][y] == 3 || map[x][y] == 6) {
				return;
			}
		}
	}
}
int render() {
	for (x = 0; x<10; x++) {
		for (y = 0; y<10; y++) {
			if (map[x][y] == 1) {
				color(8);
				printf("■"); //输出砖块的样子
			}
			if (map[x][y] == 3) {
				color(3);
				printf("♀"); //输出自己的位置
			}
			if (map[x][y] == 2) {
				color(4);
				printf("■"); //输出箱子
			}
			if (map[x][y] == 4) {
				color(0xE);
				printf("☆"); //输出箱子要到的位置
			}
			if (map[x][y] == 0) {
				color(0xF);
				printf("  "); //输出空白
			}
			if (map[x][y] == 5) {
				color(6);
				printf("★"); //箱子到达目标位置后的图标
			}
			if (map[x][y] == 6) {
				color(3);
				printf("♀");//人达到星星处，要由☆改为♀
			}
		}
		printf("\n");
	}
	return 0;
}
void setmap(int n) {
	if (n == 1) {
		memcpy(map, map_1, sizeof(map_1));
	}
	if (n == 2) {
		memcpy(map, map_2, sizeof(map_2));
	}
	if(n == 3){
        memcpy(map, map_3, sizeof(map_3));
	}
}
int finish()
{
	for (x = 0; x < 10; x++) {
		for (y = 0; y < 10; y++) {
			if (map[x][y] == 2)
				return 0;
		}
	}
	return 1;
}
void color(int m) {
	HANDLE consolehend;
	consolehend = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(consolehend, m);
}
