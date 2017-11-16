/*
 * 110.Balanced Binary Tree
 * Given a binary tree,determine if it is height-balanced.
 * For this problem,a height-balanced binary tree is defined as a binary tree in which the depth of the two subtres of every node never
 * differ by more than 1.
 */

#include <iostream>
#include <complex>
#include <vector>
#include <algorithm>
using namespace std;
using std::vector; using std::cout; using std::endl;
using vecIter = vector<int>::iterator;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isBalanced(TreeNode *root)
    {
        height(root);
        return bBalanced;
    }
private:
    int height(TreeNode *node)
    {
        if (node == NULL || !bBalanced) return 0;
        else
        {
            int leftHeight = height(node->left);
            int rightHeight = height(node->right);
            if (std::abs(leftHeight - rightHeight) > 1) 
                bBalanced = false;
            return std::max(leftHeight, rightHeight) + 1;
        }
    }
    bool bBalanced = true;
};

TreeNode *createBinaryTree(vecIter beg, vecIter end)
{
    std::vector<TreeNode *>vec;
    for (vecIter it = beg; it != end; ++it)
        vec.push_back(new TreeNode(*it));

    for (decltype(vec.size())i = 0, pos = 0; pos != vec.size() - 1; ++i)
    {
        vec[i]->left = vec[++pos];
        vec[i]->right = vec[++pos];
    }
    return *vec.begin();
}

int main()
{
    std::vector<int> vec = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
    TreeNode *root = createBinaryTree(vec.begin(), vec.end());

    Solution s;
    cout << (s.isBalanced(root) ? "true" : "false") << endl;

    return 0;
}
