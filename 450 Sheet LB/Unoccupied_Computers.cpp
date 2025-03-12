#include <bits/stdc++.h>

using namespace std;

// << ,

// int solve(int n, string s) {
//     int n = s.length();
//     unordered_map<char, bool> visi;
//     int cnt = 0;
//     int ans = 0;

//     for(int i = 0; i<n; i++) {

//         if(visi[s[i]] == false && cnt >= n) {
//             ans++;
//             continue;
//         }

//         if(visi[s[i]] == false && cnt < n) {
//             visi[s[i]] = true;
//             cnt++
//         }

//         else if(visi[s[i]] == true) {
//             cnt--;
//             visi[s[i]] = false;
//         }

//     }

//     return ans;
// }

int solve(int n, string seq)
{
    char seen[MAX_CHAR] = {0};

    int res = 0;

    int occupied = 0;

    for (int i = 0; seq[i]; i++)
    {
        int ind = seq[i] - 'A';

        if (seen[ind] == 0)
        {
            seen[ind] = 1;

            if (occupied < n)
            {
                occupied++;

                seen[ind] = 2;
            }

            else
                res++;
        }

        else
        {
            if (seen[ind] == 2)
            occupied--;

            seen[ind] = 0;
        }
    }
    
    return res;
}