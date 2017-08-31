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
        ListNode dummy{ 0 };
        dummy.next = head;
        auto curr = &dummy;

        while (curr->next && curr->next->next) 
        {
            auto next_one = curr->next;
            auto next_two = next_one->next;
            auto next_three = next_two->next;
            curr->next = next_two;
            next_two->next = next_one;
            next_one->next = next_three;
            curr = next_one;
        }
        return dummy.next;
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
