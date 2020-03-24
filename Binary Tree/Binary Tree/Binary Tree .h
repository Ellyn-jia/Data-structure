#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>

typedef char BTDataType;

typedef struct TreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}TreeNode;

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
TreeNode* BinaryTreeCreate(BTDataType* a, int* pi);
// 二叉树销毁
void BinaryTreeDestory(TreeNode** root);
// 二叉树节点个数
int BinaryTreeSize(TreeNode* root);
// 二叉树叶子节点个数
int BinaryTreeLeafSize(TreeNode* root);
// 二叉树第k层节点个数
int BinaryTreeLevelKSize(TreeNode* root, int k);
// 二叉树查找值为x的节点
TreeNode* BinaryTreeFind(TreeNode* root, BTDataType x);
// 二叉树前序遍历 
void BinaryTreePrevOrder(TreeNode* root);
// 二叉树中序遍历
void BinaryTreeInOrder(TreeNode* root);
// 二叉树后序遍历
void BinaryTreePostOrder(TreeNode* root);
// 层序遍历
void BinaryTreeLevelOrder(TreeNode* root);
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(TreeNode* root);