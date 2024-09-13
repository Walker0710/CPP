#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <unordered_map>
#include <algorithm>

using namespace std;

class compare
{
public:
    bool operator()(pair<char, int> a, pair<char, int> b)
    {
        return a.second < b.second;
    }
};

string reorganizeString(string s) {
    unordered_map<char, int> m;

    for(int i = 0; i<s.length(); i++) {
        m[s[i]]++;
    }

    priority_queue<pair<char, int>, vector<pair<char, int>>, compare> maxHeap;

    for(auto i:m) {
        maxHeap.push({i.first, i.second});
    }

    string ans;

    while (maxHeap.size() != 0) 
    {
        pair<char, int> one = maxHeap.top();
        maxHeap.pop();

        pair<char, int> two = maxHeap.top();
        maxHeap.pop();

        char oneChar = one.first;
        int oneFre = one.second;

        char twoChar = two.first;
        int twoFre = two.second;

        while(twoFre != 0) {
            ans = ans+oneChar;
            oneFre--;

            ans = ans+twoChar;
            twoFre--;
        }

        if(maxHeap.size() == 0 && oneFre > 1) {
            return "";
        }

        else if(maxHeap.size() == 0 && oneFre == 1) {
            ans = ans + oneChar;
            return ans;
        }

        else if(oneFre != 0) 
        maxHeap.push({oneChar, oneFre});
    }

    return ans;
}

class compare {
public:
    bool operator()(pair<char, int> a, pair<char, int> b) {
        return a.second < b.second;
    }
};

string reorganizeString(string s) {
    unordered_map<char, int> m;
    for (char c : s) {
        m[c]++;
    }

    priority_queue<pair<char, int>, vector<pair<char, int>>, compare> maxHeap;
    for (auto i : m) {
        maxHeap.push({i.first, i.second});
    }

    string ans = "";
    pair<char, int> prev = {'#', -1};

    while (!maxHeap.empty()) {
        auto curr = maxHeap.top();
        maxHeap.pop();
        ans += curr.first;

        if (prev.second > 0) {
            maxHeap.push(prev);
        }

        curr.second--;
        prev = curr;

        if (maxHeap.empty() && curr.second > 0) {
            return "";
        }
    }

    return ans;
}
