#include <bits/stdc++.h>

using namespace std;

// << ,

int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f)
{
    if (a == e && !(a == c && d > min(b, f) && d < max(b, f)))
    return 1;

    if (b == f && !(b == d && c > min(a, e) && c < max(a, e)))
    return 1;

    if (c + d == e + f && !(c + d == a + b && a > min(c, e) && a < max(c, e)))
    return 1;

    if (c - d == e - f && !(c - d == a - b && a > min(c, e) && a < max(c, e)))
    return 1;

    return 2;
}