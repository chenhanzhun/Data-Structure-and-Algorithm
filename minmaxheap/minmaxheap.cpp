#include<math.h>
#include <stdio.h>
#include <stdlib.h>
#include "function.h"

/**从最大结点i开始,沿着从i到根结点路径，依次检查最大结点**/
/**查找插入数据item的正确结点,这个结点应有以下性质:从该结点
向上到根的路径上所有最大结点的关键字值都不小于item,而且从结点
i向下到该结点的路径上所有最大关键字值都小于item.**/
/**查找过程中,关键字值小于item的最大结点被下移到下一个最大层**/
void verify_max(int *heap,int i,int item)
{
    int grandparent=i/4;//第一个非叶子结点
    while(grandparent)
    {
        if(item<=heap[grandparent])
            break;
        else
        {
            heap[i]=heap[grandparent];
            i=grandparent;
            grandparent/=4;
        }
    }
    heap[i]=item;
}
/**从最小结点i开始,沿着从i到根结点路径，依次检查最小结点**/
/**查找插入数据item的正确结点,这个结点应有以下性质:从该结点
向上到根的路径上所有最小结点的关键字值都不大于item,而且从结点
i向下到该结点的路径上所有最小关键字值都大于item.**/
/**查找过程中,关键字值大于item的最小结点被下移到下一个最小层**/
void verify_min(int *heap,int i,int item)
{
    int grandparent=i/4;
    while(grandparent)
    {
        if(item>=heap[grandparent])
            break;
        else
        {
            heap[i]=heap[grandparent];
            i=grandparent;
            grandparent/=4;
        }
    }
    heap[i]=item;
}
int level(int node)//判断结点属于最大层还是最小层
{
    double k=log(node)/log(2);
    if((int)k%2==0)return 0;//最小层返回0
    else return 1;//最大层返回1
}
/**最小-最大堆插入操作**/
void min_max_insert(int *heap,int *n,int item)
{
    int parent;
    int i;
    i=(*n);
    i++;
    if(MAX_SIZE==i)//判断是否为满堆
    {
        printf("it is full.\n");
        exit(1);
    }
    parent=(i)/2;//第一个非叶子结点,即结点i的父结点
    if(!parent)//判断是否为空堆
        heap[1]=item;//序号从1开始,而不是0
    else
    {
      int k;
      k=level(parent);//判断parent结点在最大层还是最小层
      switch(k)//k=0为最小层,1为最大层
      {
          case 0:
                        if(item<heap[parent])//插入结点的数据与其父结点比较
                        {
                            heap[i]=heap[parent];//交换
                            verify_min(heap,parent,item);//插入在parent结点向上到根
                                                        //的最小层中
                        }
                        else
                            verify_max(heap,i,item);
                        break;
          case 1:
                        if(item>heap[parent])
                        {
                            heap[i]=heap[parent];
                            verify_max(heap,parent,item);
                        }
                        else
                            verify_min(heap,i,item);
                        break;
      }
    }
    *n=i;
}
/*确定节点i所有儿子和后代节点的最小关键字值*/
int min_child_grandchild(int i,int n)
{
    int child,temp,t;
    int j;
    child=2*i;//i的儿子节点
    temp=heap[child];//保存当前值
    while(child<=n)//节点下标小于节点数
    {
        for(j=child;j<=n;j++)//遍历所有儿子节点和后代节点
        {
            if(temp>heap[j+1])
                {
                    temp=heap[j+1];//若当前节点的儿子节点或后代节点存在小于当前关键字值,把该节点赋给当前节点
                t=j+1;//保存最小节点的下标
                }

        }
        child=j;
    }
    return t;
}
/*最小最大堆删除操作，并返回最小元素*/
int delete_min_heap(int *heap,int *n)
{
    if(!(*n))
    {
        printf("The heap is empty.\n");
        exit(1);
    }
    int item,temp;
    int k,parent;
    int i,last;
    int x;
    x=heap[1];//根节点关键字值赋给x
    item=heap[(*n)--];//最后节点的值赋给item
    i=1;
    last=(*n)/2;//为重新插入item初始化
    /*寻找插入item的位置*/
    while(i<=last)//有儿子或后代节点,情况2
    {
        k=min_child_grandchild(i,*n);//返回最小元素的节点下标
        if(item<=heap[k])break;//如情况2(a),直接插入到根节点
        else
        {
            heap[i]=heap[k];//把关键字值移到根节点
            if(k<=2*i+1)//k是i的直接儿子,情况2(b)
            {
                i=k;//把item插入到heap[k]
                break;
            }
            else//k是i的后代节点,情况2(c)
            {
                parent=k/2;
                if(item>heap[parent])
                    SWAP(item,heap[parent],temp);
                i=k;
            }
        }
    }
    heap[i]=item;
    return x;
}

