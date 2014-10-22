#include <stdio.h>
#include <stdlib.h>
#include"function.h"


int main()
{
    int i,item;
    int n=0;
    for(item=1;item<10;item++)
        min_max_insert(heap,&n,item);//插入节点
    for(i=1;i<10;i++)
        printf("%d ",heap[i]);
        printf("\n");
    item=delete_min_heap(heap,&n);//删除节点,并返回最小元素
    printf("The deleted data is %d\n",item);
    for(i=1;i<=n;i++)
        printf("%d ",heap[i]);
    return 0;
}
