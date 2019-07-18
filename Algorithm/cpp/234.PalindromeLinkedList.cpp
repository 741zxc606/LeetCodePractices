/*
 * 234. Palindrome Linked List
 * Given a singly linked list, determine if it is palindrome.
 * Example 1:
 *
 * Input: 1->2
 * Output: false
 * Example 2:
 *
 * Input: 1->2->2->1
 * Output: true
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
 *
 */

#include <cstddef>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;
using std::vector;
using vecIter=vector<int>::iterator;

//Define struct for single Linked List
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) :val(x), next(NULL) {};
};

class Solution {
public:
    ListNode* findMiddle(ListNode* head) {
        ListNode* p1 = head, * p2 = head;
        while (p2 && p2->next)
        {
            p1 = p1->next;
            p2 = p2->next->next;
        }
        return p1;
    }

    ListNode* reverseLink(ListNode* head) {
        ListNode* p = NULL;

        while (head)
        {
            ListNode* q = head->next;
            head->next = p;
            p = head;
            head = q;
        }
        return p;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* pMid = findMiddle(head);
        ListNode* pRev = reverseLink(pMid);
        for (; head != pMid; head = head->next, pRev = pRev->next)
        {
            if (head->val != pRev->val)
            {
                return false;
            }
        }
        return true;
    }
};

ListNode* createLinkedList(vecIter begin, vecIter end)
{
    ListNode* head = begin == end ? NULL : new ListNode(*begin++);
    for (ListNode* cur = head; begin != end; cur = cur->next)
        cur->next = new ListNode(*begin++);
    return head;
}

int main()
{
    vector<int> vec1{ 1,2 };
    vector<int> vec2{ 1,2,2,1 };

    ListNode* head1 = createLinkedList(vec1.begin(), vec1.end());
    ListNode* head2 = createLinkedList(vec2.begin(), vec2.end());

    Solution s;
    
    std::cout << s.isPalindrome(head1) << std::endl;
    std::cout << s.isPalindrome(head2) << std::endl;

    return 0;
}
