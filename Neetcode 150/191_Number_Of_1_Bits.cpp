#include <bits/stdc++.h>

using namespace std;

// << ,

int hammingWeight(int n)
{
    int res = 0;

    for(int i = 0; i<32; i++) {
        if((1 << i) & n) {
            res++;
        }
    }

    return res;
}


int hammingWeight(uint32_t n) {
    int res = 0;

    while (n) {
        n &= (n - 1); // removes one 1 every time
        res++;
    }
    
    return res;
}