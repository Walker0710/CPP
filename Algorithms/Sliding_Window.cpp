#include <bits/stdc++.h>

using namespace std;

// << ,

int numberOfSubstrings(string s, int k)
{
    int ans = 0;
    int l = 0;
    unordered_map<char, int> d;

    for (char c : s)
    {
        d[c]++;
        while (d[c] == k)
        {
            d[s[l]]--;
            l++;
        }
        ans += l;
    }

    return ans;
}

int countOfSubstrings(string word, int k)
{
    int frequencies[2][128] = {};
    frequencies[0]['a'] = frequencies[0]['e'] = frequencies[0]['i'] = frequencies[0]['o'] = frequencies[0]['u'] = 1;

    int response = 0;
    int currentK = 0, vowels = 0, extraLeft = 0, left = 0;

    for (int right = 0; right < word.length(); right++)
    {
        char rightChar = word[right];

        if (frequencies[0][rightChar])
        {
            if (++frequencies[1][rightChar] == 1)
                vowels++;
        }
        else
        {
            currentK++;
        }

        while (currentK > k)
        {
            char leftChar = word[left++];
            if (frequencies[0][leftChar])
            {
                if (--frequencies[1][leftChar] == 0)
                    vowels--;
            }
            else
            {
                currentK--;
            }
            extraLeft = 0;
        }

        while (vowels == 5 && currentK == k && left < right && frequencies[0][word[left]] && frequencies[1][word[left]] > 1)
        {
            extraLeft++;
            frequencies[1][word[left++]]--;
        }

        if (currentK == k && vowels == 5)
        {
            response += (1 + extraLeft);
        }
    }

    return response;
}






long long validSubstringCount(string word1, string word2)
{
    vector<int> freq(26, 0);
    int cnt = 0;
 
    for (char ch : word2)
    {
        if (freq[ch - 'a'] == 0)
        {
            cnt++;
        }
        freq[ch - 'a']++;
    }
 
    long long j = 0, ans = 0;
 
    for (long long i = 0; i < word1.size(); i++)
    {
        if (--freq[word1[i] - 'a'] == 0)
        {
            cnt--;
        }
 
        while (cnt == 0)
        {
            ans += (word1.size() - i);
            if (++freq[word1[j] - 'a'] == 1)
            {
                cnt++;
            }
            j++;
        }
    }
 
    return ans;
}










int countKConstraintSubstrings(string s, int k)
{
    int l = 0, r = 0;
    int one = 0, zero = 0;
    int ans = 0;

    while (r < s.size())
    {
        if (s[r] == '0')
            zero++;
        else
            one++;

        while (zero > k && one > k)
        { // Both exceed k, so we need to shrink the window
            if (s[l] == '0')
                zero--;
            else
                one--;
            l++;
        }

        ans += (r - l + 1); // All substrings ending at r and starting from l to r are valid
        r++;
    }

    return ans;
}













long long countSubarrays(vector<int> &nums, int k)
{
    return atLeastK(nums, k) - atLeastK(nums, k + 1);
}

long long atLeastK(vector<int> &nums, int k)
{
    long long ans = 0;
    vector<int> temp(32, 0);

    int l = 0;
    for (int r = 0; r < nums.size(); r++)
    {
        for (int i = 0; i < 32; i++)
        {
            if ((1 << i) & nums[r])
            {
                temp[i]++;
            }
        }

        while ((r - l + 1) > 0 && calc(temp, r - l + 1) < k)
        {
            for (int i = 0; i < 32; i++)
            {
                if ((1 << i) & nums[l])
                {
                    temp[i]--;
                }
            }
            l++;
        }

        ans += (r - l + 1);
    }

    return ans;
}

// function to calculate the AND from frequency vector
int calc(vector<int> &temp, int w)
{
    int ans = 0;

    for (int i = 0; i < 32; i++)
    {
        if (temp[i] == w)
        ans += (1 << i);
    }

    return ans;
}












int minimumDifference(vector<int> &nums, int k)
{
    unordered_set<int> st1, st2;

    for (int i = 0; i < nums.size(); i++)
    {
        unordered_set<int> curr;
        curr.insert(nums[i]);

        for (int val : st2)
        {
            curr.insert(val | nums[i]);
        }

        for (auto x : st2)
        {
            st1.insert(x);
        }

        st2 = curr;
    }

    for (auto x : st2)
    st1.insert(x);

    int mini = INT_MAX;
    
    for (auto x : st1)
    {
        mini = min(mini, abs(k - x));
    }

    return mini;
}