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

void BinaryTreeDestory(TreeNode** root)
{
	if (*root)
	{
		BinaryTreeDestory((*root)->left);
		BinaryTreeDestory((*root)->right);
		free(*root);
		*root = NULL;
	}
}

int BinaryTreeSize(TreeNode* root)
{
	if (root == NULL)
		return 0;
	return 1 + Treesize(root->left) + Treesize(root->right);
}

int BinaryTreeLeafSize(TreeNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}
int BinaryTreeLevelKSize(TreeNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}
TreeNode* BinaryTreeFind(TreeNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->data == x)
		return root;
	TreeNode* ret = BinaryTreeFind(root->left, x);
	if (ret)
		return ret;
	ret = BinaryTreeFind(root->right, x);
	if (ret)
		return ret;

}
void BinaryTreePrevOrder(TreeNode* root)
{
	if (root)
	{
		putchar(root);
		BinaryTreePrevOrder(root->left);
		BinaryTreePrevOrder(root->right);
	}
}
void BinaryTreeInOrder(TreeNode* root)
{
	if (root)
	{
		BinaryTreeInOrder(root->left);
		putchar(root);
		BinaryTreeInOrder(root->right);
	}
}
void BinaryTreePostOrder(TreeNode* root)
{
	if (root)
	{
		BinaryTreeInOrder(root->left);
		BinaryTreeInOrder(root->right);
		putchar(root);
	}
}
void BinaryTreeLevelOrder(TreeNode* root)
{
	Queue qu;
	TreeNode * cur;
	QueueInit(&qu);
	QueuePush(&qu, root);
	while (!QueueIsEmpty(&qu))
	{
		cur = QueueTop(&qu);
		putchar(cur->data);
		if (cur->left)
		{
			QueuePush(&qu, cur->left);
		}

		if (cur->right)
		{
			QueuePush(&qu, cur->right);
		}
		QueuePop(&qu);
	}
	QueueDestory(&qu);
}

int BinaryTreeComplete(TreeNode* root)
{
	Queue qu;
	TreeNode * cur;
	int tag = 0;
	QueueInit(&qu);

	QueuePush(&qu, root);

	while (!QueueIsEmpty(&qu))
	{
		cur = QueueTop(&qu);

		putchar(cur->data);

		if (cur->right && !cur->left)
			return 0;
		if (tag && (cur->right || cur->left))
			return 0;
		if (cur->left)
			QueuePush(&qu, cur->left);
		if (cur->right)
			QueuePush(&qu, cur->right);
		else
			tag = 1;
		QueuePop(&qu);
	}
	QueueDestory(&qu);
	return 1;
}