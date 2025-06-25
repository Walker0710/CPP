#include <bits/stdc++.h>

using namespace std;

// << ,

string stringHash(string s, int k)
{
    int n = s.length();
    string ans = "";

    for (int i = 0; i < n; i += k)
    {
        int sum = 0;

        for (int j = 0; j < k; j++)
        {
            sum += s[i + j] - 'a';
        }

        char hashedChar = char((sum % 26) + 'a');
        ans += hashedChar;
    }

    return ans;
}