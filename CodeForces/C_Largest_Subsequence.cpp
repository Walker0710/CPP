#include <bits/stdc++.h>

using namespace std;

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define int long long

// << ,

// void solve()
// {
//     int n;
//     cin >> n;

//     string s;
//     cin >> s;

//     vector<int> lex_ind;

//     for (int i = 0; i < n; i++)
//     {
//         while (!lex_ind.empty() && (s[i] > s[lex_ind.back()]))
//             lex_ind.pop_back();

//         lex_ind.push_back(i);
//     }

//     int lex_size = lex_ind.size();
//     int first = s[lex_ind[0]];
//     int dup = 0;

//     for (int i = 0; i < lex_size; i++)
//     {
//         if(s[lex_ind[i]] == first)
//         dup++;
//     }

//     for (int i = 0; i < lex_size/2; i++)
//     {
//         swap(s[lex_ind[i]], s[lex_ind[lex_size - 1 - i]]);
//     }

//     if (is_sorted(s.begin(), s.end()))
//         cout << lex_size - dup << endl;

//     else
//     {
//         cout << -1 << endl;
//     }
// }


void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> lex_ind;

    for (int i = 0; i < n; i++)
    {
        while (!lex_ind.empty() && (s[i] > s[lex_ind.back()]))
            lex_ind.pop_back();

        lex_ind.push_back(i);
    }

    for(int i = 0; i<lex_ind.size(); i++) {
        cout << s[lex_ind[i]];
    }

    int lex_size = lex_ind.size();
    int first = s[lex_ind[0]];
    int dup = 0;

    for (int i = 0; i < lex_size; i++)
    {
        if(s[lex_ind[i]] == first)
        dup++;
    }

    for (int i = 0; i < lex_size/2; i++)
    {
        swap(s[lex_ind[i]], s[lex_ind[lex_size - 1 - i]]);
    }

    if (is_sorted(s.begin(), s.end()))
        cout << lex_size - dup << endl;

    else
    {
        cout << -1 << endl;
    }
}


signed main()
{
    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}