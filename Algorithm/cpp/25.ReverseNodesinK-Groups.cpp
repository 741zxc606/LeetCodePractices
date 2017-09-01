/*
 * 25. Reverse Nodes in k-Group
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 * k is a positive integer and is less than or equal to the length of the linked list.
 * If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 * You may not alter the values in the nodes, only nodes itself may be changed.
 * Only constant memory is allowed.
 * For example,
 * Given this linked list: 1->2->3->4->5
 * For k = 2, you should return: 2->1->4->3->5
 * For k = 3, you should return: 3->2->1->4->5
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) :val(x), next(NULL){}
};

class Solution
{
public:
    // p1->p1next->...->p2->p2next
    //      |____________|
    //   reverse this part to:
    // p1->p2->.......->p1next->p2next;
    // return p1next;

    ListNode *reverse(ListNode *p1, ListNode *p2)
    {
        ListNode *p1next = p1->next;
        ListNode *p2next = p2->next;
        ListNode *prev = p2next;
        ListNode *p = p1next;

        while (p != p2next)
        {
            ListNode *temp = p->next;
            p->next = prev;
            prev = p;
            p = temp;
        }
        p1->next = p2;
        return p1next;
    }

    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if (k == 1)
        {
            return head;
        }

        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *p1 = dummy,*p2 = dummy;

        for (int i = 0; i < k; i++)
        {
            if (p2 == NULL)
            {
                break;
            }
            p2 = p2->next;
        }
        if (p2 == NULL)
        {
            return head;
        }

        while (p2 != NULL)
        {
            p2 = reverse(p1, p2);
            for (int i = 0; i < k; i++)
            {
                if (p2 == NULL)
                {
                    break;
                }
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        return dummy->next;
    }
};

ListNode *createLinkedList(std::initializer_list<int> lst)
{
    auto iter = lst.begin();
    ListNode *head = lst.size() ? new ListNode(*iter++) : NULL;
    for (ListNode *cur = head; iter != lst.end(); cur = cur->next)
        cur->next = new ListNode(*iter++);
    return head;
}

int main()
{
    Solution s;
    ListNode *head = s.reverseKGroup(createLinkedList({ 1,2,3,4,5,6,7,8,9,10 }),3);
    for (ListNode *cur = head; cur; cur = cur->next)
        std::cout << cur->val << "->";
    std::cout << "\b\b " << std::endl;

    return 0;
}
