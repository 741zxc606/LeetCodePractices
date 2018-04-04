/*
 * 134.Gas Station
 * There are N gas station along a circular route,where the amount of gas at station i is gas[i].
 * You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station(i+1).
 * You  begin the journey with an empty tank at one of the gas stations.
 * Return the starting gas station's index if you can travel around the circuit once,otherwise return -1.
 * Note:
 * The solution is guanranteed to be unique.
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
	{
		int tank{ 0 }, start{ 0 }, stored{ 0 };
		for(decltype(gas.size())i=0;i<gas.size();++i)
			if ((tank += gas[i] - cost[i]) < 0)
			{
				start = i + 1;
				stored += tank;
				tank = 0;
			}
		return (tank + stored) < 0 ? -1 : start;
	}
};

int main()
{
	Solution s;
	vector<int>gas{ 3,4,5 };
	vector<int>cost{ 3,5,4 };
	cout << s.canCompleteCircuit(gas, cost) << endl;
}
