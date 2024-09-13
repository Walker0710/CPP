#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <limits.h>
#include <map>
#include <unordered_set>

using namespace std;

// << ,

// 1st but not for shortest path
bool oneDiff(string beginWord, string value)
{
    int c = 0;

    for (int i = 0; i < beginWord.length(); i++)
        c += (beginWord[i] != value[i]);

    return c == 1;
}

void solve(unordered_set<string> rec, string beginWord, string endWord, unordered_map<string, bool> visi, vector<string> &toPush, vector<vector<string>> &ans)
{
    visi[beginWord] = true;

    if (beginWord == endWord)
    {
        ans.push_back(toPush);
        return;
    }

    for (const auto &value : rec)
    {
        if (!visi[value] && oneDiff(beginWord, value))
        {
            toPush.push_back(value);
            solve(rec, value, endWord, visi, toPush, ans);
            toPush.pop_back();
        }
    }
    visi[beginWord] = false;
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
{

    unordered_set<string> rec;
    bool flag = false;

    for (int i = 0; i < wordList.size(); i++)
    {

        if (wordList[i] == endWord)
            flag = true;

        rec.insert(wordList[i]);
    }

    if (!flag)
        return {};

    unordered_map<string, bool> visi;
    vector<vector<string>> ans;
    vector<string> toPush;
    toPush.push_back(beginWord);

    solve(rec, beginWord, endWord, visi, toPush, ans);

    return ans;
}

// 2nd
void backtrack(const string &currentWord, const string &beginWord, unordered_map<string, vector<string>> &adj, vector<string> &path, vector<vector<string>> &res)
{
    if (currentWord == beginWord)
    {
        vector<string> result = path;
        reverse(result.begin(), result.end());
        res.push_back(result);
        return;
    }
    for (const string &nextWord : adj[currentWord])
    {
        path.push_back(nextWord);
        backtrack(nextWord, beginWord, adj, path, res);
        path.pop_back();
    }
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
{
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    
    if (wordSet.find(endWord) == wordSet.end())
    return {};

    unordered_map<string, vector<string>> adj;
    unordered_set<string> visited;
    queue<string> q;
    q.push(beginWord);
    visited.insert(beginWord);
    bool found = false;

    while (!q.empty() && !found)
    {
        int levelSize = q.size();
        unordered_set<string> currentLevelVisited;
        for (int i = 0; i < levelSize; ++i)
        {
            string currentWord = q.front();
            q.pop();
            string tempWord = currentWord;

            for (int j = 0; j < currentWord.size(); ++j)
            {
                char originalChar = currentWord[j];
                for (char c = 'a'; c <= 'z'; ++c)
                {
                    if (c == originalChar)
                        continue; // Skip if character is same as original
                    currentWord[j] = c;
                    if (wordSet.find(currentWord) != wordSet.end())
                    {
                        if (currentWord == endWord)
                            found = true;
                        if (visited.find(currentWord) == visited.end())
                        {
                            if (currentLevelVisited.find(currentWord) == currentLevelVisited.end())
                            {
                                q.push(currentWord);
                                currentLevelVisited.insert(currentWord);
                            }
                            adj[currentWord].push_back(tempWord);
                        }
                    }
                }
                currentWord[j] = originalChar;
            }
        }
        visited.insert(currentLevelVisited.begin(), currentLevelVisited.end());
    }

    vector<vector<string>> res;
    if (found)
    {
        vector<string> path = {endWord};
        backtrack(endWord, beginWord, adj, path, res);
    }
    return res;
}
