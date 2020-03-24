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