/*
 * 28. Implement strStr()
 * Implement strStr().
 * Return the index of the first occurrence of needle in haystack,or -1 if needle is not part of haystack.
 */

#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
    //using two pointers
    int strStr(char *haystack, char *needle)
    {
        if (!*haystack && !*needle) return 0;
        char *p = haystack;
        while (*p)
        {
            char *p1 = p, *p2 = needle;
            while (*p1&&*p2&&*p1 == *p2)
            {
                ++p1;
                ++p2;
            }
            if (!*p2) return p - haystack;
            else if (!*p1) break;
            ++p;
        }
        return -1;
    }
};

int main()
{
    Solution s;
    std::cout << s.strStr("Iamyourfather", "you") << std::endl;
}
