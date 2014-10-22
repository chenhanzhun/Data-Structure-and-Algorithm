#include<stdio.h>  
#include<malloc.h>  
#include<stdlib.h>  
#include"Dlist.h"  
  
int main()  
{  
    int size;  
    DLinkList L=NULL;  
    DLinkList Link=NULL;  
    /***创建空的双向链表***/  
    Link=Creat_List();  
              
    /***判断是否为空链表***/  
   if(Is_Empty(Link))  
        printf("The list is empty.\n");  
                  
   /***创建存储有数据项和结点的链表***/  
    L=DCreat_List(L);  
    size=Size_List(L);//链表的大小  
    printf("The size of list is: %d\n",size);  
    Traverse_List(L);//遍历链表  
                                 
    /***在链表的地第3个位置插入数据项6**/  
    Insert_List(L,3,6);  
    size=Size_List(L);  
    printf("The size of list is: %d\n",size);  
    Traverse_List(L);//遍历链表  
                                                
   /***删除链表第3位置的数据项***/  
    Delete_List(L,3);  
    size=Size_List(L);  
    printf("The size of list is: %d\n",size);  
    Traverse_List(L);//遍历链表  
                                                                     
    /***摧毁链表***/  
    Destroy_List(L);  
    if(Is_Empty(L))  
        printf("The list is empty.\n");  
    else  
        printf("The list is destroied.\n");  
    return 0;  
}  
