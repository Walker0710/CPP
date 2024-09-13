#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <map>

using namespace std;

void subsequence(string &s, int index, string output, vector<string> &sequence)
{
    if (index == s.length())
    {
        if (output.length() > 0)
            sequence.push_back(output);
        return;
    }

    // exxlude
    subsequence(s, index + 1, output, sequence);

    // include
    output = output + s[index];
    subsequence(s, index + 1, output, sequence);
}

int numMatchingSubseq(string s, vector<string> &words)
{
    vector<string> sequence;
    subsequence(s, 0, "", sequence);

    unordered_set<string> map;

    for (auto i : words)
    {
        map.insert(i);
    }

    int ans = 0;

    for (auto i : sequence)
    {
        if (map.find(i) != map.end())
            ans++;
    }
    return ans;
}

// optmized
bool isSubsequence(const std::string &s, const std::string &word)
{
    int s_len = s.length(), word_len = word.length();
    int i = 0, j = 0;

    while (i < s_len && j < word_len)
    {
        if (s[i] == word[j])
        {
            j++;
        }
        i++;
    }

    return j == word_len;
}

int numMatchingSubseq(const std::string &s, const std::vector<std::string> &words)
{
    int ans = 0;
    unordered_set<string> map;

    for (const auto &word : words)
    {

        if (map.find(word) != map.end())
            ans++;

        else if (isSubsequence(s, word))
        {
            map.insert(word);
            ans++;
        }
    }
    return ans;
}

//extra oprimization
bool findFuntions(string &s, string t)
{
    int i = 0, j = 0, n = s.size(), m = t.size();
    while (j < n and i < m)
        if (s[j++] == t[i])
            i++;
 
    return (t.size() - i) == 0;
}

int numMatchingSubseq(string s, vector<string> &words)
{
    unordered_map<string, int> mp;

    for (auto &str : words)
        mp[str]++;


    int ans = 0;

    for (auto ok : mp)
        if (findFuntions(s, ok.first))
            ans += ok.second;

    return ans;
}