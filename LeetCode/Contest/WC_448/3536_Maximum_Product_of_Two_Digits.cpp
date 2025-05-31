#include <bits/stdc++.h>

using namespace std;

// << ,

int maxProduct(int n)
{
    vector<int> yoo;

    while (n > 0)
    {
        yoo.push_back(n%10);
        n = n/10;
    }

    sort(yoo.rbegin(), yoo.rend());

    return yoo[0]*yoo[1];    
}