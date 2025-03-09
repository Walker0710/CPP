#include <bits/stdc++.h>

using namespace std;

// << ,
int max_ele = 256;

int findSubString(string& s) {
    int n = s.length();

    if(n <= 1) 
    return s.length();

    int dist_cnt = 0;
    vector<bool> visi(max_ele, false);

    for(int i = 0; i<n; i++) {
        if(visi[s[i]] == false) {
            visi[s[i]] = true;
            dist_cnt++;
        }
    }

    int st = 0;
    int cnt = 0;
    int ans = INT_MAX;

    vector<int> crr_cnt(max_ele, 0);

    for(int i = 0; i<n; i++) {
        crr_cnt[s[i]]++;

        if(crr_cnt[s[i]] == 1) {
            cnt++;
        }

        if(cnt == dist_cnt) {
            
            while(crr_cnt[st] > 1) {
                if(crr_cnt[st] > 1) {
                    crr_cnt[st]--;
                }

                st++;
            }

            if(i - st + 1 < ans) {
                ans = i-st+1;
            }
        }
    }

    return ans;
}

const int MAX_CHARS = 256;

string findSubString(string str)
{
    int n = str.length();

    if (n <= 1)
        return str;

    int dist_count = 0;
    bool visited[MAX_CHARS] = { false };
    for (int i = 0; i < n; i++) {
        if (visited[str[i]] == false) {
            visited[str[i]] = true;
            dist_count++;
        }
    }

    int start = 0, start_index = -1, min_len = INT_MAX;

    int count = 0;
    int curr_count[MAX_CHARS] = { 0 };
    for (int j = 0; j < n; j++) {
        curr_count[str[j]]++;

        if (curr_count[str[j]] == 1)
            count++;

        if (count == dist_count) {
            while (curr_count[str[start]] > 1) {
                if (curr_count[str[start]] > 1)
                    curr_count[str[start]]--;
                start++;
            }

            int len_window = j - start + 1;
            if (min_len > len_window) {
                min_len = len_window;
                start_index = start;
            }
        }
    }

    return min_len;
}
