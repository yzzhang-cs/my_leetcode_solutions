// https://leetcode.com/problems/sudoku-solver/
class Solution {
public:    
    void solveSudoku(vector<vector<char>>& board) {
        bool ret = backtrack(board, 0);
        if(!ret) {
            cout << "no solution." << endl;
        }
    }
    
    bool backtrack(vector<vector<char>>& board, int index) {
        if(index == 81) {
            return true;
        }
        int j = index / 9;
        int i = index % 9;
        if(board[j][i] != '.') {
            return backtrack(board, index + 1);
        }
        
        for(int k = 0; k < 9; k++) {
            if(validFill(board, index, nums[k])) {
                board[j][i] = nums[k];
                if(backtrack(board, index + 1)) {
                    return true;
                }
            }
        }
        board[j][i] = '.';
        return false;
    }
    
    bool validFill(vector<vector<char>>& board, int index, char fill) {
        int j = index / 9;
        int i = index % 9;
        
        // check rows
        for(int ii = 0; ii < 9; ii++) {
            if(i != ii && board[j][ii] == fill) {
                return false;
            }
        }
        
        // check cols
        for(int jj = 0; jj < 9; jj++) {
            if(j != jj && board[jj][i] == fill) {
                return false;
            }
        }
        
        // check box
        int box_j = j / 3;
        int box_i = i / 3;
        for(int jj = 0; jj < 3; jj++) {
            for(int ii = 0; ii < 3; ii++) {
                if(
                        (box_j * 3 + jj) * 9 + box_i * 3 + ii != index
                    &&  board[box_j * 3 + jj][box_i * 3 + ii] == fill
                ) {
                    return false;
                }
            }
        }
        return true;
    }
    
    
    
    // used for debugging
    // void printBoard(vector<vector<char>>& board) {
    //     for(int j = 0; j < 9; j++) {
    //         for(int i = 0; i < 9; i++) {
    //             cout << board[j][i] << " ";
    //         }
    //         cout << endl;
    //     }
    // }
    
private: 
    static constexpr char nums[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
};
