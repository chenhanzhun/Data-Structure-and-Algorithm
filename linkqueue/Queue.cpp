#include<stdio.h>  
#include<stdlib.h>  
#include<malloc.h>  
#include"Queue.h"  
  
/***创建空队列***/  
PQueue Creat_Queue()  
{  
    PQueue P=(PQueue)malloc(sizeof(Queue));  
    P->rear=P->front=(PNode)malloc(sizeof(Node));  
    if(NULL==P || NULL==P->front)  
    {  
            printf("The queue is failed.\n");  
            exit(1);  
     } 
    P->front->next=NULL;  
    P->size=0;  
    return P;  
}
/***判断队列是否为空***/  
int Is_Empty(PQueue P)  
{  
    if(P->front==P->rear)  
        return 1;  
    else  
        return 0;  
}  
  
PQueue CreateQueue(PQueue P) //创建队列    
{    
    P=Creat_Queue();    
    printf("Enter the data:");    
    int k;    
    while((scanf("%d",&k)) == 1)    
    {  
            Add_Queue(P,k);  
            printf("Enter the next data:");    
        }  
    return P;  
}  
  
/***数据项入队,在队尾入队***/  
PQueue Add_Queue(PQueue P,Item data)  
{  
    PNode temp=(PNode)malloc(sizeof(Node));  
    if(NULL==temp)  
    {  
            printf("The temp is failed.\n");  
            exit(1);  
        }  
    temp->data=data;  
    temp->next=NULL;  
    if(Is_Empty(P))  
        P->front->next=temp;  
    else  
        P->rear->next=temp;  
    P->rear=temp;  
    P->size++;  
    printf("Add the data of %d to queue is success: %d\n ",data,data);  
    return P;  
}  
  
/***计算队列大小***/  
int Size_Queue(PQueue P)  
{  
    return P->size;  
}  
  
/***数据项出队，在队首出队***/  
Item Delete_Queue(PQueue P)  
{  
    Item data;  
    if(Is_Empty(P))  
        return NULL;  
    PNode temp=P->front->next;  
    data=temp->data;  
    P->front->next=temp->next;  
    if(0==P->size)  
        P->rear=P->front;  
    P->size--;  
    free(temp);  
    return data;  
}  
  
/***清空队列***/  
void Clear_Queue(PQueue P)  
{    
    PNode temp = P->front->next;    
    while(temp)    
    {    
        PNode tp = temp;    
        temp = temp->next;    
        free(tp);    
     }    
    temp = P->front;    
    P->front = P->rear = NULL;    
    free(temp);    
}    
  
/***遍历队列***/  
void Traverse_Queue(PQueue P)  
{    
    if(Is_Empty(P))    
        printf("there is no data in the queue!\n");    
    else    
    {       
        PNode pCurrent = P->front->next;     
        printf("Now datas int the queue are:\n");    
        while(pCurrent)    
        {    
           printf("%d ",pCurrent->data);    
           pCurrent = pCurrent->next;    
        }    
        printf("\n");    
    }    
    return;    
}  
