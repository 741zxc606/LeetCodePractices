/*
 * 207. Course Schedule
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 * Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair:
 * [0,1]
 * Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses? 
 * 
 * Example 1: 
 *      Input: 2, [[1,0]] 
 *      Output: true
 *      Explanation: There are a total of 2 courses to take. 
 *                   To take course 1 you should have finished course 0. So it is possible. 
 * Example 2: 
 *      Input: 2, [[1,0],[0,1]]
 *      Output: false
 *      Explanation: There are a total of 2 courses to take. 
 *                   To take course 1 you should have finished course 0, and to take course 0 you should
 *                   also have finished course 1. So it is impossible. 
 * 
 * Note: 
 *      1. The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
 *      2. You may assume that there are no duplicate edges in the input prerequisites.
 * Hints: 
 *      1. This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, no topological ordering exists and 
 *         therefore it will be impossible to take all courses. 
 *      2. Topological Sort via DFS - A great cideo tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
 *      3. Topological sort could also be done via BFS. 
 */

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (prerequisites.empty())
            return true;

        stack<int> s;                        // stack for vertex whose in-degree is 0
        vector<int> inDegree(numCourses, 0); // each vertex's in-degree
        unordered_set<int> visited;          // for vertexes which have been visited before

        countInDegree(inDegree, prerequisites);  // count in-degree for each vertex
        push(s, inDegree, visited);              // push vertex whose in-degree's 0 into stack

        while (!s.empty())
        {
            int cur = s.top();
            s.pop();
            visited.insert(cur); // visit cur
            bool alreadyDel = delEdgeSourcedBy(cur, prerequisites, inDegree);  // delete all edges sources by cur
            if (alreadyDel)
                push(s, inDegree, visited);
        }
        if (visited.size() < numCourses)  // cycle exists
            return false;
        return true;
    }

    void countInDegree(vector<int> &inDegree, vector<pair<int, int>> &edges)
    {
        for (auto edge : edges)
            inDegree[edge.first]++;
    }

    void push(stack<int> &s, vector<int> &inDegree, unordered_set<int> &visited)
    {
        for (int i = 0; i < inDegree.size(); i++)
            if (inDegree[i] == 0 && visited.find(i) == visited.end()) // in-degree is 0 and never visited
                s.push(i);
    }

    bool delEdgeSourcedBy(int src, vector<pair<int, int>> &edges, vector<int> &inDegree)
    {
        bool flag = false;
        vector<pair<int, int>> copy;

        for (int i = 0; i < edges.size(); i++)
        {
            if (edges[i].second == src)
            {
                inDegree[edges[i].first]--; // subtract vertex i's in-degree
                flag = true;
            }
            else
                copy.push_back(edges[i]);
        }
        edges = copy;
        return flag;
    }
};

int main()
{
    Solution s;

    int numCourses = 2;
    vector<pair<int, int>> edges = { {1,0},{0,1} };
    std:cout << std::boolalpha << s.canFinish(numCourses, edges) << std::endl;

    return 0;
}
