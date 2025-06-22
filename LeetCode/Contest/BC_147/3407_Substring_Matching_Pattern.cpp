#include <bits/stdc++.h>

using namespace std;

// << ,

void computeLPSArray(string &pat, int M, vector<int> &lps)
{
    // Length of the previous longest prefix suffix
    int len = 0;

    // lps[0] is always 0
    lps[0] = 0;

    // loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Prints occurrences of pat in txt
vector<int> KMPSearch(string &pat, string &txt)
{
    int M = pat.length();
    int N = txt.length();

    // Create lps[] that will hold the longest prefix suffix
    // values for pattern
    vector<int> lps(M);

    vector<int> result;

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);

    int i = 0; // index for txt
    int j = 0; // index for pat
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

        // Mismatch after j matches
        else if (i < N && pat[j] != txt[i])
        {

            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return result;
}

bool hasMatch(string s, string p)
{
    vector<string> rec;
    string curr = "";

    for (int i = 0; i < p.length(); i++)
    {
        if (p[i] == '*')
        {
            if (curr.length() != 0)
            {

                rec.push_back(curr);
                curr = "";
            }
        }

        else
        {
            curr = curr + p[i];
        }
    }

    if (curr.length() != 0)
        rec.push_back(curr);

    if (rec.size() == 1)
    {
        vector<int> yoo = KMPSearch(s, rec[0]);

        if (yoo.size() != 0)
            return true;
    }
    if (rec.size() == 2)
    {
        vector<int> one = KMPSearch(s, rec[0]);
        vector<int> two = KMPSearch(s, rec[1]);

        for (int i : one)
        {
            for (int j : two)
            {
                if (i + rec[0].length() <= j)
                {
                    return true;
                }
            }
        }
    }

    return false;
}

bool hasMatch(string s, string p)
{
    int x = p.find("*");

    string b = p.substr(0, x);
    string e = p.substr(x + 1);

    int i = s.find(b);
    int j = s.rfind(e);

    return i != -1 && j != -1 && i + b.size() <= j;
}