#include<stdio.h>
#include<stdlib.h>
#include"Stack.h"

/***创建空栈，并返回栈顶***/
PStack Creat_Stack()
{
    PStack P=(PStack)malloc(sizeof(Stack));
    if(NULL!=P)
    {
            P->top=NULL;
            P->size=0;
        }
    return P;
}

/***判断是否为空栈***/
int Is_Empty(PStack P)
{
    if(0==P->size && NULL==P->top)
        return 1;
    else
        return 0;
}

/***数据项入栈***/
PStack Push_Stack(PStack P,Item val)
{
    PNode PNew=(PNode)malloc(sizeof(Node));
    if(NULL==PNew)
    {
            printf("Malloc the PNew is failed.\n");
            exit(1);
        }
    else
    {
            PNew->data=val;
            PNew->next=P->top;
            P->top=PNew;
            P->size++;
        }
    return P;
}

/***计算栈的大小***/
int Size_Stack(PStack P)
{
    /*int size=0;
     *  PNode PCurrent=(PNode)malloc(sizeof(Node));
     *      PCurrent=P->top;
     *          while(NULL!=PCurrent)
     *              {
     *                      size++;
     *                              PCurrent=PCurrent->next;
     *                                  }
     *                                      return size;*/
        return P->size;
}

/***返回栈顶数据项***/
Item Get_Item_Stack(PStack P)
{
    if((NULL != P->top->data) && Is_Empty(P)==0)
        return P->top->data;
}

/***数据项出栈***/
Item Pop_Stack(PStack P)
{
    Item data;
    PNode temp=P->top;
    if(NULL==temp)
    {
            printf("The stack is empty.\n");
            exit(1);
        }
    data=temp->data;
    P->top=temp->next;
    P->size--;
    free(temp);
    return data;
}

/***清空链栈***/
void Clear_Stack(PStack P)
{
    if(Is_Empty(P))
        printf("The stack had enpty.\n");
    PNode PCurrent=P->top;
    int i=P->size;
    while(i--)
    {
            P->top=PCurrent->next;
            P->size--;
            free(PCurrent);
            PCurrent=P->top;
        }
}

/***遍历栈，并自栈顶输出数据项***/
void Traverse_Stack(PStack P)
{
     PNode PCurrent = P->top;  
    int i = P->size; 
    printf("The data of stack are:");
    while(i--)  
    {  
            printf("%d  ",PCurrent->data);  
            PCurrent = PCurrent->next;  
        } 
    printf("\n");
}
