/*
 * 56.Merge Interval
 * Given a collection of intervals,merge all overlapping intervals.
 * For example,
 * Given [1,3],[2,6],[8,10],[15,18],
 * return [1,6],[8,10],[15,18]
 */

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() :start(0), end(0) {}
    Interval(int s, int e) :start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals)
    {
        if (intervals.empty()) return vector<Interval>{};
        vector<Interval> res;
        
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {return a.start < b.start; });
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++)
        {
            if (res.back().end < intervals[i].start) res.push_back(intervals[i]);
            else
                res.back().end = max(res.back().end, intervals[i].end);
        }
        return res;
    }
};

int main()
{
    Interval i1(1, 3);
    Interval i2(2, 6);
    Interval i3(8, 10);
    Interval i4(9, 13);

    vector<Interval> intervals;

    intervals.push_back(i1);
    intervals.push_back(i2);
    intervals.push_back(i3);
    intervals.push_back(i4);
    
    Solution s;
    vector<Interval> r = s.merge(intervals);

    for (int i = 0; i < r.size(); i++)
    {
        cout << "[" << r[i].start << "," << r[i].end << "]";
    }
    cout << endl;
    return 0;
}
