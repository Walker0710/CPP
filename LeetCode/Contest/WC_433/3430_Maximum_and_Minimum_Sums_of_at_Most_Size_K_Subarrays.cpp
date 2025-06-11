#include <bits/stdc++.h>

using namespace std;

// << ,

long minMaxSubarraySum(vector<int> &nums, int k)
{
    long maximum = maxSubarraySum(nums, k, true);
    long minimum = maxSubarraySum(nums, k, false);
    return maximum - minimum;
}

long long maxSubarraySum(vector<int> &nums, int k, bool regular)
{
    const int sz = nums.size();
    // create a monotone decreasing deque
    deque<int> max_dq;
    long prefix_max = 0;
    long total = 0;
    for (int i = 0; i < sz; i++)
    {
        // to get the minimum Subarray Sum we flip the sign of each element in the array, then flip the output
        if (!regular)
        {
            nums[i] *= -1;
        }
        // if this element is larger than a leftward element, then that leftward element will never contribute
        // to the array maximum and it, along with its contribution should be replaced
        while (!max_dq.empty() && nums[max_dq.back()] < nums[i])
        {
            // remove the element
            int old = max_dq.back();
            max_dq.pop_back();
            if (!max_dq.empty())
            {
                // remove the contribution to the prefix if there was one
                // note the left most element does not contribute to the prefix but its contribution is floating
                // based on how many elements are to the left, and how many fit within the k window
                prefix_max -= (long)(old - max_dq.back()) * nums[old];
            }
        }
        // if the deque is not empty, then adding the current element will not contribute to the entire span
        // we add the contribution to the prefix based on the number of indices the max will contribute to
        if (!max_dq.empty())
        {
            prefix_max += (long)(i - max_dq.back()) * nums[i];
        }
        // add the element to the dequeu, the element is guaranteed to contribute to at least a singleton subarray
        max_dq.push_back(i);
        // remove any element that falls outside the k window
        if (max_dq.front() + k == i)
        {
            // the leftmost element does not contribute to the prefix but the one after it does
            // and that has to be cleared as the new leftmost element becoems floating
            int old = max_dq.front();
            max_dq.pop_front();
            if (!max_dq.empty())
            {
                prefix_max -= (long)(max_dq.front() - old) * nums[max_dq.front()];
            }
        }
        // calculate the floating contribution from the leftmost element
        long left_contribution = (long)(max_dq.front() - max(-1, i - k)) * nums[max_dq.front()];
        // then add the prefix sum of maximums
        total += prefix_max + left_contribution;
    }
    return total;
}