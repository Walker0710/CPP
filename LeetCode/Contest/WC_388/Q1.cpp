#include <bits/stdc++.h>

using namespace std;

// << ,

int minimumBoxes(vector<int> &apple, vector<int> &capacity)
{
    int sum = accumulate(apple.begin(), apple.end(), 0);

    sort(capacity.rbegin(), capacity.rend());
    int cnt = 0;

    for(int i = 0; i<capacity.size() && sum > 0; i++) {
        sum = sum - capacity[i];
        cnt++;
    }

    return cnt;
}