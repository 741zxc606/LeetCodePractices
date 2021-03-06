/*
 * 149.Max Points on a Line
 * Given n points on a 2D plane,find the maximum number of points that lie on the same straight line.
 */

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Point {
    int x;
    int y;
    Point() :x(0), y(0) {}
    Point(int a, int b) :x(a), y(b) {}
};

//O(n^2) time complexity solution
int maxPoints(vector<Point>&points)
{
    #define INT_MAX 2147483647
    #define INT_MIN (-INT_MAX-1)

    if (points.size() <= 0) return 0;
    if (points.size() <= 2) return points.size();

    int maxnum = 0;
    //using a map to find the same slope line
    map<double, int> slopeMap;

    //The algorithm here is quite straight forward.
    //    take each point in array to caculate with pthers
    //
    //Actually the algorithm here can be optimized.
    //    there are many duplicated caculation.
    //    considering two points A and B,(A,B) is same with (B,A),here re-caculated.
    for (int i = 0; i < points.size(); i++)
    {
        //reset ten clope map.
        slopeMap.clear();
        slopeMap[INT_MIN] = 0;
        int samePointCnt = 1;
        for (int j = 0; j < points.size(); j++)
        {
            if (i == j) continue;//skip the same point
            //Caculate the slope of two points
            int delta_x = points[i].x - points[j].x;
            int delta_y = points[j].y - points[j].y;
            //Special case:two points are exactly at same place
            if (delta_y == 0 && delta_x == 0)
            {
                samePointCnt++;
                continue;
            }
            //Special case:delta_x == 0
            double slope = INT_MAX;
            if (delta_x != 0)
            {
                slope = 1.0*delta_y / delta_x;
            }
            //Count the points is same line.
            slopeMap[slope]++;
        }
        //find the max number of points located at same line with points[i]
        map<double, int>::iterator it;
        for (it = slopeMap.begin(); it != slopeMap.end(); it++)
        {
            if (maxnum < it->second + samePointCnt)
            {
                maxnum = it->second + samePointCnt;
            }
        }
    }
    return maxnum;
}

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
    int n = 20;
    vector<Point> points;
    generatePoints(points,n);
    printPoints(points);
    cout << maxPoints(points) << endl;
    return 0;
}
