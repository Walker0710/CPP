#include <bits/stdc++.h>

using namespace std;

// << ,

char helper(long long k, vector<int> &operations)
{
    if (k == 1)
        return 'a';

    int idx = ceil((double)(log(k) / log(2))) - 1;
    long long new_k = k - pow(2, idx);
 
    char ch = helper(new_k, operations);

    if (operations[idx] == 0)
    {
        return ch;
    }

    return (ch != 'z') ? (ch + 1) : 'a';
}

char kthCharacter(long long k, vector<int> &operations)
{ 
    return helper(k, operations);
}