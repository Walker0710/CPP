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

// TLE
int candy(vector<int> &ratings)
{
    vector<int> candy(ratings.size(), 1);
    int n = ratings.size();

    while (--n)
    {
        for (int i = 0; i < ratings.size() - 1; i++)
        {
            if (ratings[i] < ratings[i + 1] && candy[i] >= candy[i + 1])
            {
                candy[i + 1]++;
            }

            if (ratings[i] > ratings[i + 1] && candy[i] <= candy[i + 1])
            {
                candy[i]++;
            }
        }
    }

    int sum = 0;

    for (int i = 0; i < ratings.size(); i++)
        sum += candy[i];

    return sum;
}

// yoo
int candy(vector<int> &ratings)
{
    int n = ratings.size();
    vector<int> candies(n, 1);

    for (int i = 1; i < n; ++i)
    {
        if (ratings[i] > ratings[i - 1])
        {
            candies[i] = candies[i - 1] + 1;
        }
    }

    for (int i = n - 2; i >= 0; --i)
    {
        if (ratings[i] > ratings[i + 1])
        {
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
    }

    int ans = 0;
    for (int candy : candies)
    {
        ans += candy;
    }
    return ans;
}