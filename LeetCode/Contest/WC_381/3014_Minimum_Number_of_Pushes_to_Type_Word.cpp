#include <bits/stdc++.h>

using namespace std;

// << ,

int minimumPushes(string word)
{
    int yoo = word.length() / 8;
    int rem = word.length() % 8;

    return 8 * ((yoo * (yoo + 1)) / 2) + rem * (yoo + 1);
}