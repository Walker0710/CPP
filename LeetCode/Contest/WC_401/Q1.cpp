#include <bits/stdc++.h>

using namespace std;

// << ,

int numberOfChild(int n, int k)
{
    int ele = k / (n - 1);
    int mod = k % (n - 1);
    
    return ele % 2 ? n - 1 - mod : mod;
}