/*
 * 71.Simplify Path
 * Given an absolute path for a file (Unix-style),simplify if.
 * For example,
 * path = "/home/", => "/home"
 * path = "/a/./b/../../c/", => "/c"
 * Corner Cases:
 *     1.Did you consider the case where path = "/../"?
 *       In this case,you should return "/"
 *     2.Another corner case is the path might contain multiple slashes '/' together,such as "/home//foo/".
 *       In this case,you should ignore redundant slashes and return "/home/foo".
 */

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class Solution {
public:
    string simplifyPath(string path)
    {
        string res, tmp;
        vector<string> stk;
        stringstream ss(path);
        while (getline(ss, tmp, '/'))
        {
            if (tmp == "" || tmp == ".") continue;
            if (tmp == ".." && !stk.empty()) stk.pop_back();
            else if (tmp != "..") stk.push_back(tmp);
        }
        for (auto str : stk) res += "/" + str;
        return res.empty() ? "/" : res;
    }
};

int main()
{
    string p1 = "/home/";
    string p2 = "/a/./b/../../c/";
    string p3 = "/../";
    string p4 = "/home//foo";

    Solution s;
    cout << s.simplifyPath(p1) << endl;
    cout << s.simplifyPath(p2) << endl;
    cout << s.simplifyPath(p3) << endl;
    cout << s.simplifyPath(p4) << endl;

    return 0;
}
