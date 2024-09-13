#include<iostream>
#include<vector>

using namespace std;

bool isSafe(int row, int col, vector<vector<int>>& board, int val) {

    for(int i = 0; i<board[0].size(); i++) {
    
        //row check
        if(board[row][i] == val)
        return false;

        //col check
        if(board[i][col] == val) 
        return false;

        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == val) 
        return false;
    }

    return true;
}

bool solve(vector<vector<int>>& board) {

    int n = board[0].size();

    for(int row = 0; row < n; row++) {

        for(int col = 0; col < n; col++) {

            if(board[row][col] == 0) {

                for(int val; val<=9; val++) {

                    if(isSafe(row, col, board, val)) {

                        board[row][col] = val;

                        bool isFurtherSolnPoss = solve(board);

                        if(isFurtherSolnPoss) 
                        return true;

                        else 
                        board[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }

    return true;
}

void solveSudoku(vector<vector<int>>& sudoku) {

    solve(sudoku);
}


//2nd 
  void solveSudoku(vector<vector<char>>& board) {
    solve(board, 0);
  }

  bool solve(vector<vector<char>>& board, int s) {
    if (s == 81)
      return true;

    const int i = s / 9;
    const int j = s % 9;

    if (board[i][j] != '.')
      return solve(board, s + 1);

    for (char c = '1'; c <= '9'; ++c)
      if (isValid(board, i, j, c)) {
        board[i][j] = c;
        if (solve(board, s + 1))
          return true;
        board[i][j] = '.';
      }

    return false;
  }

  bool isValid(vector<vector<char>>& board, int row, int col, char c) {
    for (int i = 0; i < 9; ++i)
      if (board[i][col] == c || board[row][i] == c ||
          board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
        return false;
    return true;
  }



