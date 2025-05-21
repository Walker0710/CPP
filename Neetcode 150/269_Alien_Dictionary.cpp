#include <bits/stdc++.h>

using namespace std;

// << ,

string foreignDictionary(vector<string> &words)
{
    unordered_map<char, unordered_set<char>> adj;
    unordered_map<char, int> inDegree;

    for (string &word : words)
    {
        for (char c : word)
        {
            if (inDegree.find(c) == inDegree.end())
                inDegree[c] = 0;
        }
    }

    for (int i = 0; i < words.size() - 1; i++)
    {
        string s1 = words[i];
        string s2 = words[i + 1];
        int len = min(s1.length(), s2.length());

        bool found = false;
        for (int j = 0; j < len; j++)
        {
            if (s1[j] != s2[j])
            {
                if (adj[s1[j]].find(s2[j]) == adj[s1[j]].end())
                {
                    adj[s1[j]].insert(s2[j]);
                    inDegree[s2[j]]++;
                }
                found = true;
                break;
            }
        }

        // Edge case: ["abc", "ab"] is invalid because ab must come before abc, which is impossible
        if (!found && s1.length() > s2.length())
            return "";
    }

    queue<char> q;
    for (auto &[c, deg] : inDegree)
    {
        if (deg == 0)
            q.push(c);
    }

    string res;
    while (!q.empty())
    {
        char char_ = q.front();
        q.pop();
        res += char_;
        for (char neighbor : adj[char_])
        {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0)
            {
                q.push(neighbor);
            }
        }
    }

    return res.size() == inDegree.size() ? res : "";
}
