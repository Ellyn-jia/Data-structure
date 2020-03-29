

void InsertSort(int* a, int n){
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int t = a[end + 1];
		while (end >= 0)
		{
			if (t < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = t;
	}

}

void ShellSort(int* a, int n){
	int gap = n / 3 + 1;
	for (int i = 0; i < n - gap; i++)
	{
		int end = i;
		int t = a[end + gap];
		while (end >= 0)
		{
			if (a[end] > t)
			{
				a[end + gap] = a[end];
				end -= gap;
			}
			else
			{
				break;
			}
		}
		a[end + gap] = t;
	}
}



void Swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}
void SelectSort(int* a, int n){
	int start = 0;
	int end = n - 1;
	while (start < end)
	{
		int min = start;
		int max = end;
		for (int i = start; i < end; i++)
		{
			if (a[i] > a[max])
				max = i;
			if (a[i] < a[min])
				min = i;
		}
		Swap(&a[start], &a[min]);
		if (max == start)
			max = min;
		Swap(&a[end], a[max]);
		end--;
		start++;

	}
}

void AdjustDowm(int* a, int n, int root)
{
	int parent = root;
	int child = 2 * parent + 1;
	while (child < n)
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
	for (int i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDowm(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDowm(a, end, 0);
		end--;
	}
}

void BubbleSort(int* a, int n)
{
	for (int i = 0; i <= n - 1; i++)
	{
		int flag = 1;
		for (int j = 0; j <= n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				flag = 0;
				Swap(&a[j], &a[j + 1]);
			}
		}
		if (flag == 1)
			break;
	}
}



int GetMidIndex(int* a, int begin, int end)
{
	int mid = (begin + end) >> 1;
	if (a[mid] > a[begin])
	{
		if (a[mid] < a[end])
			return mid;
		else if (a[begin] > a[end])
			return begin;
		else
			return end;
	}
	else
	{
		if (a[mid] > a[end])
			return mid;
		else if (a[begin] < a[end])
			return begin;
		else
			return end;
	}
}
int PartSort1(int* a, int begin, int end)//hoare
{
	int key = a[end];
	int index = end;
	while (begin < end)
	{
		while (begin < end && a[begin] <= key)
			begin++;
		while (begin < end && a[end] >= key)
			end--;
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[index]);
	return begin;
}
int PartSort2(int* a, int begin, int end)//挖坑法
{
	int key = a[end];
	while (begin < end)
	{
		while (begin < end && a[begin] <= key)
			begin++;
		a[end] = a[begin];
		while (begin < end && a[end] >= key)
			end--;
		a[begin] = a[end];
 	}
	a[begin] = key;
	return begin;
}
int PartSort3(int* a, int begin, int end)
{
	int key = a[end];
	int prev = begin - 1;
	int cur = begin;
	while (cur < end)
	{
		if (cur < key && ++prev != cur)
			Swap(&a[prev], &a[cur]);
		++cur;
	}
	prev++;
	Swap(&a[prev], &a[end]);
	return prev;

}

void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
		return;
	int index = PartSort(a, begin, end);
	PartSort(a, begin, index - 1);
	PartSort(a, index + 1, end);
}

void QuickSort2(int* a, int begin, int end)//非递归
{
	Stack st;
	StackInit(&st);
	StackPush(&st, begin);
	StackPush(&st, end);
	while (!StackEmpty(&st))
	{
		int right = StackTop(&st);
		StackPop(&st);
		int left = StackTop(&st);

		int keyindex = PartSort(a, left, right);

		if (left < keyindex - 1)
		{
			StackPush(&st, left);
			StackPush(&st, keyindex - 1);
		}
		if (keyindex + 1 < right)
		{
			StackPush(&st, keyindex + 1);
			StackPush(&st, right);
		}
	}
}

void SubMergeSort(int* a, int* tmp, int begin, int end)
{
	if (begin >= end)
		return;
	int mid = (begin + end) >> 1;
	SubMergeSort(a, tmp, begin, mid);
	SubMergeSort(a, tmp, mid + 1, end);
	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;
	int index = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}
	if (begin1 < end1)
	{
		while (begin1 <= end1)
			tmp[index++] = a[begin1++];
	}
	else
	{
		while (begin2 <= end2)
			tmp[index++] = a[begin2++];
	}
	memcpy(a + begin, tmp + begin, sizeof(int)*(end - begin + 1));
}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);
	SubMergeSort(a,tmp, 0, n - 1);
	free(tmp);
}

int CountSort(int* a, int n)
{
	int max = a[0];
	int min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	int range = max - min + 1;
	int* A = (int*)malloc(sizeof(int)*range);//统计次数的数组
	memset(A, 0, sizeof(int)*range);

	for (int i = 0; i < n; i++)
		A[a[i] - min]++;

	int j = 0;
	for (int i = 0; i < range; i++)
	{
		while (A[i]--)
			a[j++] = i + min;
	}
}