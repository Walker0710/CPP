#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <numeric>

using namespace std; // < ,,,

//brut force
int maximumSum(vector<int>& arr) {

    if(arr.size() == 1)
    return arr[0];

    int ans = INT_MIN; 

    for(int i = 0; i < arr.size(); i++) {
        for(int j = i+1; j < arr.size(); j++) {

            int sum = accumulate(arr.begin() + i, arr.begin() + j + 1, 0);
            int min_element_in_subarray = *min_element(arr.begin() + i, arr.begin() + j + 1);

            if (min_element_in_subarray < 0) {
                sum -= min_element_in_subarray; 
            }

            ans = max(ans, sum);
        }
    }

    return ans;
}
