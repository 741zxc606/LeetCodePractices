/*
 * 147.Insertion Sort List
 * Sort a linked list using insertion sort.
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
    ListNode* insertionSotList(ListNode* head)
    {
        ListNode pre_head(0);
        pre_head.next = head;
        for(ListNode *p=head;p;)
            if (p->next&&p->val > p->next->val)
            {
                ListNode *i = &pre_head;
                while (!(i->next->val > p->next->val))
                    i = i->next;
                ListNode *pNode = p->next;
                p->next = pNode->next;
                pNode->next = i->next;
                i->next = pNode;
            }
            else
            {
                p = p->next;
            }
        return pre_head.next;
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

int main()
{
    Solution s;
    ListNode *head = s.insertionSotList(create_linkedlist({ 3,9,1,2,4,7,6 }));
    for (ListNode *cur = head; cur; cur = cur->next)
        std::cout << cur->val << "->";
    std::cout << "\b\b " << std::endl;

    return 0;
}
