#include<iostream>
#include<vector>

using namespace std;

bool isValid(vector<vector<int>>& grid, int i, int j) {
    int n = grid.size();

    if (i >= 0 && i < n && j >= 0 && j < n) {
        return true;
    }

    return false;
}

int surfaceArea(vector<vector<int>>& grid) {

    int n = grid.size();
    int sum = 0;

    int count = 0;

    for(int i = 0; i<n; i++) {

        for(int j = 0; j<n; j++) {

            if(grid[i][j] != 0) {

                count++;
            }
        }
    }

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            if(isValid(grid,i,j+1) && grid[i][j+1] <= grid[i][j]) {

                sum = sum + grid[i][j] - grid[i][j+1];
            }

            if(!isValid(grid, i, j + 1)) {

                sum = sum + grid[i][j];
            }

            if(isValid(grid,i+1,j) && grid[i+1][j] <= grid[i][j]) {

                sum = sum + grid[i][j] - grid[i+1][j];
            }

            if(!isValid(grid, i+1, j)) {

                sum = sum + grid[i][j];
            }

            if(isValid(grid,i,j-1) && grid[i][j-1] <= grid[i][j]) {

                sum = sum + grid[i][j] - grid[i][j-1];
            }

            if(!isValid(grid, i, j - 1)) {

                sum = sum + grid[i][j];
            }

            if(isValid(grid,i-1,j) && grid[i-1][j] <= grid[i][j]) {

                sum = sum + grid[i][j] - grid[i-1][j];
            }

            if(!isValid(grid, i-1, j)) {

                sum = sum + grid[i][j];
            }
        }
    }
    return sum + 2*count;
}

//2nd approch
    int surfaceArea(vector<vector<int>>& grid) {
       int ans=0;
       int n=grid.size();

       for(int i=0;i<n;i++){

           for(int j=0;j<n;j++){

               if(grid[i][j]!=0){

               ans=ans+(grid[i][j]*6 - (grid[i][j]-1)*2);
               }

               if((j+1)<n){
                   ans=ans-(min(grid[i][j],grid[i][j+1]));
               }
               if((i+1)<n){
                   ans=ans-(min(grid[i][j],grid[i+1][j]));
               }
               if(j!=0){
                   ans=ans-(min(grid[i][j],grid[i][j-1]));
               }
               if(i!=0){
                   ans=ans-(min(grid[i][j],grid[i-1][j]));
               }
           }
       }
       return ans;
    }