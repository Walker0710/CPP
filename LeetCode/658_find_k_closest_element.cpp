#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <unordered_map>
#include <algorithm>

using namespace std;

class compare
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        if (a.second == b.second)
        {
            return a.first > b.first;
        }
        return a.second > b.second;
    }
};

int BS(vector<int> &arr, int x)
{
    int diff = INT_MAX;
    int index = 0;

    int s = 0;
    int e = arr.size() - 1;

    while (e >= s)
    {
        int mid = (s + e) / 2;

        if (x == arr[mid])
        {
            return mid;
        }

        else if (arr[mid] < x)
        {
            s = mid + 1;
        }

        else
        {
            e = mid - 1;
        }

        if (abs(x - arr[mid]) < diff)
        {
            index = mid;
            diff = abs(x - arr[mid]);
        }

        else if (abs(x - arr[mid]) == diff && arr[mid] < arr[index])
        {
            index = mid;
        }
    }
    return index;
}

int binarySearch(vector<int> arr, int n, int x)
{
    if (arr[0] > x)
        return 0;
    int s = 0, e = n - 1;
    int mid;
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            s = mid + 1;
        else
            e = mid - 1;
    }
    return s;
}

vector<int> findClosestElements(vector<int> &arr, int k, int x)
{

    int index = BS(arr, x);
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> minHeap;

    for (int i = 0; i <= k; i++)
    {
        if (index + i < arr.size())
        {
            pair<int, int> a = {arr[index + i], abs(arr[index] - arr[index + i])};
            minHeap.push(a);
        }

        if (index - i >= 0)
        {
            pair<int, int> a = {arr[index - i], abs(arr[index] - arr[index - i])};
            minHeap.push(a);
        }
    }

    vector<int> ans;

    while (k != 0)
    {
        pair<int, int> a = minHeap.top();
        minHeap.pop();

        ans.push_back(a.first);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

// noob approch
vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    vector<int> ans;
    int n = arr.size();

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    for (int i = 0; i < n; i++)
    {
        q.push({abs(x - arr[i]), arr[i]});
    }

    while (k--)
    {
        ans.push_back(q.top().second);
        q.pop();
    }

    sort(ans.begin(), ans.end());
    return ans;
}