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
int num = 0;
void CaculateleafNum(BinaryNode* root) 
{
	if (root == NULL)
		return;
	if (root->lchird == NULL && root->rchird == NULL)
		num++;
	//������Ҷ�ӽڵ���Ŀ
	CaculateleafNum(root->lchird);
	//������Ҷ�ӽڵ���Ŀ
	CaculateleafNum(root->rchird);

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
	CaculateleafNum(&node1);
}

int main(void)
{
	CreatBinaryTree();
	cout << num;
	return 0;
}
#endif