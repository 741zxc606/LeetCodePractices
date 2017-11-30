/*
 * 116.Populating Next Right Pointers in Each Node
 * Given a binary tree
 *      struct TreeLinkNode{
 *        TreeLinkNode *left;
 *        TreeLinkNode *right;
 *        TreeLinkNode *next;
 *      }
 * Populate each next pointer to point to its next right node.If there is no next right node,the next pointer should be set to NULL.
 * Initially,all next pointers are set to NULL.
 * Node:
 *     You may only use constant extra space.
 *     You may assume that it is a perfect binary tree(ie.all leaves are at the same level,and every parent has two children).
 * For example,
 * Given the following perfect binary tree,
 *       1
       /  \
      2    3
     / \  / \
    4  5  6  7
 *
 * After calling your function,the tree should look like:
 *       1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
 */

#include <stack>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
using vecIter = std::vector<int>::iterator;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root)
    {
        if (root == NULL) return;
        while (root->left)
        {
            root->left->next = root->right;
            for (TreeLinkNode *cur = root; cur->next; cur = cur->next)
            {
                cur->right->next = cur->next->left;
                cur->next->left->next = cur->next->right;
            }
            root = root->left;
        }
    }

    /*void connect(TreeLinkNode *root) 
    {
        if (root == NULL) return;
        TreeLinkNode *pre = root;
        TreeLinkNode *cur = NULL;
        while (pre->left)
        {
            cur = pre;
            while (cur)
            {
                cur->left->next = cur->right;
                if (cur->next) cur->right->next = cur->next->left;
                cur = cur->left;
            }
            pre = pre->left;
        }
    }*/
};

TreeLinkNode *createBinaryTree(vecIter beg, vecIter end)
{
    std::vector<TreeLinkNode *> vec;
    for (vecIter it = beg; it != end; ++it)
        vec.push_back(new TreeLinkNode(*it));

    for (int i = 0, pos = 0; pos != vec.size() - 1; ++i)
    {
        vec[i]->left = vec[++pos];
        vec[i]->right = vec[++pos];
    }
    return *vec.begin();
}

void print(TreeLinkNode *root)
{
    while (root)
    {
        std::cout << root->val;
        TreeLinkNode *cur = root->next;
        while (cur)
        {
            std::cout << "->" << cur->val;
            cur = cur->next;
        }
        std::cout << std::endl;
        root = root->left;
    }
}

int main()
{
    std::vector<int> vec = {1,2,3,4,5,6,7};
    TreeLinkNode *root = createBinaryTree(vec.begin(), vec.end());
    
    Solution s;
    s.connect(root);
    print(root);

    return 0;
}
