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