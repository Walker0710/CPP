#include <bits/stdc++.h>

using namespace std;

// << ,

int sumSquare(int n)
{
    int ans = 0;

    while (n != 0)
    {
        int digi = n % 10;
        ans += digi * digi;
        n /= 10;
    }

    return ans;
}

bool isHappy(int n)
{
    unordered_set<int> visi;

    while (n != 1)
    {
        if (visi.find(n) != visi.end())
        {
            return false;
        }

        visi.insert(n);
        n = sumSquare(n);
    }

    return true;
}
