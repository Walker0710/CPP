#include <bits/stdc++.h>
using namespace std;

void computeLPSArray(string& pat, int M, vector<int>& lps)
{
    // Length of the previous longest prefix suffix
    int len = 0;

    // lps[0] is always 0
    lps[0] = 0;

    // loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            if (len != 0) {
                len = lps[len - 1];
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Prints occurrences of pat in txt
vector<int> KMPSearch(string& pat, string& txt)
{
    int M = pat.length();
    int N = txt.length();

    // Create lps[] that will hold the longest prefix suffix
    // values for pattern
    vector<int> lps(M);

    vector<int> result;

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);

    int i = 0; // index for txt
    int j = 0; // index for pat
    while ((N - i) >= (M - j)) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == M) {
            result.push_back(i - j + 1);
            j = lps[j - 1];
        }

        // Mismatch after j matches
        else if (i < N && pat[j] != txt[i]) {

            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return result;
}

int main()
{
    string txt = "geeksforgeeks";
    string pat = "geeks";
    vector<int> result = KMPSearch(pat, txt);

    // Print all the occurance (1-based indices)
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}







int countMatchingSubarrays(vector<int> &nums, vector<int> &pattern)
{

    int n = nums.size();
    vector<int> nums2(n - 1);

    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] < nums[i + 1])
        {
            nums2[i] = 1;
        }

        else if (nums[i] > nums[i + 1])
        {
            nums2[i] = -1;
        }

        else if (nums[i] == nums[i + 1])
        {
            nums2[i] = 0;
        }
    }

    vector<int> yoo = KMPSearch(pattern, nums2);

    return yoo.size();
}






int longestPrefixSuffix(string &s)
{
    int i = 1;
    int j = 0;
    int n = s.length();

    vector<int> lps(n, 0);

    while (i < n)
    {
        if (s[i] == s[j])
        {
            j++;
            lps[i] = j;
            i++;
        }

        else
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }

            else
            {
                i++;
            }
        }
    }

    return lps[n - 1];
}




int maximumLength(std::string s)
{
    int n = s.length();
    std::vector<std::vector<int>> freq(26, std::vector<int>(n + 1, 0));
    char pre = s[0];

    int len = 1;
    freq[s[0] - 'a'][1] = 1;
    int ans = -1;

    for (int i = 1; i < n; i++)
    {
        char cur = s[i];
        
        if (cur == pre)
        {
            len++;
            freq[cur - 'a'][len] += 1;
        }
        else
        {
            freq[cur - 'a'][1] += 1;
            pre = cur;
            len = 1;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        int preSum = 0;
        
        for (int j = n; j >= 1; j--)
        {
            preSum += freq[i][j];
        
            if (preSum >= 3)
            {
                ans = std::max(ans, j);
                break;
            }
        }
    }

    return ans;
}