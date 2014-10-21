#ifndef Stack_H
#define Stack_H

typedef int Item;
typedef struct node * PNode;
typedef struct node
{
    Item data;
    PNode next;
}Node;

typedef struct stack *PStack;
typedef struct stack
{
    Item size;
    PNode top;
}Stack;

/***创建空栈，并返回栈顶***/
PStack Creat_Stack();

/***判断是否为空栈***/
int Is_Empty(PStack);

/***数据项入栈***/
PStack Push_Stack(PStack,Item);

/***计算栈的大小***/
int Size_Stack(PStack);

/***返回栈顶数据项***/
Item Get_Item_Stack(PStack);

/***数据项出栈***/
Item Pop_Stack(PStack);

/***清空链栈***/
void Clear_Stack(PStack);

/***遍历栈，并自栈顶输出数据项***/
void Traverse_Stack(PStack);
#endif
