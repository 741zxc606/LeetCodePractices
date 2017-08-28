/*
 * 21. Merge Two Sorted Lists
 * Merge two sorted linked lists and return it as a new list.
 * The new list should be made by splicing together the nodes of the first two lists.
 */

#include <vector>
#include <iostream>
using namespace std;
using vecIter = std::vector<int>::iterator;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
	{
		ListNode *dummy = new ListNode(0);
		ListNode *tmp = dummy;
		while (l1 != NULL&&l2 != NULL)
		{
			if (l1->val < l2->val)
			{
				tmp->next = l1;
				l1 = l1->next;
			}
			else
			{
				tmp->next = l2;
				l2 = l2->next;
			}
			tmp = tmp->next;
		}
		if (l1 != NULL) tmp->next = l1;
		else tmp->next = l2;
		return dummy->next;
	}
};

ListNode *createLinkedList(vecIter begin,vecIter end)
{
	ListNode *head = begin == end ? NULL : new ListNode(*begin++);
	for (ListNode *cur = head; begin != end; cur = cur->next)
		cur->next = new ListNode(*begin++);
	return head;
}

bool compareTwoLinkedList(ListNode *l1, ListNode *l2)
{
	for (; l1&&l2; l1 = l1->next, l2 = l2->next)
		if (l1->val != l2->val) break;

	return l1 || l2 ? false : true;
}

void printAndClear(ListNode *head)
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
	std::vector<int> vec1 = {1,2,5,6,7,9};
	std::vector<int> vec2 = {0,1,2,3,4,8};

	ListNode *l1 = createLinkedList(vec1.begin(),vec1.end());
	ListNode *l2 = createLinkedList(vec2.begin(),vec2.end());

	Solution s;

	ListNode *lm = s.mergeTwoLists(l1, l2);

	printAndClear(lm);
}
