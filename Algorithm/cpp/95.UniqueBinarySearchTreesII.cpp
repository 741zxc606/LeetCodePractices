/*
 * 95.Unique Binary Search Trees II
 * Given an integer n,generate all structurally unique BST's(binary search trees) that store values 1...n.
 * For example,
 * Given n=3,your program should return all 5 unique BST's shown below.
 * 
 *    1         3     3      2      1
 *     \       /     /      / \      \
 *      3     2     1      1   3      2
 *     /     /       \                 \
 *    2     1         2                 3
 */

#include <vector>
#include <string>
#include <queue>
#include <cstddef>
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
    vector<TreeNode *>generateTrees(int n)
    {
        return generateTrees(1, n + 1);
    }
    vector<TreeNode *>generateTrees(int start, int end)
    {
        if (end - start < 2)
            return vector<TreeNode *>{end - start ? new TreeNode(start) : NULL};
        vector<TreeNode *> retv;
        for (int i = start; i < end; ++i)
        {
            vector<TreeNode *> retLeft = generateTrees(start, i);
            vector<TreeNode *> retRight = generateTrees(i + 1, end);
            for(auto pL:retLeft)
                for (auto pR : retRight)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = pL;
                    root->right = pR;
                    retv.push_back(root);
                }
        }
        return retv;
    }
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
    for (auto p : s.generateTrees(0))
        print_bst(p);
}
