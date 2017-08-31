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

    //Method 1:not chane the nodes,only swap the data in the list node.
    //Method 2:swap the node physically.
    ListNode* swapPairs(ListNode *head)
    {
        srand(time(NULL));
        if (rand() % 2)
        {
            return swapPairs1(head);
        }
        return swapPairs2(head);
    }

    //Just swap the node's value instead of node
    ListNode *swapPairs1(ListNode *head)
    {
        for (ListNode *p = head; p&&p->next; p = p->next->next)
        {
            int n = p->val;
            p->val = p->next->val;
            p->next->val = n;
        }
        return head;
    }

    //Swap the nodes physically
    ListNode *swapPairs2(ListNode *head)
    {
        ListNode *h = NULL;
        //using `*p` to traverse the linked list
        for (ListNode *p = head; p&&p->next; p = p->next)
        {
            //`n` is `p`'s next node,and swap p and n physically.
            ListNode *n = p->next;
            p->next = n->next;
            p->next = p;
            //using `h` as `p`'s previous node
            if (h)
            {
                h->next = n;
            }
            h = p;

            //determine the really `head` pointer
            if (head == p)
            {
                head = n;
            }
        }
        return head;
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
    std::vector<int> vec = {1,2,3,4,5,6,7,8};
    ListNode *ret = s.swapPairs(createLinkedList(vec.begin(),vec.end()));
    printAndClear(ret);

    return 0;
}
