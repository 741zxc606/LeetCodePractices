/*
 * 99.Recover Binary Search Tree
 * Two elements of a binary search tree (BST) are swapped by mistake.
 * Recover the tree without changing its structure.
 * Note:
 * A solution using O(n) space is pretty straight forward.Could you devise a constant space solution?
 */

#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void recoverTreeHelper(TreeNode *root)
    {
        if (root == NULL) return;

        recoverTreeHelper(root->left);
        if (prev)
        {
            if (prev->val > root->val)
            {
                if (n1 == NULL)
                {
                    n1 = prev;
                }
                n2 = root;
            }
        }
        prev = root;
        recoverTreeHelper(root->right);
    }

    void recoverTree(TreeNode *root)
    {
        n1 = n2 = prev = NULL;
        recoverTreeHelper(root);
        if (n1&&n2)
        {
            swap(n1->val, n2->val);
        }
    }
private:
    TreeNode *n1, *n2, *prev;
};

void print_bst(TreeNode* p)
{
    if (!p) return;
    std::vector<std::string> retv;
    std::queue<TreeNode *> q;
    q.push(p);
    do
    {
        TreeNode *node = q.front(); q.pop();
        if (node)
            retv.push_back(std::to_string(node->val));
        else
        {
            retv.push_back("#");
            continue;
        }
        q.push(node->left);
        q.push(node->right);
    } while (!q.empty());

    auto found = std::find_if(retv.rbegin(), retv.rend(), [](const std::string &s) {return s != "#"; });
    retv.erase(found.base(), retv.end());
    for (const auto &s : retv)
        std::cout << s << ",";
    std::cout << "\b" << std::endl;
}

int main()
{
    Solution s;

    TreeNode node0(0);
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node5(5);
    TreeNode node6(6);    

    node3.left = &node1;
    node3.right = &node5;
    node1.left = &node0;
    node1.right = &node6;
    node5.left = &node4;
    node5.right = &node2;

    s.recoverTree(&node3);

    print_bst(&node3);
}
