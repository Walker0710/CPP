#include <bits/stdc++.h>

using namespace std;

// << ,

int maxDifference(string s)
{
    int n = s.length();
    vector<int> fre(26, 0);

    for (int i = 0; i < n; i++)
    {
        fre[s[i] - 'a']++;
    }

    int oddMax = 0;
    int evenMin = 1e9;

    for (int i = 0; i < 26; i++)
    { 
        if (fre[i] % 2 == 0 && fre[i] != 0)
            evenMin = min(evenMin, fre[i]);
      
        else if (fre[i] != 0)
            oddMax = max(oddMax, fre[i]);
    }

    if (evenMin == 1e9)
        evenMin = 0;

    return oddMax - evenMin;
}