/*
 * 105.Construct Binary Tree from Preorder and Inorder Traversal
 * Given preorder and inorder traversal of a tree,construct the binary tree.
 * Note:
 * You may assume that duplicates do not exist in the tree.
 */

#include <iostream>
#include <string>
#include <cstddef>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using std::vector; using std::next; using std::prev;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    using cIter = vector<int>::const_iterator;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        return buildTree(preorder.cbegin(), preorder.cend(), inorder.cbegin(), inorder.cend());
    }
    TreeNode *buildTree(cIter preBeg, cIter preEnd, cIter inBeg, cIter inEnd)
    {
        if (preBeg >= preEnd || inBeg >= inEnd) return NULL;
        TreeNode *root = new TreeNode(*preBeg);
        auto inRoot = std::find(inBeg, inEnd, root->val);
        root->left = buildTree(next(preBeg), next(preBeg, inRoot - inBeg + 1), inBeg, inRoot);
        root->right = buildTree(next(preBeg,inRoot-inBeg+1),preEnd,next(inRoot),inEnd);
        return root;
    }
};

void print_bfs(TreeNode* p)
{
    if (!p) return;
    std::vector<std::string>v;
    std::queue<TreeNode *>q;
    q.push(p);
    do {
        TreeNode *node = q.front(); q.pop();
        if (node)
            v.push_back(std::to_string(node->val));
        else {
            v.push_back("#");
            continue;
        }
        q.push(node->left);
        q.push(node->right);
    } while (!q.empty());

    auto found = std::find_if(v.rbegin(), v.rend(), [](const std::string &s) {return s != "#"; });
    v.erase(found.base(), v.end());
    for (const auto &s : v)
        std::cout << s << ",";
    std::cout << "\b" << std::endl;
}

int main()
{
    Solution s;
    std::vector<int>preorder{ 1,2,4,5,3,6 };
    std::vector<int>inorder{ 4,2,5,1,3,6 };
    print_bfs(s.buildTree(preorder, inorder));
}
