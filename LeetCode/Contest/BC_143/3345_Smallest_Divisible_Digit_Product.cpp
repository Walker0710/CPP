#include <bits/stdc++.h>

using namespace std;

// << ,

bool solve(int n, int t) {
    int pro = 1;

    while (n>0)
    {
        pro = pro*(n%10);
        n = n/10;
    }
    
    return pro%t == 0 ? 1 : 0;    
}

int smallestNumber(int n, int t)
{
    while (true)
    {
        if(solve(n, t)) {
            return n;
        }

        else {
            n++;
        }
    }
    return -1;
}