/*
 * 237. Delete Node in a Linked List
 * Write a function to delete a node (expect the tail) in a single linked list,
 * given only access to that node. 
 *
 * Given linked list -- head = [4,5,1,9], which looks like following:
 *      4 -> 5 -> 1 -> 9
 * Example 1:
 *  Input: head = [4,5,1,9], node = 5
 *  Output: [4,1,9]
 *  Explanation: You're given the second node with value 5, the linked list
 *  should become 4 -> 1 -> 9 after calling your function.
 *
 * Example 2:
 *  Input: head = [4,5,1,9], node = 1
 *  Output: [4,5,9]
 *  Explanation: You're given the third node with value 1, the linked list
 *  should become 4 -> 5 -> 9 after calling your function.
 */

#include <cstddef>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;
using std::vector;
using vecIter=vector<int>::iterator;

//define struct for single linked list
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) :val(x), next(NULL) {};
};

class Solution {
public:
    void deleteNode(ListNode* node){
        node->val = node->next->val;
        node->next = node->next->next;
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
    vector<int> vec1{ 4,5,1,9 };
    ListNode* head1 = createLinkedList(vec1.begin(),vec1.end());

    Solution s;

    //to do...
}
