#include <bits/stdc++.h>

using namespace std;

// << ,

string secFrequent(string arr[], int n)
{
    unordered_map<string, int> freq;

    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    int firstMax = 0, secondMax = 0;
    string firstMaxWord, secondMaxWord;

    for (auto &entry : freq)
    {
        if (entry.second > firstMax)
        {
            secondMax = firstMax;
            secondMaxWord = firstMaxWord;
            firstMax = entry.second;
            firstMaxWord = entry.first;
        }
        else if (entry.second > secondMax && entry.second < firstMax)
        {
            secondMax = entry.second;
            secondMaxWord = entry.first;
        }
    }

    return secondMaxWord;
}