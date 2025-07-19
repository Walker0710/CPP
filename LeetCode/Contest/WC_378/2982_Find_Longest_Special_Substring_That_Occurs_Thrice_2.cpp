#include <bits/stdc++.h>

using namespace std;

// << ,

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