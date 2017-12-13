/*
 * 148.Sort List
 * Sort a linked list in O(n log n) time using constant sapce complexity.
 */

#include <iostream>
#include <initializer_list>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) :val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head)
    {
        if (!head || !(head->next)) return head;

        //get the linked list's length
        ListNode* cur = head;
        int length = 0;
        while (cur)
        {
            length++;
            cur = cur->next;
        }

        ListNode dummy(0);
        dummy.next = head;
        ListNode *left, *right, *tail;
        for (int step = 1; step < length; step <<= 1)
        {
            cur = dummy.next;
            tail = &dummy;
            while (cur)
            {
                left = cur;
                right = split(left, step);
                cur = split(right, step);
                tail = merge(left, right, tail);
            }
        }
        return dummy.next;
    }

private:
    /*
     * Divide the linked list into two lists,
     * while the first list contains first n nodes
     * return the second list's head
     */

    ListNode* split(ListNode *head, int n)
    {
        for (int i = 1; head&&i < n; i++)head = head->next;

        if (!head) return NULL;
        ListNode *second = head->next;
        head->next = NULL;
        return second;
    }

    /*
     * merge the two sorted lists l1 and l2,
     * then append the merged sorted linked list to the node head
     * return the tail of the merged sorted linked list
     */

    ListNode* merge(ListNode* l1, ListNode* l2, ListNode* head)
    {
        ListNode *cur = head;
        while (l1&&l2)
        {
            if (l1->val > l2->val)
            {
                cur->next = l2;
                cur = l2;
                l2 = l2->next;
            }
            else
            {
                cur->next = l1;
                cur = l1;
                l1 = l1->next;
            }
        }
        cur->next = (l1 ? l1 : l2);
        while (cur->next)cur = cur->next;
        return cur;
    }
};

ListNode *create_linkedlist(std::initializer_list<int> lst)
{
    auto iter = lst.begin();
    ListNode *head = lst.size() ? new ListNode(*iter++) : NULL;
    for (ListNode *cur = head; iter != lst.end(); cur = cur->next)
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
    ListNode *a = create_linkedlist({ 1,9,3,4,2,7,6 });
    ListNode *ret = s.sortList(a);
    printList(ret);
    clear(ret);
}
