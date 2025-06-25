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
    int firstMismatch = -1;
    int secondMismatch = -1;
    int thirdMismatch = -1;
    int fourthMismatch = -1;

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

            else if (diffCount == 3)
            {
                thirdMismatch = i;
            }

            else if (diffCount == 4)
            {
                fourthMismatch = i;
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

        return first == second;
    }

    if (diffCount == 4)
    {
        bool ans = false;

        // 1-2
        swap(first[firstMismatch], first[secondMismatch]);
        swap(first[thirdMismatch], first[fourthMismatch]);

        ans = ans | first == second;

        swap(first[firstMismatch], first[secondMismatch]);
        swap(first[thirdMismatch], first[fourthMismatch]);

        // 1-3
        swap(first[firstMismatch], first[thirdMismatch]);
        swap(first[secondMismatch], first[fourthMismatch]);

        ans = ans | first == second;

        swap(first[firstMismatch], first[thirdMismatch]);
        swap(first[secondMismatch], first[fourthMismatch]);

        // 1-4
        swap(first[firstMismatch], first[fourthMismatch]);
        swap(first[secondMismatch], first[thirdMismatch]);

        ans = ans | first == second;

        return ans;
    }

    return false;
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

















const int N = 1e7;
int cnt[N];

inline int MakeNumber(vector<int> &digits)
{
    int ans = 0;
    for (auto it = digits.rbegin(); it != digits.rend(); it++)
        ans = (ans * 10) + *it;
    return ans;
}

int countPairs(vector<int> &nums)
{
    memset(cnt, 0, sizeof(cnt));
    int ans = 0;
    int n = 7;
    vector<int> digits(7, 0);

    for (auto i : nums)
    {
        ans += cnt[i];

        int ind = 0;
        while (i)
        {
            digits[ind++] = i % 10;
            i /= 10;
        }
        while (ind < 7)
            digits[ind++] = 0;

        unordered_set<int> all;
        for (int l1 = 0; l1 < n; l1++)
        {
            for (int r1 = l1 + 1; r1 < n; r1++)
            {
                swap(digits[l1], digits[r1]);
                all.insert(MakeNumber(digits));
                swap(digits[l1], digits[r1]);

                for (int l2 = 0; l2 < n; l2++)
                {
                    for (int r2 = l2 + 1; r2 < n; r2++)
                    {
                        swap(digits[l1], digits[r1]);
                        swap(digits[l2], digits[r2]);

                        all.insert(MakeNumber(digits));

                        swap(digits[l2], digits[r2]);
                        swap(digits[l1], digits[r1]);
                    }
                }
            }
        }
        for (auto it : all)
            cnt[it]++;
    }
    return ans;
}