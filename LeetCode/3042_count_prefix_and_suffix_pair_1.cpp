#include <iostream>
#include <vector>
#include <limits.h>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int isPrefixAndSuffix(string str1, string str2)
{
    if (str1.size() <= str2.size())
    {
        int j = 0, i = 0;
        while (i < str1.size())
        {
            if (str1[i++] != str2[j++])
                return 0;
            if (i == str1.size())
                break;
        }

        i = str1.size() - 1;
        j = str2.size() - 1;
        while (i >= 0)
        {
            if (str1[i--] != str2[j--])
                return 0;
            if (i < 0)
                break;
        }
        return 1;
    }
    return 0;
}

int countPrefixSuffixPairs(vector<string> &words)
{
    int ans = 0;
    for (int i = 0; i < words.size() - 1; i++)
    {
        for (int j = i + 1; j < words.size(); j++)
        {
            ans += isPrefixAndSuffix(words[i], words[j]);
        }
    }
    return ans;
}