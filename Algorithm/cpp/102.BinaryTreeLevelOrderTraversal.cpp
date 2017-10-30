/*
 * 102.Binary Tree Level Order Traversal
 * Given a binary tree,return the level order traversal of its traversal of its nodes' values.(ie,from left to right,level by level).
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 *
 * return its level order traversal as:
 * [
 *  [3],
 *  [9,20],
 *  [15,7]
 * ]
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*Define a binary tree node.*/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    vector<vector<int>> ret;

    vector<vector<int>> levelOrder(TreeNode* root)
    {
        buildTree(root, 0);
        return ret;
    }

    void buildTree(TreeNode *root, int depth)
    {
        if (root == NULL) return;
        if (ret.size() == depth)
            ret.push_back(vector<int>());

        ret[depth].push_back(root->val);
        buildTree(root->left, depth + 1);
        buildTree(root->right, depth + 1);
    }
};

int main()
{
    TreeNode root(3);
    TreeNode node1(9);
    TreeNode node2(20);
    TreeNode node3(15);
    TreeNode node4(7);
    root.left = &node1;
    root.right = &node2;
    node2.left = &node3;
    node2.right = &node4;

    Solution s;
    for (const auto&v : s.levelOrder(&root))
    {
        for (auto i : v)
            std::cout << i << " ";
        std::cout << std::endl;
    }

    return 0;
}
