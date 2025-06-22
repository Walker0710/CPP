#include <bits/stdc++.h>

using namespace std;

// << ,

auto comp = [](vector<int> &a, vector<int> &b)
{
    if (a[2] == b[2])
    {
        if (a[1] == b[1])
            return a[0] < b[0];
        return a[1] < b[1];
    }
    return a[2] < b[2];
};

class TaskManager
{
public:
    unordered_map<int, pair<int, int>> mp;
    priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pq;

    TaskManager(vector<vector<int>> &tasks)
    {
        for(auto &t : tasks) {
            pq.push(t);
            mp[t[1]] = {t[0], t[2]};
        }
    }

    void add(int userId, int taskId, int priority)
    {
        pq.push({userId, taskId, priority});
        mp[taskId] = {userId, priority};
    }

    void edit(int taskId, int newPriority)
    {
        pair<int, int> yoo = mp[taskId];

        mp[taskId] = {yoo.first, newPriority};
        pq.push({yoo.first, taskId, newPriority});
    }

    void rmv(int taskId)
    {
        mp[taskId].second = -1;
    }

    int execTop()
    {
        while(!pq.empty() && mp[pq.top()[1]].second != pq.top()[2])
        pq.pop();

        if(pq.empty())
        return -1;

        vector<int> t = pq.top();
        mp[t[1]].second = -1;
        pq.pop();

        return t[0];
    }
};