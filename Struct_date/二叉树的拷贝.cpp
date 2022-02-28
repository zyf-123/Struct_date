#if 0;
#include<iostream>
#include<cstring>
#pragma warning (disable:4996)
using namespace std;
//�������Ľڵ�
typedef struct BinaryNode
{
	char ch;
	struct BinaryNode* lchird;
	struct BinaryNode* rchird;
};
//����������
void Recursion(BinaryNode * root)
{
	if (root == NULL)
		return;
	cout << root->ch;
	Recursion(root->lchird);
	Recursion(root->rchird);
	
}
//����������
BinaryNode* CopyBinaryTree(BinaryNode* root)
{
	if (root == NULL)
		return NULL;
	BinaryNode* newnode = new BinaryNode;
	newnode->ch = root->ch;
	newnode->lchird = CopyBinaryTree(root->lchird);
	newnode->rchird = CopyBinaryTree(root->rchird);
	return newnode;

}
//�ͷŶ�����
void FreeBinaryTree(BinaryNode* root)
{
	if (root == NULL)
		return ;
	FreeBinaryTree(root->lchird);
	FreeBinaryTree(root->rchird);
	delete root;

}
void CreatBinaryTree()
{
	//�����ڵ�
	BinaryNode node1{ 'A',NULL,NULL };
	BinaryNode node2{ 'B',NULL,NULL };
	BinaryNode node3{ 'C',NULL,NULL };
	BinaryNode node4{ 'D',NULL,NULL };
	BinaryNode node5{ 'E',NULL,NULL };
	BinaryNode node6{ 'F',NULL,NULL };
	BinaryNode node7{ 'G',NULL,NULL };
	BinaryNode node8{ 'H',NULL,NULL };
	//�����ڵ��ϵ
	node1.lchird = &node2;
	node1.rchird = &node6;

	node2.rchird = &node3;

	node3.lchird = &node4;
	node3.rchird = &node5;

	node6.lchird = &node7;
	node7.lchird = &node8;
	BinaryNode* root= CopyBinaryTree(&node1);
	Recursion(&node1);
	cout << endl;
	Recursion(root);
	FreeBinaryTree(root);
}

int main(void)
{
	CreatBinaryTree();

	return 0;
}
#endif