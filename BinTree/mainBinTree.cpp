#include<stdio.h>
#include<stdlib.h>
#include"BinTree.h"

int main()
{
	BinTree Ptr=NULL;
	Elemtype ch;

	Ptr=Init_BinTree(NULL);//初始化二叉树
	/***判断二叉树是否为空***/
	if(Is_Empty(Ptr))
		printf("It is empty.\n");

	printf("Enter the data:\n");
	Ptr=Create_BinTree();//创建二叉树
	ch=Get_Data(Ptr);//获取二叉树根节点的数据项
	printf("The first data is:%c\n",ch);

	printf("The data of Pre_Order_BinTree are:\n");
	Pre_Order_BinTree(Ptr);//先序遍历
	printf("\n");

	printf("The data of NPre_Order_BinTree are:\n");
	NPre_Order_BinTree(Ptr);//非递归先序遍历
	printf("\n");

	printf("The data of Mid_Order_BinTree are:\n");
	Mid_Order_BinTree(Ptr);//中序遍历
	printf("\n");

	printf("The data of NMid_Order_BinTree are:\n");
	NMid_Order_BinTree(Ptr);//非递归中序遍历
	printf("\n");

	printf("The data of Post_Order_BinTree are:\n");
	Post_Order_BinTree(Ptr);//后序遍历
	printf("\n");

	printf("The data of NMid_Order_BinTree are:\n");
	NPost_Order_BinTree(Ptr);//非递归后序遍历
	printf("\n");

	printf("The data of Level_Order_BinTree are:\n");
	Level_Order_BinTree(Ptr);//层次遍历
	printf("\n");

	Delete_ChildTree(Ptr,1);//删除左子树
	printf("After deleted, the data of Pre_Order_BinTree are:\n");
		Pre_Order_BinTree(Ptr);//删除左子树后，先序遍历
		printf("\n");	

	/*
	Clear_BinTree(Ptr);
	*/
	Destroy_BinTree(Ptr);//销毁二叉树
	if(Is_Empty(Ptr))
		printf("It is empty.\n");

	return 0;
}

