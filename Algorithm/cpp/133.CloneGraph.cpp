/*
 * 133.Clone Graph
 * Clone an undirected graph.Each node in the graph contians a label and a list of its neighbors.
 * 
 * OJ's undirected graph serialization:
 * Nodes are labeled unquely.
 * We use # as a separator for each node,and , as a separator for node label and each neighbor of the node.
 * As an example,consider the serialized graph{0,1,2#1,2#2,2}
 * The graph has a total of three nodes,and therefore contains three parts as separated by #.
 * 1.First node is labeled as 0.Connect node 0 to both nodes 1 and 2.
 * 2.Second node is labeled as 1.Connect node 1 to node 2.
 * 3.Third node is labeled as 2.Connect node 2 to node 2(itself),thus forming a self-cycle.
 * Visually,the graph looks like the following:
 *     1
 *    / \
 *   /   \
 *  0 --- 2
 *       / \
 *       \_/
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *>neighbors;
	UndirectedGraphNode(int x) :label(x) {};
};

class Solution {
	unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>map;
	void DFS(UndirectedGraphNode *node)
	{
		if (map.find(node) != map.end()) return;
		map[node] = new UndirectedGraphNode(node->label);
		for (UndirectedGraphNode *neighbor : node->neighbors)
		{
			DFS(neighbor);
			map[node]->neighbors.push_back(map[neighbor]);
		}
	}
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
	{
		if (!node) return node;
		DFS(node);
		return map[node];
	}
};

void printUndirectedGraph(UndirectedGraphNode *node)
{
	std::ostringstream out;
	std::unordered_map<int, unordered_set<int>>map{ {0,std::unordered_set<int>()} };
	std::deque<UndirectedGraphNode*>cache;
	cache.push_back(node);
	do {
		std::sort(cache.begin(), cache.end(), [](UndirectedGraphNode* n1, UndirectedGraphNode* n2)
		{
			return n1->label < n2->label;
		});
		UndirectedGraphNode *node = cache.front(); cache.pop_front();
		out << node->label;
		auto found = map.find(node->label);
		for (UndirectedGraphNode* neighbor : node->neighbors)
		{
			if (map.find(neighbor->label) == map.end())cache.push_back(neighbor);
			if (found != map.end())
			{
				std::unordered_set<int>&exist = found->second;
				if (exist.find(neighbor->label) == exist.end())out << "," << neighbor->label;
			}
			map[neighbor->label].emplace(node->label);
		}
		out << "#";
	} while (!cache.empty());

	std::string out_str = out.str();
	std::cout << out_str.substr(0, out_str.size() - 1) << std::endl;
}

int main()
{
	Solution s;

	UndirectedGraphNode node0(0);
	UndirectedGraphNode node1(1);
	UndirectedGraphNode node2(2);
	UndirectedGraphNode node3(3);
	UndirectedGraphNode node4(4);
	UndirectedGraphNode node5(5);
	node0.neighbors.push_back(&node1);
	node0.neighbors.push_back(&node5);
	node1.neighbors.push_back(&node0);
	node1.neighbors.push_back(&node2);
	node1.neighbors.push_back(&node5);
	node2.neighbors.push_back(&node1);
	node2.neighbors.push_back(&node3);
	node3.neighbors.push_back(&node2);
	node3.neighbors.push_back(&node4);
	node3.neighbors.push_back(&node4);
	node4.neighbors.push_back(&node3);
	node4.neighbors.push_back(&node3);
	node4.neighbors.push_back(&node5);
	node4.neighbors.push_back(&node5);
	node5.neighbors.push_back(&node0);
	node5.neighbors.push_back(&node1);
	node5.neighbors.push_back(&node4);
	node5.neighbors.push_back(&node4);

	printUndirectedGraph(&node0);
	UndirectedGraphNode *node = s.cloneGraph(&node0);
	printUndirectedGraph(node);
}
