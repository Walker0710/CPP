#include <bits/stdc++.h>

using namespace std;

// << ,

vector<int> assignElements(vector<int> &groups, vector<int> &elements)
{
    int n = groups.size();
    int m = elements.size();

    vector<int> ans(n, -1);

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<m; j++) {
            if(groups[i]%elements[j] == 0) {
                ans[i] = j;
                break;
            }
        }
    }

    return ans;
}


void solve(int ele, unordered_map<int, int> &m, vector<int> &ans) {
    int yoo = INT_MAX;

    for(int i = 1; i*i <= ele; i++) {

        if(ele%i == 0 && m.count(i)) {
            yoo = min(yoo, m[i]);
        }

        if(i != ele/i && ele%i == 0 && m.count(ele/i)) {
            yoo = min(yoo, m[ele/i]);
        }
    }

    if(yoo != INT_MAX) 
    ans.push_back(yoo);

    else {
        ans.push_back(-1);
    }
}

vector<int> assignElements(vector<int> &groups, vector<int> &elements)
{
    unordered_map<int, int> m;

    for(int i = 0; i<elements.size(); i++) {
        if(m.count(elements[i]) == 0)
        m[elements[i]] = i;
    }

    vector<int> ans;

    for(int i = 0; i<groups.size(); i++) {
        solve(groups[i], m, ans);
    }

    return ans;
}