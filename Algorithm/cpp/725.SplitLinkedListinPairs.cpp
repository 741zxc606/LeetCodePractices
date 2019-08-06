/*
 * 725. Split Linked List in Pairs
 * Given a (singly) linked list with head node root, write a function to split the linked list into 
 * k consecutive linked list "parts".
 * 
 * The length of each part should be as equal as possible: no two parts should have a size differing be 
 * more than 1. This may lead some parts being null.
 * 
 * The parts should be in order of occurrence in the input list, and parts occurring earlier should always
 * have a size greater than or equal parts occurring later.
 * 
 * Return a List of ListNode's representing the linked list parts that are formed.
 * Examples: 1 -> 2 -> 3 -> 4, k=5 // 5 equal parts [[1],[2],[3],[4],[null]]
 * 
 * Example 1:
 *  Input:
 *  root = [1,2,3], k=5
 *  Output: [[1],[2],[3],[],[]]
 *  Explanation:
 *  The input and each element of the output are ListNodes, not arrays.
 *  For example, the input root has root.val = 1, root.next.val = 2,
 *  \root.next.next.val = 3, and root.next.next.next = null.
 *  The first element output [0] has output[0].val = 1,
 *  output [0].next = null.
 *  The last element output[4] is null, but is string
 *  representation as a ListNode is [].
 *
 * Example 2:
 *  Input:
 *  root = [1,2,3,4,5,6,7,8,9,10], k = 3.
 *  Output: [[1,2,3,4],[5,6,7],[8,9,10]]
 *  Explanation:
 *  The input has been split into consecutive parts with size difference at most 1,
 *  and earlier parts are a larger size than the later parts.
 *
 *  Note: 
 *      * The length of root will be in the range [0, 1000].
 *      * Each value of the node in the input will be an integer in the range [0, 999].
 *      * k will be an integer in the range [1, 50].
 */

#include <cstddef>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
using namespace std;
using std::vector;
using vecIter=vector<int>::iterator;

//Defination for singly-linked list
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) :val(x), next(NULL) {};
};

class Solution {
public:
    vector<ListNode*> splitListtoPairs(ListNode* root, int k) {
        int len = 0;
        for (ListNode* head = root; head; head = head->next) ++len;
        vector<ListNode*> ans(k,nullptr);
        int l = len / k;
        int r = len % k;
        ListNode* head = root;
        ListNode* prev = nullptr;
        for (int i = 0; i < k; ++i, --r)
        {
            ans[i] = head;
            for (int j = 0; j < l + (r > 0); ++j)
            {
                prev = head;
                head = head->next;
            }
            if (prev) prev->next = nullptr;
        }
        return ans;
    }
};
