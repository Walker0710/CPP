#include <bits/stdc++.h>

using namespace std;

// << ,

long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int k)
{
    unordered_map<int, int> count;
    long long result = 0;

    for (int y : nums2)
    {
        count[y * k]++;
    }

    for (int x : nums1)
    {
        for (int d = 1; 1LL * d * d <= x; ++d)
        {
            if (x % d == 0)
            {
                if (count.count(d))
                {
                    result += count[d];
                }

                int other = x / d;

                if (other != d && count.count(other))
                {
                    result += count[other];
                }
            }
        }
    }
    return result;
}


vector<int> getPrimeFactors(int x)
{
    vector<int> primeFactors;

    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            primeFactors.push_back(i);

            while (x % i == 0)
            {
                x /= i;
            }
        }
    }

    if (x != 1)
    {
        primeFactors.push_back(x);
    }

    return primeFactors;
}