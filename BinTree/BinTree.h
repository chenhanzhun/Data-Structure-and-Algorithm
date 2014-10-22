#ifndef BinTree_H
#define BinTree_H

/****二叉树结构的声明*****/
typedef char Elemtype;

typedef struct node
{
	Elemtype data;
	struct node * L_Child;
	struct node * R_Child;
}BinNode,*BinTree;

/***链栈结构的声明***/
typedef struct snode * PNode;
typedef struct snode
{
	BinTree val;
	PNode next;
}Node;

typedef struct stack *PStack;
typedef struct stack
{
	//Item size;
	PNode top;
}Stack;

/***队列链式结构的声明***/
typedef struct qnode *QPNode;

typedef struct qnode
{
	BinTree Data;
	QPNode next;
}QNode;

typedef struct queue *PQueue;

typedef struct queue
{
	QPNode front;
	QPNode rear;
	int size;
}Queue;

/**************函数声明****************/

/***创建新的二叉树，当Ptr为NULL的时候，即为空二叉树***/
BinTree Init_BinTree(BinTree Ptr);

/***判断二叉树是否为空***/
int Is_Empty(BinTree Ptr);

/***生成节点***/  
BinNode *MakeNode(Elemtype data,BinNode *L_Child,BinNode *R_Child);

/***释放节点***/  
void FreeNode(BinNode *pnode); 

/***增加数据项到二叉树，即插入新的子树***/
BinTree Insert_ChildTree(BinTree Ptr,BinTree node,int n);

/***创建二叉树，使二叉树里有数据项***/
BinTree Create_BinTree();

/***返回根结点数据项***/
Elemtype Get_Data(BinTree Ptr);

/***返回左子树***/
BinTree LTree(BinTree Ptr);

/***返回右子树***/
BinTree RTree(BinTree Ptr);

/*删除子树*/  
void Delete_ChildTree(BinTree Ptr,int n);

/***清空二叉树***/
void Clear_BinTree(BinTree Ptr);

/***销毁二叉树***/
void Destroy_BinTree(BinTree Ptr);


/****************************************
/**********二叉树的遍历问题**************
/***************************************/

/******递归遍历************************/

/***先序遍历的递归实现***/
void Pre_Order_BinTree(BinTree Ptr);

/***中序遍历的递归实现***/
void Mid_Order_BinTree(BinTree Ptr);

/***后序遍历的递归实现***/
void Post_Order_BinTree(BinTree Ptr);



/*****遍历的非递归实现,即迭代遍历*****/

/***前序遍历的非递归实现***/
void NPre_Order_BinTree(BinTree Ptr);

/***中序遍历的非递归实现***/
void NMid_Order_BinTree(BinTree Ptr);

/***后序遍历的非递归实现***/
void NPost_Order_BinTree(BinTree Ptr);


/*******************层序遍历实现********/
void Level_Order_BinTree(BinTree Ptr);


/***创建空栈，并返回栈顶***/
PStack Create_Stack();

/***判断是否为空栈***/
int SIs_Empty(PStack);

/***数据项入栈***/
void Push_Stack(PStack,Elemtype);

/***返回栈顶数据项***/
BinTree Get_Item_Stack(PStack);

/***获得栈顶结点***/
PNode Get_Top(PStack); 

/***数据项出栈***/
void Pop_Stack(PStack);

/*******************************
********************************
******队列的声明****************
*******************************/

/***创建空队列***/
PQueue Creat_Queue();

/***判断队列是否为空***/
int QIs_Empty(PQueue);

/***数据项入队，在队尾入队***/
void Add_Queue(PQueue,BinTree);

/***数据项出队，在队首出队***/
BinTree Delete_Queue(PQueue,BinTree);
#endif

