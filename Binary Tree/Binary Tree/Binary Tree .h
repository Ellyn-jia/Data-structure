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


// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
TreeNode* BTCreate(BTDataType* a, int* pi);
// ����������
void BTDestory(TreeNode* root);
// �������ڵ����
int TreeSize(TreeNode* root);
// ������Ҷ�ӽڵ����
int LeafSize(TreeNode* root);
// ��������k��ڵ����
int LevelKSize(TreeNode* root, int k);
// ����������ֵΪx�Ľڵ�
TreeNode* TreeFind(TreeNode* root, BTDataType x);
// ǰ��
void PrevOrder(TreeNode* root);
// ����
void InOrder(TreeNode* root);
// ����
void PostOrder(TreeNode* root);
// �������
void BinaryTreeLevelOrder(TreeNode* root);
// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(TreeNode* root);
