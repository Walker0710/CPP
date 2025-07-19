#include <bits/stdc++.h>

using namespace std;

// << ,

long long solve(long long start, long long finish, int limit, string curr)
{
    long long ans = 0;

    if (!curr.empty())
    {
        long long val = stoll(curr);

        if (val > finish)
        return 0;
        
        if (val >= start && curr.size() >= s.size() && curr.substr(curr.size() - s.size()) == s)
        {
            ans++;
        }
    }

    for (char ch = '0'; ch <= (char)(limit + '0'); ++ch)
    {
        if (curr.empty() && ch == '0')
        continue;

        ans += solve(start, finish, limit, curr + ch);
    }

    return ans;
}

string s;

long long numberOfPowerfulInt(long long start, long long finish, int limit, string s_)
{
    s = s_;
    return solve(start, finish, limit, "");
}