#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include"BinTree.h"

/***创建新的二叉树，当Ptr为NULL的时候，即为空二叉树***/
BinTree Init_BinTree(BinTree Ptr)
{
	BinTree BTree=Ptr;
	return BTree;
}

/***判断二叉树是否为空***/
int Is_Empty(BinTree Ptr)
{
	if(Ptr)
		return 0;
	else
		return 1;
}

/***生成节点***/  
BinNode* MakeNode(Elemtype data,BinNode *L_Child,BinNode *R_Child)
{
	BinNode* Pnode=(BinNode*)malloc(sizeof(BinNode));
	if(Pnode)
	{
		Pnode->data=data;
		Pnode->L_Child=L_Child;
		Pnode->R_Child=R_Child;
	}
	return Pnode;
}

/***释放节点***/  
void FreeNode(BinNode *Pnode)
{
	if(NULL!=Pnode)	
		free(Pnode);
}

/***使用先序遍历创建二叉树，使二叉树里有数据项***/
BinTree Create_BinTree()
{
	BinTree Ptr;
	Elemtype ch;
    	scanf(" %c", &ch); //调用scanf时，树的结点一次全部输入,则%c之前不用加空格，如果要一次一个的输入，在%c前加个空格
	if(ch == '*')
    	 {
        	Ptr = NULL;
    	}
    	else
	{
		Ptr=(BinTree)malloc(sizeof(BinNode));
		if(!Ptr)
		{
			printf("Malloc the Ptr is failed.\n");
			exit(1);
		}
		Ptr->data=ch;
		Ptr->L_Child=Create_BinTree();
		Ptr->R_Child=Create_BinTree();
	}
	return Ptr;
}

/***返回根结点数据项***/
Elemtype Get_Data(BinTree Ptr)
{
	if(Ptr)
	return Ptr->data;
}

/***返回左子树***/
BinTree LTree(BinTree Ptr)
{
	if(Ptr)
	return Ptr->L_Child;
}

/***返回右子树***/
BinTree RTree(BinTree Ptr)
{
	if(Ptr)
	return Ptr->R_Child;
}

/***增加数据项到二叉树，即插入新的子树***/
BinTree Insert_ChildTree(BinTree Ptr,BinTree node,int n) 
//Ptr为父结点，node为子结点,n=1表示添加左子树，n=2表示添加右子树
{
	if(Ptr==NULL)
	 {   	
		if(1==n && NULL==Ptr->L_Child) //n=1 且左子树为空，添加到左子树
		{
			Ptr->L_Child=node;
			return node;
		}
		else
		{
			printf("The L_ChildTree is no empty.\n");
			return NULL;
		}
		if( 2==n && Ptr->R_Child) //n=2且右子树为空，添加到右子树
		{
			Ptr->R_Child=node;
			return node;
		}
		else
		{
			printf("The RL_ChildTree is no empty.\n");
			return NULL;
		}
	}
	return NULL;
}

/***n=1删除左子树，n=2删除右子树***/  
void Delete_ChildTree(BinTree Ptr,int n)  
{  
    if(Ptr)  
    {  
        if( 1 == n && Ptr->L_Child != NULL)  
        {  
            Ptr->L_Child = NULL;  
            FreeNode(Ptr->L_Child);  
        }     
        if( 2 ==n && Ptr->R_Child != NULL)  
        {  
            Ptr->R_Child = NULL;  
            FreeNode(Ptr->R_Child);  
        }     
    }  
}  

/***清空二叉树***/
void Clear_BinTree(BinTree Ptr)
{
	
	if(NULL!=Ptr->L_Child)
		Clear_BinTree(Ptr->L_Child);
	if(NULL!=Ptr->R_Child)
		Clear_BinTree(Ptr->R_Child);
	free(Ptr);
	Ptr=NULL;
}

/***销毁二叉树***/
void Destroy_BinTree(BinTree Ptr)
{
	if(Ptr)
		Clear_BinTree(Ptr);
}


/****************************************
/**********二叉树的遍历问题**************
/***************************************/

/******递归遍历************************/

/***先序遍历的递归实现***/
void Pre_Order_BinTree(BinTree Ptr)
{
	if(Ptr)
	{
		printf("%c ",Ptr->data);
		if(Ptr->L_Child)
			Pre_Order_BinTree(Ptr->L_Child);
		if(Ptr->R_Child)
			Pre_Order_BinTree(Ptr->R_Child);
	}
}

/***中序遍历的递归实现***/
void Mid_Order_BinTree(BinTree Ptr)
{
	if(Ptr)
	{
		if(Ptr->L_Child)
			Mid_Order_BinTree(Ptr->L_Child);		
		printf("%c ",Ptr->data);
		if(Ptr->R_Child)
			Mid_Order_BinTree(Ptr->R_Child);
	}
}

/***后序遍历的递归实现***/
void Post_Order_BinTree(BinTree Ptr)
{
	if(Ptr)
	{
		if(Ptr->L_Child)		
			Post_Order_BinTree(Ptr->L_Child);
		if(Ptr->R_Child)		
			Post_Order_BinTree(Ptr->R_Child);
		printf("%c ",Ptr->data);
	}
}


/***创建空栈，并返回栈顶***/
PStack Create_Stack()
{
	PStack P=(PStack)malloc(sizeof(Stack));
	if(NULL!=P)
	{
		P->top=NULL;
		//P->size=0;
	}
	return P;
}

/***判断是否为空栈***/
int SIs_Empty(PStack P)
{
	if(NULL==P->top)
		return 1;
	else
		return 0;
}

