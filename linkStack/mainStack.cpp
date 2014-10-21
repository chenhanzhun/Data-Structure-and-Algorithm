#include<stdio.h>
#include<stdlib.h>
#include"Stack.h"

int main()
{
    int size=0;
    int top_data,Pop_data;
    PStack PS;
    PS=Creat_Stack();
    if(NULL!=PS)
        printf("The stack is created.\n");

/***判断是否为空栈***/
    if(Is_Empty(PS))
        printf("The stack is empty.\n");

/***数据项入栈***/
    Push_Stack(PS,2);
    Push_Stack(PS,3);
    Push_Stack(PS,5);
    Traverse_Stack(PS);

/***计算栈的大小***/
    size=Size_Stack(PS);
    printf("The length of stack is: %d\n",size);
    
/***返回栈顶数据项***/
    top_data=Get_Item_Stack(PS);
    printf("The top of data is: %d\n",top_data);

/***数据项出栈***/
    Pop_data=Pop_Stack(PS);
    printf("The Pop of data is: %d\n",Pop_data);
    Traverse_Stack(PS);

/***清空链栈***/
    Clear_Stack(PS);
    Traverse_Stack(PS);
    
    return 0;
}
