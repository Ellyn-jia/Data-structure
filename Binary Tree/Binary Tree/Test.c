#include"Binary Tree .h"

int main()
{

	BTDataType a[100] = "ABC##DE#G##F###";
	int i = 0;
	TreeNode* root = BTCreate(a, &i);

	PrevOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	PostOrder(root);
	printf("\n");

	TreeNode* ret = TreeFind(root, 'A');


	return 0;
}