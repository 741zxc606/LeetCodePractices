/*
 * 206. Reverse Linked List
 * Reverse a singly linked list.
 * Example: 
 *      Input: 1->2->3->4->5->NULL
 *      Output: 5->4->3->2->1->NULL
 * Follow up:
 * A linked list can be reversed either iteratively or recursively. Could you implement both?
 */

#include <cstddef>
#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) :val(x), next(NULL) {}
};

class Solution {
public:
    //iteratively
    ListNode* reverseList_1(ListNode* head)
    {
        ListNode *h = NULL, *p = NULL;
        while (head)
        {
            p = head->next;
            head->next=h;
            h = head;
            head = p;
        }
        return h;
    }

    //recursively
    ListNode* reverseList_2(ListNode* head)
    {
        if (head == NULL || head->next == NULL) return head;
        ListNode *h = reverseList_2(head->next);
        head->next->next = head;
        head->next = NULL;
        return h;
    }
};

ListNode *create_linkedlist(std::initializer_list<int> lst)
{
    auto iter = lst.begin();
    ListNode *head = lst.size() ? new ListNode(*iter++) : NULL;
    for (ListNode *cur = head; iter != lst.end(); cur->next)
        cur->next = new ListNode(*iter++);
    return head;
}


void printList(ListNode *head)
{
    for (ListNode *cur = head; cur; cur = cur->next)
        cout << cur->val << "->";
    cout << "\b\b " << endl;
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

int main()
{
    Solution s;
    ListNode *head = s.reverseList_1(create_linkedlist({ 1,2,3,4,5,NULL }));
    printList(head);

    clear(head);
}
