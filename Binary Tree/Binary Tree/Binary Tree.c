#include"Binary Tree .h"

TreeNode* BinaryTreeCreate(BTDataType* a, int* pi)
{
	if (a[*pi] == '#')
		return NULL;
	else
	{
		TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
		root->data = a[*pi];
		(*pi)++;
		root->left = BinaryTreeCreate(a, pi);
		(*pi)++;
		root->right = BinaryTreeCreate(a, pi);
		return root;
	}
}

