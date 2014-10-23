#include"heap.h"


int main()
{
    int item,i;
    int n=0;
    for(i=1;i<MAX_SIZE;i++)
    {
        scanf("%d",&item);
        max_Heap_insert(heap,&n,item);
    }
    for(i=1;i<=n;i++)
        printf("%d ",heap[i]);
    printf("\n");
    item=max_Heap_delete(heap,&n);
    printf("The deleted data is:%d",item);
    printf("\n");
    for(i=1;i<=n;i++)
        printf("%d ",heap[i]);
    return 0;
}
