#include <bits/stdc++.h>

using namespace std;

// << ,

int leastInterval(vector<char>& tasks, int n) {
    vector<int> count(26, 0);

    for(int i = 0; i<tasks.size(); i++) {
        count[tasks[i] - 'A']++;
    }

    sort(count.begin(), count.end());

    int maxii = count[25];
    int idle = (maxii - 1)*n;

    for(int i = 24; i >= 0; i--) {
        idle = idle - min(maxii - 1, count[i]);
    }

    return max(0, idle) + tasks.size();
}