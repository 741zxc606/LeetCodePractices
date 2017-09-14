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
        if (!head) return head;

        int len = 1;//number of nodes
        ListNode *newH, *tail;
        newH = tail = head;

        while (tail->next)//get the number of nodes int the list
        {
            tail = tail->next;
            len++;
        }
        tail->next = head;//circle the list

        if (k%len)
        {
            for (auto i = 0; i < len - k; i++)
                tail = tail->next;//the tail node is the (len-k)-th node (1st node is head)
        }
        newH = tail->next;
        tail->next = NULL;
        return newH;
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
