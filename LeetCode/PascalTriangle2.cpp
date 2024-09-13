#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>

using namespace std;

// my approch
void solveOpt(int rowIndex, int index, vector<int> &prev, vector<int> &curr)
{

    if (index == rowIndex)
        return;

    curr[0] = prev[0] = 1;

    for (int i = 1; i < index; i++)
    {

        int first = (i < prev.size()) ? prev[i] : 0;
        int sec = (i - 1 >= 0) ? prev[i - 1] : 0;

        curr[i] = first + sec;
    }

    curr[index] = 1;
    prev = curr;

    solveOpt(rowIndex, index + 1, prev, curr);
}

vector<int> getRow(int rowIndex)
{

    vector<int> prev(rowIndex + 1, 0);
    vector<int> curr(rowIndex + 1, 0);

    solveOpt(rowIndex, 1, prev, curr);
    return curr;
}

// someone's  approch
vector<int> getRow(int rowIndex)
{
    vector<int> ans(rowIndex + 1, 1);

    for (int i = 1; i <= rowIndex; i++)
    {
        for (int j = i - 1; j > 0; j--)
        {
            ans[j] += ans[j - 1];
        }
    }
    return ans;
}