/*
 * 145.Binary Tree Postorder Traversal
 * Given a binary tree,return the postorder traversal of its nodes' valuses.
 * For example:
 * Given binary tree {1,#,2,3},
 *    1
 *     \
 *      2
 *     /
 *    3
 * 
 * return [3,2,1].
 * Note:Recursive solution is trivial,could you do it iteratively?
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstddef>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> nodes;
        stack<TreeNode*> toVisit;
        TreeNode* curNode = root;
        TreeNode* lastNode = NULL;
        while (curNode || !toVisit.empty())
        {
            if (curNode)
            {
                toVisit.push(curNode);
                curNode = curNode->left;
            }
            else
            {
                TreeNode* topNode = toVisit.top();
                if (topNode->right&&lastNode != topNode->right)
                    curNode = topNode->right;
                else
                {
                    nodes.push_back(topNode->val);
                    lastNode = topNode;
                    toVisit.pop();
                }
            }
        }
        return nodes;
    }
};

int main()
{
    TreeNode root(1);
    TreeNode node2(2);
    TreeNode node3(3);    

    root.right = &node2;
    node2.left = &node3;

    Solution s;
    for (auto i : s.postorderTraversal(&root))
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
