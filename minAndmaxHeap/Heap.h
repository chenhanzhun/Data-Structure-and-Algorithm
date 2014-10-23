#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
int heap[MAX_SIZE];
void max_Heap_insert(int *heap,int *n,int item);
int max_Heap_delete(int *heap,int *n);
#endif // HEAP_H_INCLUDED

