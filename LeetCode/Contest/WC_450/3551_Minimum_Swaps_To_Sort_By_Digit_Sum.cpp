#include <bits/stdc++.h>

using namespace std;

// << ,

int check(int yoo)
{
    int ans = 0;
    while (yoo != 0)
    {
        ans += yoo % 10;
        yoo /= 10;
    }
    return ans;
}

int minSwaps(vector<int> &nums)
{
    int n = nums.size();
    vector<pair<int, int>> withIndex(n);

    for (int i = 0; i < n; i++)
        withIndex[i] = {check(nums[i]), nums[i]};

    vector<pair<int, int>> sorted = withIndex;
    sort(sorted.begin(), sorted.end());

    for(int i = 0; i<n; i++) {
        cout << sorted[i].first << " " << sorted[i].second << endl;
    }

    unordered_map<int, int> indexMap;
    for (int i = 0; i < n; i++)
        indexMap[sorted[i].second] = i;

    vector<bool> visited(n, false);
    int swaps = 0;

    for (int i = 0; i < n; i++)
    {
        if (visited[i] || indexMap[nums[i]] == i)
            continue;

        int cycle_size = 0;
        int j = i;

        while (!visited[j])
        {
            visited[j] = true;
            j = indexMap[nums[j]];
            cycle_size++;
        }

        if (cycle_size > 1)
            swaps += cycle_size - 1;
    }

    return swaps;
}
