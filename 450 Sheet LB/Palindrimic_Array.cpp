#include <bits/stdc++.h>

using namespace std;

// << ,
bool isPalindrome(int n)
{
    string s = to_string(n);
    int len = s.length();

    for (int i = 0; i < len / 2; i++)
    {
        if (s[i] != s[len - 1 - i])
            return false;
    }
    return true;
}

bool isPalinArray(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (!isPalindrome(arr[i]))
            return false;
    }
    return true;
}