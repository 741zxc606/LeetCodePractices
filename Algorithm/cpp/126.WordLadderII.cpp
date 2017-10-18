/*
 * 126.Word Ladder II
 * Given two words (beginWord and endWord),and a dictionary's word list,find all shorted transformation sequence(s) from beginWord to
 * endWord,such that:
 *      1.Only one letter can be changed at a time
 *      2.Each transformed word must exist in the word list.Note that beginWord is not a transformed word.
 * For example,
 * Given:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * Return
 *      [
 *          ["hit","hot","dot","dog","cog"],
 *          ["hit","hot","lot","log","cog"]
 *      ]
 * Note:
 *      - Return an empty list if there is no such transformation sequence.
 *      - All words have the same length.
 *      - All words contain only lowercase alphabetic characters.
 *      - You may assume no duplicates in the word list.
 *      - You may assume beginWord and endWord are non-empty and are not the same.
 */

#include <iostream>
#include <map>
#include <queue>
#include <unordered_set>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 2 Methods:
//
//      1)Using BSF algorithm build a tree like below.
//      2)Using DSF to parse the transformation path.

map <string, unordered_set<string>>& buildTree(string& beginWord, string& endWord, unordered_set<string> &wordList)
{
    static map<string, unordered_set<string>> parents;
    parents.clear();

    unordered_set<string> level[3];
    unordered_set<string> *previousLevel = &level[0];
    unordered_set<string> *currentLevel = &level[1];
    unordered_set<string> *newLevel = &level[2];
    unordered_set<string> *p = NULL;
    currentLevel->insert(beginWord);

    bool reachEnd = false;

    while (!reachEnd)
    {
        newLevel->clear();
        for (auto it = currentLevel->begin(); it != currentLevel->end(); it++)
        {
            for (int i = 0; i < it->size(); i++)
            {
                string newWord = *it;
                for (char c = 'a'; c < 'z'; c++)
                {
                    newWord[i] = c;
                    if (newWord == endWord)
                    {
                        reachEnd = true;
                        parents[*it].insert(endWord);
                        continue;
                    }
                    if (wordList.count(newWord) == 0 || currentLevel->count(newWord) > 0 || previousLevel->count(newWord) > 0)
                    {
                        continue;
                    }
                    newLevel->insert(newWord);
                    parents[*it].insert(newWord);
                }
            }
        }

        if (newLevel->empty()) break;

        p = previousLevel;
        previousLevel = currentLevel;
        currentLevel = newLevel;
        newLevel = p;
    }

    if (!reachEnd)
    {
        parents.clear();
    }
    return parents;
}

void generatePath(string beginWord, string endWord, map<string, unordered_set<string>> &parents, vector<string>path, vector<vector<string>> &paths)
{
    if (parents.find(beginWord) == parents.end())
    {
        if (beginWord == endWord)
        {
            paths.push_back(path);
        }
        return;
    }
    for (auto it = parents[beginWord].begin(); it != parents[beginWord].end(); it++)
    {
        path.push_back(*it);
        generatePath(*it,  endWord, parents, path, paths);
        path.pop_back();
    }
}

vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList)
{
    vector<vector<string>> ladders;
    vector<string> ladder;
    ladder.push_back(beginWord);
    if (beginWord == endWord)
    {
        ladder.push_back(endWord);
        ladders.push_back(ladder);
        return ladders;
    }

    map<string, unordered_set<string>> &parents = buildTree(beginWord, endWord, wordList);

    if (parents.size() <= 0)
    {
        return ladders;
    }

    generatePath(beginWord, endWord, parents, ladder, ladders);

    return ladders;
}

void printLadders(vector<vector<string>>&ladders)
{
    int i, j;
    for (i = 0; i < ladders.size(); i++)
    {
        for (j = 0; j < ladders[i].size() - 1; j++)
        {
            cout << ladders[i][j] << "->";
        }
        cout << ladders[i][j] << endl;
    }
}

int main()
{    
    string beginWord = "hit";
    string endWord = "cog";

    unordered_set<string> wordList({ "hot","dot","dog","lot","log","cog" });

    vector<vector<string>> ladders;
    ladders = findLadders(beginWord, endWord, wordList);
    printLadders(ladders);
    return 0;
}
