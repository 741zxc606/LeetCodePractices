/*
 * 112.Path Sum
 * Given a binary tree and a sum,determine if the tree has a root-to-leaf path such that adding all the values along
 * the path equals the given sum.
 * For example:
 * Given the below binary tree and sum = 22,
 *            5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
 * return true,as there exist a root-to-leaft path 5->4->11->2 which sum is 22.
 */

#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :val(x), left(NULL), right(NULL) {};
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) 
    {
        if (!root) return false;
        if (!root->left && !root->right && sum - root->val == 0) return true;
        return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};

int main()
{
    TreeNode root(5);
    TreeNode node1(4);
    TreeNode node2(8);
    TreeNode node3(11);
    TreeNode node4(13);
    TreeNode node5(4);
    TreeNode node6(7);
    TreeNode node7(2);
    TreeNode node8(1);

    root.left = &node1;
    root.right = &node2;
    node1.left = &node3;
    node2.left = &node4;
    node2.right = &node5;
    node3.left = &node6;
    node3.right = &node7;
    node5.right = &node8;

    Solution s;
    std::cout << s.hasPathSum(&root, 3) << std::endl;
    std::cout << s.hasPathSum(&root, 22) << std::endl;
    std::cout << s.hasPathSum(&root, 42) << std::endl;
    return 0;
}
