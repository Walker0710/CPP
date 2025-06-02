#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <stack>

using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{

    unordered_set<int> mark(nums2.begin(), nums2.end());
    vector<int> ans;

    for (int i = 0; i < nums1.size(); i++)
    {

        int index = mark.find(nums1[i]);
        if (mark[index + 1] > nums1[i])
        {

            ans.push_back(mark[index + 1]);
        }

        else
        {

            ans.push_back(-1);
        }
    }

    return ans;
}

int indexT(int k, vector<int> &nums2)
{

    int i = 0;

    while (nums2[i] != k)
    {

        i++;
    }

    return i;
}

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{

    unordered_map<int, int> maping;
    vector<int> ans;

    for (int i = 0; i < nums1.size(); i++)
    {

        int index = indexT(nums1[i], nums2);

        if (index + 1 < nums2.size())
        {

            maping[nums1[i]] = nums2[index + 1];
        }

        else
        {

            maping[nums1[i]] = INT32_MAX;
        }
    }

    for ()
    {
    }
}

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> map; // map for next greater element
    stack<int> st;
    for (int num : nums2)
    {
        while (!st.empty() && st.top() < num)
        { // Pop elements from stack and update map with next greater element
            map[st.top()] = num;
            st.pop();
        }
        st.push(num); // Push current element onto stack
    }
    for (int i = 0; i < nums1.size(); i++)
    {                                                        // Check if each element in nums1 has a next greater element in map
        nums1[i] = map.count(nums1[i]) ? map[nums1[i]] : -1; // Update element in nums1 with next greater element or -1
    }
    return nums1;
}
