#include <stdio.h>  
#include <stdlib.h>  
//链表节点  
typedef struct node  
{  
    int data;  
    struct node *next;  
}Node;  
//逆转的while实现  
void rev(Node **list)   //链表逆转  
{  
    if (*list == NULL || (*list)->next == NULL)  //空或者只有一个节点  
    {  
        return;  
    }  
    else  
    {  
        Node *pPre, *pCur, *pNext;  
  
        pPre = *list;  
        pCur = (*list)->next;  
  
        while (pCur)  
        {  
            pNext = pCur->next;  
  
            pCur->next = pPre;  
  
            pPre = pCur;  
  
            pCur = pNext;  
  
        }  
  
        (*list)->next = NULL;  
        *list = pPre;  
    }  
}  
//逆转的递归实现  
void rev_r(Node **list, Node *pCur, Node *pNext)  
{  
    if (pCur == NULL || pNext == NULL)  
    {  
        (*list)->next = NULL;  
  
        *list = pCur;  
  
        return;  
    }  
  
    rev_r(list, pNext, pNext->next);  
  
    pNext->next = pCur;  
}  
//逆转的goto实现  
void rev_goto(Node **list)  
{  
    if (*list == NULL || (*list)->next == NULL)  
        return;  
    else  
    {  
        Node *pPre = *list;  
        Node *pCur = (*list)->next;  
        Node *pNext = NULL;  
  
    stage:  
        pNext = pCur->next;  
  
        pCur->next = pPre;  
  
        pPre = pCur;  
  
        pCur = pNext;  
  
        if (pCur)  
            goto stage;  
  
        (*list)->next = NULL;  
        *list = pPre;  
    }  
}  
void print(Node *list)  
{  
    if (list == NULL)  
        return;  
    printf("%4d", list->data);  
    print(list->next);  
}  
int selectdata(Node*list, int data){
	Node * t = list;
	int i=1;
	while(t->next){
		t = t->next;
		if(t->data == data){
			return i;
		}
		i++;
	}
	return -1;
}
int main()   
{  
    Node p1 = { 1, NULL };  
    Node p2 = { 2, &p1 };  
    Node p3 = { 3, &p2 };  
    Node p4 = { 4, &p3 };  
    Node p5 = { 5, &p4 };  
    Node p6 = { 6, &p5 };  
    Node *list = &p6;  
    printf("原链表\n");  
    print(list);  
    printf("\n");  
    printf("逆转\n");  
  
    //rev(&list);   //while  
    //rev_r(&list, list, list->next);   //递归  
    rev_goto(&list);    //goto  
    print(list);  
    printf("\n");  
    
    printf("查找元素5的位置\n");
    int address = selectdata(list, 5);
    if(address == -1){
    	printf("没有该元素");
    }
    else{
    	printf("元素5的位置为：%d\n", address+1);
    }
    system("pause");  
}  
