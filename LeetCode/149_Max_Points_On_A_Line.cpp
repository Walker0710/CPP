#include <bits/stdc++.h>

using namespace std;

// << ,

struct hash_pair
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &pair) const
    {
        auto hash1 = hash<T1>{}(pair.first);
        auto hash2 = hash<T2>{}(pair.second);
        return hash1 ^ hash2;
    }
};

int maxPoints(vector<vector<int>> &points)
{
    unordered_map<pair<int, int>, int, hash_pair> slopeCount;
    int n = points.size();

    if (n < 3)
        return n;

    int maxPoints = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {

            vector p1 = points[i];
            vector p2 = points[j];

            int slope = (p2[1] - p1[1]) * 1000000 + (p2[0] - p1[0]);
            int intercept = p1[1] * 1000000 - slope * p1[0];

            slopeCount[{slope, intercept}]++;
            maxPoints = max(maxPoints, slopeCount[{slope, intercept}]);
        }
    }

    return maxPoints;
}


int maxPoints(vector<vector<int>> &points)
{
    int n = points.size();

    if (n < 3)
        return n;

    int ans = 0;

    for (auto it1 : points)
    {
        unordered_map<double, int> mp;
        double x1 = it1[0], y1 = it1[1];
        
        for (auto it2 : points)
        {
            if (it2 == it1)
            continue;
            
            double x2 = it2[0], y2 = it2[1];
            double slope;
        
            if (x2 - x1 == 0)
            {
                slope = INT_MAX; 
            }
        
            else
            {
                slope = (y2 - y1) / (x2 - x1);
            }
            mp[slope]++;
            ans = max(ans, mp[slope]);
        }
    }
    
    return ans + 1; 
}