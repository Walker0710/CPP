#include <bits/stdc++.h>

using namespace std;

// << ,

int areaOfMaxDiagonal(vector<vector<int>> &d)
{
    int diag = 0;
    int area = 0;
    int n = d.size();

    for (int i = 0; i < n; i++)
    {
        int len = d[i][0];
        int wid = d[i][1];

        int currentDiag = len * len + wid * wid;

        if (currentDiag > diag)
        {
            area = len * wid;
            diag = currentDiag;
        }

        else if (currentDiag == diag && len * wid > area)
        {
            area = len * wid;
        }
    }

    return area;
}
