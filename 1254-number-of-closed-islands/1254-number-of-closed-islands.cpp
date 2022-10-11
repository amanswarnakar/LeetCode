class Solution {
public:
  
    /*  BRUTE FORCE - TLE 
    void dfs(vector<vector<int>> v, vector<vector<int>> &vis, int r, int c){
      if(r < 0 or r >= v.size() or c < 0 or c >= v[0].size()) return;
      if(vis[r][c] == 1 or v[r][c] == 1) return;
      vis[r][c] = 1;
      dfs(v, vis, r+1, c);
      dfs(v, vis, r-1, c);
      dfs(v, vis, r, c+1);
      dfs(v, vis, r, c-1);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
      int ans = 0, m = grid.size(), n = grid[0].size();
      vector<vector<int>> vis(m, vector<int>(n, 0));
      for(int i = 0; i < n; i++){
        if(grid[0][i] == 0 and vis[0][i] == 0) dfs(grid, vis, 0, i);
        if(grid[m - 1][i] == 0 and vis[m - 1][i] == 0) dfs(grid, vis, m - 1, i);
      }
      for(int i = 0; i < m; i++){
        if(grid[i][0] == 0 and vis[i][0] == 0) dfs(grid, vis, i, 0);
        if(grid[i][n - 1] == 0 and vis[i][n - 1] == 0) dfs(grid, vis, i, n - 1);
      }
      for(int i = 1; i < m - 1; i++){
        for(int j = 1; j < n - 1; j++){
          if(grid[i][j] == 0 and vis[i][j] == 0) {
            dfs(grid, vis, i, j); ans++;
          }
        }
      }
      return ans;
    }
    */
  
    bool dfs(vector<vector<int>> &v, int r, int c){
      if(r < 0 or r >= v.size() or c < 0 or c >= v[0].size()) return false;
      if(v[r][c] == 1) return true;
      v[r][c] = 1;
      bool d1 = dfs(v, r+1, c);
      bool d2 = dfs(v, r-1, c);
      bool d3 = dfs(v, r, c+1);
      bool d4 = dfs(v, r, c-1);
      return d1 and d2 and d3 and d4;
    }
  
    int closedIsland(vector<vector<int>>& g) {
      int ans = 0, m = g.size(), n = g[0].size();
      for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
          if(g[i][j] == 0) ans += dfs(g, i, j);
        }
      }
      return ans;
    }
};