/***数据项入栈***/
void Push_Stack(PStack P,BinTree val)
{
	PNode PNew=(PNode)malloc(sizeof(Node));
	if(NULL==PNew)
	{
		printf("Malloc the PNew is failed.\n");
		exit(1);
	}
	else
	{
		PNew->val=val;
		PNew->next=P->top;
		P->top=PNew;
		//P->size++;
	}
	//return P;
}



/***返回栈顶数据项***/
BinTree Get_Item_Stack(PStack P)
{
	if(NULL!=P->top->val && SIs_Empty(P)==0)
		return P->top->val;
}

/*PNode Get_Top(PStack P)
{
	if(P)
		return P->top;
}
*/
/***数据项出栈***/
void Pop_Stack(PStack P)
{
	BinTree data;
	PNode temp=P->top;
	if(NULL==temp)
	{
		printf("The stack is empty.\n");
		exit(1);
	}
	data=temp->val;
	P->top=temp->next;
	//P->size--;
	free(temp);
	//return data;
}

/*****遍历的非递归实现,即迭代遍历*****/

/***前序遍历的非递归实现***/
void NPre_Order_BinTree(BinTree Ptr)
{  
    PStack stack = Create_Stack();  //创建一个空栈  
    BinTree pCurrent = Ptr;             //定义用来指向当前访问的节点的指针  
   
    while(pCurrent || !SIs_Empty(stack))  
    {  
		printf("%c ", pCurrent->data);  
		Push_Stack(stack,pCurrent);  
        pCurrent = pCurrent->L_Child;   
        while(!pCurrent && !SIs_Empty(stack))  
        {  
            pCurrent = Get_Item_Stack(stack);  
            Pop_Stack(stack);  
            pCurrent = pCurrent->R_Child;              
        }  
    }  
} 

/***中序遍历的非递归实现***/
void NMid_Order_BinTree(BinTree Ptr)
{  
    PStack stack = Create_Stack();  //创建一个空栈  
    BinTree pCurrent = Ptr;             //定义用来指向当前访问的节点的指针  
  
   while(pCurrent || !SIs_Empty(stack))  
    {  
        Push_Stack(stack,pCurrent);  
        pCurrent = pCurrent->L_Child;  
        while(!pCurrent && !SIs_Empty(stack))  
        {  
            pCurrent = Get_Item_Stack(stack); 
			printf("%c ", pCurrent->data);  
            Pop_Stack(stack);  
            pCurrent = pCurrent->R_Child;              
        }  
    }  
} 

/***后序遍历的非递归实现***/
void NPost_Order_BinTree(BinTree Ptr)
{
    PStack stack = Create_Stack();  //创建一个空栈  
    BinTree pCurrent;                      //当前结点 
    BinTree pre=NULL;                 //前一次访问的结点 
    Push_Stack(stack,Ptr);
    while(!SIs_Empty(stack))
    {
        pCurrent = Get_Item_Stack(stack); 
        if((pCurrent->L_Child==NULL&&pCurrent->R_Child==NULL)||
           (pre!=NULL&&(pre==pCurrent->L_Child||pre==pCurrent->R_Child)))
        {
            printf("%c ", pCurrent->data);  
            Pop_Stack(stack);
            pre=pCurrent; 
        }
        else
        {
            if(pCurrent->R_Child!=NULL)
				Push_Stack(stack,pCurrent->R_Child);
            if(pCurrent->L_Child!=NULL)    
                Push_Stack(stack,pCurrent->L_Child);
        }
    }    
}


/************队列的定义*******************/


/***创建空队列***/
PQueue Creat_Queue()
{
	PQueue QP=(PQueue)malloc(sizeof(Queue));
	QP->rear=QP->front=(QPNode)malloc(sizeof(QNode));
	if(NULL==QP || NULL==QP->front)
	{
		printf("The queue is failed.\n");
		exit(1);
	}
	//P->front=P->rear;
	QP->front->next=NULL;
	QP->size=0;
	return QP;
}
/***判断队列是否为空***/
int QIs_Empty(PQueue QP)
{
	if(QP->front==QP->rear || QP->size==0)
		return 1;
	else
		return 0;
}


/***数据项入队，在队尾入队***/
void Add_Queue(PQueue QP,BinTree Data)
{
	QPNode tp=(QPNode)malloc(sizeof(QNode));
	if(NULL==tp)
	{
		printf("The temp is failed.\n");
		exit(1);
	}
	tp->Data=Data;
	tp->next=NULL;
	if(QIs_Empty(QP))
		QP->front->next=tp;
	else
		QP->rear->next=tp;
	QP->rear=tp;
	QP->size++;
	//printf("Add the data of %d to queue is success: %d\n ",Data,Data);
	//return P;
}


/***数据项出队，在队首出队***/
BinTree Delete_Queue(PQueue QP,BinTree Data)
{
	//BinTree data;
	if(QIs_Empty(QP))
		exit(0);
	QPNode tep=QP->front->next;
	Data=tep->Data;
	QP->front->next=tep->next;
	if(0==QP->size)
		QP->rear=QP->front;
	QP->size--;
	free(tep);
	return Data;
}

/*******************层序遍历实现********/
void Level_Order_BinTree(BinTree Ptr)
{  
    PQueue QP;
	QP=Creat_Queue();
	BinTree temp=NULL;
    if(Ptr)  
    {  
        Add_Queue(QP,Ptr);  
        while(!QIs_Empty(QP))  
        {  
            temp=Delete_Queue(QP,temp);  
			printf("%c ",temp->data);  
			if(temp->L_Child!=NULL) Add_Queue(QP,temp->L_Child);  
			if(temp->R_Child!=NULL) Add_Queue(QP,temp->R_Child);  
        }  
        printf("\n");  
    }  
}
