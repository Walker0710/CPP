#include <bits/stdc++.h>

using namespace std;

// << ,

// why wrong
vector<int> subarraySum(vector<int> &arr, int target)
{
    int n = arr.size();

    int s = 0, e  = 0;
    int sum = 0;

    while(e < n) {

        while(sum < target && e < n) {
            sum = sum + arr[e];
            e++;
        }

        if(sum == target) {
            return {s+1, e};
        }

        sum -= arr[s];
        s++;
    }

    return {-1};
}


// correct one
vector<int> subarraySum(vector<int>& arr, int target) {
    int n = arr.size();
    int s = 0, e = 0, sum = 0;

    while (e < n) {
        sum += arr[e];

        while (sum > target && s <= e) {
            sum -= arr[s];
            s++;
        }

        if (sum == target) {
            return {s + 1, e + 1}; 
        }

        e++;
    }

    return {-1};
}