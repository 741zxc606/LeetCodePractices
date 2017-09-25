/*
 * 93.Restore IP Addresses
 * Given a string containing only digits,restore it by returning all possitive valid IP address combinations.
 * For example:
 * Given "25525511135"
 * return ["255.255.11.135","255.255.111.35"].
 */

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> result;
        string ip;
        restoreIpHelper(s, 0, 0, ip, result);
        return result;
    }

    void restoreIpHelper(string& s, int start, int partNum, string ip, vector<string>& result)
    {
        int len = s.size();
        if (len - start<4 - partNum || len - start>(4 - partNum) * 3)
        {
            return;
        }

        if (partNum == 4 && start == len)
        {
            ip.erase(ip.end() - 1, ip.end());
            result.push_back(ip);
            return;
        }

        int num = 0;
        for (int i = start; i < start + 3; i++)
        {
            num = num * 10 + s[i] - '0';
            if (num < 256)
            {
                ip += s[i];
                restoreIpHelper(s, i + 1, partNum + 1, ip + '.', result);
            }

            if (num == 0)
            {
                break;
            }
        }
    }
};

int main()
{
    string s1 = "25525511135";

    Solution s;
    vector<string> result = s.restoreIpAddresses(s1);

    cout << s1 << endl;
    for (int i = 0; i<result.size(); i++)
    {
        cout << '\t' << result[i] << endl;
    }

    return 0;
}
