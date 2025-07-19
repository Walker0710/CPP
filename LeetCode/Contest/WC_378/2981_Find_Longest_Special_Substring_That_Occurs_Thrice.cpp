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
            len = lps[len - 1];
            
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
    
    vector<int> lps(M), result;
    computeLPSArray(pat, M, lps);
    
    int i = 0, j = 0;
    
    while ((N - i) >= (M - j))
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
    
        if (j == M)
        {
            result.push_back(i - j); 
            j = lps[j - 1];
        }

        else if (i < N && pat[j] != txt[i])
        {
            if (j != 0)
            j = lps[j - 1];
    
            else
            i++;
        }
    }

    return result;
}

bool isCheck(string s, int mid)
{
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        string pattern(mid, ch); 

        vector<int> match_positions = KMPSearch(pattern, s);
        
        if (match_positions.size() >= 3)
        return true;
    }
    
    return false;
}

int maximumLength(string s)
{
    int ans = 0;
    int st = 1, en = s.length();
    
    while (st <= en)
    {
        int mid = (st + en) / 2;
    
        if (isCheck(s, mid))
        {
            ans = mid;
            st = mid + 1;
        }
    
        else
        {
            en = mid - 1;
        }
    }
 
    return ans == 0 ? -1 : ans;
}