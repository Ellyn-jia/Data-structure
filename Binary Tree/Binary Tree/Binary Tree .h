#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<malloc.h>

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}TreeNode;


// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
TreeNode* BTCreate(BTDataType* a, int* pi);
// 二叉树销毁
void BTDestory(TreeNode* root);
// 二叉树节点个数
int TreeSize(TreeNode* root);
// 二叉树叶子节点个数
int LeafSize(TreeNode* root);
// 二叉树第k层节点个数
int LevelKSize(TreeNode* root, int k);
// 二叉树查找值为x的节点
TreeNode* TreeFind(TreeNode* root, BTDataType x);
// 前序
void PrevOrder(TreeNode* root);
// 中序
void InOrder(TreeNode* root);
// 后序
void PostOrder(TreeNode* root);
// 层序遍历
void BinaryTreeLevelOrder(TreeNode* root);
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(TreeNode* root);
