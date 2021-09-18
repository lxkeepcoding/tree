#define _CRT_SECURE_NO_WARNINGS   1

#include"Heap.h"


int main()
{
	int a[] = { 20, 16, 38, 29, 50, 35, 66, 19, 26, 28 };
	int n = sizeof(a) / sizeof(a[0]);
	HP hp;
	HeapInit(&hp, a, n);
	HeapPrint(&hp);
	HeapPush(&hp, 88);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	printf("%d\n", HeapTop(&hp));
	HeapDestroy(&hp);
	
	return 0;
}
