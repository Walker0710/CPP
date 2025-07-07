#include <bits/stdc++.h>

using namespace std;

// << ,

int numberOfAlternatingGroups(vector<int> &colors)
{
    int n = colors.size();

    colors.push_back(colors[0]);
    colors.push_back(colors[1]);

    int ans = 0;

    for(int i = 0; i<n; i++) {
        if(colors[i] == colors[i+2] && colors[i] != colors[i+1]) {
            ans++;
        }
    }

    return ans;
}