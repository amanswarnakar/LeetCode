class Solution {
public:
    void dfs(vector<vector<int>> &h, vector<vector<int>> &visit, int r, int c, int m, int n, int ph){
      if(r < 0 or c < 0 or r >= m or c >= n)
        return;
      if( h[r][c] < ph or visit[r][c] == -1)
        return;
      visit[r][c] = -1;
      dfs(h, visit, r+1, c, m, n, h[r][c]);
      dfs(h, visit, r-1, c, m, n, h[r][c]);
      dfs(h, visit, r, c+1, m, n, h[r][c]);
      dfs(h, visit, r, c-1, m, n, h[r][c]);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
      vector<vector<int>> ans;
      int m = h.size(), n = h[0].size();
      if(m == 0 or n == 0) return ans;
      vector<vector<int>> pac(m, vector<int>(n, 0)), atl(m, vector<int>(n, 0));
      for(int i = 0; i < m; i++){
        dfs(h, pac, i, 0, m, n, h[i][0]);  
        dfs(h, atl, i, n-1, m, n, h[i][n-1]);  
      }
      for(int i = 0; i < n; i++){
        dfs(h, pac, 0, i, m, n, h[0][i]);
        dfs(h, atl, m-1, i, m, n, h[m-1][i]);
      }
      for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
          if(pac[i][j] == -1 and atl[i][j] == pac[i][j]){
            ans.push_back({i, j});
          }
        }
      }
      return ans;
    }
};