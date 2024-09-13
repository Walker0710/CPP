#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> generateMatrix(int n) {

    vector<vector<int>> matrix(n,vector<int>(n, 0));
    int lastRow = n-1;
    int firstRow = 0;
    int lastCol = n-1;
    int firstCol = 0;
    int count = 1;

    while(count <= n*n) {

        for(int i = firstCol; i<=lastCol; i++) {

            matrix[firstRow][i] = count;
            count++;
        }

        firstRow++;

        for(int i = firstRow; i<=lastRow; i++) {

            matrix[i][lastCol] = count;
            count++;
        }

        lastCol--;

        for(int i = lastCol; i>= firstCol; i--) {

            matrix[lastRow][i] = count;
            count++;
        }

        lastRow--;

        for(int i = lastRow; i>= firstRow; i--) {

            matrix[i][firstCol] = count;
            count++;
        }

        firstCol++;
    }

    return matrix;
}