#include <bits/stdc++.h>

using namespace std;

// << ,

int findUnion(vector<int> &a, vector<int> &b)
{
    set<int> unionSet;

    for (int num : a) {
        unionSet.insert(num);
    }

    for (int num : b) {
        unionSet.insert(num);
    }

    return unionSet.size();
}