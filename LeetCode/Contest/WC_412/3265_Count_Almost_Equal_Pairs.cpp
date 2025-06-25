#include <bits/stdc++.h>

using namespace std;

// << ,

bool check(int num1, int num2)
{
    string first = to_string(num1);
    string second = to_string(num2);

    // Pad the shorter string with leading zeros
    while (first.length() < second.length())
    first = "0" + first;
    
    while (second.length() < first.length())
    second = "0" + second;

    int diffCount = 0;
    int firstMismatch = -1, secondMismatch = -1;

    for (int i = 0; i < first.length(); i++)
    {
        if (first[i] != second[i])
        {
            diffCount++;

            if (diffCount == 1)
            {
                firstMismatch = i;
            }
            else if (diffCount == 2)
            {
                secondMismatch = i;
            }
            else
            {
                return false;
            }
        }
    }

    if (diffCount == 2)
    {
        swap(first[firstMismatch], first[secondMismatch]);
    }

    return first == second;
}

int countPairs(vector<int> &nums)
{
    int count = 0;
    int n = nums.size();
 
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] == nums[j] || check(nums[i], nums[j]))
            {
                count++;
            }
        }
    }
 
    return count;
}