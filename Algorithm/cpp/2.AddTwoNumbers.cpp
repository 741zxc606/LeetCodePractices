/*
 * 2.Add Two Numbers
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of 
 * their nodes contain a single digit. Add the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 */
#include <iostream>
#include <algorithm>
using namespace std;

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
	{
		int x = 0, y = 0, carry = 0, sum = 0;
		ListNode *h = NULL, **t = &h;

		while (l1 != NULL || l2 != NULL)
		{
			x = getValueAndMoveNext(l1);
			y = getValueAndMoveNext(l2);

			sum = carry + x + y;

			ListNode *node = new ListNode(sum % 10);
			*t = node;
			t = (&node->next);

			carry = sum / 10;
		}

		if(carry>0)
		{
			ListNode *node = new ListNode(carry % 10);
			*t = node;
		}
		return h;
	}
private:
	int getValueAndMoveNext(ListNode* &l)
	{
		int x = 0;
		if (l != NULL)
		{
			x = l->val;
			l = l->next;
		}
		return x;
	}
};

int main()
{
	int l1[] = {2,4,3};
	int l2[] = {5,6,4};
	ListNode Sum[] = Solution().addTwoNumbers(l1, l2);
}
