/*
 * 92.Reverse Linked List II
 * Reverse a linked list from position m to n,Do it in-place and in one-pass.
 * For example:
 * Given 1->2->3->4->5->NULL,m=2 and n=4,
 * return 1->4->3->2->5->NULL.
 * NOTE:
 * Given m,n satisfy the following condition:
 * 1 <= m< = n <= length of list.
 */

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
    ListNode* reverseBetween(ListNode* head, int m, int n)
    {
        if (m == n) return head;
        n -= m;
        ListNode prehead(0);
        prehead.next = head;
        ListNode* pre = &prehead;
        while (--m) pre = pre->next;
        ListNode* pstart = pre->next;
        while (n--)
        {
            ListNode *p = pstart->next;
            pstart->next = p->next;
            p->next = pre->next;
            pre->next = p;
        }
        return prehead.next;
    }
};

ListNode *create_linkerlist(std::initializer_list<int> lst)
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
    ListNode *head = s.reverseBetween(create_linkerlist({ 1,2,3,4,5 }), 2, 4);
    for (ListNode *cur = head; cur; cur = cur->next)
        std::cout << cur->val << "->";
    std::cout << "\b\b " << std::endl;    
}
