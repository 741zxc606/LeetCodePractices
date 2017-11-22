/*
 * 111.Minimum Depth of Binary Tree
 * Given a binary tree,find its minimum depth.
 * The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int minDepth(TreeNode* root)
    {
        if (root == NULL)
        {
            return 0;
        }
        if (root->left == NULL&&root->right == NULL)
        {
            return 1;
        }
        int left = INT_MAX;
        if (root->left)
        {
            left = minDepth(root->left) + 1;
        }
        int right = INT_MAX;
        if (root->right)
        {
            right = minDepth(root->right) + 1;
        }
        return left < right ? left : right;
    }
};

int main()
{
    TreeNode root(1);
    TreeNode t2(2);
    TreeNode t3(3);
    TreeNode t4(4);
    TreeNode t5(5);
    TreeNode t6(6);
    TreeNode t7(7);
    TreeNode t8(8);
    TreeNode t9(9);

    root.left = &t2;
    root.right = &t3;
    t2.left = &t4;
    t2.right = &t5;
    t3.right = &t6;
    t4.left = &t7;
    t4.right = &t8;
    t8.left = &t9;

    Solution s;
    std::cout << s.minDepth(&root) << std::endl;
    return 0;


}
