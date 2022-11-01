class Solution {
public:
    int dfs(vector<vector<int>> &v, int m, int n, int r, int c){
      if(r == m) return c;
      if(min(r, c) < 0 or c >= n) return -1;
      if(v[r][c] == 1){
        if(c < n - 1 and v[r][c + 1] == 1)
          return dfs(v, m, n, r + 1, c + 1);
        else return -1;
      } else if(v[r][c] == -1){
        if(c > 0 and v[r][c - 1] == -1)
          return dfs(v, m, n, r + 1, c - 1);
        else return -1;
      }
      return -1;
    }
    vector<int> findBall(vector<vector<int>>& grid) {
      int m = grid.size(), n = grid[0].size();
      vector<int> ans(n, 0);
      for(int i = 0; i < n; i++){
        ans[i] = dfs(grid, m, n, 0, i);
      }
      return ans;
    }
};