/*
 * 328. Odd Even Linked List
 * Given a singly linked list, group all odd nodes nodes together followed by the even nodes.
 * Please note here we are talking about the node number and not the value in the nodes.
 * 
 * You should try to do it in place. The program should run in O(1) space complexity and O(nodes)
 * time complexity.
 *
 * Example 1:
 *  Input: 1 -> 2 -> 3 -> 4 -> 5 ->NULL
 *  Output: 1 -> 3 -> 5 -> 2 -> 4 -> NULL
 * Example 2:
 *  Input: 2 -> 1 -> 3 -> 5 -> 6 -> 4 -> 7 -> NULL
 *  Output: 2 -> 3 -> 6 -> 7 -> 1 -> 5 -> 4 -> NULL
 * Note:
 *  * The relative order inside both the even and odd groups should
 *    remain as it was in the input.
 *  * The first node is considered even, the second node odd and so on...
 */

#include <cstddef>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return head;
        ListNode* pOdd = head;
        ListNode* p = head->next;
        ListNode* pNext = NULL;
        while (p && (pNext = p->next)) {
            p->next = pNext->next;
            pNext->next = pOdd->next;
            pOdd->next = pNext;

            p = p->next;
            pOdd = pOdd->next;
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
        std::cout << head -> val;
        if (head->next) std::cout << "->";
        ListNode* del = head;
        head = head->next;
        delete del;
    }
}

int main()
{
    vector<int> vec1{ 1,2,3,4,5,NULL };
    ListNode* head1 = createLinkedList(vec1.begin(),vec1.end());

    vector<int> vec2{2,1,3,5,6,4,7,NULL};
    ListNode* head2 = createLinkedList(vec2.begin(), vec2.end());

    Solution s;

    ListNode* res1 = s.oddEvenList(head1);
    ListNode* res2 = s.oddEvenList(head2);

    printAndClear(res1);
    std::cout << std::endl;
    printAndClear(res2);

    return 0;
}
