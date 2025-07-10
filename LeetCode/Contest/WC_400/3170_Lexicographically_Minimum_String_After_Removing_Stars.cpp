#include <bits/stdc++.h>

using namespace std;

// << ,

string clearStars(string s)
{
    map<char, vector<int>> mp;
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        mp[s[i]].push_back(i);
    }

    vector<bool> visi(n, false);

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '*')
        {
            visi[i] = true;

            for (auto &yoo : mp)
            {

                int indii = lower_bound(yoo.second.begin(), yoo.second.end(), i) - yoo.second.end();

                if (yoo.second[indii] < i)
                {
                    visi[yoo.second[indii]] = true;

                    yoo.second.pop_back();
                }
            }
        }
    }

    string ans = "";

    for (int i = 0; i < n; i++)
    {
        if (!visi[i])
        {
            ans = ans + s[i];
        }
    }

    return ans;
}

string clearStars(string s)
{
    priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char, int>>> minh;
    unordered_map<int, bool> mpp;
 
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '*')
        {
            mpp[-minh.top().second] = true;
            minh.pop();
        }
        else
        {
            minh.push({s[i], -i});
        }
    }
 
    string res;
 
    for (int i = 0; i < s.size(); i++)
    {
        if (mpp.count(i) || s[i] == '*')
        continue;
        
        res += s[i];
    }
 
    return res;
}