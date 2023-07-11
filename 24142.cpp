#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

ifstream ifile("hull.inp");
ofstream ofile("hull.out");

struct Point
{
    int x, y;
};

bool compare(Point a, Point b)
{
    return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}

int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0)
        return 0;
    return (val > 0) ? 1 : 2;
}

vector<Point> convex(vector<Point>& points)
{
    int n = points.size();
    sort(points.begin(), points.end(), compare);

    vector<Point> hull;
    for (int i = 0; i < n; i++)
    {
        while (hull.size() > 1 && orientation(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) != 2)
        {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    int t = hull.size() + 1;
    for (int i = n - 2; i >= 0; i--)
    {
        while (hull.size() >= t && orientation(hull[hull.size() - 2], hull[hull.size() - 1], points[i]) != 2)
        {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    hull.pop_back();
    return hull;
}

int main()
{
    vector<Point> points;

    int n, tempx, tempy;
    ifile >> n;
    for (int i = 0; i < n; i++)
    {
        ifile >> tempx >> tempy;
        points.push_back({ tempx, tempy });
    }

    vector<Point> hull = convex(points);
    ofile << hull.size() << endl;
    for (int i = 0; i < hull.size(); i++)
    {
        ofile << hull[i].x << " " << hull[i].y << endl;
    }

    return 0;
}