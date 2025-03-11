#include <bits/stdc++.h>

using namespace std;

// << ,

vector<int> computeLPSArray(string &pat)
{
    int n = pat.length();
    vector<int> lps(n);

    lps[0] = 0;
    int len = 0;

    int i = 1;
    while (i < n)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }

        else if (pat[i] != pat[len])
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }

            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int minChar(string &s)
{
    int n = s.length();
    string rev = s;
    reverse(rev.begin(), rev.end());

    s = s + "$" + rev;

    vector<int> lps = computeLPSArray(s);

    return (n - lps.back());
}

int main()
{
    string s = "AAAACECAAAA";
    cout << minChar(s);
    return 0;
}