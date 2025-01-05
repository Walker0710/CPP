#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <limits.h>
#include <map>
#include <unordered_set>

using namespace std;

// << ,

pair<int, int> getMinMax(vector<int> arr)
{
    int mini = INT_MAX;
    int maxi = INT_MIN;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < mini)
        {
            mini = arr[i];
        }

        if (arr[i] > maxi)
        {
            maxi = arr[i];
        }
    }

    return {mini, maxi};
}