#include<iostream>
#include<vector>

using namespace std;

bool combination(vector<string> board, char x) {

    string string1 = board[0];
    string string2 = board[1];
    string string3 = board[2];

    if(string1[0] == x && string1[1] == x && string1[2] == x) {

        return true;
    }

    if(string2[0] == x && string2[1] == x && string2[2] == x) {

        return true;
    }

    if(string3[0] == x && string3[1] == x && string3[2] == x) {

        return true;
    }

    if(string1[0] == x && string2[0] == x && string3[0] == x) {

        return true;
    }

    if(string1[1] == x && string2[1] == x && string3[1] == x) {

        return true;
    }

    if(string1[2] == x && string2[2] == x && string3[2] == x) {

        return true;
    }

    if(string1[0] == x && string2[1] == x && string3[2] == x) {

        return true;
    }

    if(string1[2] == x && string2[1] == x && string3[0] == x) {

        return true;
    }

    return false;
}

bool validTicTacToe(vector<string>& board) {

    int countX = 0;
    int countO = 0;

    for(int i = 0; i<3; i++) {

        string yo = board[i];

        for(int j = 0; j<3; j++) {

            if(yo[j] == 'X') {

                countX++;
            }

            if(yo[j] == 'O') {

                countO++;
            }
        }
    }

    if((countO == countX || countX == countO + 1) && !combination(board, 'X') && !combination(board, 'O')) {

        return true;
    }

    if((countO == countX || countX == countO + 1) && combination(board, 'X') && combination(board, 'O')) {

        return false;
    }

    if(countO == countX && !combination(board, 'X') && combination(board, 'O')) {

        return true;
    }

    if(countX == countO + 1 && combination(board, 'X') && !combination(board, 'O')) {

        return true;
    }

    return false;
}