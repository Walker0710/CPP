#include <bits/stdc++.h>

using namespace std;

// << ,

int rowWithMax1s(vector<vector<int>> &arr) {
    int row = arr.size();
    int col = arr[0].size();

    int i = 0;
    int j = col - 1;

    int ans = -1; 
    int maxi = 0; 

    while (i < row && j >= 0) {
        
        if (arr[i][j] == 1) {
            j--;

            if (col - j - 1 > maxi) {
                maxi = col - j - 1;
                ans = i;
            }
        } 
        
        else {
            i++;
        }
    }

    return ans;
}
