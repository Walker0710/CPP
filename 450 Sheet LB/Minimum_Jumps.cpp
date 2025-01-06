#include <bits/stdc++.h>

using namespace std;

// << ,

int minJumps(vector<int> &arr)
{
    int n = arr.size();

    int i = 0;
    int ans = 0;

    while (i != n)
    {
        int yoo = arr[i];
        int maxi = 0;
        int maxIndex = 0;

        for (int j = i + 1; j <= i + yoo; j++)
        {
            int temp = arr[j] - (yoo - j);

            if (temp > maxi)
            {
                maxi = temp;
                maxIndex = j;
            }
        }

        i = maxIndex;
        ans++;
    }

    return ans;
}

int minJumps(vector<int> &arr)
{
    int n = arr.size();

    if (n <= 1)
    return 0;

    if (arr[0] == 0)
    return -1;

    int jumps = 0;
    int currEnd = 0;
    int farthest = 0;

    for (int i = 0; i < n - 1; i++)
    {
        farthest = max(farthest, i + arr[i]);

        if (i == currEnd)
        {
            jumps++;
            currEnd = farthest;

            if (currEnd >= n - 1)
                break;
        }

        if (currEnd <= i)
            return -1;
    }

    return jumps;
}
