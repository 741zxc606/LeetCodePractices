/*
* 160.Intersection of Two Linked Lists
*
* Write a program to find the node at which the intersection of two singly linked lists begins.
* For example:
*    A:    a1 -> a2
*                   -> c1 -> c2 -> c3
*    B:  b1->b2->b3
* begin to intersect at node c1.
* Notes:
*    1.If the two linked lists have no intersection at all,return null.
*    2.The linked lists must retain their original structure after the function returns.
*    3.You may assume there are no cycles anywhere in the entire linked structure.
*    4.Your code should preferably run in O(n) time and use only O(1) memory.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
	struct ListNode *p;
	for (p = headA; p->next != NULL; p = p->next) {}
	p->next = headB;

	bool first = true;
	struct ListNode *p0, *p1;
	for (p0 = headA, p1 = headA; p1 != NULL&&p1->next != NULL; p0 = p0->next, p1 = p1->next->next)
	{
		if (p0 == p1 && !first)
		{
			p0 = headA;
			while (p0 != NULL)
			{
				p0 = p0->next;
				p1 = p1->next;
			}
			p->next = NULL;
			return p0;
		}
		first = false;
	}
	p->next = NULL;
	return NULL;
};

int main()
{
	struct ListNode *headA = malloc(sizeof(*headA));
	struct ListNode *headB = malloc(sizeof(*headB));
	struct ListNode *common = malloc(sizeof(*common));

	headA->val = 1;
	headB->val = 2;
	common->val = 4;
	headA->next = common;
	headB->next = common;
	common->next = NULL;

	struct ListNode *p = getIntersectionNode(headA, headB);

	if (p != NULL)
	{
		printf_s("%d\n", p->val);
	}
	return 0;
}
