#define _CRT_SECURE_NO_WARNINGS   1

#include"Heap.h"

void Swap(int *p, int *q)
{
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}

void AdjustDown(int *a, int n, int parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		//选出左右孩子较大的一个
		if (child + 1<n&&a[child + 1] > a[child])
		{
			++child;
		}
		//孩子和父亲比大小
		if (a[child] > a[parent])
		{
			Swap(&a[parent], &a[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void AdjustUp(int*a,int child)
{
	int parent = (child - 1) / 2;
	while (child>0)
	{
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

HP* HeapInit(HP*php, HPDataType*a, int n)
{
	assert(php);
	php->a = (HPDataType*)malloc(sizeof(HPDataType)*n);
	if (php->a == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	memcpy(php->a, a, sizeof(HPDataType)*n);
	php->size = n;
	php->capacity = n;

	//建大堆
	for (int j = (n - 1 - 1) / 2; j >= 0; --j)
	{
		AdjustDown(php->a,php->size, j);
	}
}
void HeapDestroy(HP *php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->size = php->capacity = 0;

}
void HeapPush(HP*php, HPDataType x)
{
	assert(php);
	if (php->size == php->capacity)
	{
		HPDataType*tmp = (HPDataType*)realloc(php->a, sizeof(HPDataType)*php->capacity * 2);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		php->a = tmp;
		php->capacity *= 2;
	}
	php->a[php->size] = x;
	php->size++;
	AdjustUp(php->a, php->size-1);
}
void HeapPop(HP*php)
{
	assert(php);
	assert(php->size > 0);
	Swap(&php->a[0], &php->a[php->size-1]);
	php->size--;
	AdjustDown(php->a, php->size-1, 0);
}
HPDataType HeapTop(HP*php)
{
	assert(php);
	assert(php->size > 0);
	return php->a[0];
}
int HeapSize(HP*php)
{
	assert(php);
	return php->size;
}
bool HeapEmpty(HP*php)
{
	if (php->size == 0)
		return true;
	else
		return false;
}
void HeapPrint(HP*php)
{
	for (int i = 0; i <php-> size; i++)
	{
		printf("%d  ", php->a[i]);
	}
	printf("\n");
	printf("\n");
	int num = 0;
	int levelSize = 1;
	for (int i = 0; i < php->size; i++)
	{
		printf("%d  ", php->a[i]);
		++num;
		if (levelSize == num)
		{
			printf("\n");
			levelSize *= 2;
			num = 0;
		}
	}
	printf("\n");
	printf("\n");
	printf("\n");
}