#include<iostream>
#include<vector>

using namespace std;

    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<int> arr;
        int oR=mat.size();
        int oC=mat[0].size();
        if((oR*oC)!=(r*c)) return mat;
        for(int i=0;i<oR;i++){
            for(int j=0;j<oC;j++){
                arr.push_back(mat[i][j]);
            }
        }
        vector<vector<int>> ans(r,vector<int> (c));
        int k=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                ans[i][j]=arr[k++];
            }
        }
        return ans;
    }

    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {

        vector<vector<int>> ans(r, vector<int>(0,c));

        int row = mat.size();
        int col = mat[0].size();
        int ri=0;
        int ci=0;

        if(r*c != row*col) return mat;

        for(int i=0; i<row; i++){

            for(int j=0; j<col; j++){
                ans[ri][ci] = mat[i][j];
                ci++;
                
                if(ci > c-1 ){
                ci=0;
                ri++;
            }
            }
        }
        return ans;
    }