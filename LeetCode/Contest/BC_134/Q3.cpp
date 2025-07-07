#include <bits/stdc++.h>

using namespace std;

// << ,

int numberOfAlternatingGroups(vector<int> &colors, int k)
{
    colors.insert(colors.end(), colors.begin(), colors.begin() + (k - 1));
    int ans = 0;
    int l = 0;

    for (int r = 0; r < colors.size(); r++)
    {
        if (r > 0 && colors[r] == colors[r - 1])
        {
            l = r;
        }

        if (r - l + 1 >= k)
        {
            ans++;
        }
    }

    return ans;
}