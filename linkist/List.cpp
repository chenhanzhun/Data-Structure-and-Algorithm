#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include "List.h"

/**函数定义**/
/***创建空链表，并返回链表指针***/
List Creat_Empty(List L)
{
    L=(PNode)malloc(sizeof(node));
    L->next=NULL;
    L->data=0;
    return L;
}

/***判断是否为空链表***/
int Is_Empty(List L)
{
    return L->next==NULL;
    /*
     *  if(NULL==L->next)
     *          return 1;
     *              else
     *                      return 0;
     *                          */
}

/***创建链表，并返回链表***/
List Make_List()
{
    int val;
    PNode pHead =(PNode)malloc(sizeof(node));  
    PNode pCurrent = pHead;  
    pCurrent->next = NULL;
    if(NULL==pHead)
        {
                    printf("Malloc the list is failed.");
                    exit(1);
                }
    printf("Input the first data:");
    while(scanf("%d",&val)==1)
        {
                    PNode pNew=(PNode)malloc(sizeof(node));
                    if(NULL==pNew)
                    {
                                    printf("Malloc the pNew is failed.");
                                    exit(1);
                                }
                    pNew->data=val;
                    pCurrent->next=pNew;
                    pNew->next=NULL;
                    pCurrent=pNew;
                    printf("Please input the next data:");
                }
    return pHead;
}

/***判断是为最后节点***/
int Is_Last(Position P)
{
    return P->next==NULL;
}
/***计算链表的长度***/
int Length(List L)
{
    int len=0;
    PNode PCurrent=L->next;
    while(NULL!=PCurrent)
    {
            len++;
            PCurrent=PCurrent->next;
     }
    return len;
}

/***遍历链表***/
void Traverse_List(List L)
{
    PNode PCurrent=L->next;
    printf("The data of list are:\n");
    while(NULL!=PCurrent)
    {
            printf("%d   ",PCurrent->data);
            PCurrent=PCurrent->next;
     }
    printf("\n");
}

/***在链表的某个位置插入数据项***/
void Insert(Item val,List L,Position P)
{
    PNode temp;
    temp=(PNode)malloc(sizeof(node));
    if(NULL==temp)
        exit(0);
    temp->data=val;
    temp->next=P->next;
    P->next=temp;
}

/***查找链表中对应的数据项，并返回该数据项***/
int Search(Item val,List L)
{
    Position P;
    P=L->next;
    if(P!=NULL && P->data !=val)
        P=P->next;
    return P->data;
}

/***查找链表中对应的数据项，并返回该数据项的前驱位置***/
Position Search_Previous(Item val,List L)
{
    Position P;
    P=L;
    if(P->next!=NULL && P->next->data!=val)
        P=P->next;
    return P;
}

/***查找链表中对应的数据项，并返回该数据项的后继位置***/
Position Search_Next(Item val,List L)
{
    Position P;
    P=L;
    if(P!=NULL && P->data!=val)
        P=P->next;
    return P;
}
/*
 * 获得位置P后继节点位置 
 */  
Position Advance(Position P)  
{  
    if(P!=NULL)  
    return P->next;  
}

/***删除链表中的某个数据项***/
void Delete(Item val,List L)
{
    Position P, temp;
    P=Search_Previous(val,L);
    if(!Is_Last(P))
    {
            temp=P->next;
            P->next=temp->next;
            free(temp);
     }

}

/***删除链表L除头节点外的所有节点***/
void Delete_List(List L)
{
    Position P, temp;
    P=L->next;
    L->next=NULL;
    while(P!=NULL)
    {
            temp=P->next;
            free(P);
            P=temp;
     }
}

/***返回P节点位置的数据项****/
int Get_Item(Position P)  
{  
    if(P!=NULL)  
    return P->data;  
}
