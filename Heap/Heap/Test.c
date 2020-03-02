#include"Heap.h"


void Test()
{
	int a[10] = { 11, 23, 67, 99, 44, 67, 7 ,8, 0, 6};
	Heap hp;
	HeapCreat(&hp, a, 10);
	HeapPush(&hp, 3);
	HeapPush(&hp, 77);

	HeapPrint(&hp);
	printf("\n");

	
	while (!HeapEmpty(&hp))
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}

}


int main()
{
	Test();
	return 0;
}