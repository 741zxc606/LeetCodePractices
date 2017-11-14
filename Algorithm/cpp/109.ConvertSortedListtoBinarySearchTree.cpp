/*
 * 109.Convert Sorted List to Binary Search Tree
 * Given a singly linked list where elements are sorted in ascending order,convert it to a height balanced BST.
 */

#include <iostream>
#include <cstddef>
#include <initializer_list>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) :val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head)
    {
        auto n = [](ListNode *p)
        {
            int count{ 0 };
            for (; p; p = p->next, ++count);
            return count;
        }(head);
        return sortedListToBST(&head, n);
    }

    TreeNode *sortedListToBST(ListNode **head_ref, int n)
    {
        if (n < 1) return NULL;
        TreeNode *left = sortedListToBST(head_ref, n / 2);
        TreeNode *root = new TreeNode((*head_ref)->val);
        root->left = left;
        *head_ref = (*head_ref)->next;
        root->right = sortedListToBST(head_ref, n - n / 2 - 1);
        return root;
    }
};

void print_bfs(TreeNode* p)
{
    if (!p) return;
    std::vector<std::string>v;
    std::queue<TreeNode *>q;
    q.push(p);
    do {
        TreeNode *node = q.front(); q.pop();
        if (node)
            v.push_back(std::to_string(node->val));
        else {
            v.push_back("#");
            continue;
        }
        q.push(node->left);
        q.push(node->right);
    } while (!q.empty());

    auto found = std::find_if(v.rbegin(), v.rend(), [](const std::string &s) {return s != "#"; });
    v.erase(found.base(), v.end());
    for (const auto &s : v)
        std::cout << s << ",";
    std::cout << "\b" << std::endl;
}

ListNode *create_linkedlist(std::initializer_list<int>lst)
{
    auto iter = lst.begin();
    ListNode *head = lst.size() ? new ListNode(*iter++) : NULL;
    for (ListNode *cur = head; iter != lst.end(); cur = cur->next)
        cur->next = new ListNode(*iter++);
    return head;
}

int main()
{
    Solution s;
    TreeNode *ret = s.sortedListToBST(create_linkedlist({ 1,2,3,4,5,6,7,8,9 }));
    print_bfs(ret);
}
