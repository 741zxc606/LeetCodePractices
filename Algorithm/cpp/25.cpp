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
    ListNode(int x) :val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        head = dummy;
        while (head->next != NULL)
        {
            head = reverseKNodes(head, k);
        }
        return dummy->next;
    }

    //reverse the next k nodes after head:head->n1->n2->...nk...=>heda->nk->nk-1...n1->...
    //return n1(the next head)
    ListNode *reverseKNodes(ListNode *head, int k)
    {
        ListNode *node = head;
        for (int i = 0; i < k; i++)
        {
            if (node->next == NULL)
            {
                return node;
            }
            node = node->next;
        }

        ListNode *n1 = head->next;
        ListNode *curt = n1;
        ListNode *next = curt->next;
        for (int i = 0; i < k - 1; i++)
        {
            if (next == NULL)
            {
                n1->next = NULL;
                break;
            }
            ListNode *temp = next->next;
            next->next = curt;
            curt = next;
            next = temp;
        }
        head->next = curt;
        n1->next = next;
        return n1;
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
    ListNode *head = s.reverseKGroup(createLinkedList({ 1,2,3,4,5,6,7,8,9,10 }), 3);
    for (ListNode *cur = head; cur; cur = cur->next)
        std::cout << cur->val << "->";
    std::cout << "\b\b " << std::endl;

    return 0;
}
