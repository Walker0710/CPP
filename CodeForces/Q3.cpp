#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point
{
    long long x, y;
    int index;
};

void solve()
{
    int n;
    cin >> n;

    vector<Point> points(n);
    vector<int> indices(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> points[i].x >> points[i].y;
        points[i].index = i + 1;
        indices[i] = i;
    }

    vector<bool> inRightHalfX(n + 1, false);
    vector<bool> inRightHalfY(n + 1, false);

    sort(indices.begin(), indices.end(), [&](int a, int b)
         {
        if (points[a].x != points[b].x)
            return points[a].x < points[b].x;
        return points[a].y < points[b].y; });

    for (int i = n / 2; i < n; ++i)
    {
        inRightHalfX[points[indices[i]].index] = true;
    }

    sort(indices.begin(), indices.end(), [&](int a, int b)
         {
        if (points[a].y != points[b].y)
            return points[a].y < points[b].y;
        return points[a].x < points[b].x; });

    for (int i = n / 2; i < n; ++i)
    {
        inRightHalfY[points[indices[i]].index] = true;
    }

    vector<int> groupA, groupB, groupC, groupD;

    for (const auto &pt : points)
    {
        bool xHalf = inRightHalfX[pt.index];
        bool yHalf = inRightHalfY[pt.index];

        if (xHalf && yHalf)
        {
            groupA.push_back(pt.index);
        }
        else if (xHalf && !yHalf)
        {
            groupB.push_back(pt.index);
        }
        else if (!xHalf && yHalf)
        {
            groupC.push_back(pt.index);
        }
        else
        {
            groupD.push_back(pt.index);
        }
    }

    for (size_t i = 0; i < groupA.size(); ++i)
    {
        cout << groupA[i] << " " << groupD[i] << "\n";
    }

    for (size_t i = 0; i < groupB.size(); ++i)
    {
        cout << groupB[i] << " " << groupC[i] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
