 #include <stdio.h>
 #include<windows.h>
 #include<conio.h>
  //宏定义 maze[ROWS][COLS];行和列;
  #define ROWS 7
  #define COLS 6
  //绘制迷宫(全局变量)
  char maze[ROWS][COLS]= {
      {'#','#','#','#','#','#'},
      {'#','0','#',' ',' ',' '},
      {'#',' ','#',' ','#','#'},
     {'#',' ','#',' ',' ','#'},
     {'#',' ',' ','#',' ','#'},
     {'#','#',' ',' ',' ','#'},
     {'#','#','#','#','#','#'}
 };
 //设置X,Y坐标(全局变量);
 int currentX=1,currentY=1;
 //移动后的XY坐标(全局变量);
 int nextX,nextY;
 //看下一步是否能走  int[x][y]==' ' ;
 char street = ' ';
 
 //初始化函数
 void printMaze();
 void moveToNextPosition();
 void calculateNextPosition(char direction);
 
 
 
 int main(int argc, const char * argv[]) {
     nextX = currentX;
     nextY = currentY;
     //屏幕打印出迷宫;
     printMaze();
     char direction;
     while (1) {
         printf("请移动人物,用键盘W/S/A/D(上下左右)操作\n");
         direction = getch();
         calculateNextPosition(direction);
         moveToNextPosition();
         system("CLS");
         printMaze();
         if (currentX==ROWS-1||currentY==COLS-1){
             printf("通关了,呵呵!");
             break;
         }
     }
     return 0;
 }
 
 
 //打印地图
 void printMaze(){
     for(int i = 0;i<ROWS;i++){
         for (int j = 0;j<COLS;j++) {
             printf("%c",maze[i][j]);
         }
         printf("\n");
     }
 }
 //移动人物
 void moveToNextPosition(){
     if (maze[nextX][nextY]==street) {
         char temp = maze[currentX][currentY];
         maze[currentX][currentY] = maze[nextX][nextY];
         maze[nextX][nextY] = temp;
         currentX = nextX;
         currentY = nextY;
         
     }else{
         nextX = currentX;
         nextY = currentY;
     }
 }
 //计算下一个位置
 void calculateNextPosition(char direction){
     switch (direction) {
         case 'w':{
             nextX = currentX - 1;
             break;
         }
         case 's':{
             nextX = currentX + 1;
             break;
         }
         case 'a':{
             nextY = currentY - 1;
             break;
         }
         case 'd':{
             nextY = currentY + 1;
             break;
         }
         default:
            break;
     }
 }
