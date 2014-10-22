#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include"Dlist.h"
/**********************
 * ****函数定义***********
 * **********************/

/***创建有数据项结点，并返回该结点的地址***/
Position Make_Node(Item data)
{
    PNode P=(PNode)malloc(sizeof(Node));
    if(NULL!=P)
    {
            P->data=data;
            P->next=NULL;
            P->previous=NULL;
        }
    return P;
}

/***创建空的双向链表***/
DLinkList Creat_List()
{
    DLinkList L=(DLinkList)malloc(sizeof(DLink));
    PNode PHead=Make_Node(0);
    if(NULL!=L && NULL!=PHead)
    {
                L->size=0;
                L->head=PHead;
                L->tail=PHead;
        }
    return L;
}

/***判断是否为空链表***/
int Is_Empty(DLinkList L)
{
    if(0==L->size && L->head==L->tail)
        return 1;
    else
        return 0;
}

/***创建存储有数据项和结点的链表***/
DLinkList DCreat_List(DLinkList L)
{
    int data;
    L=Creat_List();
    PNode PCurrent=L->head;
    printf("Please enter the first data:");
    while(scanf("%d",&data)==1)
    {
            PNode temp=(PNode)malloc(sizeof(Node));
            if(temp)
            {
                        temp->data=data;
                        temp->next=PCurrent->next;
                        PCurrent->next=temp;
                        PCurrent=temp;
                        printf("Enter the next data:");
                        L->size++;
                    }
        }
    return L;
}

/***释放某个结点***/
void Free_Node(Position P)
{
    free(P);
}

/***在链表的第i个位置插入数据项***/
void Insert_List(DLinkList L,int i,Item data)
{
    PNode PCurrent,temp;
    int j=0;
    PCurrent=L->head;
    while(NULL!=PCurrent->next && j<i-1)
            {
                    PCurrent=PCurrent->next;
                    ++j;
                }
        if(j!=i-1 || i<1)
                {
                        printf("Insert the data is failed.\n");
                        return;
                    }
            temp=(PNode)malloc(sizeof(Node));
                temp->data=data;
                    temp->next=PCurrent->next;
                        temp->previous=PCurrent;
                            PCurrent->next=temp;
                                if(NULL!=temp->next)
                                            PCurrent->next->previous=temp;
                                    L->size++;
                                        printf("Insert the data of %d is success: %d\n",data,data);
}

/***计算链表的大小***/
int Size_List(DLinkList L)
{
    return L->size;
}

/***在链表的第i个位置删除数据项***/
void Delete_List(DLinkList L,int i)
{
    PNode PCurrent,temp;
    int j=0;
    PCurrent=L->head;
    while(NULL!=PCurrent->next && j<i-1)
            {
                    PCurrent=PCurrent->next;
                    ++j;
                }
        if(j!=i-1 || i<1)
                {
                        printf("Delete the data is failed.\n");
                        return;
                    }
            temp=PCurrent->next;
                PCurrent->next=temp->next;
                    if(NULL!=temp->next)
                            temp->next->previous=PCurrent->next;
                        free(temp);
                            L->size--;
}

/***摧毁链表***/
void Destroy_List(DLinkList L)
{  
    PNode  temp = L->head->next;  
    while(temp)  
    {  
            PNode tp = temp;  
            temp = temp->next;  
            free(tp);  
        }  
    free(L);  
} 

/***遍历链表***/
void Traverse_List(DLinkList L)
{
    if(Is_Empty(L))
    {
            printf("The DList is no data.\n");
            exit(0);
        }
    PNode PCurrent=L->head->next;
    printf("The DList of data are:\n");
    while(NULL!=PCurrent)
    {
            printf("%d  ",PCurrent->data);
            PCurrent=PCurrent->next;
        }
    printf("\n");
}
