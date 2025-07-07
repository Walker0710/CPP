#include <bits/stdc++.h>

using namespace std;

// << ,

string winningPlayer(int x, int y)
{
    bool flag = true;

    while (x >= 1 && y >= 4)
    {
        flag = !flag;
        x--;
        y = y - 4;
    }

    if(flag)
    return "Bob";

    return "Alice";    
}