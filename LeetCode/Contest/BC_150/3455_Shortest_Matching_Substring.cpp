#include <bits/stdc++.h>

using namespace std;

// << ,

void computeLPSArray(string &pat, int M, vector<int> &lps)
{
    int len = 0;

    lps[0] = 0;

    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
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
}

vector<int> KMPSearch(string &pat, string &txt)
{
    int M = pat.length();
    int N = txt.length();

    vector<int> lps(M);

    vector<int> result;

    computeLPSArray(pat, M, lps);

    int i = 0;
    int j = 0;

    while ((N - i) >= (M - j))
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }

        if (j == M)
        {
            result.push_back(i - j + 1);
            j = lps[j - 1];
        }

        else if (i < N && pat[j] != txt[i])
        {

            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return result;
}

int shortestMatchingSubstring(string s, string p)
{
    vector<string> rec;
    string curr = "";

    for (int i = 0; i < p.length(); i++)
    {
        if (p[i] == '*')
        {
            if (curr.size() != 0)
            {
                rec.push_back(curr);
            }

            curr = "";
        }

        else
        {
            curr.push_back(p[i]);
        }
    }

    if (curr.size() != 0)
        rec.push_back(curr);

    if (rec.size() == 1)
    {
        vector<int> yoo = KMPSearch(rec[0], s);

        if (yoo.size() == 0)
        return -1;

        return rec[0].size();
    }

    else if (rec.size() == 2)
    {
        vector<int> one = KMPSearch(rec[0], s);
        vector<int> two = KMPSearch(rec[1], s);

        int ans = INT_MAX;

        if (one.size() == 0 || two.size() == 0)
        {
            return -1;
        }

        for (int i = 0; i < one.size(); i++)
        {
            int st = one[i];
            int en = one[i] + rec[0].size() - 1;

            int second = lower_bound(two.begin(), two.end(), en + 1) - two.begin();

            if (second == two.size())
                continue;

            second = two[second];
            int yoo = second + rec[1].size() - 1;

            ans = min(ans, yoo - st + 1);
        }

        if (ans == INT_MAX)
            ans = -1;
        return ans;
    }

    else if (rec.size() == 3)
    {
        vector<int> one = KMPSearch(rec[0], s);
        vector<int> two = KMPSearch(rec[1], s);
        vector<int> three = KMPSearch(rec[2], s);

        int ans = INT_MAX;

        if (one.size() == 0 || two.size() == 0 || three.size() == 0)
        {
            return -1;
        }

        for (int i = 0; i < one.size(); i++)
        {
            int st = one[i];
            int en = one[i] + rec[0].size() - 1;

            int second = lower_bound(two.begin(), two.end(), en + 1) - two.begin();

            if (second == two.size())
                continue;

            second = two[second];
            int secondEnd = second + rec[1].size() - 1;

            int thrid = lower_bound(three.begin(), three.end(), secondEnd + 1) - three.begin();

            if (thrid == three.size())
                continue;

            thrid = three[thrid];
            int thridEnd = thrid + rec[2].size() - 1;

            ans = min(ans, thridEnd - st + 1);
        }

        if (ans == INT_MAX)
            ans = -1;
        return ans;
    }

    return 0;
}