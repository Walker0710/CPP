#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

bool check(vector<int>&first, vector<int>& second) {

    if(first[0] >= second[0] && first[1] >= second[1] && first[2] >= second[2]) 
    return true;

    return false;
}

int solve(vector<vector<int>>& a)
{
    int n = a.size();
    vector<int> next(n+1, 0);
    vector<int> current(n+1, 0);

    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr-1; prev >= -1; prev--)
        {  
            int include = 0;

            if (prev == -1 || check(a[curr], a[prev]))
            include = a[curr][2] + next[curr+1];

            int exclude = 0 + next[prev+1];

            current[prev + 1] = max(include, exclude);   
        }
        next = current;
    }
    return next[0];
}

int maxHeight(vector<vector<int>>& cuboids) {

    //sabse badi wli side ko height lenge
    for(auto &a:cuboids) 
    sort(a.begin(), a.end());

    sort(cuboids.begin(), cuboids.end());

    return solve(cuboids);
}