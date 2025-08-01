#include <bits/stdc++.h>

using namespace std;

// << ,

int romanToDecimal(string &s)
{
    unordered_map<char, int> romanValues = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}};

    int result = 0;

    for (int i = s.length() - 1; i >= 0; i--)
    {

        int currvalue = romanValues[s[i]];

        if (i < s.length() - 1 && currvalue < romanValues[s[i + 1]])
        {
            result = result - currvalue;
        }

        else
        {
            result = result + currvalue;
        }
    }

    return result;
}
