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
}void reverse(int* nums, int start, int end)
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