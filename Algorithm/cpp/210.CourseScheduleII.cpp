/*
 * 210. Course Schedule II
 * There are a total of n courses you have to take, labeled from 0 to n-1.
 * Some courses may have prerequisites, for example to take course 0 you have to first take course 1, 
 * which is expressed as a pair: [0,1]
 * Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.
 * There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all course, return all empty array.
 * Example 1: 
 *      Input: 2, [[1,0]]
 *      Output: [0,1]
 *      Explanation: There are a total of 2 courses to take. To take course 1 you should have finished 
 *                   course 0. So the correct course order is [0,1].
 * Example 2:
 *      Input: 4, [[1,0],[2,0],[3,1],[3,2]]
 *      Output: [0,1,2,3] or [0,2,1,3] 
 *      Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both
 *                   course 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
 *                   So one correct course order is [0,1,2,3]. Another correct oedering is [0,2,1,3] . 
 * Note: 
 *      1. The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
 *      2. You may assume that there are no duplicate egdes in the input prerequisites.
 */

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    // if has cycle, return false, else return true 
    bool topologicalSort(int n, vector<int>& explored, vector<int>& path,
        unordered_map<int, vector<int>>& graph, vector<int>&result)
    {
        for (int i = 0; i < graph[n].size(); i++)
        {
            int prereq = graph[n][i];

            if (path[prereq])
            {
                result.clear();
                return false;
            }

            path[prereq] = true;
            if (!topologicalSort(prereq, explored, path, graph, result))
            {
                result.clear();
                return false;
            }
            path[prereq] = false;
        }
        if (!explored[n])
        {
            result.push_back(n);
        }
        explored[n] = true;
        return true;
    }

    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites)
    {
        vector<int> result;
        vector<int> enterance(numCourses, true);

        // using map to store the graph, it's easy to search the edge for each node
        // the bool in pair means it is explored or not
        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < prerequisites.size(); i++)
        {
            graph[prerequisites[i].first].push_back(prerequisites[i].second);
            enterance[prerequisites[i].second] = false;
        }

        // explored[] is used to record the node already checked
        vector<int> explored(numCourses, false);

        // path[] is used to check the cycle during DFS
        vector<int> path(numCourses, false);

        for (int i = 0; i < numCourses; i++)
        {
            if (!enterance[i] || explored[i]) continue;
            if (!topologicalSort(i, explored, path, graph, result)) return result;
        }

        // if there has one course hasn't been explored, means there is a cycle
        for (int i = 0; i < numCourses; i++)
        {
            if (!explored[i]) return vector<int>();
        }
        return result;
    }
};

int main()
{
    Solution s;

    int numCourses = 4;
    vector<pair<int, int>> prerequisites = { { 1,0 },{ 2,0 },{3,1},{3,2} };
    s.findOrder(numCourses, prerequisites);

    for (const auto &v : prerequisites)
    {
        for (const auto &c : v)    //need to improve
        {
            std::cout << c << " ";
        }
        cout << std::endl;
    }

    return 0;
}
