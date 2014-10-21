#ifndef Queue_H
#define Queue_H

typedef int Item;
typedef struct node *PNode;

typedef struct node
{
    Item data;
    PNode next;
}Node;

typedef struct queue *PQueue;

typedef struct queue
{
    PNode front;
    PNode rear;
    Item size;
}Queue;

/***创建空队列***/
PQueue Creat_Queue();

/***判断队列是否为空***/
int Is_Empty(PQueue);

PQueue CreateQueue(PQueue); //创建队列  


/***数据项入队，在队尾入队***/
PQueue Add_Queue(PQueue,Item);

/***计算队列大小***/
int Size_Queue(PQueue);

/***数据项出队，在队首出队***/
Item Delete_Queue(PQueue);

/***清空队列***/
void Clear_Queue(PQueue);

/***遍历队列***/
void Traverse_Queue(PQueue);
#endif
