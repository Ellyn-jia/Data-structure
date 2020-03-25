#include"Binary Tree .h"
int main()
{
	int i = 0;
	BTDataType a[100];
	scanf("%s", a);
	TreeNode* root = BinaryTreeCreate(a, &i);

	return 0;
}