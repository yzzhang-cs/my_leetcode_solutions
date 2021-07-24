// https://leetcode.com/problems/n-queens/
typedef vector<vector<string>> vvs;
typedef vector<string> vs;
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vvs res;
        vs board(n, string(n, '.'));

        backtrack(res, board, 0);
        return res;
    }
    
    void backtrack(vvs &res, vs &board, int j) {
        for(int i = 0; i < board.size(); i++) {
            if(validPlacement(board, j, i)) {
                board[j][i] = 'Q';
                if(j == board.size() - 1) {
                    res.push_back(board);
                }
                else {
                    backtrack(res,board, j + 1);
                }
                board[j][i] = '.';
            }
        }
        return;
    }
    
    bool validPlacement(const vs& board, int j, int i) {
        int n = board.size();
        int jj, ii;
        // check horizontal
        for(ii = 0; ii < n; ii++) {
            if(ii != i && board[j][ii] == 'Q') {
                return false;
            }
        }
        
        // check vertical
        for(jj = 0; jj < n; jj++) {
            if(jj != j && board[jj][i] == 'Q') {
                return false;
            }
        }
        
        // check \
        // up
        jj = j - 1;
        ii = i - 1;
        while(jj >= 0 && ii >= 0) {
            if(board[jj][ii] == 'Q') {
                return false;
            }
            jj--;
            ii--;
        }
        // down
        jj = j + 1;
        ii = i + 1;
        while(jj < n && ii < n) {
            if(board[jj][ii] == 'Q') {
                return false;
            }
            jj++;
            ii++;
        }
        
        // check /
        // up
        jj = j - 1;
        ii = i + 1;
        while(jj >= 0 && ii < n) {
            if(board[jj][ii] == 'Q') {
                return false;
            }
            jj--;
            ii++;
        }
        
        // down
        jj = j + 1;
        ii = i - 1;
        while(jj < n && ii >= 0) {
            if(board[jj][ii] == 'Q') {
                return false;
            }
            jj++;
            ii--;
        }
        return true;
    }
};
