#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "common.h"
#include "ware.h"

//初始化
void init(){
	//打开文件
	if( (fp=fopen(FILENAME, "rb+")) == NULL && (fp=fopen(FILENAME, "wb+")) == NULL ){
		pause("Error on open %s file!", FILENAME);
		exit(EXIT_FAILURE);
	}

	wareSize = sizeof(WARE);
	fileSize = getFileSize(fp);
	wareIndex = NULL;

	updateIndex();
}

//添加货物信息
void addware(){
	WARE ware;
	int i, nPreEleCount = 0;
	
    getWareID(&ware.id);
    getWareName(ware.name); 
    getWarePrice(&ware.price);
    getWareNumber(&ware.number);

	for(i=0; i<wareCount; i++){
		if(ware.id == wareIndex[i]){
			pause("错误：该货物信息已存在，无需重复添加！按任意键返回...");
			return;
		}else if(ware.id > wareIndex[i]){
			nPreEleCount++;
		}else{
			break;
		}
	}

	finsert(fp, nPreEleCount*wareSize, &ware, wareSize);
	updateIndex();
	pause("提示：添加成功！按任意键返回...");
}

//删除货物信息
void deleteware(){
	WARE ware;
	int i, index = -1;

	getWareID(&ware.id);
	for(i=0; i<wareCount; i++){
		if(ware.id == wareIndex[i]){
			index = i;
		}else if(ware.id < wareIndex[i]){
			break;
		}
	}

	if(index<0){
		pause("错误：该货物信息不存在，删除失败！按任意键返回...");
		return;
	}else{
		fdelete(fp, index*wareSize, wareSize);
	}

	updateIndex();
	pause("提示：删除成功，按任意键返回...");
}



//根据ID查询货物信息
void findWareByID(){
	WARE ware;
	int i, index = -1;

	getWareID(&ware.id);
	for(i=0; i<wareCount; i++){
		if(ware.id == wareIndex[i]){
			index = i;
		}else if(ware.id < wareIndex[i]){
			break;
		}
	}
	if(index<0){
		pause("错误：该货物信息不存在，查询失败！按任意键返回...");
		return;
	}else{
		fseek(fp, wareSize*index, SEEK_SET);
		fread(&ware, wareSize, 1, fp);
		printf("-----------------------------------\n");
		printf("  型号  |  名称  |  价格  |  数量 \n");
		printf("--------+--------+--------+--------+\n");
		printf("   %d   | %-6s |   %d  |   %d \n", ware.id, ware.name, ware.price, ware.number);
		printf("------------------------------------\n");
		pause("\n按任意键返回...");
	}
}

//根据名称查询货物信息
void findWareByName(){
	WARE ware;
	int n = 0;  //匹配到几条货物记录
	float total;
	char name[20];

	getWareName(name);
	fseek(fp, 0, SEEK_SET);
	while(fread(&ware, wareSize, 1, fp)){
		if(strstr(ware.name, name)){
			n++;
			if(n==1){
				printf("-----------------------------------\n");
		        printf("  型号  |  名称  |  价格  |  数量 \n");
		        printf("--------+--------+--------+--------+\n");
			}
			printf("   %d   | %-6s |   %d  |   %d \n", ware.id, ware.name, ware.price, ware.number);
		}
	}

	if(n>0){
		printf("-----------------------------------------------------------------------\n");
		pause("\n共查询到%d条记录。按任意键返回...", n);
	}else if(n==0){
		pause("错误：没有查询到相关记录！按任意键返回...");
	}
}

//显示所有学生信息
void displayAllware(){
	WARE ware;
	if(!wareCount){
		pause("还未添加任何货物信息，按任意键返回...");
		return;
	}
	int n=0;
	fseek(fp, 0, SEEK_SET);
	system("cls");
	printf("-----------------------------------\n");
	printf("  型号  |  名称  |  价格  |  数量 \n");
	printf("--------+--------+--------+--------+\n");
	while( fread(&ware, wareSize, 1, fp) ){
		n++;
		printf("   %d   | %-6s |   %d  |   %d \n", ware.id, ware.name, ware.price, ware.number);
	}
	pause("\n共有%d条货物信息，按任意键返回...", n);
}



//更新索引
void updateIndex(){
	int i;
	free(wareIndex);
	wareCount = getFileSize(fp)/wareSize;
	wareIndex = (int*)malloc(wareCount*sizeof(int));
	for(i=0; i<wareCount; i++){
		fseek(fp, wareSize*i, SEEK_SET);
		fread(&wareIndex[i], sizeof(int), 1, fp);
	}
}

//输入货物ID
void getWareID(int *id){
	while(1){
		printf("输入货物型号：");
		fflush(stdin);
		scanf("%d", id);
		if(checkWareID(*id)){
			break;
		}
	}
}

//输入学生姓名
void getWareName(char name[]){
	while(1){
		printf("输入名称：");
		fflush(stdin);
		scanf("%s", name);
		if(checkWareName(name)){
			break;
		}
	}
}

//输入货物价格 
void getWarePrice(int *price){
	while(1){
		printf("输入价格（1-1500）：");
		fflush(stdin);
		scanf("%d", price);
		if(checkWarePrice(*price)){
			break;
		}
	}
}

//输入货物数量 
void getWareNumber(int *number){
	while(1){
		printf("输入货物数量：");
		fflush(stdin);
		scanf("%d", number);
		if(checkWareNumber(*number)){
			break;
		}
	}
}

//检查货物ID是否正确
int checkWareID(int wareID){
	if(wareID <= 0 || wareID > MAX_WARE_ID){
		printf("错误：型号必须是大于0且小于等于%d的整数！\n", MAX_WARE_ID);
		return 0;
	}
	return 1;
}

//检查货物名称是否正确
int checkWareName(char name[]){
	if(strlen(name) > MAX_WARE_NAME){
		printf("错误：名称的最大长度不超过%d个字节！\n", MAX_WARE_NAME);
		return 0;
	}
	return 1;
}



//检查货物数量是否正确
int checkWareNumber(int number){
	if(number <=0 || number > MAX_WARE_NUMBER){
		printf("错误：数量的取值范围为1~%d！\n", MAX_WARE_NUMBER);
		return 0;
	}
	return 1;
}

//检查货物价格是否正确
int checkWarePrice(int price){
	if(price < 0 || price > MAX_WARE_PRICE){
		printf("错误：货物价格的取值范围为0~%d！\n", MAX_WARE_PRICE);
		return 0;
	}
	return 1;
}

