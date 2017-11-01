/*
 * 107.Binary Tree Level Order Traversal II
 * Given a binary tree,return the bottom-up level order traversal of its nodes' values.(ie,from left to right,level by level from leaf to root).
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *   3
 *  / \
 *  9  20
 *     / \
 *   15   7
 * return its bottom-up level order traversal as:
 * [
 *  [15,7],
 *  [9,20],
 *  [3]
 * ]
 */

#include <iostream>
#include <vector>
#include <queue>
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

    vector<vector<int>> res;

    void DFS(TreeNode *root, int level)
    {
        if (root == NULL) return;
        if (level == res.size())//The level does not exist in output
        {
            res.push_back(vector<int>());//Create a new level
        }

        res[level].push_back(root->val);//Add the current value to its level
        DFS(root->left, level + 1);//Got to the next level
        DFS(root->right, level + 1);
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        DFS(root, 0);
        return vector<vector<int>>(res.rbegin(), res.rend());
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

    /* Create a tree like this:
    *   3
    *  / \
    *  9  20
    *     / \
    *   15   7
    */

    Solution s;

    for (auto vec : s.levelOrderBottom(&root))
    {
        for (auto i : vec)
            std::cout << i << " ";
        std::cout << std::endl;
    }

    return 0;
}
