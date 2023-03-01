class Solution {
public:
    bool isSafe(vector<string> &board, int r, int c){
      for(int i = r; i >= 0; i--){
        if(board[i][c] == 'Q') return false;
      }
      for(int i = c; i >= 0; i--){
        if(board[r][i] == 'Q') return false;
      }
      for(int i = r, j = c; i >= 0 and j >= 0; i--, j--){
        if(board[i][j] == 'Q') return false;
      }
      for(int i = r, j = c; i >= 0 and j < board.size(); i--, j++){
        if(board[i][j] == 'Q') return false;
      }
      return true;
    }
    void recur(int row, vector<string> &board, vector<vector<string>> &ans){
      int n = board.size();
      if(row == n){
        ans.emplace_back(board);
        return;
      }
      for(int i = 0; i < n; i++){
        if(isSafe(board, row, i)) {
          board[row][i] = 'Q';
          recur(row + 1, board, ans);
          board[row][i] = '.';
        }
      }
    }
    vector<vector<string>> solveNQueens(int n) {
      vector<vector<string>> ans;
      vector<string> board(n, string(n, '.'));
      recur(0, board, ans);
      return ans;
    }
};