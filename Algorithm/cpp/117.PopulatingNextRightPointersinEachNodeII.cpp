/*
 * 117.Populating Next Right Pointers in Each Node II
 * Follow up for problem "Populating Next Right Pointers in Each Node".
 * What if the given tree could be any binary tree?Would your previous solution still work?
 * Note:
 *     You may only use constant extra space.
 * For example,
 * Given the following binary tree,
 *       1
       /  \
      2    3
     / \    \
    4   5    7
 * 
 * After calling your function,the tree should look like:
 *       1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL
 */

#include <queue>
#include <vector>
#include <iostream>
using namespace std;
using vecIter = std::vector<int>::iterator;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root)
    {
        while (root && (root->left || root->right))
        {
            if (root->left && root->right)
                root->left->next = root->right;
            for (TreeLinkNode *cur = root, *find = root->next; find; find = find->next)
            {
                if (!find->left && !find->right) continue;
                if (find->left && find->right)
                    find->left->next = find->right;
                (cur->right ? cur->right->next : cur->left->next) = find->left?find->left:find->right;
                cur = find;
            }
            root = root->left ? root->left : root->right;
            while (root->next && !root->left && !root->right)root = root->next;
        }
    }
};

TreeLinkNode *createBinaryTree(vecIter beg, vecIter end)
{
    std::vector<TreeLinkNode *> vec;
    for (vecIter it = beg; it != end; ++it)
        vec.push_back(new TreeLinkNode(*it));

    for (int i = 0, pos = 0; pos != vec.size() - 1; ++i)
    {
        vec[i]->left = vec[++pos];
        vec[i]->right = vec[++pos];
    }
    return *vec.begin();
}

void print(TreeLinkNode *root)
{
    while (root)
    {
        std::cout << root->val;
        TreeLinkNode *cur = root->next;
        while (cur)
        {
            std::cout << "->" << cur->val;
            cur = cur->next;
        }
        std::cout << std::endl;
        root = root->left;
    }
}

int main()
{
    std::vector<int> vec = { 1,2,3,4,5,6,7 };
    TreeLinkNode *root = createBinaryTree(vec.begin(), vec.end());

    Solution s;
    s.connect(root);
    print(root);

    return 0;
}
