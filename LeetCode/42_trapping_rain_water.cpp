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

using namespace std;

//one case missing
vector<int> nextBiggerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {

        int curr = arr[i];

        while (s.top() != -1 && arr[s.top()] < curr)
        {
            s.pop();
        }

        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int trap(vector<int> &height)
{
    int ans = 0;
    vector<int> nextBig = nextBiggerElement(height, height.size());
    int i = 0;

    while (i < height.size())
    {
        if (nextBig[i] == -1)
        {
            i++;
            continue;
        }

        int next = nextBig[i];
        int width = next - i;
        int totalArea = height[i] * width;
        int j = i;

        while (j < next)
        {
            totalArea = totalArea - height[j];
            j++;
        }

        ans = ans + totalArea;
        i = next;
    }
    return ans;
}


//everything passed
int trap(vector<int> &height)
{
    int n = height.size();
    int water = 0;

    vector<int> leftMax(n);
    vector<int> rightMax(n);
    
    leftMax[0] = height[0];

    for (int i = 1; i < n; i++)
    leftMax[i] = max(height[i], leftMax[i - 1]);

    rightMax[n - 1] = height[n - 1];
    
    for (int i = n - 2; i >= 0; i--)
    rightMax[i] = max(height[i], rightMax[i + 1]);

    for (int i = 1; i < n - 1; i++)
    {
        water += min(rightMax[i], leftMax[i]) - height[i];
    }
    
    return water;
}