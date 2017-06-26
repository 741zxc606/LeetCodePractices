/*
 * Given a string S，find the longest palindromic substring in S.
 * You may assume that the maximum length of S is 1000,
 * and there exixsts one unique longest palindromic substring.
 */

#include <iostream>
#include <string.h>
#include <string>
#include <vector>
using namespace std;

string findPalindrome(string s,int left,int right)
{
    int n=s.size();
    int l=left;
    int r=right;
    while(left>=0&&right<=n-1&&s[left]==s[right])
    {
        left--;
        right++;
    }
    return s.substr(left+1,right-left-1);
}

string longestPalindrome_recursive_way(string s)
{
    int n=s.size();
    if(n<=1) return s;

    string longest;

    string str;
    for(int i=0;i<n-1;i++)
    {
        str=findPalindrome(s,i,i);
        if(str.size()>longest.size())
        {
            longest=str;
        }
    }
    return longest;
}

string longestPalindrome_dp_way(string s)
{
    string longest;
    int n=s.size();
    if(n<=1) return s;

    for(int i=n-1;i>=0;i--)
    {
        for(int j=i;j<n;j++)
        {
            if(i==j||(s[i]==s[j]&&(j-i<2)||matrix[i+1][j-1]))
            {
                matrix[i][j]=true;
                if(longest.size()<j-i+1)
                {
                    longest=s.substr(i,j-i+1);
                }
            }
        }
    }
    return longest;
}

string longestPalindrome_dp_opt_way(string s)
{
    int n=s.size();
    if(n<=1) return s;

    bool **matrix=new bool* [n];
    int start=0,len=0;

    for(int i=0;i<n;i++)
    {
        matrix[i]=new bool[i+1];
        memset(matrix[i],false,(i+1)*sizeof(bool));
        matrix[i][i]=true;
        for(int j=0;j<i;j++)
        {
            if(i==j||(s[j]==s[i]&&(i-j<2||matrix[i-1][j+1])))
            {
                mareix[i][j]=true;
                if(len<i-j+1)
                {
                    start=j;
                    lemn=i-j+1;
                }
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        delete [] matrix[i];
    }
    delete [] matrix;

    return s.substr(start,len);
}

string longestPalindrome(string s)
{
    return longestPalindrome_dp_opt_way(s);
    return longestPalindrome_recursive_way(s);
}

int main(int argc,char**atgv)
{
    string s="abaxdfgdcaba";
    if(argc>1)
    {
        s=argv[1];
    }
    cout << s <<":"<<longPalindrome(s) <<endl;

    s = "321012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210012321001232100123210123210012321001232100123210123";
    cout <<  s << " : " << longestPalindrome(s) << endl;
    return 0;
}
