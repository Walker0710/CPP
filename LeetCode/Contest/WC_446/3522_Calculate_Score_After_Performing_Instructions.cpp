#include <bits/stdc++.h>

using namespace std;

// << ,

long long calculateScore(vector<string> &instructions, vector<int> &values)
{
    int n = instructions.size();
    vector<bool> visi(n, false);
    long long ans = 0;            
    int i = 0;

    while (i >= 0 && i < n)
    {
        if (visi[i]) break;

        visi[i] = true;

        if (instructions[i] == "add") {
            ans += values[i];
            i++;
        }
        else if (instructions[i] == "jump") {
            i += values[i];
        }
    }

    return ans;
}
