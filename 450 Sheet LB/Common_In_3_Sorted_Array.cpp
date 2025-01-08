#include <bits/stdc++.h>

using namespace std;

// << ,

//tle
vector<int> commonElements(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3)
{
    vector<int> ans;

    auto last = unique(arr1.begin(), arr1.end());
    arr1.erase(last, arr1.end());

    for (int i = 0; i < arr1.size(); i++)
    {

        int sec = 0, thi = 0;

        while (sec < arr2.size() && arr2[sec] < arr1[i])
        {
            sec++;
        }

        while (thi < arr3.size() && arr3[thi] < arr1[i])
        {
            thi++;
        }

        if (thi < arr3.size() && sec < arr2.size() && arr1[i] == arr2[sec] && arr1[i] == arr3[thi])
        {
            ans.push_back(arr1[i]);
        }
    }

    return ans;
}




vector<int> commonElements(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3) {

    vector<int> ans;
    int i = 0, j = 0, k = 0;

    while (i < arr1.size() && j < arr2.size() && k < arr3.size()) {

        if (arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
            
            if (ans.empty() || ans.back() != arr1[i]) {
                ans.push_back(arr1[i]);
            }
            
            i++;
            j++;
            k++;
        }

        else if (arr1[i] < arr2[j]) {
            i++;
        } 
        
        else if (arr2[j] < arr3[k]) {
            j++;
        } 
        
        else {
            k++;
        }
    }

    if (ans.empty()) {
        return {-1};
    }

    return ans;
}
