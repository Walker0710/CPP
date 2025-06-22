#include <bits/stdc++.h>

using namespace std;

// << ,

bool canAliceWin(int n)
{
    if(n < 10) {
        return false;
    }

    bool turn = true;
    int cnt = 10;

    while (n > 0)
    {
        if(n - cnt < 0 && turn)
        return false;

        else if(n - cnt < 0 && !turn) {
            return true;
        }

        n = n - cnt;
        turn = !turn;
        cnt--;
    }
    
    return !turn;
}