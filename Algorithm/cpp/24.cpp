/*
* 24. Swap Nodes in Pairs
* Given a linked list,swap every teo adjacent nodes and return its head.
* For example:
* Given 1->2->3->4,you should return the list as 2->1->4->3.
* Your algorithm should use only constant space.Youmay not modify the values in the lists,
* only nodes itself can be changed.
*/

#include <vector>
#include <time.h>
#include <algorithm>
#include <iostream>
using namespace std;
using vecIter = std::vector<int>::iterator;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) :val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode* swapPairs(ListNode* head)
    {
        if (head == NULL || head->next == NULL) return head;
        {
            ListNode *helper = new ListNode(0);
            ListNode *ret = head;
            ListNode *cur = helper;
            while (ret&&ret->next)
            {
                ListNode *next = ret->next->next;
                cur->next = ret->next;
                cur = cur->next;
                cur->next = ret;
                cur = cur->next;
                cur->next == NULL;
                ret = next;
            }
            if (ret) cur->next = ret;
            return helper->next;
        }
    }
};

ListNode *createLinkedList(vecIter begin, vecIter end)
{
    ListNode *head = begin == end ? NULL : new ListNode(*begin++);
    for (ListNode *cur = head; begin != end; cur = cur->next)
        cur->next = new ListNode(*begin++);
    return head;
}
void printAndClear(ListNode *head)
{
    while (head)
    {
        std::cout << head->val;
        if (head->next) std::cout << "->";
        ListNode *del = head;
        head = head->next;
        delete del;
    }
    std::cout << std::endl;
}

int main()
{
    Solution s;
    std::vector<int> vec = { 1,2,3,4,5,6,7,8 };
    ListNode *ret = s.swapPairs(createLinkedList(vec.begin(), vec.end()));
    printAndClear(ret);

    return 0;
}
