#include <bits/stdc++.h>

using namespace std;

// << ,

int smallestNumber(int n)
{
    int b = log2(n) + 1; 
    return (1 << b) - 1; 
}