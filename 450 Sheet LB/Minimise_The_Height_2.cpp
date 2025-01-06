#include <bits/stdc++.h>

using namespace std;

// << ,

// int getMinDiff(vector<int> &arr, int k)
// {
//     int n = arr.size();
//     sort(arr.begin(), arr.end());

//     if(arr[n-1] < k) {
//         return arr[n-1] - arr[0];
//     }

//     else {
//         arr[0] += k;
//         arr[n-1] -= k;
        
//         int mini = arr[0];
//         int maxi = arr[n-1];
//         int ans = maxi - mini;

//         for(int i = 1; i<n; i++) {

//             int tempMin = arr[i] - k;
//             int tempMax = arr[i] + k;

//             if(tempMin > mini) {
//                 ans = min(ans, maxi - tempMin);
//             }

//             if(tempMax > )

//         }
//     }
// }


int getMinDiff(vector<int> &arr, int k)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());

    if(arr[n-1] < k || arr[n-1] - arr[0] < 2*k) {
        return arr[n-1] - arr[0];
    }

    else {
        return arr[n-1] - arr[0] - 2*k;
    }
}