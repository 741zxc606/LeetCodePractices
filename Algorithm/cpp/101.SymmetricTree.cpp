/*
* 101.Symmetric Tree
* Given a binary tree,check whether it is a mirror of itself(ie,ie,symmetric around its center).
* For example,this binary tree [1,2,2,3,4,4,3] is symmetrix:
*          1
*         / \
*        2   2
*       / \ / \
*      3  4 4  3
*
* But the following [1,2,2,null,3,null,3] is not:
*          1
*         / \
*        2   2
*         \   \
*          3   3
*
* Note:
* Bonus points if you could solve it both recursively and iteratively.
*/

#include <cstddef>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
using vecIter = std::vector<int>::iterator;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode *root)
    {
        TreeNode *left, *right;
        if (!root)
            return true;

        queue<TreeNode*> q1, q2;
        q1.push(root->left);
        q2.push(root->right);
        while (!q1.empty() && !q2.empty())
        {
            left = q1.front();
            q1.pop();
            right = q2.front();
            q2.pop();
            if (NULL == left && NULL == right)
                continue;
            if (NULL == left || NULL == right)
                return false;
            if (left->val != right->val)
                return false;
            q1.push(left->left);
            q1.push(left->right);
            q2.push(right->right);
            q2.push(right->left);
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
    int a[] = { 1,2,2,3,4,4,3 };
    int b[] = { 1,2,2,NULL,3,NULL,3 };

    Solution s;
    std::cout << std::boolalpha << s.isSymmetric(createTree(a, sizeof(a) / sizeof(int))) << std::endl;
    std::cout << std::boolalpha << s.isSymmetric(createTree(b, sizeof(b) / sizeof(int))) << std::endl;
    return 0;
}
