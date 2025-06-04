#include <bits/stdc++.h>

using namespace std;

// << ,

int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets)
{
    int ans = 0;
    vector<bool> visi(fruits.size(), false);

    for(int i = 0; i<fruits.size(); i++) {
        bool flag = false;
        
        for(int j = 0; j<baskets.size(); j++) {

            if(!visi[j] && fruits[i] <= baskets[j]) {
                visi[j] = true;
                flag = true;
                break;
            }
        }

        if(!flag)
        ans++;
    }

    return ans;
}