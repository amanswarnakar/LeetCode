class Solution {
public:
    void dfs(vector<vector<char>> &v, vector<vector<int>> &vis, int r, int c){
      if(r < 0 or r > v.size() - 1 or c < 0 or c > v[0].size() - 1) return;
      if(vis[r][c] == 0 and v[r][c] == '1'){
        vis[r][c] = 1;
        dfs(v, vis, r+1, c);
        dfs(v, vis, r-1, c);
        dfs(v, vis, r, c+1);
        dfs(v, vis, r, c-1);
      }
    }
    int numIslands(vector<vector<char>>& grid) {
      int ans = 0, m = grid.size(), n = grid[0].size();
      vector<vector<int>> vis(m, vector<int>(n, 0));
      for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
          if(grid[i][j] == '1' and vis[i][j] == 0){
            dfs(grid, vis, i, j); ans++;
          }
        }
      }
      return ans;
    }
};