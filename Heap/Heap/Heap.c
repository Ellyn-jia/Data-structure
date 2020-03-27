#include"Heap.h"

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void HeapPrint(Heap* hp)
{
	for (int i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->a[i]);
	}
	printf("\n");
}

void AdjustDowm(HeapDataType* a, int n, int root)
{
	int parent = root;
	int child = 2 * parent + 1;
	while(child < n)
	{
		if (child + 1 < n && a[child - 1] < a[child])
		{
			child++;
		}
		if (a[parent] > a[child])
		{
			swap(&a[parent], &a[child]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* a, int n)
{
	for (int i = (n - 2) / 2; i > = 0; i--)
		AdjustDowm(a, n, i);
	int end = n - 1;
	while (end > 0)
	{
		int tmp = a[0];
		a[0] = a[end];
		a[end] = tmp;

		AdjustDowm(a, end, 0);	
		end--;					

	}
}

void HeapCreat(Heap* hp, HeapDataType* a, int n)
{
	hp->a = (HeapDataType*)malloc(sizeof(HeapDataType)*n);
	memcpy(hp->a, a, sizeof(HeapDataType)*n);
	hp->size = n;
	hp->capacity = n;
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDowm(hp->a, hp->size, i);
	}
	return hp;

}


void AdjustUp(HeapDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HeapPush(Heap* hp, HeapDataType x)
{
	if (hp->size == hp->capacity)
	{
		int newcapacity = hp->capacity * 2;
		hp->a = (HeapDataType*)realloc(hp->a, sizeof(HeapDataType)*newcapacity);
		hp->capacity = newcapacity;
	}
	hp->a[hp->size] = x;
	hp->size++;
	AdjustUp(hp->a, hp->size - 1);

}

void HeapPop(Heap* hp)
{
	swap(&hp->a[0], &hp->a[hp->size - 1]);
	hp->size--;
	AdjustDowm(hp->a, hp->size, 0);

}
HeapDataType HeapTop(Heap* hp)
{
	return hp->a[0];

}
int HeapEmpty(Heap* hp)
{
	return hp->size == 0 ? 1 : 0;
}



void TopK(int* a, int sum, int num)
{
	Heap* hp;
	HeapCreat(&hp, a, num);
	for (int i = num; i < sum; i++)
	{
		if (HeapTop(&hp) < a[i])
		{
			HeapPop(&hp);
			HeapPush(&hp, a[i]);
		}
	}
}

