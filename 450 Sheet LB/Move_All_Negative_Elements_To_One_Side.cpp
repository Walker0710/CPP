#include <bits/stdc++.h>

using namespace std;

// << ,

//order is not maintained
void segregateElements(vector<int> &arr)
{
    int j = 0;

    for (int i = 0; i < arr.size(); i++)
    {

        if (arr[i] > 0)
        {
            if (i != j)
            swap(arr[i], arr[j]);
            
            j++;
        }
    }
}


//order is maintained
void segregateElements(vector<int> &arr)
{
    vector<int> helper(arr.size());

    int j = 0;
    for(int i = 0; i<arr.size(); i++) {

        if(arr[i] >= 0) {
            helper[j] = arr[i];
            j++;
        }
    }

    for(int i = 0; i<arr.size(); i++) {

        if(arr[i] < 0) {
            helper[j] = arr[i];
            j++;
        }
    }

    arr = helper;
}