#include <bits/stdc++.h>

using namespace std;

// << ,

int get(vector<pair<int, int>> &points)
{
    int maxArea = -1;

    for (int i = 0; i < points.size() - 3; i++)
    {
        if (points[i].first == points[i + 1].first && points[i + 2].first == points[i + 3].first && points[i].second == points[i + 2].second && points[i + 1].second == points[i + 3].second)
        {
            int area = (points[i + 2].first - points[i].first) * (points[i + 1].second - points[i].second);
            maxArea = max(maxArea, area);
        }
    }

    return maxArea;
}

int maxRectangleArea(vector<vector<int>> &points)
{
    int maxArea = -1;
    int n = points.size();

    sort(points.begin(), points.end());

    for (int i = 0; i < n - 3; i++)
    {
        vector<pair<int, int>> rectanglePoints;

        rectanglePoints.push_back({points[i][0], points[i][1]});
        rectanglePoints.push_back({points[i + 1][0], points[i + 1][1]});

        int j = i + 2;
    
        while (j < n - 2)
        {
            if (points[j][1] > points[i + 1][1] || points[j][1] < points[i][1])
            {
                j++;
            }
    
            else
            {
                break;
            }
        }

        if (j < n - 1)
        {
            rectanglePoints.push_back({points[j][0], points[j][1]});
            rectanglePoints.push_back({points[j + 1][0], points[j + 1][1]});

            maxArea = max(maxArea, get(rectanglePoints));
        }
    }

    return maxArea;
}