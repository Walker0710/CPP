#include <bits/stdc++.h>

using namespace std;

// << ,

int maximumPrimeDifference(vector<int> &nums)
{
    vector<int> prime(100+1, 1);

    for (int i = 2; i * i < 100; i++)
    {
        if (prime[i] == 1)
        {
            for (int j = i * i; j <= 100; j = j + i)
            {
                prime[j] = 0;
            }
        }
    }

    prime[0] = 0;
    prime[1] = 0;

    int n = nums.size();

    int i = 0;
    int j = n-1;

    while (i < n && prime[nums[i]] == 0)
    {
        i++;
    }

    while (j>=0 && prime[nums[j]] == 0)
    {
        j--;
    }
    
    return j - i;
}