#include <bits/stdc++.h>

using namespace std;

// << ,

// C++ Program to find the next greater number same set of
// digits

string nextPermutation(string N)
{
    // If number of digits is 1 then just return the vector
    if (N.length() == 1) {
        return "Not Possible";
    }

    // Start from the right most digit and find the first
    // digit that is smaller than the digit next to it.
    int i = 0;
    for (i = N.length() - 1; i > 0; i--) {
        if (N[i] > N[i - 1])
            break;
    }

    // If i is 0 that means elements are in decreasing order
    // Therefore, no greater element possible
    if (i == 0) {
        return "Not Possible";
    }

    // Find the smallest digit on right side of (i-1)'th
    // digit that is greater than N[i-1]
    for (int j = N.length() - 1; j >= i; j--) {
        if (N[i - 1] < N[j]) {
            // Swap the found smallest digit i.e. N[j]
            // with N[i-1]
            swap(N[i - 1], N[j]);
            break;
        }
    }

    // Reverse the digits after (i-1) because the digits
    // after (i-1) are in decreasing order and thus we will
    // get the smallest element possible from these digits
    reverse(N.begin() + i, N.end());

    return N;
}

int main()
{
    // Sample Input
    string N = "218765";

    // Function Call
    cout << nextPermutation(N);
}