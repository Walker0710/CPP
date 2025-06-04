#include <bits/stdc++.h>

using namespace std;

// << ,

int maxContainers(int n, int w, int maxWeight)
{
    if(n*n*w <= maxWeight) {
        return n*n;
    }

    else {
        return (maxWeight/w);
    }
}