/*
 * 61.Rotate List
 * Given a list,rotate the list to the right by k places,where k is non-negative.
 *
 * For example:
 * Given 1->2->3->4->5->NULL and k=2,
 * return 4->5->1->2->3->NULL.
 */

#include <vector>
#include <algorithm>
#include <cstddef>
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) :val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        if (!head || k <= 0)
        {
            return head;
        }

        //find the length of list
        int len = 1;
        ListNode *p = head;
        while (p->next != NULL)
        {
            p = p->next;
            len++;
        }

        //connect the tail to head
        p->next = head;
        //find the left place(take care the case - k > len)
        k = len - k%len;

        //find the place
        for (int i = 0; i < k; i++)
        {
            p = p->next;
        }

        //break the list
        head = p->next;
        p->next = NULL;

        return head;
    }
};

ListNode *create_linkedlists(std::initializer_list<int>lst)
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
    ListNode *head = s.rotateRight(create_linkedlists({ 1,2,3,4,5 }), 2);
    for (ListNode *cur = head; cur; cur = cur->next)
        std::cout << cur->val << "->";
    std::cout << "\b\b" << std::endl;

    return 0;
}
