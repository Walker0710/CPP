#include <bits/stdc++.h>

using namespace std;

// << ,

long long sumDigitDifferences(vector<int> &nums)
{
    long long n = nums.size();

    if (n < 2)
        return 0;

    int numDigits = to_string(nums[0]).size();
    vector<vector<long long>> digitCount(numDigits, vector<long long>(10, 0));

    for (int num : nums)
    {
        string s = to_string(num);
        for (int i = 0; i < numDigits; ++i)
        {
            digitCount[i][s[i] - '0']++;
        }
    }

    long long totalDifference = 0;

    for (int i = 0; i < numDigits; ++i)
    {
        for (int d1 = 0; d1 < 10; ++d1)
        {
            for (int d2 = 0; d2 < 10; ++d2)
            {
                if (d1 != d2)
                {
                    totalDifference += digitCount[i][d1] * digitCount[i][d2];
                }
            }
        }
    }

    return totalDifference / 2;
}