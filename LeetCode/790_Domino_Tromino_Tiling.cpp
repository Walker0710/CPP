#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>

using namespace std;

bool check(vector<vector<int>> &matrix) {
    for(int i = 0; i<2; i++) {
        for(int j = 0; j<matrix[0].size(); j++) {

            if(matrix[i][j] != 1) 
            return false;
        }
    }
    return true;
}

int solve(vector<vector<int>> &matrix, int index) {

    if(check(matrix))
    return 1;

    //domino
    //horizontal
    
}

int numTilings(int n) {
    vector<vector<int>> matrix(2, vector<int> (n, 0));
    return solve(matrix, 0);
}