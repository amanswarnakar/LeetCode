class Solution {
public:
    void dfs(vector<vector<char>> &v, int r, int c){
      if(r < 0 or r >= v.size() or c < 0 or c >= v[0].size())
        return;
      if(v[r][c] == '1'){
        v[r][c] = '2';
        dfs(v, r+1, c);
        dfs(v, r-1, c);
        dfs(v, r, c+1);
        dfs(v, r, c-1);
      }
    }
  
    int numIslands(vector<vector<char>>& grid) {
      int m = grid.size(), n = grid[0].size(), ans = 0;
      for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
          if(grid[i][j] == '1'){
            dfs(grid, i, j);
            ans++;
          }
        }
      }
      return ans;
    }
};