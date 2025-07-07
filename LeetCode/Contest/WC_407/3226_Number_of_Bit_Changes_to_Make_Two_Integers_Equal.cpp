#include <bits/stdc++.h>

using namespace std;

// << ,

int minChanges(int n, int k)
{
    int ans = 0;

    for(int i = 0; i<32; i++) {
        int fir = (n >> i) & 1;
        int sec = (k >> i) & 1;

        if(fir == 1 && sec == 0) 
        ans++;

        else if(fir == 0 && sec == 1)
        return -1;
    }

    return ans;
}