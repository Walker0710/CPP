#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

//tle
class compare
{
public:
    bool operator()(vector<int> a, vector<int> b)
    {
        return a[0] + a[1] < b[0] + b[1];
    }
};

vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
{
    vector<vector<int>> pairs;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (i < nums1.size() && j < nums2.size())
            { // Bounds check added
                vector<int> a = {nums1[i], nums2[j]};
                pairs.push_back(a);
            }
        }
    }

    priority_queue<vector<int>, vector<vector<int>>, compare> pq;

    for (int i = 0; i < k && i < pairs.size(); i++)
    { // Ensure k does not exceed pairs size
        pq.push(pairs[i]);
    }

    for (int i = k; i < pairs.size(); i++)
    {
        if (pairs[i][1] + pairs[i][0] < pq.top()[1] + pq.top()[0])
        {
            pq.pop();
            pq.push(pairs[i]);
        }
    }

    vector<vector<int>> ans;
    for (int i = 0; i < k && !pq.empty(); i++)
    { // Ensure pq is not empty
        vector<int> toPush = pq.top();
        pq.pop();
        ans.push_back(toPush);
    }

    return ans;
}


//yo
vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < nums1.size(); ++i)
    {
        pq.push({nums1[i] + nums2[0], 0});
    }

    vector<vector<int>> ans(k, vector<int>(2, 0));
    int i = 0;

    // since k can be less than max pairs possible, checking pq.empty()
    while (i < k && !pq.empty())
    {
        int sum = pq.top().first;
        int pos = pq.top().second;
        pq.pop();

        ans[i][0] = sum - nums2[pos];
        ans[i][1] = nums2[pos];

        if (pos < nums2.size() - 1)
        {
            pq.push({sum - nums2[pos] + nums2[pos + 1], pos + 1});
        }
        i++;
    }

    return ans;
}