/*
* 149.Max Points on a Line
* Given n points on a 2D plane,find the maximum number of points that lie on the same straight line.
*/

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct Point {
    int x;
    int y;
    Point() :x(0), y(0) {}
    Point(int a, int b) :x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point>& points)
    {
        if (points.size() < 2) return points.size();

        int result = 0;

        for (int i = 0; i < points.size(); i++)
        {
            map<pair<int, int>,int> lines;
            int localmax = 0, overlap = 0, vertical = 0;

            for (int j = i + 1; j < points.size(); j++)
            {
                if (points[j].x == points[i].x&&points[j].y == points[i].y)
                {
                    overlap++;
                    continue;
                }
                else if (points[j].x == points[i].x) vertical++;
                else
                {
                    int a = points[j].x - points[i].x, b = points[j].y - points[i].y;
                    int gcd = GCD(a, b);

                    a /= gcd;
                    b /= gcd;

                    lines[make_pair(a, b)]++;
                    localmax = max(lines[make_pair(a, b)], localmax);
                }
                localmax = max(vertical, localmax);
            }        
            result = max(result, localmax + overlap + 1);
        }
        return result;
    }

private:
    int GCD(int a, int b)
    {
        if (b == 0) return a;
        else return GCD(b, a%b);
    }
};

void generatePoints(vector<Point>&points, int n)
{
    srand(time(0));
    Point p;
    for (int i = 0; i < n; i++)
    {
        p.x = rand() % 1;
        p.y = rand() % 1;
        points.push_back(p);
    }
}

void printPoints(vector<Point>&points)
{
    for (int i = 0; i < points.size(); i++)
    {
        cout << "(" << points[i].x << "," << points[i].y << ")";
    }
    cout << endl;
}

int main()
{
    Solution s;
    int n = 20;
    vector<Point> points;
    generatePoints(points, n);
    printPoints(points);
    cout << s.maxPoints(points) << endl;
    return 0;
}
