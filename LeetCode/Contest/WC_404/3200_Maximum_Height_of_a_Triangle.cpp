#include <bits/stdc++.h>

using namespace std;

// << ,

int solve(int red, int blue, bool yoo) {
    bool flag = yoo;
    int size = 0;
    
    for(int cnt = 1; cnt<1000; cnt++) 
    {
        if(flag && blue >= cnt) {
            blue = blue - cnt;
            size++;
            flag = !flag;
        }

        else if(!flag && red >= cnt) {
            red = red - cnt;
            size++;
            flag = !flag;
        }

        else {
            return size;
        }
    }

    return 0;
}

int maxHeightOfTriangle(int red, int blue)
{
    return max(solve(red, blue, true), solve(red, blue, false));
}