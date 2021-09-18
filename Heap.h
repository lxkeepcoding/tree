# pragma once
#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>
#include<assert.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType *a;
	int size;
	int capacity;

}HP;

void AdjustDown(int *a, int n, int parent);
void AdjustUp(int *a, int child);
HP* HeapInit(HP*php, HPDataType*a, int n);
void HeapDestroy(HP *php);
void HeapPush(HP*php, HPDataType x);
void HeapPop(HP*php);
HPDataType HeapTop(HP*php);
int HeapSize(HP*php);
bool HeapEmpty(HP*php);
void HeapPrint(HP*php);