/*
* 2.Add Two Numbers
* You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of
* their nodes contain a single digit. Add the two numbers and return it as a linked list.
* You may assume the two numbers do not contain any leading zero, except the number 0 itself.
* Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
* Output: 7 -> 0 -> 8
*/

#include <iostream>
using namespace std;

typedef struct node
{
	int data;
	node *next;
}node;

node* init(int a[], int n)
{
	node *head = NULL, *p;
	for (int i = 0; i < n; ++i)
	{
		node *nd = new node();
		nd->data = a[i];
		if (i == 0)
		{
			head = p = nd;
			continue;
		}
		p->next = nd;
		p = nd;
	}
	return head;
}

node* addlink(node *p, node *q)
{
	if (p == NULL) return q;
	if (q == NULL) return p;
	node *res, *pre = NULL;
	int c = 0;
	while (p&&q)
	{
		int t = p->data + q->data + c;
		node *r = new node();
		r->data = t % 10;
		if (pre)
		{
			pre->next = r;
			pre = r;
		}
		else pre = res = r;
		c = t % 10;
		p = p->next; q = q->next;
	}
	while (p)
	{
		int t = p->data + c;
		node *r = new node();
		r->data = t % 10;
		pre->next = r;
		pre = r;
		c = t / 10;
		p = p->next;
	}
	while (q)
	{
		int t = q->data + c;
		node *r = new node();
		r->data = t % 10;
		pre->next = r;
		pre = r;
		c = t / 10;
		q = q->next;
	}
	if (c > 0)
	{
		node *r = new node();
		r->data = c;
		pre->next = r;
	}
	return res;
}

void print(node *head)
{
	while (head)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

int main()
{
	int n = 3;
	int a[] = {2,4,3};
	int m = 3;
	int b[] = {5,6,4};

	node *p = init(a, n);
	node *q = init(b, m);
	node *res = addlink(p,q);
	if (p) print(p);
	if (q) print(q);
	if (res) print(res);
	return 0;
}
