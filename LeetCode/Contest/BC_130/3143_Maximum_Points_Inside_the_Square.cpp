#include <bits/stdc++.h>

using namespace std;

// << ,

int maxPointsInsideSquare(vector<vector<int>> &points, string s)
{
    int n = s.length();
    unordered_map<char, vector<vector<int>>> mp;

    // creating map from char to pts
    for (int i = 0; i < n; i++)
    {
        mp[s[i]].push_back(points[i]);
    }

    for (auto &rec : mp)
    {
        sort(rec.second.begin(), rec.second.end());
    }

    int side = 0;

    // finding side of square
    for (auto &rec : mp)
    {
        vector<vector<int>> pt = rec.second;

        if (pt.size() > 1)
        {
            int mini = min(abs(pt[0][0] - pt[1][0]), abs(pt[0][1] - pt[1][1]));

            side = min(side, mini);
        }
    }

    // counting pt in the square
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        vector<int> pt = points[i];
        int maxi = max(abs(pt[1]), abs(pt[0]));

        if (maxi < side)
        {
            ans++;
        }
    }

    return ans;
}

int maxPointsInsideSquare(vector<vector<int>> &points, string s)
{
    int n = points.size();

    auto isValid = [&](int side)
    {
        unordered_set<char> tags;
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            int x = points[i][0];
            int y = points[i][1];

            if (max(abs(x), abs(y)) <= side)
            {
                if (tags.count(s[i]))
                return -1; 
                
                tags.insert(s[i]);
                count++;
            }
        }

        return count;
    };

    int low = 0, high = 1e9;
    int ans = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int count = isValid(mid);
        if (count >= 0)
        {
            ans = count;
            low = mid + 1; 
        }
        else
        {
            high = mid - 1; 
        }
    }

    return ans;
}