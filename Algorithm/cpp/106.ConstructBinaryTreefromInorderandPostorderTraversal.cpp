/*
 * 106.Construct Binary Tree from Inorder and Postorder Traversal
 * Given inorder and postorder traversal of a tree,construct the binary tree.
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
    using vcIt = vector<int>::const_iterator;
    TreeNode* buildTree(vector<int>& inorder,vector<int>& postorder)
    {
        return buildTree(inorder.cbegin(), inorder.cend(), postorder.cbegin(), postorder.cend());
    }
    TreeNode *buildTree(vcIt inBeg, vcIt inEnd, vcIt postBeg, vcIt postEnd)
    {
        if (inBeg >= inEnd || postBeg >= postEnd)return NULL;
        TreeNode *root = new TreeNode(*prev(postEnd));
        auto inRoot = find(inBeg, inEnd, root->val);
        root->left = buildTree(inBeg, inRoot, postBeg, next(postBeg, inRoot - inBeg));
        root->right = buildTree(next(inRoot), inEnd, next(postBeg, inRoot - inBeg), prev(postEnd));
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
    std::vector<int>inorder{ 7,4,2,8,5,1,6,9,3 };
    std::vector<int>postorder{ 7,4,8,5,2,9,6,3,1 };
    print_bfs(s.buildTree(inorder, postorder));
}
