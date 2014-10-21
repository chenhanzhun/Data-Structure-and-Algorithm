#ifndef List_H
#define List_H

typedef struct Node *PNode;//定义节点指针
typedef int Item;//定义数据类型

typedef struct Node//定义节点结构
{
    Item data;//数据域
    PNode next;//指针域
}node;

typedef PNode Position;
typedef PNode List;

/**函数声明**/
/***创建空链表，并返回链表指针***/
List Creat_Empty(List);

/***判断是否为空链表***/
int Is_Empty(List);

/***创建链表，并返回头指针***/
List Make_List();

/***判断是为最后节点***/
int Is_Last(Position);

/***计算链表的长度***/
int Length(List);

/***遍历链表***/
void Traverse_List(List); 

/***在链表的某个位置插入数据项***/
void Insert(Item,List,Position);

/***查找链表中对应的数据项，并返回该数据项***/
int Search(Item,List);

/***查找链表中对应的数据项，并返回该数据项的前驱位置***/
Position Search_Previous(Item,List);

/***查找链表中对应的数据项，并返回该数据项的后继位置***/
Position Search_Next(Item,List); 

/***获得P的后继节点***/
Position Advance(Position P);

/***删除链表中的某个数据项***/
void Delete(Item,List);

/***删除链表除头节点外的所有节点***/
void Delete_List(List); 

/***查找P节点的数据项***/
int Get_Item(Position P);
#endif
