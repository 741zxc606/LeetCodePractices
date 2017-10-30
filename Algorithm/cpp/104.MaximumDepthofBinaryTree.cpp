/*
 * 104.Maximum Depth of Binary Tree
 * Given a binary tree,find its maximum depth.
 * The maximum depth is the number if nodes along the longest path from root node down th the farthest leaf node.
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

    /* Depth-first-search */
    int maxDepth(TreeNode* root)
    {
        return root == NULL ? 0 : max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }

    /* Breadth-first-search */
    int BFSmaxDepth(TreeNode* root)
    {
        if (root == NULL)
            return 0;

        int res = 0;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            ++res;
            for (int i = 0, n = q.size(); i < n; ++i)
            {
                TreeNode *p = q.front();
                q.pop();

                if (p->left != NULL)
                    q.push(p->left);
                if (p->right != NULL)
                    q.push(p->right);
            }
        }
        return res;
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

    cout << s.maxDepth(&root) << endl;
    cout << s.BFSmaxDepth(&root) << endl;
    
    return 0;
}
