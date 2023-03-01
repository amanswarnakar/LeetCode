class Solution {
public:
    bool check(vector<vector<char>> &b, int r, int c, char val){
      for(int i = 0; i < 9; i++){
        if(b[r][i] == val) return false;
      }
      for(int i = 0; i < 9; i++){
        if(b[i][c] == val) return false;
      }
      int row = r - r % 3, col = c - c % 3;
      for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
          if(b[i + row][j + col] == val) return false;
        }
      }
      return true;
    }
    bool solve(vector<vector<char>> &b, int r, int c){
      if(r == 9) return true;
      if(c == 9) return solve(b, r + 1, 0);
      if(b[r][c] != '.') return solve(b, r, c + 1);
      
      for(char ch = '1'; ch <= '9'; ch++){
        if(check(b, r, c, ch)){
          b[r][c] = ch;
          if(solve(b, r, c + 1)) return true;
          b[r][c] = '.';
        }
      }
      return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
      solve(board, 0, 0);
    }
};