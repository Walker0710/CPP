#include <bits/stdc++.h>

using namespace std;

// << ,

bool areRotations2(string &s1, string &s2)
{
    int n = s1.length();
    int j = 0;
    int i = 0;

    while (j < n && s2[j] != s1[0])
    {
        j++;
    }

    if (j == n - 1)
    {
        return false;
    }

    while (i < n)
    {
        while (i < n && j < n && s1[i] == s2[j])
        {
            i++;
            j++;
        }

        if (j == n)
        {
            j = 0;
        }

        else if (i < n && s1[i] != s2[j])
        {
            return false;
        }
    }

    return true;
}

bool areRotations(string &s1, string &s2)
{
    bool ans = areRotations2(s1, s2) || areRotations2(s2, s1);
    return ans;
}

bool areRotations(string &s1, string &s2)
{
    string temp = s1 + s2;

    if(temp.find(s2) != string::npos) {
        return true;
    }

    return false;
}