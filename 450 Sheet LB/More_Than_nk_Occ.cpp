#include <bits/stdc++.h>

using namespace std;

// << ,

int countOccurence(vector<int> &arr, int k)
{
    int n = arr.size();
    int x = n / k;

    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    int cnt = 0;

    for (auto i : freq)
    {
        if (i.second > x)
        {
            cnt++;
        }
    }

    return cnt;
}
