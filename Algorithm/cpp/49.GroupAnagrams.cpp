/*
* 49.Group Anagrams
* Given an array of strings,group anagrams together.
* For example,given:["eat","tea","tan","ate","nat","bat"],
* Return:
* [
*  ["ate","eat","tea"],
*  ["nat","tan"],
*  ["bat"]
* ]
* Note:All inputs will be in lower-case.
*/

#include <string>
using std::string;
#include <vector>
using std::vector;
#include <map>
using std::map;
#include <algorithm>
using std::sort;
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<vector<string>> result;
        map<string, int> m;
        for (std::size_t i = 0; i < strs.size(); i++)
        {
            string word = strs[i];
            sort(word.begin(), word.end());
            if (m.find(word) == m.end())
            {
                vector<string> v;
                v.push_back(strs[i]);
                result.push_back(v);
                m[word] = result.size() - 1;
            }
            else
            {
                result[m[word]].push_back(strs[i]);
            }
        }

        for (std::size_t i = 0; i < result.size(); i++)
        {
            sort(result[i].begin(), result[i].end());
        }
        return result;
    }    
};

int main()
{
    Solution s;
    vector<string> vec = { "eat","tea","tan","ate","nat","nat","bat" };
    for (const auto &str : s.groupAnagrams(vec))
        //Error C2679 binary '<<': no operator found which takes a right-hand operand of type 'const std::vector<std::string,std::allocator<_Ty>>'
        cout << str << " ";
    cout << endl;
    
    return 0;
}
