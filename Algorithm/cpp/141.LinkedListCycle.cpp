/*
 * 141.Linked List Cycle
 * Given a linked list,determine if it has a cycle in it.
 * Follow up:
 * Can you solve it without using extra space?
 */

#include <iostream>
#include <algorithm>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
    ListNode(int x) :val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head)
    {
        if (head == NULL || head->next == NULL)return false;
        ListNode* fast = head;
        ListNode* slow = head;
        do {
            slow = slow->next;
            fast = fast->next->next;
        } while (fast != NULL&&fast->next != NULL&&fast != slow);
        return fast == slow ? true : false;
    }
};

int main()
{
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(5);
    ListNode node6(6);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;
    node6.next = &node1;

    Solution s;
    std::cout << s.hasCycle(&node1) << std::endl;

    return 0;
}
