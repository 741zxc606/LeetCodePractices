/*
 * 143.Binary Tree Preorder Traversal
 * Given a binary tree,return the preorder traversal of its nodes' values.
 * For example:
 * Given binary tree [1,null,2,3],
 *    1
 *     \
 *      2
 *     /
 *    3
 *
 * return [1,2,3]
 * Note:Recursive solution is trivial,could you do it iteratively?
 */

#include <iostream>
#include <stack>
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
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> ret;
        for(stack<TreeNode *>s;root||!s.empty();)
            if (root)
            {
                s.push(root->right);
                ret.push_back(root->val);
                root = root->left;
            }
            else
            {
                root = s.top(); s.pop();
            }
        return ret;
    }
};

int main()
{
    TreeNode root(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node5(5);

    root.left = &node2;
    root.right = &node3;
    node3.left = &node4;
    node4.right = &node5;

    Solution s;
    for (auto i : s.preorderTraversal(&root))
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
