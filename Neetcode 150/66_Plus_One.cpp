#include <bits/stdc++.h>

using namespace std;

// << ,

vector<int> plusOne(vector<int> &digits)
{
    int n = digits.size();
    int carry = 1;

    for(int i = n-1; i>=0; i--) {
        int yoo = digits[i] + carry;

        digits[i] = yoo%10;
        carry = yoo/10;

        if(carry == 0) {
            break;
        }
    }

    if(carry != 0) {
        digits.insert(digits.begin(), carry);
    }

    return digits;
}