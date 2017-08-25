/*
 * 19.Remove Nth Node From End of List
 * Given a linked list,remove the nth node from the end of list and return its head.
 * For example:
 *  Given linked list: 1->2->3->4->5,and n=2.
 *  After removing the second node from the end,the linked list becomes 1->2->3->5.
 * Note:
 * Given n will always be valid.
 * Try to do this in one pass.
 */

#include <cstddef>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;
using std::vector;
using vecIter = vector<int>::iterator;

//Define for singly-linked list.
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//
class Solution
{
public:
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		ListNode **del = &head, *iter = head;
		for (int i = 0; i < n; ++i, iter = iter->next);
		for (; iter != NULL; del = &((*del)->next), iter = iter->next);
		*del = (*del)->next;
		return head;
	}

	ListNode* removeNthFromEnd2(ListNode* head, int n)
	{
		ListNode *res = new ListNode(0);
		res->next = head;
		ListNode *tmp = res;
		for (int i = 0; i < n; i++)
		{
			head = head->next;
		}
		while (head != NULL)
		{
			head = head->next;
			tmp = tmp->next;
		}
		tmp->next = tmp->next->next;
		return res->next;
	}
};

ListNode *createLinkedList(vecIter begin, vecIter end)
{
	ListNode *head = begin == end ? NULL : new ListNode(*begin++);
	for (ListNode *cur = head; begin != end; cur = cur->next)
		cur->next = new ListNode(*begin++);
	return head;
}

void printAnClear(ListNode *head)
{
	while (head)
	{
		std::cout << head->val;
		if (head->next) std::cout << "->";
		ListNode *del = head;
		head = head->next;
		delete del;
	}
	std::cout << std::endl;
}

int main()
{
	vector<int> vec1{1,2,3,4,5};
	vector<int> vec2{1,2};

	ListNode *head1 = createLinkedList (vec1.begin(),vec1.end());
	ListNode *head2 = createLinkedList (vec2.begin(),vec2.end());

	Solution s;
	ListNode *res1 = s.removeNthFromEnd(head1,2);
	ListNode *res2 = s.removeNthFromEnd(head2,2);

	printAnClear(res1);
	printAnClear(res2);

	ListNode *res3 = s.removeNthFromEnd2(head1, 2);
	ListNode *res4 = s.removeNthFromEnd2(head2, 2);

	printAnClear(res3);
	printAnClear(res4);

	return 0;
}
