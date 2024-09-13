#include<iostream>
#include<vector>

using namespace std;

void rotate(vector<vector<int>> &matrix) {

    int row = matrix.size();
    int col = matrix[0].size();

    for(int i = 0; i< row; i++) {

        for(int j = 0; j<col; j++) {

            matrix[i][j] = matrix[j][col-1-i];
            //matrix[j][col-1-i] = matrix[i][j];
        }
    }
}

int main() {

    vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};

    rotate(matrix);

    for(int i = 0; i< 3; i++) {

        for(int j = 0; j<3; j++) {

            cout<<matrix[i][j];
        }

        cout<<endl;
    }
}