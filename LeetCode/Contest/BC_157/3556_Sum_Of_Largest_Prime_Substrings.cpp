#include <bits/stdc++.h>

using namespace std;

// << ,

bool isPrime(long long num)
{
    if (num < 2)
        return false;
    if (num == 2)
        return true;
    if (num % 2 == 0)
        return false;
    for (long long i = 3; i <= sqrt(num); i += 2)
        if (num % i == 0)
            return false;
    return true;
}

long long sumOfLargestPrimes(string s)
{
    long long n = s.length();
    unordered_set<long long> prime;

    for (long long i = 0; i < n; i++)
    {
        for (long long j = i; j < n; j++)
        {
            long long yoo = stoll(s.substr(i, j - i + 1));

            if (isPrime(yoo))
            {
                prime.insert(yoo);
            }
        }
    }

    set<long long> sortedPrimes(prime.begin(), prime.end());

    long long ans = 0;
    long long cnt = 0;

    for (auto it = sortedPrimes.rbegin(); it != sortedPrimes.rend() && cnt < 3; ++it)
    {
        ans += *it;
        cnt++;
    }

    return ans;
}

