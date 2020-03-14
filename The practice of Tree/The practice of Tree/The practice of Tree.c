


//判断两棵树是否相同
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/
bool isSameTree(struct TreeNode* p, struct TreeNode* q){
	if (p == NULL && q == NULL)
		return true;
	if (p == NULL || q == NULL)
		return false;
	if (q->val != p->val)
		return false;
	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}


//对称二叉树

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/

bool _isSymmetric(struct TreeNode* p, struct TreeNode* q)
{
	if (p == NULL && q == NULL)
		return true;
	if (p == NULL || q == NULL)
		return false;
	return p->val == q->val && _isSymmetric(p->left, q->right) && _isSymmetric(p->right, q->left);
}

bool isSymmetric(struct TreeNode* root){
	if (root == NULL)
		return true;
	return _isSymmetric(root->left, root->right);
}



//平衡二叉树
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/


int Depth(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	int leftDepth = Depth(root->left);
	int rightDepth = Depth(root->right);
	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

bool isBalanced(struct TreeNode* root){
	if (root == NULL)
		return true;
	int leftDepth = Depth(root->left);
	int rightDepth = Depth(root->right);

	return abs(leftDepth - rightDepth) < 2 && isBalanced(root->left) && isBalanced(root->right);
}


//翻转二叉树
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/


struct TreeNode* invertTree(struct TreeNode* root){
	if (root == NULL)
		return NULL;
	struct TreeNode* t = root->left;
	root->left = root->right;
	root->right = t;

	invertTree(root->left);
	invertTree(root->right);
	return root;
}


//二叉树的最大深度
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/


int maxDepth(struct TreeNode* root){
	if (root == NULL)
		return 0;
	int leftDepth = maxDepth(root->left);
	int rightDepth = maxDepth(root->right);
	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}


//判断单值二叉树
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/


bool isUnivalTree(struct TreeNode* root){
	if (root == NULL)
		return true;
	if (root->left && root->left->val != root->val)
		return false;
	if (root->right && root->right->val != root->val)
		return false;
	return isUnivalTree(root->left) && isUnivalTree(root->right);

}



//二叉树前序遍历

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/


/**
* Note: The returned array must be malloced, assume caller calls free().
*/

int Treesize(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	return 1 + Treesize(root->left) + Treesize(root->right);
}

void _preorderTraversal(struct TreeNode* root, int* A, int* pi)
{
	if (root == NULL)
		return;
	A[(*pi)++] = root->val;
	_preorderTraversal(root->left, A, pi);
	_preorderTraversal(root->right, A, pi);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
	int size = Treesize(root);
	int* A = (int*)malloc(sizeof(int)*size);

	*returnSize = size;

	int i = 0;
	_preorderTraversal(root, A, &i);
	return A;
}

//二叉树中序
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/


/**
* Note: The returned array must be malloced, assume caller calls free().
*/

int Treesize(struct TreeNode* root){
	if (root == NULL)
		return 0;
	return 1 + Treesize(root->left) + Treesize(root->right);
}
void _inorderTraversal(struct TreeNode* root, int* A, int* pi){
	if (root == NULL)
		return;
	_inorderTraversal(root->left, A, pi);
	A[(*pi)++] = root->val;
	_inorderTraversal(root->right, A, pi);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize){

	int size = Treesize(root);
	int* A = (int*)malloc(sizeof(int)*size);
	*returnSize = size;

	int i = 0;
	_inorderTraversal(root, A, &i);
	return A;
}

//二叉树后序
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     struct TreeNode *left;
*     struct TreeNode *right;
* };
*/


/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int Treesize(struct TreeNode* root)
{
	if (root == NULL)
		return 0;
	return 1 + Treesize(root->left) + Treesize(root->right);
}
void _postorderTraversal(struct TreeNode* root, int* A, int* pi)
{
	if (root == NULL)
		return;
	_postorderTraversal(root->left, A, pi);
	_postorderTraversal(root->right, A, pi);
	A[(*pi)++] = root->val;
}
int* postorderTraversal(struct TreeNode* root, int* returnSize){
	int size = Treesize(root);
	int* A = (int*)malloc(sizeof(int)*size);
	*returnSize = size;

	int i = 0;
	_postorderTraversal(root, A, &i);
	return A;
}
