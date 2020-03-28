#include"Binary Tree .h"

TreeNode* BTCreate(BTDataType* a, int* pi)
{
	if (a[*pi] == '#')
		return NULL;
	else
	{
		TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
		root->data = a[*pi];
		(*pi)++;
		root->left = BTCreate(a, pi);
		(*pi)++;
		root->right = BTCreate(a, pi);
		return root;
	}
}

void BTDestory(TreeNode* root)
{
	if (root == NULL)
		return;
	BTDestory(root->left);
	BTDestory(root->right);
	free(root);
}

int TreeSize(TreeNode* root)
{
	if (root == NULL)
		return 0;
	return 1 + Treesize(root->left) + Treesize(root->right);
}

int LeafSize(TreeNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return LeafSize(root->left) + LeafSize(root->right);
}

int LevelKSize(TreeNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return LevelKSize(root->left, k - 1) + LevelKSize(root->right, k - 1);
}

TreeNode* TreeFind(TreeNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->data == x)
		return root;
	TreeNode* ret = TreeFind(root->left, x);
	if (ret)
		return ret;
	ret = TreeFind(root->right, x);
	if (ret)
		return ret;
	return NULL;
}

void PrevOrder(TreeNode* root)
{
	if (root == NULL)
		return;
	printf("%c ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}


void InOrder(TreeNode* root)
{
	if (root == NULL)
		return;
	InOrder(root->left);
	printf("%c ", root->data);
	InOrder(root->right);
}


void PostOrder(TreeNode* root)
{
	if (root == NULL)
		return;
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->data);
}

void BinaryTreeLevelOrder(TreeNode* root)
{
	Queue q;
	QueueInit(q);
	if (root == NULL)
		QueuePush(&q, root);
	while (!EmptyQueue(&q))
	{
		TreeNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", front->data);
		if (front->left)
			QueuePush(&q, front->left);
		if (front->right)
			QueuePush(&q, front->right);
	}
}
int BinaryTreeComplete(TreeNode* root)
{
	Queue q;
	QueueInit(q);
	if (root == NULL)
		QueuePush(&q, root);
	while (!EmptyQueue(&q))
	{
		TreeNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front == NULL)
			break;

		QueuePush(&q, root->left);
		QueuePush(&q, root->right);
	}
	while (!EmptyQueue(&q))
	{
		TreeNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front != NULL)
			return 0;
	}
	return 1;
}