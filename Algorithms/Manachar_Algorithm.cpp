#include <bits/stdc++.h>

using namespace std;

// << ,

#include <bits/stdc++.h>
using namespace std;
#define SIZE 100000 + 1

int P[SIZE * 2];

// Transform S into new string with special characters inserted.
string convertToNewString(const string &s)
{
    string newString = "@";

    for (int i = 0; i < s.size(); i++)
    {
        newString += "#" + s.substr(i, 1);
    }

    newString += "#$";
    return newString;
}

string longestPalindromeSubstring(const string &s)
{
    string Q = convertToNewString(s);
    int c = 0, r = 0; // current center, right limit

    for (int i = 1; i < Q.size() - 1; i++)
    {
        // find the corresponding letter in the palidrome subString
        int iMirror = c - (i - c);

        if (r > i)
        {
            P[i] = min(r - i, P[iMirror]);
        }

        // expanding around center i
        while (Q[i + 1 + P[i]] == Q[i - 1 - P[i]])
        {
            P[i]++;
        }

        // Update c,r in case if the palindrome centered at i expands past r,
        if (i + P[i] > r)
        {
            c = i; // next center = i
            r = i + P[i];
        }
    }

    // Find the longest palindrome length in p.

    int maxPalindrome = 0;
    int centerIndex = 0;

    for (int i = 1; i < Q.size() - 1; i++)
    {

        if (P[i] > maxPalindrome)
        {
            maxPalindrome = P[i];
            centerIndex = i;
        }
    }

    cout << maxPalindrome << "\n";
    return s.substr((centerIndex - 1 - maxPalindrome) / 2, maxPalindrome);
}

int main()
{
    string s = "kiomaramol\n";
    cout << longestPalindromeSubstring(s);
    return 0;
}







vector<int> manacher(string &s)
{
    string t = "#" + string(1, s[0]);
    
    for (int i = 1; i < s.size(); ++i) 
    {
        t += "#" + string(1, s[i]);
    }
    
    t += "#";
    
    int n = t.size();
    vector<int> p(n, 0);
    int l = 0, r = 0;

    for (int i = 0; i < n; i++)
    {
        p[i] = (i < r) ? min(r - i, p[l + (r - i)]) : 0;
    
        while (i + p[i] + 1 < n && i - p[i] - 1 >= 0 && t[i + p[i] + 1] == t[i - p[i] - 1]) 
        {
            p[i]++;
        }
        
        if (i + p[i] > r) 
        {
            l = i - p[i];
            r = i + p[i];
        }
    }
    
    return p;
}

string longestPalindrome(string s)
{
    vector<int> p = manacher(s);
    int resLen = 0, center_idx = 0;
 
    for (int i = 0; i < p.size(); i++)
    {
        if (p[i] > resLen)
        {
            resLen = p[i];
            center_idx = i;
        }
    }
 
    int resIdx = (center_idx - resLen) / 2;
    return s.substr(resIdx, resLen);
}