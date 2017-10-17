/*
 * 127.Word Ladder
 * Given two words (beginWord and endWord),and a dictionary's word list,find the length of shortest transformation sequence from
 * beginWord to endWord,such that:
 *      1.Only one letter can be changed at a time.
 *      2.Each transformed word must exisit in the word list.Note that beginWord is not a transformed word.
 *
 * For example:
 * Given:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * As one shorted transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 * return its length is 5.
 *
 * Note:
 *      - Return 0 if there is no such transformation sequence.
 *      - All words have the same length.
 *      - All words contain only lowercase alphabetic characters.
 *      - You may assume no duplicates in the word list.
 *      - You may assume beginWord and endWord are non-empty and are not the same.
 */

#include <unordered_set>
#include <map>
#include <queue>
#include <string>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord,string endWord,unordered_set<string> &wordList)
    {
        //using a map for two purpose:
        //1)store the distance so far.
        //2)remove the duplication

        map<string, int> dis;
        dis[beginWord] = 1;

        queue<string> q;
        q.push(beginWord);

        while (!q.empty())
        {
            string word = q.front();
            q.pop();

            if (word == endWord)
            {
                break;
            }

            for (int i = 0; i < word.length(); i++)
            {
                string temp = word;
                for (char c = 'a'; c <= 'z'; c++)
                {
                    temp[i] = c;
                    if (wordList.count(temp) > 0 && dis.count(temp) == 0)
                    { 
                        dis[temp] = dis[word] + 1;
                    q.push(temp);
                    }
                }
            }
        }
        return (dis.count(endWord) == 0) ? 0 : dis[endWord];
    }    
};

int main()
{
    Solution s;
    string beginWord = "hit";
    string endWord = "cog";
    unordered_set<string> wordList({"hot","dot","dog","lot","log","cog"});

    cout << s.ladderLength(beginWord,endWord,wordList) << endl;
}
