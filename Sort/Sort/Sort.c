

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
		if (a[start] != a[max])
			Swap(&a[end], a[max]);
		end--;
		start++;

	}
}