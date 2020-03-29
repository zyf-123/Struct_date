#if 0
#include<iostream>
using namespace std;
int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
int len = sizeof(arr) / sizeof(arr[0]);
struct	Node
{
	int data;
	Node* next;
};
Node * m()
{
	Node* head = new Node;
	head->next = NULL;
	for (int i = 0; i < 10; i++)
	{
		Node* newp = new Node;
		newp->next = head->next;
		newp->data = i;
		head->next = newp;

	}
	Node* pre = head->next;
	while (pre)
	{
		cout << pre->data;
		pre = pre->next;
	}
	cout << endl;
	return head;
}

void sequence_list_transpose(int *arr);
struct Node* reverse(struct Node* head);
void print(struct Node* head);
int main()
{

	//sequence_list_transpose(arr);
	Node * p=m();
	
	print(reverse(p));
	return 0;
}
void sequence_list_transpose(int *arr)
{
	
	for (int i = 0; i <len/2; i++)
	{
		int temp;
		temp = arr[i];
		arr[i] = arr[len- i - 1];
		arr[len - i -1] = temp;
	}
}
struct Node* reverse(struct Node* head)
{
			if (head == NULL)
				return NULL;
			if (head->next == NULL)//链表中只有一个节点
				return head;

			Node* p1,* p2,* p3;
			p1 = head;//为了保存头节点
			p2 = head->next;
			head->next = NULL;
			p3 = p2->next;
			while (p3 != NULL)
			{
				p2->next = p1;
				p1 = p2;
				p2 = p3;
				p3 = p2->next;
			}
			p2->next = p1;
			head = p2;
			return head;
};
void print(struct Node* head)
{
	Node* pre = head;
	while (pre ->next!=NULL)
	{
		cout << pre->data;
		pre = pre->next;
	}
}
#endif