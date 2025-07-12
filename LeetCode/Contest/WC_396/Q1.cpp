#include <bits/stdc++.h>

using namespace std;

// << ,

bool isVowel(char ch)
{
    ch = tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

bool isValid(string s)
{
    if (s.length() < 3)
        return false;

    bool hasVowel = false;
    bool hasConsonant = false;

    for (char ch : s)
    {
        if (!isalnum(ch))
            return false; // allow only letters and digits

        if (isalpha(ch))
        {
            if (isVowel(ch))
            {
                hasVowel = true;
            }
            else
            {
                hasConsonant = true;
            }
        }
    }

    return hasVowel && hasConsonant;
}