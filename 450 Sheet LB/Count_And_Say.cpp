#include <bits/stdc++.h>

using namespace std;

// << ,
string solve(int ind, int n, string yoo)
{

    if (ind == n)
        return yoo;

    int len = yoo.length();
    int cnt = 1;
    string toReturn = "";

    for (int i = 0; i < len; i++)
    {

        if (i + 1 < len && yoo[i] == yoo[i + 1])
        {
            cnt++;
        }

        else
        {
            toReturn = toReturn + to_string(cnt) + yoo[i];
            cnt = 1;
        }
    }

    return solve(ind + 1, n, toReturn);
}

string countAndSay(int n)
{
    return solve(1, n, "1");
}

string countAndSay(int n)
{
    string ans = "1";

    for (int i = 2; i <= n; i++)
    {
        string lastString = ans;
        int l = ans.size();
        int j = 0;
        ans = "";
        
        while (j < l)
        {
            int count = j;
            while (j < l && lastString[j] == lastString[count])
            {
                count++;
            }
            ans += to_string(count - j) + lastString[j];
            j = count;
        }
    }
    return ans;
}