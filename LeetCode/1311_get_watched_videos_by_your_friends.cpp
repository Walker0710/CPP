#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <limits.h>
#include <algorithm>

using namespace std;

// 1st approch
void bfs(unordered_map<int, bool> &visited, vector<vector<string>> &watchedVideos, vector<vector<int>> &friends, int id, int level, vector<string> &ans)
{
    unordered_map<int, vector<int>> levelMap;
    int minLvl = 0;

    queue<int> q;
    q.push(id);
    visited[id] = true;
    q.push(-1);

    levelMap[minLvl++].push_back(id);

    while (!q.empty())
    {

        int frntNode = q.front();
        q.pop();

        if (frntNode == -1)
        {

            minLvl++;

            if (!q.empty())
                q.push(-1);

            continue;
        }

        for (auto i : friends[frntNode])
        {

            if (!visited[i])
            {

                q.push(i);
                visited[i] = true;
                levelMap[minLvl].push_back(i);
            }
        }
    }

    vector<int> yo = levelMap[level];

    set<string> toPush;

    for (int i = 0; i < yo.size(); i++)
    {

        vector<string> kisneKon = watchedVideos[yo[i]];

        for (int j = 0; j < kisneKon.size(); j++)
        {

            toPush.insert(kisneKon[j]);
        }
    }

    for (auto it = toPush.begin(); it != toPush.end(); it++)
    {

        ans.push_back(*it);
    }
}

vector<string> watchedVideosByFriends(vector<vector<string>> &watchedVideos, vector<vector<int>> &friends, int id, int level)
{

    unordered_map<int, bool> visited;
    vector<string> ans;

    bfs(visited, watchedVideos, friends, id, level, ans);

    return ans;
}

// 2nd
vector<string> watchedVideosByFriends(vector<vector<string>> &watchedVideos, vector<vector<int>> &friends, int id, int level)
{
    unordered_map<string, int> freq;
    vector<bool> visited(friends.size(), false);
    queue<int> q;
    q.push(id);
    visited[id] = true;

    while (!q.empty() && level-- > 0)
    {
        for (int i = q.size(); i > 0; i--)
        {
            int f = q.front();
            q.pop();
            for (int j : friends[f])
            {
                if (!visited[j])
                {
                    q.push(j);
                    visited[j] = true;
                }
            }
        }
    }

    while (!q.empty())
    {
        for (string &video : watchedVideos[q.front()])
            freq[video]++;
        q.pop();
    }

    vector<pair<int, string>> pairs;
    
    for (auto &p : freq)
    pairs.push_back({p.second, p.first});
    
    sort(pairs.begin(), pairs.end());
    
    vector<string> res;
    
    for (auto &p : pairs)
    res.push_back(p.second);
    
    return res;
}
