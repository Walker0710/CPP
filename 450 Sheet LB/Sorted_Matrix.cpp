#include <bits/stdc++.h>

using namespace std;

// << ,

vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat)
{
    vector<int> ele;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            ele.push_back(Mat[i][j]);
        }
    }

    sort(ele.begin(), ele.end());
    int curr = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            Mat[i][j] = ele[curr];
            curr++;
        }
    }

    return Mat;
}