#include <bits/stdc++.h>

using namespace std;

// << ,

bool subArrayExists(vector<int> &arr)
{
    int n = arr.size();
    
    vector<int> prefix(n);
    prefix[0] = arr[0];

    unordered_set<int> s;
    s.insert(arr[0]);

    for(int i = 1; i<n; i++) {
        prefix[i] = prefix[i-1] + arr[i];
        s.insert(prefix[i]);
    }

    if(s.size() != n || s.count(0) > 0) {
        return true;
    }

    else{
        return false;
    }
}


//alternative approch
bool subArrayExists(vector<int>& arr) {
    
    unordered_set<int> prefixSums;
    int sum = 0;

    for (int num : arr) {
        sum += num;

        if (sum == 0 || prefixSums.find(sum) != prefixSums.end() || num == 0) {
            return true;
        }

        prefixSums.insert(sum);
    }

    return false;
}
