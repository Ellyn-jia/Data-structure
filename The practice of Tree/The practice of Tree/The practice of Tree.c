


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


