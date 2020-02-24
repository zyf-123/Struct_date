#include<iostream>
using namespace std;
struct	Node
{
	int data;
	Node* next;
};
int m()
{
	Node *head =new Node;
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
	return 0;
}
#if 0
int weichafa()
{
	Node *phead, *pnew, *pend;
	phead = new	Node;
	pend = phead;
	for (int i = 0; i < 10; i++)
	{
		pnew = new Node;
		pnew->data = i;
		pend->next = pnew;
		pend = pnew;

	}
	pend->next = NULL;
	
	Node* pre = phead->next;
	while (pre)
	{
		cout << pre->data;
		pre = pre->next;
	}
	return 0;
}
//可能要删除的数是第一个 
    while(head!=NULL&&head->num==k)
     {
         p=head;
         head=head->next;
         free(p);
     }
     //下面扫描链表中间寻找需要删除的数 
     q=head;
   p=head->next;
     while(p!=NULL)
     {
         if(p->num==k)//删除p结点 
         {
          q->next=p->next;
            free(p);
            p=q->next;
         }
         else//q和p往后挪一个结点 
         {
             q=p;
             p=p->next;
        }
   }
#endif
