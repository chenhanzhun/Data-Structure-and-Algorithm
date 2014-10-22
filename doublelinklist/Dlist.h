#ifndef DList_H
#define DList_H

typedef int Item;
typedef struct node *PNode;
typedef PNode Position;
typedef struct node
{
    Item data;
    PNode previous;
    PNode next;
}Node;

typedef struct link *DLinkList;
typedef struct link
{
    PNode head;
    PNode tail;
    Item size;
}DLink;

/***创建有数据项结点，并返回该结点的地址***/
Position Make_Node(Item);

/***创建空的双向链表***/
DLinkList Creat_List();

/***判断是否为空链表***/
int Is_Empty(DLinkList);

/***创建存储有数据项和结点的链表***/
DLinkList DCreat_List(DLinkList);

/***释放某个结点***/
void Free_Node(Position);

/***在链表的第i个位置插入数据项***/
void Insert_List(DLinkList,int,Item);

/***计算链表的大小***/
int Size_List(DLinkList);

/***在链表的第i个位置删除数据项***/
void Delete_List(DLinkList,int);

/***摧毁链表***/
void Destroy_List(DLinkList);

/***遍历链表***/
void Traverse_List(DLinkList);
#endif
