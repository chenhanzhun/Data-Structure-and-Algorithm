#include<stdio.h>
#include<stdlib.h>
#include"List.h"
#define NUMBER 5
#define N 3




int main(void)
{
List list;
Position P;
int len,val;
list=NULL;
List L=NULL;

L=Creat_Empty(L);//创建空链表
printf("The empty of list is created.\n");
if(Is_Empty(L))//判断链表是否为空
printf("The list is empty.\n");


list=Make_List();//生成存储有数据项的链表
Traverse_List(list);//遍历该链表


len=Length(list);//链表的长度
if(!Is_Empty(list))
printf("The length of list is:%d\n",len);


P=list;
Insert(NUMBER,list,P);//在链表中插入数据项
P= Advance(P);//获取P后继节点位置
if(P)
printf("Insert the new data of %d is successed\n",Get_Item(P));
else
printf("Insert the data of %d is failed.\n",NUMBER);
Traverse_List(list);//遍历该链表


val=Search(N,list);//在链表中查找相应的数据项
if(val==N)
printf("Search the data of %d is successed.\n",N);
else
printf("Search the data of %d is failed.\n",N);


Delete(NUMBER,list);//删除数据项
Traverse_List(list);//遍历该链表


Delete_List(list);//摧毁链表
if(Is_Empty(list))
printf("The list is destroied.");
return 0;
}

