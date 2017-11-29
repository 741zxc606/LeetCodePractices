/*
 * 114.Flatten Binary Tree to Linked List
 * Given a binary tree,flatten it to a linked list in-place.
 * For example,
 * Given
 *       1
        / \
       2   5
      / \   \
     3   4   6
 * The flattened tree should look like:
 *  1
     \
      2
       \
        3
         \
          4
           \
            5
             \
              6
 * Hints:
 * If you notice carefully in the flattened tree,each node's right child points to the next node of a pre-order traversal.
 */

#include <iostream>
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
    void flatten(TreeNode* root)
    {
        TreeNode* now = root;
        while (now)
        {
            if (now->left)
            {
                //find current node's prenode that links to xurrent node's right subtree
                TreeNode* pre = now->left;
                while (pre->right)
                {
                    pre = pre->right;
                }
                pre->right = now->right;
                //use current node's left subtree to replace its right subtree(original right)
                //subtree is already linked by current node's prenode
                now->right = now->left;
                now->left = NULL;
            }
            now = now->right;
        }
    }
};

int main()
{
    TreeNode root(1);
    TreeNode node1(2);
    TreeNode node2(3);
    TreeNode node3(4);
    TreeNode node4(5);
    TreeNode node5(6);

    root.left = &node1;
    root.right = &node4;
    node1.left = &node2;
    node1.right = &node3;
    node4.right = &node5;

    Solution s;
    s.flatten(&root);
    for (TreeNode *p = &root; p; p = p->right)
        std::cout << p->val << " ";
    std::cout << std::endl;
}
