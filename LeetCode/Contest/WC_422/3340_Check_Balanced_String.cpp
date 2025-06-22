#include <bits/stdc++.h>

using namespace std;

// << ,

bool isBalanced(string num)
{
    int even = 0;
    int odd = 0;

    for(int i = 0; i<num.length(); i++) {
        if(i%2 == 0)
        even = even + (num[i] - '0');

        if(i%2 == 1)
        odd = odd + (num[i] - '0');
    }

    return even == odd;
}