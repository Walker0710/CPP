#include <bits/stdc++.h>

using namespace std;

// << ,

class TimeMap
{
public:
    unordered_map<string, map<int, string>> rec;

    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        // rec[key].insert({timestamp, value});
        rec[key][timestamp] = value;
    }

    string get(string key, int timestamp)
    {
        auto it = rec[key].upper_bound(timestamp);

        if (it == rec[key].begin())
        {
            return "";
        }

        else
        {
            return prev(it)->second;
        }
    }
};


class TimeMap
{
private:
    unordered_map<string, vector<pair<int, string>>> keyStore;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp)
    {
        keyStore[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp)
    {
        auto &values = keyStore[key];
        int left = 0, right = values.size() - 1;
        string result = "";

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (values[mid].first <= timestamp)
            {
                result = values[mid].second;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return result;
    }
};