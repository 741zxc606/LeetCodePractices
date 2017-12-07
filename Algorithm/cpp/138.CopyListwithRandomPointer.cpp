/*
* 138.Copy List with Random Pointer
* A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
* Return a deep copy of the list.
*/

#include <iostream>
#include <algorithm>
using namespace std;

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) :label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head)
	{
		RandomListNode *newHead, *l1, *l2;

		if (head == NULL) return NULL;
		for (l1 = head; l1 != NULL; l1 = l1->next->next)
		{
			l2 = new RandomListNode(l1->label);
			l2->next = l1->next;
			l1->next = l2;
		}

		newHead = head->next;
		for (l1 = head; l1 != NULL; l1 = l1->next->next)
		{
			if (l1->random != NULL)l1->next->random = l1->random->next;
		}

		for (l1 = head; l1 != NULL; l1 = l1->next)
		{
			l2 = l1->next;
			l1->next = l2->next;
			if (l2->next != NULL)l2->next = l2->next->next;
		}
		return newHead;
	}
};

void print_RandomList(RandomListNode *head)
{
	while (head)
	{
		cout << head->label << " ";
		if (head->random)cout << head->random->label << " ";
		else cout << "NULL" << " ";
		head = head->next;
	}
	cout << endl;
}

void clear(RandomListNode *head)
{
	while (head)
	{
		RandomListNode *tmp = head;
		head = head->next;
		delete tmp;
	}
}

int main()
{
	Solution s;
	RandomListNode head(0);
	RandomListNode node(1);
	RandomListNode last(2);

	head.next = &node;
	node.next = &last;

	head.random = &last;
	node.random = &head;
	last.random = &last;

	print_RandomList(&head);
	RandomListNode *new_head = s.copyRandomList(&head);
	print_RandomList(new_head);
	clear(new_head);

	return 0;
}
