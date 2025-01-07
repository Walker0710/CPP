#include <bits/stdc++.h>

using namespace std;

// << ,

// normal method
void mergeArrays(vector<int> &a, vector<int> &b)
{
    int n = a.size();
    int m = b.size();
    int l = n-1;
    int r = 0;

    while (l >= 0 && r < m)
    {
        if(a[l] > b[r]) {
            swap(a[l], b[r]);
            l--;
            r++;
        }

        else {
            break;
        }
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}


// gap method - shell sort
void swapIfGreater(vector<int> &arr1, vector<int> &arr2, int ind1, int ind2) {
    if(arr1[ind1] > arr2[ind2]) {
        swap(arr1[ind1], arr2[ind2]);
    }
}

void mergeArrays(vector<int> &a, vector<int> &b)
{
    int n = a.size();
    int m = b.size();

    int len = n + m;
    int gap = len/2 + (len%2);

    while(gap > 0) {
        int left = 0;
        int right = left + gap;

        while(right < len) {

            //arr1 and arr2
            if(left < n && right >= n) {
                swapIfGreater(a, b, left, right - n);
            }

            //arr2 and arr2 
            else if(left >= n) {
                swapIfGreater(b, b, left-n, right-n);
            }

            //arr1 and arr1
            else {
                swapIfGreater(a, a, left, right);
            }

            left++;
            right++;
        }

        if(gap == 1)
        break;

        gap = (gap/2) + (gap%2);
    }
}