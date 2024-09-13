#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <unordered_map>
#include <stack>

using namespace std;

int maxTurbulenceSize(vector<int>& arr) {

    int n = arr.size();

    if(n == 1)
    return n;

    if(n == 2) {
        
        if(arr[0] == arr[1])
        return 1;

        return n;
    }

    int flag = false;

    if(arr[0] > arr[1])
    flag = true;

    int ans = 0;
    int length = 1;

    for(int i = 0; i<arr.size(); i++) {

        if(i+1 < arr.size() && ((flag && arr[i] > arr[i+1]) || (!flag && arr[i] < arr[i+1]))) {
            length++;
            flag = !flag;
        }

        else {
            ans = max(ans, length);
            length = 1;

            if(i+1 < n && arr[i] != arr[i+1])
            i--;

            flag = !flag;
        }
    }
    return ans;
}