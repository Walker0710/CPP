#include <bits/stdc++.h>

using namespace std;

// << ,

bool checkTwoChessboards(string coordinate1, string coordinate2)
{
    char ch1 = coordinate1[0];
    int num1 = coordinate1[1];

    char ch2 = coordinate2[0];
    int num2 = coordinate2[1];

    if (((ch1 - 'a') % 2 == 0 && (ch2 - 'a') % 2 == 0) || ((ch1 - 'a') % 2 == 1 && (ch2 - 'a') % 2 == 1)) {
        return num1%2 == num2%2;
    }

    else if (((ch1 - 'a') % 2 == 1 && (ch2 - 'a') % 2 == 0) || ((ch1 - 'a') % 2 == 0 && (ch2 - 'a') % 2 == 1)) {
        return abs(num1%2 - num2%2);
    }

    return false;
}