/*
 * 203. Remove Linked List Elements
 * Remove all the elements form a linked list of integers that have value val.
 * Example:
 *	Input:	1->2->6->3->4->5->6, val=6
 *	Output:	1->2->3->4->5
 */

#include <cstddef>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;
using std::vector;
using vecIter = vector<int>::iterator;

//Define struct for single-linked list 
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {};
};

class Solution
{
public:
    ListNode* removeElement(ListNode *head, int val) {
        static ListNode dummy(-1);
        dummy.next = head;
        ListNode* p = &dummy;

        while (p->next)
        {
            if (p->next->val == val)
            {
                p->next = p->next->next;
            }
            else
            {
                p = p->next;
            }
        }
        return dummy.next;
    }
};

ListNode* createLinkedList(vecIter begin, vecIter end)
{
    ListNode *head = begin == end ? NULL : new ListNode(*begin++);
    for (ListNode* cur = head; begin != end; cur = cur->next)
        cur->next = new ListNode(*begin++);
    return head;
}

void printAndClear(ListNode *head)
{
    while (head)
    {
        std::cout << head->val;
        if (head->next) std::cout << "->";
        ListNode* del = head;
        head = head->next;
        delete del;
    }
    std::cout << std::endl;
}

int main()
{
    vector<int> vec1{ 1,2,6,3,4,5,6 };
    ListNode* head1 = createLinkedList(vec1.begin(), vec1.end());
    int val = 6;

    Solution s;
    ListNode* res1 = s.removeElement(head1, val);

    printAndClear(res1);

    return 0;
}
