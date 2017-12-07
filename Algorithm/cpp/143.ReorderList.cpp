/*
 * 143.Reorder List
 * Given a singly linked list L:L0->L1->...Ln-1->Ln,
 * reorder it to:Lo->Ln->L1->Ln-1->L2->Ln-2->...
 * You must do this in-place without altering the node's values.
 * For example,
 * Given {1,2,3,4},reorder it to {1,4,2,3}.
 */

#include <iostream>
#include <algorithm>
#include <initializer_list>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) :val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode* head)
    {
        if (!head || !head->next) return;

        //find the middle node:O(n)
        ListNode *p1 = head, *p2 = head->next;
        while (p2&&p2->next)
        {
            p1 = p1->next;
            p2 = p2->next->next;
        }

        //cut from the middle and reverse the second half:O(n)
        ListNode *head2 = p1->next;
        p1->next = NULL;

        p2 = head2->next;
        head2->next = NULL;
        while (p2)
        {
            p1 = p2->next;
            p2->next = head2;
            head2 = p2;
            p2 = p1;
        }

        //merge two lists:O(n)
        for (p1 = head, p2 = head2; p1;)
        {
            auto t = p1->next;
            p1 = p1->next = p2;
            p2 = t;
        }
    }
};

ListNode *creat_linkedlist(std::initializer_list<int> lst)
{
    auto iter = lst.begin();
    ListNode *head = lst.size() ? new ListNode(*iter++) : nullptr;
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
        cout << cur -> val << "->";
    cout << "\b\b " << endl;
}

int main()
{
    Solution s;
    ListNode *a = creat_linkedlist({1,2,3,4,5,6,7,8,9});
    s.reorderList(a);
    printList(a);
    clear(a);
}
