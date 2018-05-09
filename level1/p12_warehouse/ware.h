#ifndef _WARE_H
#define _WARE_H

#include "common.h"

#define FIND_BY_NUMBER 1
#define FIND_BY_NAME 2

FILE *fp; //文件指针
int wareSize; //一条货物信息的长度（字节数）
int wareCount; //总共有多少条货物信息
long fileSize; //文件长度
int *wareIndex; //货物信息索引

//货物信息结构体
typedef struct _WARE{
	int id; //型号 
	char name[20]; //货物名称
	int price; //货物价格
	int number; //货物数量 
} WARE;

//初始化
extern void init();

//货物信息增删改 
extern void displayAllware();
extern void addware();
extern void deleteware();
extern void findWareByID();
extern void findWareByName();

//更新索引
extern void updateIndex();

//检验货物信息
extern int checkWareID(int wareID);
extern int checkWareName(char name[]);
extern int checkPrice(int price);
extern int checkNumber(int number);

//输入货物信息
extern void getWareID(int *id);
extern void getWareName(char name[]); 
extern void getWarePrice(int *price);
extern void getWareNumber(int *numver);

#endif
