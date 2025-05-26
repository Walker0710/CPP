#include <bits/stdc++.h>

using namespace std;

// << ,
double solve(double x, int n) {
    if(n == 0)
    return 1;

    double half = solve(x, n/2);
    
    return (n%2 == 0) ? half*half : x*half*half;
}

double myPow(double x, int n)
{
    if(x == 0)
    return 0;

    if(x == 1)
    return 1;

    double ans = solve(x, abs(n));

    return (n >= 0) ? ans : 1/ans;
}