#include <bits/stdc++.h>

using namespace std;

// << ,

void threeWayPartition(vector<int> &arr, int a, int b)
{
    sort(arr.begin(), arr.end());
}


void threeWayPartition(vector<int> &arr, int a, int b)
{
    int n = arr.size();
    int start = 0;
    int curr = 0;
    int end = n-1;

    while(curr <= end) {

        if(arr[curr] < a) {
            swap(arr[curr], arr[start]);
            start++;
            curr++;
        }

        else if(arr[curr] >= a && arr[curr] <= b) {
            curr++;
        }

        else if(arr[curr] > b) {
            swap(arr[curr], arr[end]);
            end--;
        }
    }
}