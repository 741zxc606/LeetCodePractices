/*
 * 100.Same Tree
 * Given two binary trees,write a function to check if they are equal or not.
 * Two binary trees are considered equal if they are structuarally identical and the nodes have the same value.
 */

#include <vector>
#include <string>
#include <queue>
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
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if (p&&q)
            return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        else if (!p && !q) return true;
        else return false;
    }
};

int main()
{
    TreeNode root1(1);
    TreeNode root2(1);
    TreeNode t2(2);
    TreeNode t3(3);
    TreeNode t4(4);
    TreeNode t5(5);
    TreeNode t6(6);
    TreeNode t7(7);
    TreeNode t8(8);
    TreeNode t9(9);

    root1.left = &t2;
    root1.right = &t3;
    root2.left = &t2;
    root2.right = &t3;
    t2.left = &t4;
    t2.right = &t5;
    t3.right = &t6;
    t4.left = &t7;
    t4.right = &t8;
    t8.left = &t9;

    Solution s;

    std::cout << std::boolalpha << s.isSameTree(&root1, &root2) << std::endl;

    return 0;
}
