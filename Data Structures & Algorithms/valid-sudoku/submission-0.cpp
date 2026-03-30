#include<string>
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // check all rows
       for(int row=0; row<9; row++) {
            vector<bool> visited(10, false);
            for(int col=0; col<9; col++) {
                auto num = board[row][col];
                if(visited[num] == true)
                    return false;
                    if(board[row][col] != '.') {
                        visited[num] = true;
                    }
            }
       }
        // check all columns
       for(int col=0; col<9; col++) {
            vector<bool> visited(10, false);
            for(int row=0; row<9; row++) {
                auto num = board[row][col];
                if(visited[num] == true) {
                     return false;
                }
                if(board[row][col] != '.' ) {
                    visited[num] = true;
                }
            }
       }
        for(int i=0; i<9; i+=3) {
            for(int j=0; j<9; j+=3) {
                if(!checkInSmallSudok(board, i, j))
                    return false;
            }
        }
        return true;
    }

    bool checkInSmallSudok(vector<vector<char>>& board, int curr_row, int curr_col) {
        vector<bool> visited(10, false);
       for(int row=curr_row; row<curr_row + 3; row++) {
            for(int col=curr_col; col< curr_col + 3; col++) {
                auto num = board[row][col];
                if(visited[num] == true)
                     return false;
                     if(board[row][col] != '.') {
                        visited[board[row][col]] = true;
                     }
            }
       }
       return true;
    }
};
