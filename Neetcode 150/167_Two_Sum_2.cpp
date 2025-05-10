#include <bits/stdc++.h>

using namespace std;

// << ,

vector<int> twoSum(vector<int>& numbers, int target) {
    int n = numbers.size();
    int s = 0;
    int e = n-1;
    
    while (e > s)
    {
        if(numbers[s] + numbers[e] == target) {
            return {s+1, e+1};
        }

        else if(numbers[s] + numbers[e] > target) {
            e--;
        }

        else {
            s++;
        }
    }

    return {};
}