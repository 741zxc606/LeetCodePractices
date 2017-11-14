/*
 * 108.Convert Sorted Array to Binary Search Tree
 * Given an array where elements are sorted in searching order,convert it to height balanced BST.
 */

#include <iostream>
#include <vector>
#include <cstddef>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        return sortedArrayToBST(nums.begin(), nums.end());
    }

    TreeNode *sortedArrayToBST(vector<int>::iterator beg, vector<int>::iterator end)
    {
        if (beg == end)return NULL;
        auto mid = beg + (end - beg) / 2;
        TreeNode *root = new TreeNode(*mid);
        root->left = sortedArrayToBST(beg, mid);
        root->right = sortedArrayToBST(std::next(mid), end);
        return root;
    }
};

vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ret;
    for (std::stack<TreeNode *>s; !s.empty() || root;)
    {
        if (root)
        {
            s.push(root);
            root = root->left;
        }
        else
        {
            root = s.top(); s.pop();
            ret.push_back(root->val);
            root = root->right;
        }
    }
    return ret;
}

int main()
{
    vector<int> vec{ 2,3,5,7,9,10,14,18 };
    vector<int> vec1;
    Solution s;
    TreeNode *root = s.sortedArrayToBST(vec);
    for (auto i : inorderTraversal(root))
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
