/*
 * 445. Add Two Numbers II
 * You are given two non-empty linked list representing two non-negative integers.
 * The most significant digit comes first and each of their nodes contains a single digit.
 * Add the two numbers and return it as a linked list.
 *
 * You may assume the two numbers do not contain any leading zero, expect the number 0 itself.
 *
 * Follow up:
 * What if you cannot confirm the input lists? In other words, reversing the lists is not allowed.
 *
 * Example:
 * Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 8 -> 0 -> 7
 */

#include <cstddef>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
using std::vector;
using vecIter=vector<int>::iterator;

//Defitination for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) :val(x), next(NULL) {};
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;
        while (l1) 
        {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }
        ListNode* head = nullptr;
        int sum = 0;
        while (!s1.empty() || !s2.empty() || sum)
        {
            sum += s1.empty() ? 0 : s1.top();
            sum += s2.empty() ? 0 : s2.top();
            if (!s1.empty()) s1.pop();
            if (!s2.empty()) s2.pop();
            ListNode* n = new ListNode(sum % 10);
            sum /= 10;
            n->next = head;
            head = n;
        }
        return head;
    }
};

ListNode* createLinkedList(vecIter begin, vecIter end)
{
    ListNode* head = begin == end ? NULL : new ListNode(*begin++);
    for (ListNode* cur = head; begin != end; cur = cur->next)
        cur->next = new ListNode(*begin++);
    return head;
}

void printAndClear(ListNode* head)
{
    while (head)
    {
        std::cout << head->val;
        if (head->next) std::cout << "->";
        ListNode* del = head;
        head = head->next;
        delete del;
    }
}

int main()
{
    vector<int> vec1{ 7,2,4,3 };
    ListNode* l1 = createLinkedList(vec1.begin(), vec1.end());

    vector<int> vec2{ 5,6,4 };
    ListNode* l2 = createLinkedList(vec2.begin(), vec2.end());

    Solution s;
    ListNode* res = s.addTwoNumbers(l1, l2);

    printAndClear(res);
    
    return 0;
}
