class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& v) {
      int row[9][9] = {0}, col[9][9] = {0}, cube[9][9] = {0};
      for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
          if(isdigit(v[i][j])){
            int k = i / 3 * 3 + j / 3;
            int num = v[i][j] - '1';
            if(row[i][num] or col[j][num] or cube[k][num])
              return false;
            row[i][num] = col[j][num] = cube[k][num] = 1;
          }
        }
      }
      return true;
    }
};