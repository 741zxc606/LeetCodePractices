/*
 * 82.Remove Duplicates from Sorted List II
 * Given a sorted linked list,delete all nodes that have duplicate numbers,leaving only distinct numbers from the original list.
 * For example,
 * Given 1->2->3->3->4->4->5,return 1->2->5.
 * Given 1->1->1->2->3,return 2->3.
 */

#include <cstddef>
#include <vector>
#include <algorithm>
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
        if (!head) return 0;
        if (!head->next) return head;

        int val = head->val;
        ListNode* p = head->next;

        if (p->val != val)
        {
            head->next = deleteDuplicates(p);
            return head;
        }
        else
        {
            while (p&&p->val == val) p = p->next;
            return deleteDuplicates(p);
        }
    }
};

ListNode *createList(int a[],int n)
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

void printandClear(ListNode *head)
{
    while (head)
    {
        printf("%d",head->val);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    int a[] = { 1,2,3,3,4,4,5 };
    int b[] = { 1,1,1,2,3 };

    Solution s;

    printandClear(s.deleteDuplicates(createList(a, sizeof(a) / sizeof(int))));
    printandClear(s.deleteDuplicates(createList(b, sizeof(b) / sizeof(int))));
}
