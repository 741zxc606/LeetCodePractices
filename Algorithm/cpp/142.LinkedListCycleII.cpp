/*
 * 142.Linked List Cycle II
 * Given a linked list,return the node where the cycle begins.If there is no cycle,return null.
 * Note:Do not modify the linked list.
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
    ListNode *detectCycle(ListNode *head)
    {
        if (head == NULL || head->next == NULL)return NULL;

        ListNode* fast = head;
        ListNode* slow = head;
        bool isCycle = false;

        while (fast != NULL&&slow != NULL)
        {
            fast = fast->next;
            if (slow->next == NULL)return NULL;
            slow = slow->next->next;
            if (fast == slow) { isCycle = true; break; }
        }

        if (!isCycle) return NULL;
        fast = head;
        while (fast != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
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
    std::cout << s.detectCycle(&node1)->val << std::endl;

    return 0;
}
