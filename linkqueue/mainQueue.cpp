#include<stdio.h>
#include<stdlib.h>
#include "Queue.h"
#define num 5

int main()
{
    
    /***创建空队列***/
    PQueue PQ;
    int size=0;
    int data;
    PQ=Creat_Queue();
    printf("The queue is created.\n");

    /***判断队列是否为空***/
    if(Is_Empty(PQ))
        printf("The queue is empty.\n");

    PQ=CreateQueue(PQ); //创建队列
    /***遍历队列***/
    Traverse_Queue(PQ);

    /***数据项入队，在队尾入队***/
    PQ=Add_Queue(PQ,num);
    /***遍历队列***/
    Traverse_Queue(PQ);

    /***计算队列大小***/
    size=Size_Queue(PQ);
    printf("The size of queue are: %d\n",size);

    /***数据项出队，在队首出队***/
    data=Delete_Queue(PQ);
    printf("The deleted data is: %d\n",data);
    /***遍历队列***/
    Traverse_Queue(PQ);

    /***清空队列***/
    Clear_Queue(PQ);
    if(Is_Empty(PQ))
        printf("The queue is empty.\n");
    /***遍历队列***/
    Traverse_Queue(PQ);

    return 0;
}
