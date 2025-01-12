#include <bits/stdc++.h>

using namespace std;

// << ,

void sort012(vector<int> &arr)
{
    int n = arr.size();
    int start = 0;
    int curr = 0;
    int end = n-1;

    while(curr <= end) {
        if(arr[curr] == 0) {
            swap(arr[curr], arr[start]);
            start++;
            curr++;
        }

        else if(arr[curr] == 1) {
            curr++;
        }

        else if(arr[curr] == 2) {
            swap(arr[curr], arr[end]);
            end--;
        }
    }
}