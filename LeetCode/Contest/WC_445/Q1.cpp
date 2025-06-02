#include <bits/stdc++.h>

using namespace std;

// << ,

int findClosest(int x, int y, int z)
{
    int one = abs(x - z);
    int two = abs(y - z);

    if (one > two)
        return 2;

    else if (two > one)
        return 1;

    else
        return 0;
}