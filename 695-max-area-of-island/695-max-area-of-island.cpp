class Solution {
public:
    void dfs(vector<vector<int>> &v, int r, int c, int &area){
      if(r < 0 or r >= v.size() or c < 0 or c >= v[0].size())
        return;
      if(v[r][c] == 1){
        area++; v[r][c] = 2;
        dfs(v, r+1, c, area);
        dfs(v, r-1, c, area);
        dfs(v, r, c+1, area);
        dfs(v, r, c-1, area);
      }
    }
  
    int maxAreaOfIsland(vector<vector<int>>& grid) {
      int m = grid.size(), n = grid[0].size(), ans = 0;
      for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
          int temp = 0;
          if(grid[i][j] == 1) dfs(grid, i, j, temp);
          ans = max(ans, temp);
        }
      }
      return ans;
    }
};