/*
 * 124.Binary Tree Maximum Path Sum
 * Given a binary tree,find the maximum path sum.
 * For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along
 * the parent-child connections.The path must contain at least one node and does not need to go through the root.
 * For example:
 * Given the below binary tree,
 *        1
 *       / \
 *      2   3
 * Return 6.
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
    int maxPathSum(TreeNode *root, int &maxSum)
    {
        if (!root) return 0;
        int leftMax = std::max(0, maxPathSum(root->left, maxSum));
        int rightMax = std::max(0, maxPathSum(root->right, maxSum));
        maxSum = std::max(maxSum, leftMax + rightMax + root->val);
        return root->val + std::max(leftMax, rightMax);
    }
public:
    int maxPathSum(TreeNode* root)
    {
        int maxSum = INT_MIN;
        maxPathSum(root, maxSum);
        return maxSum;
    }
};

int main()
{
    Solution s;

    TreeNode root(1);
    TreeNode node1(2);
    TreeNode node2(3);
    TreeNode node3(4);
    TreeNode node4(5);
    TreeNode node5(6);

    root.left = &node1;
    root.right = &node2;
    node1.left = &node3;
    node1.right = &node4;
    node2.right = &node5;

    /*
                1
               / \
              2   3
             / \   \
            4   5   6
     */

    std::cout << s.maxPathSum(&root) << std::endl;
    return 0;
}
