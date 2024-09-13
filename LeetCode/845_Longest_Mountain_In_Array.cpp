#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

int longestMountain(vector<int>& arr) {

    int ans = 0;
    int i = 0;
    while (i<arr.size()) {

        int count = 0;
        while (i+1 < arr.size() && arr[i] < arr[i+1]) {
            count++;
            i++;
        }

        if(i != 0 && i+1 < arr.size() && arr[i-1] < arr[i] && arr[i] > arr[i+1]) {

            while (i+1 < arr.size() && arr[i] > arr[i+1])
            {
                count++;
                i++;
            }
            i--;
        }

        else 
        count = 0;

        ans = max(count, ans);
        i++;
    }
    if(ans != 0)
    ans++;

    return ans;
}
