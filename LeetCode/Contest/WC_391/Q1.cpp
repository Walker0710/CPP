#include <bits/stdc++.h>

using namespace std;

// << ,

int sumOfTheDigitsOfHarshadNumber(int x)
{
    int sum = 0;
    int temp = x;

    while (x)
    {
        sum = sum + x%10;
        x = x/10;
    }
    
    if(team%sum == 0)
    return sum;

    return -1;
}