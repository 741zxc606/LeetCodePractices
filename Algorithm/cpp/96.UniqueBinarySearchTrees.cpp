/*
* 96.Unique Binary Search Trees
* Given n,how many structurally unique BST's(binary search trees) that store values 1...n?
* For example,
* Given n=3,your program should return all 5 unique BST's shown below.
*
*    1         3     3      2      1
*     \       /     /      / \      \
*      3     2     1      1   3      2
*     /     /       \                 \
*    2     1         2                 3
*/

/*
* Taking 1~n as root respectively:
*      1 as root: # of trees = F(0) * F(n-1)  // F(0) == 1
*      2 as root: # of trees = F(1) * F(n-2)
*      3 as root: # of trees = F(2) * F(n-3)
*      ...
*      n-1 as root: # of trees = F(n-2) * F(1)
*      n as root:   # of trees = F(n-1) * F(0)
*
* So, the formulation is:
*      F(n) = F(0) * F(n-1) + F(1) * F(n-2) + F(2) * F(n-3) + ... + F(n-2) * F(1) + F(n-1) * F(0)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int numTrees(int n)
    {
        int *cnt = (int *)malloc((n + 1) * sizeof(int));
        memset(cnt, 0, (n + 1) * sizeof(int));
        cnt[0] = 1;
        cnt[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                cnt[i] += cnt[j] * cnt[i - j - 1];
            }
        }
        int sum = cnt[n];
        free(cnt);
        return sum;
    }
};

int main()
{
    int n = 3;
    Solution s;
    cout << s.numTrees(n) << endl;

    return 0;
}
