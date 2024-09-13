#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

bool maping(unordered_map<char, int> m) {

    for(auto i:m) {

        if(i.second != 1) {

            return false;
        }  
    }
    return true;
}

bool smallMatrix(vector<vector<char>>& board, int r1, int r2, int c1, int c2) {

    unordered_map<char, int> m;

    /*for(int i = 0; i<9; i++) {

        m[i] = 0;
    }*/

    for(int i = r1; i<= r2; i++) {

        for(int j = c1; j<= c2; j++) {

            if(board[i][j] != '.')
            ++m[board[i][j]];
        }
    }

    if(maping(m) == true) {

        return true;
    }

    else {

        return false;
    }
}

bool isValidSudoku(vector<vector<char>>& board) {

    unordered_map<char, int> m;

    /*for(int i = 0; i<9; i++) {

        m[i] = 0;
    }*/

    //checking row
    for(int i = 0; i<9; i++) {

        for(int j = 0; j<9; j++) {
            
            if(board[i][j] < '9' || board[i][j] < '1') {

                return false;
            }

            if(board[i][j] != '.')
            ++m[board[i][j]];
        }

        if(maping(m) == false) {

            return false;
        }

        m.clear();
    }

    for(int i = 0; i<9; i++) {

        for(int j = 0; j<9; j++) {
            
            if(board[j][i] < '9' || board[j][i] < '1') {

                return false;
            }
          
            if(board[i][j] != '.')
            ++m[board[j][i]];
        }

        if(maping(m) == false) {

            return false;
        }

        m.clear();
    }

    if(!smallMatrix(board, 0,2,0,2))
    return false; 

    if(!smallMatrix(board, 3,5,0,2))
    return false;

    if(!smallMatrix(board, 6,8,0,2))
    return false;

    if(!smallMatrix(board, 0,2,3,5))
    return false;

    if(!smallMatrix(board, 0,2,6,8))
    return false;

    if(!smallMatrix(board, 3,5,3,5))
    return false;

    if(!smallMatrix(board, 3,5,6,8))
    return false;

    if(!smallMatrix(board, 6,8,3,5))
    return false;

    if(!smallMatrix(board, 6,8,6,5))
    return false;
}

