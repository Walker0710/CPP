#include <bits/stdc++.h>

using namespace std;

// << ,

int reverse(int x)
{
    const int MIN = -2147483648;
    const int MAX = 2147483647;

    int res = 0;

    while (x != 0)
    {
        int digit = x % 10;
        x /= 10;

        if (res > MAX / 10 || (res == MAX / 10 && digit > MAX % 10))
            return 0;

        if (res < MIN / 10 || (res == MIN / 10 && digit < MIN % 10))
            return 0;

        res = (res * 10) + digit;
    }

    return res;
}

// BIT_MASK
int reverse(int x)
{
    int org = x;
    x = abs(x);
    string strX = to_string(x);
    reverse(strX.begin(), strX.end());
    long long res = stoll(strX);
    
    if (org < 0)
    {
        res *= -1;
    }
    
    if (res < -(1LL << 31) || res > (1LL << 31) - 1)
    {
        return 0;
    }
    
    return static_cast<int>(res);
}