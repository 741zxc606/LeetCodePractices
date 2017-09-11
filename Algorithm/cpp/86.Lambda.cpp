/*
* 86.Partition List
* Given a linked list and a value X,partition it such that all nodes less than x come before nodes greater than or equal to x.
* You should preserve the original relative order of the nodes in each of the two partitions.
*
* For example,
* Given 1->4->3->2->5->2 and x=3,
* return 1->2->2->4->3->5.
*/

#include <algorithm>
#include <iostream>
#include <cstddef>
#include <initializer_list>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) :val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x)
    {
        ListNode *prev = NULL, *back = NULL, **pp = &prev, **pb = &back;
        for (; head; [&head](ListNode ***p)
        {
            **p = head; *p = &head->next; head = **p;
        }(head->val < x ? &pp : &pb));
        *pp = back; *pb = NULL;
        return prev;
    }
};

ListNode *createLinkedList(std::initializer_list<int>lst)
{
    auto iter = lst.begin();
    ListNode *head = lst.size() ? new ListNode(*iter++) : NULL;
    for (ListNode *cur = head; iter != lst.end(); cur = cur->next)
        cur->next = new ListNode(*iter++);
    return head;
}

void printList(ListNode *head)
{
    for (ListNode *cur = head; cur; cur = cur->next)
        std::cout << cur->val << "->";
    std::cout << "\b\b " << std::endl;
    //std::cout << std::endl;
}

void clearList(ListNode *head)
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
    ListNode *ret = s.partition(createLinkedList({ 1,4,3,2,5,2 }), 3);

    printList(ret);
    clearList(ret);
}
