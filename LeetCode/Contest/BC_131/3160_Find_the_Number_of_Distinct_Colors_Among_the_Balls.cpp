#include <bits/stdc++.h>

using namespace std;

// << ,

vector<int> queryResults(int limit, vector<vector<int>> &queries)
{
    unordered_map<int, int> color;
    unordered_map<int, int> person;
    vector<int> ans(queries.size(), 0);

    for(int i = 0; i<queries.size(); i++) {
        int ind = queries[i][0];
        int clr = queries[i][1];

        if(person.find(ind) != person.end()) {
            int prevclr = person[ind];
            person[ind] = clr;

            color[prevclr]--;

            if(color[prevclr] == 0)
            color.erase(prevclr);

            color[clr]++;
        }

        else {
            person[ind] = clr;
            color[clr]++;
        }

        ans[i] = color.size();
    }

    return ans;
}