class Solution {
    int dfs(vector<vector<int>> &v, int r, int c, int zero){
      if(min(r, c) < 0 or r >= v.size() or c >= v[0].size() or v[r][c] == -1) return 0;
      if(v[r][c] == 2) return zero == -1 ? 1 : 0;
      v[r][c] = -1;
      zero--;
      int res = 0;
      res += dfs(v, r + 1, c, zero);
      res += dfs(v, r, c + 1, zero);
      res += dfs(v, r - 1, c, zero);
      res += dfs(v, r, c - 1, zero);
      v[r][c] = 0;
      zero++;
      return res;
    }
public:
    int uniquePathsIII(vector<vector<int>>& v) {
      int m = v.size(), n = v[0].size(), zero = 0, sx = 0, sy = 0;
      for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
          if(v[i][j] == 0) zero++;
          else if(v[i][j] == 1){
            sx = i; sy = j;
          }
        }
      }
      return dfs(v, sx, sy, zero);
    }
};