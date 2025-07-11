#include <bits/stdc++.h>

using namespace std;

// << ,

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