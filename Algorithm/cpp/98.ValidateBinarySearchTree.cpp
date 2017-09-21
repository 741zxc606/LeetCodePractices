/*
 * 98.Validate Binary Search Tree
 * Given a binary tree,determine if it is a valid binary search tree (BST).
 * Assume a BST is defined as follows:
 *    1.The left subtree of a node contains only nodes with ketys less than the node's key.
 *    2.The right subtree of a node contains only nodes with keys greater trhan the node's key.
 *    3.Both the left and right subtrees must also be binary search trees.
 * Example 1:
 *     2
 *    / \
 *   1   3
 * Binary tree [2,1,3],return true.
 * Example 2:
 * Binary tree [1,2,3],return false.
 */

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root)
    {
        //travel the tree by inner-order
        vector<TreeNode*> stack;
        TreeNode* node = root;
        vector<int> v;
        while (stack.size() > 0 || node != NULL)
        {
            if (node != NULL)
            {
                stack.push_back(node);
                node = node->left;
            }
            else
            {
                node = stack.back();
                stack.pop_back();
                v.push_back(node->val);
                node = node->right;
            }
        }

        //check the vector whether sorted or not
        for (int i = 0; v.size() > 0 && i < v.size() - 1; i++)
        {
            if (v[i] >= v[i + 1])
            {
                return false;
            }
        }
        return true;
    }
};

TreeNode* createTree(int a[], int n)
{
    if (n <= 0) return NULL;

    TreeNode **tree = new TreeNode*[n];

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            tree[i] = NULL;
            continue;
        }
        tree[i] = new TreeNode(a[i]);
    }
    int pos = 1;
    for (int i = 0; i < n&&pos < n; i++)
    {
        if (tree[i])
        {
            tree[i]->left = tree[pos++];
            if (pos < n)
            {
                tree[i]->right = tree[pos++];
            }
        }
    }
    return tree[0];
}

int main()
{
    Solution s;

    std::cout << std::boolalpha << s.isValidBST(NULL) << std::endl;

    int a[] = { 2,1,3 };
    std::cout << std::boolalpha << s.isValidBST(createTree(a, sizeof(a) / sizeof(int))) << std::endl;

    int b[] = { 1,2,3 };
    std::cout << std::boolalpha << s.isValidBST(createTree(b, sizeof(b) / sizeof(int))) << std::endl;
}
