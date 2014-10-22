#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
#define MAX_SIZE 10
int heap[MAX_SIZE];
void verify_max(int *heap,int i,int item);
void verify_min(int *heap,int i,int item);
int level(int node);//判断结点属于最大层还是最小层
void min_max_insert(int *heap,int *n,int item);
int delete_min_heap(int *heap,int *n);
int min_child_grandchild(int i,int n);
#endif // FUNCTION_H_INCLUDED
