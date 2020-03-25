#pragma once
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

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
TreeNode* BinaryTreeCreate(BTDataType* a, int* pi);
// ����������
void BinaryTreeDestory(TreeNode** root);
// �������ڵ����
int BinaryTreeSize(TreeNode* root);
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(TreeNode* root);
// ��������k��ڵ����
int BinaryTreeLevelKSize(TreeNode* root, int k);
// ����������ֵΪx�Ľڵ�
TreeNode* BinaryTreeFind(TreeNode* root, BTDataType x);
// ������ǰ����� 
void BinaryTreePrevOrder(TreeNode* root);
// �������������
void BinaryTreeInOrder(TreeNode* root);
// �������������
void BinaryTreePostOrder(TreeNode* root);
// �������
void BinaryTreeLevelOrder(TreeNode* root);
// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(TreeNode* root);

typedef int QDataType;
typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QueueNode;

typedef struct Queue
{
	struct QueueNode* first;
	struct QueueNode* end;
}Queue;

void QueueInit(Queue* q);
void QueuePush(Queue* q, QDataType x);
void QueuePop(Queue* q);
QDataType QueueFirst(Queue* q);
QDataType QueueEnd(Queue* q);
int QueueSize(Queue* q);//������ЧԪ�ظ���
int QueueEmpty(Queue* q);//�� 1   �ǿ� 0
void QueueDestory(Queue* q);