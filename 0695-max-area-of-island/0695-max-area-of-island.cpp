class Solution {
public:
    void dfs(vector<vector<int>> &v, int r, int c, int &area){
      if(r < 0 or r >= v.size() or c < 0 or c >= v[0].size() or v[r][c] != 1) return;
      v[r][c] = 2;
      area++;
      dfs(v, r+1, c, area);
      dfs(v, r-1, c, area);
      dfs(v, r, c+1, area);
      dfs(v, r, c-1, area);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
      int area = 0, ans = 0;
      for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
          if(grid[i][j] == 1) dfs(grid, i, j, area);
          ans = max(ans, area);
          area = 0;
        }
      }
      return ans;
    }
};