#include<iostream>
#include<vector>

using namespace std;

bool isValid(vector<vector<int>> &board, int r, int c) {

    int row = board.size() - 1;
    int col = board[0].size() - 1;

    if(r >= 0 && r<= row && c >= 0 && c <= col && board[r][c] == 1) {

        return true;
    }

    return false;
}

int countLive(vector<vector<int>>& board, int r, int c) {

    int ans = 0;

    if(isValid(board, r-1, c)) {

        ans++;
    }

    if(isValid(board, r-1, c+1)) {

        ans++;
    }

    if(isValid(board, r, c+1)) {

        ans++;
    }

    if(isValid(board, r+1, c+1)) {

        ans++;
    }

    if(isValid(board, r+1, c)) {

        ans++;
    }

    if(isValid(board, r+1, c-1)) {

        ans++;
    }

    if(isValid(board, r, c-1)) {

        ans++;
    }

    if(isValid(board, r-1, c-1)) {

        ans++;
    }

    return ans;

}

void gameOfLife(vector<vector<int>>& board) {

    int row = board.size();
    int col = board[0].size();
    vector<vector<int>> copy(row,vector<int>(col, 0));

    for(int i =0; i< row; i++) {

        for(int j = 0; j<col; j++) {

            copy[i][j] = board[i][j];
        }
    }

    for(int i = 0; i<row; i++) {

        for(int j = 0; j<col; j++) {

            int yo = countLive(copy, i, j);
            
            if(board[i][j] == 1 && yo < 2) {

                board[i][j] = 0;
            }

            if(board[i][j] == 1 && (yo == 2 || yo == 3)) {

                board[i][j] = 1;
            }

            if(board[i][j] == 1 && yo > 3) {

                board[i][j] = 0;
            }

            if(board[i][j] == 0 && yo == 3) {

                board[i][j] = 1;
            }
        }
    }
}