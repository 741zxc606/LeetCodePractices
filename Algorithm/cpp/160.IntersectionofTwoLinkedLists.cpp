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

#include <cstddef>
#include <vector>
#include <iostream>
using namespace std;
using std::vector;
using vecIter = std::vector<int>::iterator;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
		ListNode *p1 = headA;
		ListNode *p2 = headB;

		if (p1 == NULL || p2 == NULL) return NULL;

		while (p1 != NULL &&p2 != NULL&&p1 != p2)
		{
			p1 = p1->next;
			p2 = p2->next;

			if (p1 == p2) return p1;

			if (p1 == NULL) p1 = headB;
			if (p2 == NULL) p2 = headA;
		}
		return p1;
	}
};
