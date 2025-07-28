#include <bits/stdc++.h>

using namespace std;

// << ,

// hamesha check wle fn me extreme case dekhna like lastindex as stuff
int maxPointsInsideSquare(vector<vector<int>> &points, string s)
{
    int n = points.size();

    auto isValid = [&](int side)
    {
        unordered_set<char> tags;
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            int x = points[i][0];
            int y = points[i][1];

            if (max(abs(x), abs(y)) <= side)
            {
                if (tags.count(s[i]))
                return -1;
                
                tags.insert(s[i]);
                count++;
            }
        }

        return count;
    };

    int low = 0, high = 1e9;
    int ans = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int count = isValid(mid);

        if (count >= 0)
        {
            ans = count;
            low = mid + 1; 
        }
        else
        {
            high = mid - 1; 
        }
    }

    return ans;
}













#define ll long long

ll countLessThanOrEqualToX(vector<int> &coins, ll midX)
{
    int m = coins.size();
    // make the mask
    // i.e. if m = 3 (3,6,9) we need (1<<3)-1 = 111
    // with 111 we can try all possibilities
    // like 010 => 6, 110 => 3,6; 111=>3,6,9 and so on
    int allOnes = (1 << m) - 1;

    ll count = 0;

    // check for all the combinaiton
    for (int mask = 1; mask <= allOnes; mask++)
    {
        // for all the combination, get the lcm of set bits
        // check the count of set bits
        // if count is odd => add to contribution,
        // if count is even => subtract from contribution

        ll lcmOfSetBits = 1;

        // find lcm of that coins which are in mask
        for (int j = 0; j < m; j++)
        {
            if (mask & (1 << j))
            {
                lcmOfSetBits = lcm(lcmOfSetBits, coins[j]);
            }
        }

        // count -> odd -> add
        if (__builtin_popcount(mask) & 1)
        {
            count += (midX / lcmOfSetBits);
        }
        else
        {
            count -= (midX / lcmOfSetBits);
        }
    }
    return count;
}

long long findKthSmallest(vector<int> &coins, int k)
{
    // lower limit to start the binary search
    ll l = 1;

    // higher limit => max-coin = 25, maxk = 2*1e9
    // ~ 25*1e9 + 25 => round of to higher value
    ll r = 1e11;
    ll ans = 0;
    while (l <= r)
    {
        ll midX = (l + r) / 2;
        ll count = countLessThanOrEqualToX(coins, midX);
        if (count < k)
        {
            // no of elements less than or equal to x
            // is less than k
            // therefore move to right
            l = midX + 1;
        }
        else
        {
            ans = midX;
            r = midX - 1;
        }
    }

    return ans;
}








bool binarySearch(vector<int> &nums, vector<int> &changeIndices, int idx)
{
    unordered_map<int, int> last;

    for (int i = 0; i < idx; i++)
    {
        last[changeIndices[i]] = i;
    }

    if (last.size() != nums.size())
    return false;
    
    int cnt = 0;

    for (int i = 0; i < idx; i++)
    {
        if (i == last[changeIndices[i]])
        {
            if (cnt < nums[changeIndices[i] - 1])
            return false;

            else
            cnt -= nums[changeIndices[i] - 1];
        }

        else
        {
            cnt++;
        }
    }
    
    return true;
}

int earliestSecondToMarkIndices(vector<int> &nums, vector<int> &changeIndices)
{
    int n = nums.size();
    int m = changeIndices.size();

    int l = 0;
    int r = m + 1;

    while (l < r)
    {
        int mid = l + (r - l) / 2;

        if (binarySearch(nums, changeIndices, mid))
        {
            r = mid;
        }

        else
        {
            l = mid + 1;
        }
    }

    return r == m + 1 ? -1 : r;
}