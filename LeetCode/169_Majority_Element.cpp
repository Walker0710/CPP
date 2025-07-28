#include <bits/stdc++.h>

using namespace std;

// << ,

int majorityElement(vector<int> &nums)
{
    unordered_map<int, int> hash;
    int res = 0;
    int majority = 0;

    for (int n : nums)
    {
        hash[n] = 1 + hash[n];

        if (hash[n] > majority)
        {
            res = n;
            majority = hash[n];
        }
    }

    return res;
}


// n/2
int majorityElement(vector<int> &nums)
{
    int sum = 0;
    int cndi = -1;

    for (int i = 0; i < nums.size(); i++)
    {
        if (sum == 0)
        {
            cndi = nums[i];
            sum = 1;
        }

        else
        {
            if (nums[i] == cndi)
            {
                sum++;
            }

            else
            {
                sum--;
            }
        }
    }

    return cndi;
}



// n/3
vector<int> majorityElement(vector<int> &nums)
{
    int majority1 = 0;
    int majority2 = 0;
    int count1 = 0;
    int count2 = 0;

    for (const int num : nums)
    {
        if (num == majority1)
        {
            count1++;
        }

        else if (num == majority2)
        {
            count2++;
        }

        else if (count1 == 0)
        {
            majority1 = num;
            count1++;
        }

        else if (count2 == 0)
        {
            majority2 = num;
            count2++;
        }

        else
        {
            count1--;
            count2--;
        }
    }

    count1 = 0;
    count2 = 0;

    for (const int num : nums)
    {
        if (num == majority1)
        {
            count1++;
        }

        else if (num == majority2)
        {
            count2++;
        }
    }

    vector<int> res;

    if (count1 > nums.size() / 3)
    {
        res.push_back(majority1);
    }

    if (count2 > nums.size() / 3)
    {
        res.push_back(majority2);
    }

    return res;
}