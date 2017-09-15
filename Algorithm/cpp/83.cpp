/*
* 83.Remove Duplicates from the Sorted List
* Given a sorted linked list,delete all duplicates such that each element appear only once.
* For example,
* Given 1->1->2,return 1->2.
* Given 1->1->2->3->3,return 1->2->3.
*/

#include <vector>
#include <algorithm>
#include <cstddef>
#include <iostream>
using namespace std;
using std::vector;
using vecIter = vector<int>::iterator;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) :val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        for (ListNode *cur = head; cur&&cur->next;)
        {
            if (cur->val == cur->next->val)
            {
                ListNode *del = cur->next;
                cur->next = del->next;
                delete del;
            }
            else cur = cur->next;
        }
        return head;
    }
};

ListNode *createLinkedList(vecIter beg, vecIter end)
{
    ListNode *head = beg == end ? NULL : new ListNode(*beg++);
    for (ListNode *cur = head; beg != end; cur = cur->next)
        cur->next = new ListNode(*beg++);
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
    vector<int> vec1 = { 1,1,2 };
    vector<int> vec2 = { 1,1,2,3,3 };

    ListNode *head1 = createLinkedList(vec1.begin(), vec1.end());
    ListNode *head2 = createLinkedList(vec2.begin(), vec2.end());

    Solution s;
    ListNode *res1 = s.deleteDuplicates(head1);
    ListNode *res2 = s.deleteDuplicates(head2);

    printAndClear(res1);
    printAndClear(res2);

    return 0;
}
