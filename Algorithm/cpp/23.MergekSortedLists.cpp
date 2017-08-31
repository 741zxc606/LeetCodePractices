/*
 * 23. Merge k Sorted Lists
 * Merge k sorted linked lists and return it as one sorted list.Analyze and describe its complexity.
 */

#include <cstddef>
#include <vector>
#include <iostream>
using namespace std;
using std::vector;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};

class Solution
{
	ListNode *mergeTwoLists(ListNode *l1,ListNode *l2)
	{
		ListNode *head = NULL, **lastPtrRef = &head;
		for (; l1&&l2; lastPtrRef = &((*lastPtrRef)->next))
		{
			if (l1->val <= l2->val)
			{
				*lastPtrRef = l1;
				l1 = l1->next;
			}
			else
			{
				*lastPtrRef = l2; 
				l2 = l2->next;
			}
		}
		*lastPtrRef = l1 ? l1 : l2;
		return head;
	}

	using vecNodeCIter = vector<ListNode *>::const_iterator;
	ListNode *mergeKLists(vecNodeCIter begin, vecNodeCIter end)
	{
		if (begin == end) return NULL;
		else if (std::distance(begin, end) == 1) return *begin;
		else if (std::distance(begin, end) == 1) return mergeTwoLists(*begin, *std::next(begin));
		else return mergeTwoLists(mergeKLists(begin, begin + std::distance(begin, end) / 2), mergeKLists(begin + std::distance(begin, end) / 2, end));
	}

public:
	ListNode *mergeKLists(vector<ListNode *>&lists)
	{
		return mergeKLists(lists.cbegin(),lists.cend());
	}
};

ListNode *create_linkedlist(std::initializer_list<int> lst)
{
	auto iter = lst.begin();
	ListNode *head = lst.size() ? new ListNode(*iter++) : nullptr;
	for (ListNode *cur = head; iter != lst.end(); cur=cur->next)
		cur->next = new ListNode(*iter++);
	return head;
}

void clear(ListNode *head)
{
	while (head)
	{
		ListNode *del = head;
		head = head->next;
		delete del;
	}
}

void printList(ListNode *head)
{
	for (ListNode *cur = head; cur; cur = cur->next)
		cout << cur->val << "->";
	cout << "\b\b " << endl;
}

int main()
{
	Solution s;
	vector<ListNode *> vec{
		create_linkedlist({1,3,5,7,9}),
		create_linkedlist({0,2,4,6,8}),
		create_linkedlist({11,12,22})
	};
	ListNode *ret = s.mergeKLists(vec);
	printList(ret);
	clear(ret);

	return 0;
}
