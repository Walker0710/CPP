#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <set>
#include <map>

using namespace std;

int minSwapsCouples(vector<int> &s)
{
    int n = s.size();
    map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[s[i]] = i;

    int cnt = 0;
    for (int i = 0; i < n - 1; i += 2)
    {
        int partner = (s[i] % 2 == 0 ? s[i] + 1 : s[i] - 1);
        if (s[i + 1] != partner)
        {
            int j = mp[partner];
            swap(s[i + 1], s[j]); 
            mp[s[j]] = j;         
            cnt++;
        }
    }
    return cnt;
}