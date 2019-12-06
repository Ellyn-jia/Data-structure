//移除val元素
int removeElement(int* nums, int numsSize, int val){
	int start1 = 0;
	int start2 = 0;
	while (start2 < numsSize)
	{
		if (nums[start2] == val)
		{
			++start2;
		}
		else
		{
			nums[start1] = nums[start2];
			++start1;
			++start2;
		}
	}
	return start1;
}



//合并两个有序数组
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
	int end1 = m - 1;
	int end2 = n - 1;
	int end = m + n - 1;
	while (end1 >= 0 && end2 >= 0)
	{
		if (nums2[end2] > nums1[end1])
		{
			nums1[end] = nums2[end2];
			end2--;
			end--;
		}
		else
		{
			nums1[end] = nums1[end1];
			end1--;
			end--;
		}
	}
	if (end1 < 0)
	{
		while (end2 >= 0)
		{
			nums1[end] = nums2[end2];
			end--;
			end2--;
		}
	}
	else
	{
		while (end1 >= 0)
		{
			nums1[end] = nums1[end1];
			end--;
			end1--;
		}
	}
}

//旋转数组

void reverse(int* nums, int start, int end)
{
	while (start < end)
	{
		int t = nums[start];
		nums[start] = nums[end];
		nums[end] = t;
		start++;
		end--;
	}
}

void rotate(int* nums, int numsSize, int k){
	k %= numsSize;
	reverse(nums, 0, numsSize - 1);
	reverse(nums, 0, k - 1);
	reverse(nums, k, numsSize - 1);
}







//数组形式的整数加法
/**
* Note: The returned array must be malloced, assume caller calls free().
*/

void reverse(int* arr, int i)
{
	int left = 0;
	int right = i - 1;
	while (left < right)
	{
		int t = arr[left];
		arr[left] = arr[right];
		arr[right] = t;
		left++;
		right--;
	}
}
int* addToArrayForm(int* A, int ASize, int K, int* returnSize){
	int* arr = (int*)malloc(sizeof(int)* 10001);
	int endA = ASize - 1;
	int next = 0;//进位数
	int i = 0;
	while (endA >= 0 || K > 0)
	{
		int x1 = 0;
		int x2 = 0;
		if (endA >= 0)
		{
			x1 = A[endA];
			endA--;
		}
		if (K >= 0)
		{
			x2 = K % 10;
			K /= 10;
		}
		int ret = x1 + x2 + next;
		if (ret > 9)
		{
			ret %= 10;
			next = 1;
		}
		else
		{
			next = 0;
		}

		arr[i] = ret;
		i++;
	}
	if (next == 1)
	{
		arr[i] = next;
		i++;
	}
	reverse(arr, i);
	*returnSize = i;
	return arr;
}