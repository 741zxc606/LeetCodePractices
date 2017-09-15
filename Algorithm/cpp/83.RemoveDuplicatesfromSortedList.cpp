/*
 * 83.Remove Duplicates from the Sorted List
 * Given a sorted linked list,delete all duplicates such that each element appear only once.
 * For example,
 * Given 1->1->2,return 1->2.
 * Given 1->1->2->3->3,return 1->2->3.
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
    ListNode* deleteDuplicates(ListNode* head)
    {
        for (ListNode *p = head; p&&p->next;)
        {
            if (p->val == p->next->val)
            {
                p->next = p->next->next;
                continue;
            }
            p = p->next;
        }
        return head;
    }
};

void printList(ListNode* h)
{
    while (h != NULL)
    {
        printf("%d", h->val);
        h = h->next;
    }
    printf("\n");
}

ListNode* createList(int a[], int n)
{
    ListNode *head = NULL, *p = NULL;
    for (int i = 0; i < n; i++)
    {
        if (head == NULL)
        {
            head = p = new ListNode(a[i]);
        }
        else
        {
            p->next = new ListNode(a[i]);
            p = p->next;
        }
    }
    return head;
}

int main()
{
    Solution s;

    int a[] = { 1,1,2,3,3 };
    int b[] = { 1,1,1 };

    printList(s.deleteDuplicates(createList(a, sizeof(a) / sizeof(int))));
    printList(s.deleteDuplicates(createList(b, sizeof(b) / sizeof(int))));
}
