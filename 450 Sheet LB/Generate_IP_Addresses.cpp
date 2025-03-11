#include <bits/stdc++.h>

using namespace std;

// << ,

bool isValid(string &s)
{
    int n = s.length();

    if (n == 1)
        return true;

    int val = stoi(s);

    if (s[0] == '0' || val > 255)
        return false;

    return true;
}

void solve(int ind, string &s, string curr, int cnt, vector<string> &ans)
{
    string temp = "";

    if (ind >= s.length())
        return;

    if (cnt == 3)
    {
        temp = s.substr(ind);

        if (temp.length() <= 3 && isValid(temp))
            ans.push_back(curr + temp);

        return;
    }

    for (int i = ind; i < min(ind + 3, (int)s.length()); i++)
    {
        temp = temp + s[i];

        if (isValid(temp))
        {
            solve(i + 1, s, curr + temp + '.', cnt + 1, ans);
        }
    }
}

vector<string> generateIp(string s)
{
    vector<string> ans;
    solve(0, s, "", 0, ans);
    return ans;
}