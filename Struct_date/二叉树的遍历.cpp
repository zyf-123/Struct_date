#if 0;
#include<iostream>
#include<cstring>
#pragma warning (disable:4996)
using namespace std;
//二叉树的节点
typedef struct BinaryNode
{
	char ch;
	struct BinaryNode* lchird;
	struct BinaryNode* rchird;
};
void  Recursion(BinaryNode* root)
{
	if (root == NULL)
		return;
	//先序遍历
	//访问根节点
	cout << root->ch;
	//再遍历左子树
	Recursion(root->lchird);
	//再遍历右子树
	Recursion(root->rchird);
}
void CreatBinaryTree()
{
	//创建节点
	BinaryNode node1{ 'A',NULL,NULL };
	BinaryNode node2{ 'B',NULL,NULL };
	BinaryNode node3{ 'C',NULL,NULL };
	BinaryNode node4{ 'D',NULL,NULL };
	BinaryNode node5{ 'E',NULL,NULL };
	BinaryNode node6{ 'F',NULL,NULL };
	BinaryNode node7{ 'G',NULL,NULL };
	BinaryNode node8{ 'H',NULL,NULL };
	//建立节点关系
	node1.lchird = &node2;
	node1.rchird = &node6;
	
	node2.rchird = &node3;
	
	node3.lchird = &node4;
	node3.rchird = &node5;

	node6.lchird = &node7;
	node7.lchird = &node8;
	Recursion(&node1);
}

int main(void)
{
	CreatBinaryTree();
	cout << endl;
	return 0;
}
#endif